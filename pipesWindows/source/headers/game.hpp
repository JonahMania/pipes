#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include "texture.hpp"
#include "pipe.hpp"
#include "map.hpp"
#include "input.hpp"
#include "connect.hpp"
#include "button.hpp"
#include "timer.hpp"
#include "renderAll.hpp"
#include "update.hpp"
#include "runInput.hpp"

/*Runs one level of the game 
* Returns 0 while the level is in progress
* Returns 1 if the user moves on to the next level
* Returns -1 if the user exits to the main menu
* Returns 2 if the user restarts the level
* Returns -2 if the user closes the application
*/
int runLevel( const char *m );

#endif
