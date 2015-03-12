#include "headers/input.hpp"

//Returns the x chord or the mouse cursor
int getMouseX()
{
	int mouseX;
	SDL_GetMouseState( &mouseX, NULL );
	return mouseX;
}

//Returns the y chord of the mouse cursor
int getMouseY()
{
	int mouseY;
	SDL_GetMouseState( NULL, &mouseY );
	return mouseY;
}

//returns true if left button was pressed
bool leftButtonPress()
{
	int ret = SDL_GetMouseState( NULL, NULL ); 
	if(ret&SDL_BUTTON(1))
		return true;
	return false;
}
