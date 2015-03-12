#include "headers/game.hpp"
#include "tinyxml2.h"

extern SDL_Renderer* windowRenderer; //The SDL_Renderer declared in initialize.cpp
SDL_Event event; //SDL_Event to handle user input
Button flowSpeed = Button(359, 720); //Button to increase flow speed
Button quit = Button( 708, 720 ); //Button to quit level
Button nextLevel = Button( 10, 720 ); //Button to advance to the next level
Button restart = Button( 10, 720 ); //Button to restart the level

//Function to read a xml map file and place all pipe pieces into an array
bool placePipes( Pipe *pipes[], int startX, int startY, int endX, int endY, int levelWidth, int levelHeight, const char *m )
{
	
    //Find the correct orientation for the starting pipe and set it as the second to last item in the pipes array
	if( startX < 1 )
		pipes[levelWidth * levelHeight] = new Pipe( startX - 1, startY - 1, 14, false );
	else if( startX > levelWidth )
		pipes[levelWidth * levelHeight] = new Pipe( startX - 1, startY - 1, 13, false );
	else if( startY < 1 )
		pipes[levelWidth * levelHeight] = new Pipe( startX - 1, startY - 1, 12, false );
	else
		pipes[levelWidth * levelHeight] = new Pipe( startX - 1, startY - 1, 11, false );	
    //Find the correct orientation for the exit pipe and set it to the last item in the array
	if( endX < 1 )
		pipes[levelWidth * levelHeight + 1] = new Pipe( endX - 1, endY - 1, 18, false );
	else if( endX > levelWidth )
		pipes[levelWidth * levelHeight + 1] = new Pipe( endX - 1, endY - 1, 17, false );
	else if( endY < 1 )
		pipes[levelWidth * levelHeight + 1] = new Pipe( endX - 1, endY - 1, 15, false );
	else
		pipes[levelWidth * levelHeight + 1] = new Pipe( endX - 1, endY - 1, 16, false );

    //Use tinyxml2 to parse the XMLDocument and place the remaining pipes into the array
	tinyxml2::XMLDocument doc;
    if( doc.LoadFile( m ) == 0 )
    {	
        tinyxml2::XMLElement* tile= doc.FirstChildElement( "map" )->FirstChildElement( "data" )->FirstChildElement( "tile" );
        
		int i = 0;
		int x = 0;
		int y = 0;
		while( tile )
        {
            if( i < levelWidth * levelHeight )
            {
                int typ = 0;
                int hidden = 0;
                std::stringstream t;
                t << tile->Attribute( "type" );
                t >> typ;
                std::stringstream h;
                h << tile->Attribute( "hidden" );
                h >> hidden;
                
                if( hidden == 0 )
                    pipes[i] = new Pipe( x, y, typ, false );
                else
                    pipes[i] = new Pipe( x, y, typ, true );
                x++;
                if( x >= levelWidth )
                {
                    x = 0;
                    y += 1;
                }
                if( y > levelHeight )
                    break;
                tile = tile->NextSiblingElement();   
            }
            i++;
        } 
        return true;
    }
	std::cout << "ERROR: map was not loaded" << doc.ErrorID() << std::endl;
	return false;
}

