#ifndef _INITIALIZE_HPP_
#define _INITIALIZE_HPP_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "texture.hpp"

//Initializes sdl and sets up the window
bool initialize();
//Loads all images for the game
bool loadImages();
//Free memory and close sdl
void close();

#endif 
#undef main