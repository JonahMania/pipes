#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

//Returns the x coordinate of the mouse pointer
int getMouseX();
//Returns the y coordinate of the mouse pointer
int getMouseY();
//Returns true if the left mouse button was pressed
bool leftButtonPress();

#endif
#undef main