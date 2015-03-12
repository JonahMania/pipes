#ifndef _TEXTURE_HPP_ 
#define _TEXTURE_HPP_ 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture
{
	public:
		//Initializes variables
		Texture();
		//Deallocates memory
		~Texture();
		//Loads an image takes sting p as path to image
		bool loadImage( std::string p, SDL_Renderer* w );
		//Deallocates texture
		void close();
		//Renders texture at a given point
		void render( int x, int y, SDL_Renderer* w, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		//Get image width
		int getWidth();
		//Get image height
		int getHeight();

	private:
		//Hardware texture
		SDL_Texture* hardTexture;
		//Image width
		int imageWidth;
		//Image height
		int imageHeight;
};

#endif
