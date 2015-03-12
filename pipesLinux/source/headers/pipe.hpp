#ifndef _PIPE_HPP_
#define _PIPE_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.hpp"
#include "input.hpp"
#include "map.hpp"

/*
pipe key
0 = stright up
1 = stright sideways
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

class Pipe
{
	public:
		//Constructor
		Pipe(int x, int y, int t, bool h );
		int xPos; //The x position of the pipe piece
		int yPos; //The y position of the pipe piece
		int type; //The type of pipe see pipe key
		bool filled; //True when pipe is filled with water
		bool hidden; //True when the pipe is covered with a question tile
		bool removed; //True while the pipe is being moved by the user
		int large; //True when the pipe is connected should be rendered as large
		int boardFrame; //The frame number for the pipes zooming animation
		int waterFrame; //The frame number of for the water flowing through the pipe

		//Renders the pipe at given position and to the given renderer
		void render(int x, int y, SDL_Renderer* w );
		//Renders the pipe as large at the given position and to the given renderer
		void renderLarge(int x, int y, SDL_Renderer* w);
		//Checks if the pipe is being hovered over
		bool hover( const char *m );
		//Checks if the pipe was selected
		bool selected( int offsetX, int offsetY  );
};

		//Swaps two pipes and returns true if swap was successful or false if swap is not possible
		bool swap( int x, int y, Pipe *pipes[] );

#endif
