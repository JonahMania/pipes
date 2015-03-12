#include "headers/update.hpp"
//Updates level variables while a user is playing
//Checks if the level is completed or failed
//Checks which pipes are connected to which
//Moves the water throughout the board
int update( Pipe *pipes[], int levelWidth, int levelHeight, int startX, int startY, int endX, int endY, int *fillingPipe )
{
    //Set all pipes to small
	for(int i = 0; i < levelWidth * levelHeight + 2; i ++ )
		pipes[i]->large = false;
    //Find the pipe before the exit pipe
	int endPrev = endConnected(pipes, levelWidth, levelHeight, endX, endY);
    //Find the pipe connected to the pipe next to the start pipe
	int next = startConnected( levelWidth, levelHeight, startX, startY, pipes, levelWidth * levelHeight );
    //Find the pipe after the start pipe
	int prev = findStartNext( levelWidth, levelHeight, startX, startY, pipes);
	int temp = 1;
	int pos = levelHeight * levelWidth;
    pipes[levelWidth * levelHeight]->filled = true;
    //Make sure the water in the first pipe is flowing the correct way
	if( pipes[levelWidth * levelHeight]->type == 11 && pipes[prev]->type == 3 )
		temp = -1;
	if( pipes[levelWidth * levelHeight]->type == 12 && ( pipes[prev]->type == 0 || pipes[prev]->type == 6 || pipes[prev]->type == 8 || pipes[prev]->type == 4  ) )
		temp = -1;
	if( pipes[levelWidth * levelHeight]->type == 13 && ( pipes[prev]->type == 1 || pipes[prev]->type == 7 || pipes[prev]->type == 9 || pipes[prev]->type == 2) )
		temp = -1;
    //Check each pipe as long as the next pipe is connected
	while( next > -1 )
	{

		//If the prev pipe is the fillingPipe reassign the fillingPipe to the next connected pipe
		if(prev == *fillingPipe && pipes[*fillingPipe]->filled && next < levelWidth * levelHeight )
			*fillingPipe = next;

        pipes[prev]->large = temp;
        temp = 1;
        
        //Make sure all pipes are flowing in the right direction
        if( next < levelWidth * levelHeight )
        {
		    if( ( pipes[next]->type == 0 || pipes[next]->type == 6 || pipes[next]->type == 8 ) && pipes[prev]->yPos < pipes[next]->yPos )
		        temp = -1;
		    if( ( pipes[next]->type == 1 || pipes[next]->type == 7 || pipes[next]->type == 9 ) && pipes[prev]->xPos > pipes[next]->xPos )
		        temp = -1;
		    if( pipes[next]->type == 2 && pipes[prev]->xPos > pipes[next]->xPos )
		        temp = -1;
		    if( pipes[next]->type == 3 && pipes[prev]->yPos > pipes[next]->yPos )
		        temp = -1;
		    if( pipes[next]->type == 4 && pipes[prev]->yPos < pipes[next]->yPos )
		        temp = -1;
		    if( pipes[next]->type == 5 && pipes[prev]->xPos < pipes[next]->xPos )
		        temp = -1;
        }
		pos = prev;
        //If the next pipe is out of the array
        if( next > levelWidth * levelHeight )
            break;
		prev = next;
        //Set next to the next connected pipe
		next = connected( levelWidth, levelHeight, pipes, next, *pipes[pos] );
               
	}
    //Check if the user has won or lost the level
	if( pipes[ levelWidth * levelHeight + 1 ]->type == 15 )
	{	
		if( checkEnd( pipes, levelWidth, levelHeight, endPrev ) && prev == endPrev )
		{
			pipes[endPrev]->large = 1;
			if( pipes[endPrev]->filled )
				return 1; // Win
            else
                return 0;
		}
		else if( prev == *fillingPipe && pipes[pos]->filled )
			return -1; // lost
		else
			return 0; // Level incomplete
	}
	else
	{
		if( checkEnd( pipes, levelWidth, levelHeight, endPrev ) && pos == endPrev )
		{ 
			if( pipes[endPrev]->filled )
				return 1; // Win
            else
                return 0;
		}
		else if( prev == *fillingPipe && pipes[pos]->filled )
			return -1; // lost
		else
			return 0; // Level incomplete
	}
}

