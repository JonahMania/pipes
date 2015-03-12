#ifndef _RUNINPUT_HPP_
#define _RUNINPUT_HPP_

#include "pipe.hpp"
#include "button.hpp"

//Checks all input and makes changes for one level of the game
void runInput( Pipe *pipes[], int offsetX, int offsetY, int levelWidth, int levelHeight, int *waterInterval, int *status, int *ret );

#endif
