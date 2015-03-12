#include "headers/runInput.hpp"
//Buttons from game.cpp
extern Button flowSpeed; 
extern Button quit;
extern Button nextLevel;
extern Button restart;
//Checks all input and makes changes for one level of the game
void runInput( Pipe *pipes[], int offsetX, int offsetY, int levelWidth, int levelHeight, int *waterInterval, int *status, int *ret )
{
	int moving = -1;
	//Look to see if the player has selected a pipe to swap
	for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
	{
		if( pipes[i]->removed == true )
		{
			moving = i;
		}
	}

	//Swap pipe
	if( moving > -1 )
	{
		for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
		{
			if(pipes[i]->selected( offsetX, offsetY ) && !pipes[i]->hidden && pipes[i]->waterFrame < 1 )
			{
				pipes[moving]->removed = false;
				swap( i, moving, pipes );
				
			}
            else
                pipes[moving]->removed = false;
		}
	}

	//If the player does not have a selected pipe check if they are trying to pick up a pipe
	if( moving < 0 && *status == 0 )
	{
		for( int i = 0; i < levelWidth * levelHeight + 2; i++ )
		{
			if( pipes[i]->selected( offsetX, offsetY ) && pipes[i]->type < 11 && pipes[i]->waterFrame < 1)
			{
				if(pipes[i]->hidden == true )	
				{		
					pipes[i]->hidden = false;
				}	
				else if( pipes[i]->type != 10 && pipes[i]->waterFrame < 1 )
				{
					pipes[i]->removed = true;
				}
			}
		}
	}

	//If the player has clicked increase flow speed increase flow speed
	if( flowSpeed.selected() )
		*waterInterval = 6;
    //If the level is over and won
	if( *status == 1 )
	{
        //If the user selects quit
		if( quit.selected() )
			*ret = -1;
        //If the player selects continue
		if( nextLevel.selected() )
			*ret = 1;
	}
    //If the level is over and lost
	if( *status == -1 )
	{	
        //If the user selects quit
		if( quit.selected() )
			*ret = -1;
        //If the user selects restart
		if( restart.selected() )
			*ret = 2;
	}
		
}