/*Runs one level of the game 
* Returns 0 while the level is in progress
* Returns 1 if the user moves on to the next level
* Returns -1 if the user exits to the main menu
* Returns 2 if the user restarts the level
* Returns -2 if the user closes the application
*/
int runLevel( const char *m )
{
	//Get map data
	int levelWidth = getWidth( m ); 
	int levelHeight = getHeight( m );
	int startX = getStartX( m );
	int startY = getStartY( m );
	int endX = getEndX( m );
	int endY =  getEndY( m );
	int offSetX = getOffsetX( m );
	int offSetY = getOffsetY( m );
	int speed = getSpeed( m );

	//Create array to store pipes
	Pipe *pipes[ ( levelWidth * levelHeight ) + 2];
	//The position of the pipe currently being filled with water
    int fillingPipe = levelWidth * levelHeight;
    //Set the water speed correctly for the current level
	int waterInterval = 0;
	if(speed == 3 ) 
    	waterInterval = 40;
    else if( speed == 2 )
        waterInterval = 55;   
    else
    	waterInterval = 80;    

	//Declear a timer to keep track of animation frames
	Timer frameTimer;
	int timeSinceZoom = 0; 
	int zoomInterval = 20; //Board zoom speed
	int timeSinceWater = 0;
	int timeSinceGlow = 0;
	int glowInterval = 100; //Exit pipe glow speed
	int glowWait = 0;
	bool glow = true;
	int pipeCheck = 0;
	int ret = 0;
    
    //Call placePipes to fill the pipes array
	if( !placePipes( pipes, startX, startY, endX, endY, levelWidth, levelHeight, m ))
	{
		std::cerr<<"ERROR: Pipes were not placed correctly " << std::endl;
	}
	else
	{
        //Quit flag
		bool quit = false;
    	int status = 0;
	
		while(!quit)
		{
            //Check if the user has pressed any buttons
			while( SDL_PollEvent( &event ) != 0 ) 
			{
                //If the user has quit the program close correctly
				if( event.type == SDL_QUIT )
				{
                    ret = -2;
					quit = true;
                    break;
				}

				if( event.type == SDL_MOUSEBUTTONDOWN )
				{
                    //Call runInput to handle input from the mouse
					runInput( pipes, offSetX, offSetY, levelWidth, levelHeight, &waterInterval, &status, &ret );
				}
			}
			
            //Run update and set the current status of the level
			status = update( pipes, levelWidth, levelHeight, startX, startY, endX, endY, &fillingPipe );
			
            //Update the frame to zoom an individual pipe piece
			timeSinceZoom += frameTimer.getTime();
			if( timeSinceZoom > zoomInterval )
			{
				timeSinceZoom -= zoomInterval;
				for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
				{
					if( pipes[i]->hover( m ) && pipes[i]->boardFrame < 7 && pipes[i]->type < 10)
						pipes[i]->boardFrame ++;
					if( pipes[i]->boardFrame > 0 && !pipes[i]->hover( m ) && pipes[i]->type < 10)
						pipes[i]->boardFrame --;
				}	
			}
			//Update the frame for end pipe
			timeSinceGlow += frameTimer.getTime();			
			if( timeSinceGlow > glowInterval )
			{
				timeSinceGlow -= glowInterval;
				glowWait++;
				if( glowWait > 30 )
				{
					if( pipes[levelWidth * levelHeight + 1]->boardFrame == 0 )
						glow = false;
					if( pipes[levelWidth * levelHeight + 1]->boardFrame == 5 )
					{
						glow = true;
						glowWait = 0;
					}
					if( pipes[levelWidth * levelHeight + 1]->boardFrame < 6 && !glow )
						pipes[levelWidth * levelHeight + 1]->boardFrame++;
					if( pipes[levelWidth * levelHeight + 1]->boardFrame < 6 && glow)
						pipes[levelWidth * levelHeight + 1]->boardFrame--;
				}	
			}
            //Update the frame for the flowing water
			timeSinceWater += frameTimer.getTime();
			if( timeSinceWater > waterInterval )
			{
				timeSinceWater -= waterInterval;
                if( fillingPipe == levelWidth * levelHeight )
                {
                    if( pipes[levelWidth * levelHeight]->waterFrame == 29)
                        fillingPipe = findStartNext( levelWidth, levelHeight, startX, startY, pipes);
                    else
                    	pipes[levelWidth * levelHeight]->waterFrame++;
                }
                else if( ( pipes[fillingPipe]->type == 6 || pipes[fillingPipe]->type == 7 ) && pipeCheck > 1 )
                {
                    if( pipes[fillingPipe]->waterFrame == 64 )
                        pipes[fillingPipe]->filled = true;
                    if( pipes[fillingPipe]->large && !pipes[fillingPipe]->filled )
                        pipes[fillingPipe]->waterFrame++;
                    pipeCheck = 0;
                }
                else if( pipeCheck > 0 && (pipes[fillingPipe]->type != 6 && pipes[fillingPipe]->type != 7) )
                {

                    if( pipes[fillingPipe]->waterFrame == 33 )
                        pipes[fillingPipe]->filled = true;
                    if( pipes[fillingPipe]->large && !pipes[fillingPipe]->filled )
                        pipes[fillingPipe]->waterFrame++;
                    pipeCheck++;
                     
                }
                else
                {
                    if( pipes[fillingPipe]->type == 8 || pipes[fillingPipe]->type == 9 )
                    {                    
		                if( pipes[fillingPipe]->waterFrame == 33 )
		                    pipes[fillingPipe]->filled = true;
		                if( pipes[fillingPipe]->large && !pipes[fillingPipe]->filled )
		                    pipes[fillingPipe]->waterFrame++;
                    }
                    pipeCheck++;          
                }
			}
            //Restart the frame timer      
 			frameTimer.start();		
            //Render all textures for the level
			renderAll( pipes, offSetX, offSetY, levelWidth,levelHeight, windowRenderer, &status );
            //If the level is no longer running quit out of the level
			if( ret != 0 ) 
				quit = true;
		}
	}
    //Free all the memory in the pipes array
    for( int i = 0; i < levelWidth*levelHeight + 2; i++ )
    {
    	delete pipes[i];
    }
	return ret;
    
}



