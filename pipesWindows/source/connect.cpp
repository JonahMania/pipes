#include "headers/connect.hpp"

//Returns next pipes location or -1 if not connected or not of right type
int connected( int levelWidth, int levelHeight, Pipe *pipes[], int pos, Pipe prevPipe )
{		
    //If the pipe is not hidden
	if( !pipes[pos]->hidden )
    {
		//Previous pipe is below current pipe
		if( prevPipe.yPos - 1 == pipes[pos]->yPos && prevPipe.xPos == pipes[pos]->xPos )
		{		
			if( pipes[pos]->type == 0 || pipes[pos]->type == 6 || pipes[pos]->type == 8 )
				return pos - levelWidth;
			if( pipes[pos]->type == 3 )
				return pos - 1;
			if( pipes[pos]->type == 2 )
				return pos + 1;
		}
		//Previous pipe is above current pipe
		if( prevPipe.yPos + 1 == pipes[pos]->yPos && prevPipe.xPos == pipes[pos]->xPos ) 
		{
			if( pipes[pos]->type == 0 || pipes[pos]->type == 6 || pipes[pos]->type == 8 )
				return pos + levelWidth;
			if( pipes[pos]->type == 5 )
				return pos - 1;
			if( pipes[pos]->type == 4 )
				return pos + 1;
		}
		//Previous pipe is to the left of current pipe
		if( prevPipe.yPos == pipes[pos]->yPos && prevPipe.xPos + 1 == pipes[pos]->xPos )
		{
			if( pipes[pos]->type == 1 || pipes[pos]->type == 7 || pipes[pos]->type == 9 )
				return pos + 1;
			if( pipes[pos]->type == 3 )
				return pos + levelWidth;
			if( pipes[pos]->type == 5 )
				return pos - levelWidth;
		}
		//Previous pipe is to the right of current pipe
		if( prevPipe.yPos == pipes[pos]->yPos && prevPipe.xPos - 1 == pipes[pos]->xPos )
		{
			if( pipes[pos]->type == 1 || pipes[pos]->type == 7 || pipes[pos]->type == 9 )
				return pos - 1;
			if( pipes[pos]->type == 2 )
				return pos + levelWidth;
			if( pipes[pos]->type == 4 )
				return pos - levelWidth;
		}
    }

	return -1;
}

//Returns the position of the pipe next to the start pipe 
//Returns -1 if no pipe found
int findStartNext( int levelWidth, int levelHeight, int startX, int startY, Pipe *pipes[] )
{
    //If start pipe is to the left of the board
	if( startX < 1 )
		return ( (startY - 1 ) * levelWidth );
    //If the start pipe is to the right of the board 
	if( startX > levelWidth )
		return startY * levelWidth - 1;
    //If the start pipe is above the board
	if( startY < 1 )
		return startX - 1;
    //If the start pipe is below the board
	if( startY > levelHeight )
		return levelWidth * ( levelHeight - 1 ) + startX - 1;

	return -1;

}

//Checks if start pipe is connected and if so returns the pipe after the connected pipe
int startConnected( int levelWidth, int levelHeight, int startX, int startY, Pipe *pipes[], int pos )
{
    //Set next to the pipe next to the start pipe
	int next = findStartNext( levelWidth, levelHeight, startX, startY, pipes );
    //Get type of next
	int nextType = pipes[next]->type;

	if( pipes[pos]->type == 14 )
	{
		if( nextType == 1 || nextType == 7 || nextType == 9 )
			return next + 1;
		if( nextType == 3 )
			return next + levelWidth;
		if( nextType == 5 )
			return next - levelWidth;
	}
	if( pipes[pos]->type == 13 )
	{
		if( nextType == 1 || nextType == 7 || nextType == 9 )
			return next - 1;
		if( nextType == 2 )
			return next + levelWidth;
		if( nextType == 4 )
			return next - levelWidth;
	}
	if( pipes[pos]->type == 12 )
	{
		if( nextType == 0 || nextType == 6 || nextType == 8 )
			return next + levelWidth;
		if( nextType == 4 )
			return next + 1;
		if( nextType == 5 )
			return next - 1;
	}
	if( pipes[pos]->type == 11 )
	{
		if( nextType == 0 || nextType == 6 || nextType == 8 )
			return next - levelWidth;
		if( nextType == 2 )
			return next + 1;
		if( nextType == 3 )
			return next - 1;
	}

	return -1;
}

//returns the position of the pipe that will be connected to the exit pipe
int endConnected( Pipe *pipes[], int levelWidth, int levelHeight, int endX, int endY )
{
    if( endX < 1 && endY <= levelHeight )
        return ( endY - 1 ) * levelWidth;
	if( endX <= levelWidth && endY < levelHeight )
		return endX - 1;
	if( endX > levelWidth && endY <= levelHeight )
		return ( levelHeight * endY ) - 1;
	if( endX <= levelWidth && endY > levelHeight )
		return ( levelWidth * ( levelHeight - 1 ) ) + endX -1;
	if( endX < levelWidth && endY <= levelHeight )
		return ( levelWidth * endY ) + 1;
}

//Checks if the end pipe is connected to the pipe next to it
bool checkEnd(Pipe *pipes[], int levelWidth, int levelHeight, int endConnected )
{
	int endType = pipes[levelWidth * levelHeight + 1]->type;
	int prev = pipes[endConnected]->type;
	if( endType == 15 )
		if( prev == 0 || prev == 6 || prev == 8 || prev == 4 || prev == 5 )
			return true;
	if( endType == 16 )
		if( prev == 0 || prev == 6 || prev == 8 || prev == 2 || prev == 3 )
			return true;
	if( endType == 17 )
		if( prev == 1 || prev == 7 || prev == 9 || prev == 2 || prev == 4 )
			return true;
	if( endType == 18 )
		if( prev == 1 || prev == 7 || prev == 9 || prev == 3 || prev == 5 )
			return true;
	return false;
}
