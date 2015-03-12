#include "headers/button.hpp"

extern Texture buttonsTexture; //Button texture from initialize.cpp
extern SDL_Rect buttonsClips[]; //ButtonClips from initialize.cpp

//Constructor
Button::Button(int x, int y)
{
    //X position of the button
	xPos = x;
    //Y position of the button
	yPos = y;
}

//Returns true if mouse pointer is hovered over the button
bool Button::hover()
{
    //If the mouse cursor is between the left, right, top and bottom of the button
	if( getMouseX() >= xPos && getMouseX() <= xPos + 306 && getMouseY() >= yPos && getMouseY() <= yPos + 40 )
		return true;
	return false;
}
//Returns true if the button was clicked
bool Button::selected()
{
    //If the mouse cursor is between the left, right, top and bottom of the button and the left button was pressed
	if( getMouseX() >= xPos && getMouseX() <= xPos + 306 && getMouseY() >= yPos && getMouseY() <= yPos + 40 && leftButtonPress() )
		return true;
	return false;
}

void Button::render(SDL_Renderer* w, int clip)
{
    //If the button is being hovered over render with lights on
	if( hover() )
		buttonsTexture.render(xPos, yPos, w, &buttonsClips[clip + 1], 0.0, NULL,  SDL_FLIP_NONE);
    //Render normaly
	else
		buttonsTexture.render(xPos, yPos, w, &buttonsClips[clip], 0.0, NULL,  SDL_FLIP_NONE);
}
