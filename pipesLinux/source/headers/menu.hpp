#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>
#include "texture.hpp"
#include "button.hpp"

//returns 0 for play 1 for levelSelect 2 for quit
int mainMenu();
//retures number of selected level -1 for back
int levelSelect();
#endif
