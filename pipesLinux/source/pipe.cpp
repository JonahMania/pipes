#include "headers/pipe.hpp"

/*
pipe types
0 = straight up
1 = straight sideways
2 = bend bottom to right
3 = bend bottom to left
4 = bend top to right
5 = bend top to left
6 = slow up
7 = slow sideways
8 = speed up
9 = speed sideways
10 = alarm
11 = start up
12 = start down
13 = start left
14 = start right
15 = end up
16 = end down
17 = end left
18 = end right
*/ 

//Textures from initialize.cpp
extern Texture boardTexture;
extern Texture straightTexture;
extern Texture bendTexture;
extern Texture slowTexture;
extern Texture slowTextureExt;
extern Texture speedTexture;
extern Texture startTexture;
extern Texture questionTexture;
extern SDL_Rect boardClips[];
extern SDL_Rect straightClips[];
extern SDL_Rect bendClips[];
extern SDL_Rect slowClips[];
extern SDL_Rect speedClips[];
extern SDL_Rect startClips[];

//Constructor
Pipe::Pipe( int x, int y, int t, bool h )
{
	if( t < 0 || t > 19 )
		t = 0;
	
	xPos = x;
	yPos = y;
	type = t;
	filled = false;
	hidden = h;
	removed = false;
	large = 0;
	boardFrame = 0;
	waterFrame = 0;
}

//Renders the pipe at given position and to the given renderer
void Pipe::render( int x, int y,SDL_Renderer* w )
{
    //If the pipe is hidden render the question tile
	if( hidden )
	{
		questionTexture.render(x, y, w, NULL,0.0, NULL, SDL_FLIP_NONE);
	}
    //If the pipe is removed from the board render a empty box
	else if( removed )
	{
		boardTexture.render(x, y, w, &boardClips[39], 0.0, NULL,  SDL_FLIP_NONE);
	} 
    //Render the correct pipe type with the correct size
	else
	{
		if( type == 0 )
			if(large > 0)
				straightTexture.render(x, y, w, &straightClips[1 + waterFrame], 0.0, NULL,  SDL_FLIP_NONE);
			else if( large < 0 )
				straightTexture.render(x, y, w, &straightClips[1 + waterFrame], 180, NULL,  SDL_FLIP_NONE);
			else
				boardTexture.render(x, y, w, &boardClips[0 + boardFrame], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 1 )	
			if(large > 0)
				straightTexture.render(x, y, w, &straightClips[1 + waterFrame], 90, NULL,  SDL_FLIP_NONE);
			else if( large < 0 )
				straightTexture.render(x, y, w, &straightClips[1 + waterFrame], 270, NULL,  SDL_FLIP_NONE);
			else
				boardTexture.render(x, y, w, &boardClips[0 + boardFrame], 90, NULL,  SDL_FLIP_NONE);
		if( type == 2 )
			if(large > 0)
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 0.0, NULL,  SDL_FLIP_NONE);
			else if( large < 0 )
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 270, NULL,  SDL_FLIP_HORIZONTAL);
			else
				boardTexture.render(x, y, w, &boardClips[8 + boardFrame], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 3 )
			if(large > 0)
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 90, NULL,  SDL_FLIP_NONE);
			else if( large < 0 )
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 0, NULL,  SDL_FLIP_HORIZONTAL);
			else
				boardTexture.render(x, y, w, &boardClips[8 + boardFrame], 90, NULL,  SDL_FLIP_NONE);
		if( type == 4 )
			if(large > 0)
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 270, NULL,  SDL_FLIP_NONE);
			else if( large < 0)
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 180, NULL,  SDL_FLIP_HORIZONTAL);
			else
				boardTexture.render(x, y, w, &boardClips[8 + boardFrame], 270, NULL,  SDL_FLIP_NONE);
		if( type == 5 )
			if(large > 0)
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 180, NULL,  SDL_FLIP_NONE);
			else if( large < 0 )
				bendTexture.render(x, y, w, &bendClips[1 + waterFrame], 90, NULL,  SDL_FLIP_HORIZONTAL);
			else
				boardTexture.render(x, y, w, &boardClips[8 + boardFrame], 180, NULL,  SDL_FLIP_NONE);
		if( type == 6 )
			if(large > 0)
            {
                if(waterFrame < 35)
					slowTexture.render(x, y, w, &slowClips[1 + waterFrame], 0.0, NULL,  SDL_FLIP_NONE);
                else
					slowTextureExt.render(x, y, w, &slowClips[1 + waterFrame], 0.0, NULL,  SDL_FLIP_NONE);                  
            }
			else if( large < 0 )
            {
            	if(waterFrame < 35)
					slowTexture.render(x, y, w, &slowClips[1 + waterFrame], 180, NULL,  SDL_FLIP_NONE);
                else
					slowTextureExt.render(x, y, w, &slowClips[1 + waterFrame], 180, NULL,  SDL_FLIP_NONE);
            }
			else
				boardTexture.render(x, y, w, &boardClips[16 + boardFrame], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 7 )
			if(large > 0)
            {	
                if(waterFrame < 35)
					slowTexture.render(x, y, w, &slowClips[1 + waterFrame], 90, NULL,  SDL_FLIP_NONE);
                else
					slowTextureExt.render(x, y, w, &slowClips[1 + waterFrame], 90, NULL,  SDL_FLIP_NONE);
            }
			else if(large < 0)
            {
            	if(waterFrame < 35)
					slowTexture.render(x, y, w, &slowClips[1 + waterFrame], 270, NULL,  SDL_FLIP_NONE);
            	else
					slowTextureExt.render(x, y, w, &slowClips[1 + waterFrame], 270, NULL,  SDL_FLIP_NONE);
            }
			else
				boardTexture.render(x, y, w, &boardClips[16 + boardFrame], 90, NULL,  SDL_FLIP_NONE);
		if( type == 8 )
			if(large > 0)
				speedTexture.render(x, y, w, &speedClips[1 + waterFrame], 0.0, NULL,  SDL_FLIP_NONE);
			else if(large < 0)
				speedTexture.render(x, y, w, &speedClips[1 + waterFrame], 180, NULL,  SDL_FLIP_NONE);
			else
				boardTexture.render(x, y, w, &boardClips[24 + boardFrame], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 9 )
			if(large > 0)
				speedTexture.render(x, y, w, &speedClips[1 + waterFrame], 90, NULL,  SDL_FLIP_NONE);
			else if(large < 0)
				speedTexture.render(x, y, w, &speedClips[1 + waterFrame], 270, NULL,  SDL_FLIP_NONE);
			else
				boardTexture.render(x, y, w, &boardClips[24 + boardFrame], 90, NULL,  SDL_FLIP_NONE);
		if( type == 10 )
			boardTexture.render(x, y, w, &boardClips[32], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 11 )
			startTexture.render(x, y, w, &startClips[0 + waterFrame], 270, NULL, SDL_FLIP_NONE);
		if( type == 12 )
			startTexture.render(x, y, w, &startClips[0 + waterFrame], 90, NULL, SDL_FLIP_NONE);
		if( type == 13 )
			startTexture.render(x, y, w, &startClips[0 + waterFrame], 180, NULL, SDL_FLIP_NONE);
		if( type == 14 )
			startTexture.render(x, y, w, &startClips[0 + waterFrame], 0.0, NULL, SDL_FLIP_NONE);
		if( type == 15 )
			boardTexture.render(x, y, w, &boardClips[33 + boardFrame], 0.0, NULL, SDL_FLIP_NONE);
		if( type == 16 )
			boardTexture.render(x, y, w, &boardClips[33 + boardFrame], 180, NULL, SDL_FLIP_NONE);
		if( type == 17 )
			boardTexture.render(x, y, w, &boardClips[33 + boardFrame], 90, NULL, SDL_FLIP_NONE);
		if( type == 18 )
			boardTexture.render(x, y, w, &boardClips[33 + boardFrame], 270, NULL, SDL_FLIP_NONE);
	}
}

