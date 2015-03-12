#ifndef _UPDATE_HPP_
#define _UPDATE_HPP_

#include <iostream>
#include "pipe.hpp"
#include "connect.hpp"
#include <cmath>

//Updates level variables while a user is playing
//Checks if the level is completed or failed
//Checks which pipes are connected to which
//Moves the water throughout the board
int update( Pipe *pipes[], int levelWidth, int levelHeight, int startX, int startY, int endX, int endY, int *fillingPipe );

#endif
