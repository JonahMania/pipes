#ifndef _RENDERALL_HPP_
#define _RENDERALL_HPP_

#include <iostream>
#include "texture.hpp"
#include "pipe.hpp"
#include "button.hpp"

//Renders all images for a level of the game
void renderAll( Pipe *pipes[], int offSetX, int offSetY, int levelWidth, int levelHeight, SDL_Renderer* w, int *status);

#endif
