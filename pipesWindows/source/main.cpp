#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "headers/texture.hpp"
#include "headers/initialize.hpp"
#include "headers/input.hpp"
#include "headers/game.hpp"
#include "headers/menu.hpp"

//Create a array of all maps for the game
const char *maps[] = {"maps/level1.xml","maps/level2.xml","maps/level3.xml","maps/level4.xml","maps/level5.xml",
					  "maps/level6.xml","maps/level7.xml","maps/level8.xml","maps/level9.xml","maps/level10.xml",
					  "maps/level11.xml","maps/level12.xml","maps/level13.xml","maps/level14.xml","maps/level15.xml"}; 

int main()
{
    //Initialize SDL and set up window
	if( !initialize() )
	{
		std::cout << "ERROR: Failled to initialize" << std::endl;
        return 1;
	}
	else
	{
        //Load all Textures
		if( !loadImages() )
		{
			std::cout << "ERROR: Failed to load images" << std::endl;
            return 1;
		}
		else
		{ 
            //Create quit flag
			bool quit = false;
			while( !quit )
			{
				//Run the main menu
				int m = mainMenu();		
				//If the the user selects play
				if( m == 0 )
				{
                    //Run levels from beginning
					for(int i = 0; i < 15; i++)
					{
						int r = runLevel(maps[i]);
                        //If the user quits to main menu
						if( r == -1 )
							break;
                        //If the user restarts the level
						if( r == 2 )
							i--;
                        //If the user quits the program
                        if( r == -2 )
                        {
                            quit = true;
                            break;
                        }
					}
				}
                //If the player selects level select
				if( m == 1 )
				{
					int level = levelSelect();
			        //If the user has selected a level
					if(level > 0)
                        //Run levels from the selected level
						for(level; level <= 15; level++)
						{
							int r = runLevel(maps[level - 1]);
                            //If the user quits to main menu
							if( r == -1 )
								break;
                            //If the user restarts the level
							if( r == 2 )
								level--;
                            //If the user quits the program
                        	if( r == -2 )
                        	{
                            	quit = true;
                            	break;
                        	}
						}
                    //If the user quits the program
                    else if( level == 0 )
						quit = true;                    
					else
                        continue;
				}
                //If the user quits the program
				if( m == 2 )
					quit = true;
			}
		}
	}
    //Free memory
	close();
	return 0;
}
