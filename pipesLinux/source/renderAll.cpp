#include "headers/renderAll.hpp"

//Buttons from game.cpp
extern Button flowSpeed;
extern Button quit;
extern Button nextLevel;
extern Button restart;
//FinalTexture from initialize.cpp
extern Texture finalTexture;
extern SDL_Rect finalClips[];
//Renders all images for a level of the game
void renderAll( Pipe *pipes[], int offSetX, int offSetY, int levelWidth, int levelHeight, SDL_Renderer* w, int *status )
{
	//Render Background as black
	SDL_SetRenderDrawColor( w, 0, 0, 0, 0xFF );
	SDL_RenderClear( w );
	//Render all pipes
	for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
		pipes[i]->render( pipes[i]->xPos*96 + offSetX, pipes[i]->yPos*96 + offSetY, w );
    //Render a pipe to the mouse pointer if it is selected
	for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
		if(pipes[i]->removed)
			pipes[i]->renderLarge( getMouseX() - 48, getMouseY() - 48, w );
    //If the level is in progress render the flowspeed button
	if( *status == 0 )
		flowSpeed.render(w,0);
	
	//If the level is over and won
	if( *status == 1 )
	{
        //Render the hack successful image
		finalTexture.render(490, 0, w, &finalClips[0], 0.0, NULL,  SDL_FLIP_NONE);
        //Render the continue button
		nextLevel.render(w,10);
        //Render the quit button
		quit.render(w,6);
	}
    //If the level is over and lost
	if( *status == -1 )
	{
        //Render Hack failed image
		finalTexture.render(620, 0, w, &finalClips[1], 0.0, NULL,  SDL_FLIP_NONE);
        //Render the restart button
		restart.render(w,8);
        //Render the quit button
		quit.render(w,6);
	}
	//Update screen
	SDL_RenderPresent( w );
}