//Renders the pipe as large at the given position and to the given renderer
void Pipe::renderLarge(int x, int y, SDL_Renderer* w)
{

		if( type == 1 )	
			straightTexture.render(x, y, w, &straightClips[0], 90, NULL,  SDL_FLIP_NONE);
		if( type == 2 )
			bendTexture.render(x, y, w, &bendClips[0], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 3 )
			bendTexture.render(x, y, w, &bendClips[0], 90, NULL,  SDL_FLIP_NONE);
		if( type == 4 )
			bendTexture.render(x, y, w, &bendClips[0], 270, NULL,  SDL_FLIP_NONE);
		if( type == 5 )
			bendTexture.render(x, y, w, &bendClips[0], 180, NULL,  SDL_FLIP_NONE);
		if( type == 6 )
			slowTexture.render(x, y, w, &slowClips[0], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 7 )
			slowTexture.render(x, y, w, &slowClips[0], 90, NULL,  SDL_FLIP_NONE);
		if( type == 8 )
			speedTexture.render(x, y, w, &speedClips[0], 0.0, NULL,  SDL_FLIP_NONE);
		if( type == 9 )
			speedTexture.render(x, y, w, &speedClips[0], 90, NULL,  SDL_FLIP_NONE);
		if( type == 0 )
			straightTexture.render(x, y, w, &straightClips[0], 0.0, NULL,  SDL_FLIP_NONE);		
}
//Checks if the pipe is being hovered over
bool Pipe::hover( const char *m )
{
	if( ( getMouseX() > (this-> xPos*96) + getOffsetX( m ) ) && ( getMouseX() <= (this->xPos*96) + getOffsetX( m ) + 96 ) && ( getMouseY() > (this->yPos*96) + getOffsetY( m ) ) && ( getMouseY() <= (this->yPos*96) + getOffsetY( m ) + 96 ) )
		return true;
	return false;	
}
//Checks if the pipe was selected
bool Pipe::selected( int offsetX, int offsetY )
{ 
	if( ( getMouseX() > (this-> xPos*96) + offsetX ) && ( getMouseX() <= (this->xPos*96) + offsetX + 96 ) && ( getMouseY() > (this->yPos*96) + offsetY ) && ( getMouseY() <= (this->yPos*96) + offsetY + 96 ) && leftButtonPress() )
		return true;
	return false;
}
//Swaps two pipes and returns true if swap was successful or false if swap is not possible
bool swap( int x, int y, Pipe *pipes[] )
{
	if( pipes[x]->type < 10 && pipes[y]->type < 10)
	{
		
		int tempX = pipes[x]->xPos;
		int tempY =	pipes[x]->yPos;

		pipes[x]->xPos = pipes[y]->xPos;
		pipes[x]->yPos = pipes[y]->yPos;
		pipes[y]->xPos = tempX;
		pipes[y]->yPos = tempY;	

		Pipe temp = *pipes[x];
		*pipes[x] = *pipes[y];
		*pipes[y] = temp;
		
		return true;
	}
	return false;
}
