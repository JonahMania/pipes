#ifndef _PLACEPIPES_HPP_
#define _PLACEPIPES_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sstream>

//Searches a xml map file and returns the level width
int getWidth( const char *m );
//Searches a xml map file and returns the level height
int getHeight( const char *m );
//Searches a xml map file and returns the x position of the starting pipe 
int getStartX( const char *m );
//Searches a xml map file and returns the y position of the starting pipe 
int getStartY( const char *m );
//Searches a xml map file and returns the x position of the ending pipe 
int getEndX( const char *m );
//Searches a xml map file and returns the y position of the ending pipe 
int getEndY( const char *m );
//Searches a xml map file and returns the speed of the water
int getSpeed( const char *m );
//Calculates the x offset of the game board
int getOffsetX( const char *m );
//Calculates the y offset of the game board
int getOffsetY( const char *m );

#endif
