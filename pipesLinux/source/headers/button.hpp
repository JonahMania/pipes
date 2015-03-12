#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "input.hpp"
#include "texture.hpp"


class Button
{
	public:
		//constructor
		Button(int x,int y);
        //X position of the button
		int xPos;
        //Y position of the button
		int yPos;
    
    //Returns true if mouse pointer is hovered over the button
	bool hover();
    //Returns true if the button was clicked
	bool selected();
    //Renders a specified button clip to the renderer w
	void render(SDL_Renderer* w, int clip);
};

#endif
