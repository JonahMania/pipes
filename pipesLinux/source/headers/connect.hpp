#ifndef _CONNECT_HPP_
#define _CONNECT_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "pipe.hpp"
#include "map.hpp"

//Returns next pipes location or -1 if not connected or not of right type
int connected(int levelWidth, int levelHeight, Pipe *pipes[], int pos, Pipe prevPipe);
//Returns the postion of the pipe next to the start pipe 
//Returns -1 if no pipe found
int findStartNext( int levelWidth, int levelHeight, int startX, int startY, Pipe *pipes[] );
//Checks if start pipe is connected and if so returns the pipe after the connected pipe
int startConnected( int levelWidth, int levelHeight, int startX, int startY, Pipe *pipes[], int pos );
//Returns the position of the pipe connected to the exit pipe
int endConnected( Pipe *pipes[], int levelWidth, int levelHeight, int endX, int endY );
//Checks if the end pipe is connected to the pipe next to it
bool checkEnd(Pipe *pipes[], int levelWidth, int levelHeight, int endConnected);
#endif
