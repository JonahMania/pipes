#include "headers/texture.hpp"

//Initializes variables
Texture::Texture()
{
	hardTexture = NULL;
	imageWidth = 0;
	imageHeight = 0;
}

//Deallocates memory
Texture::~Texture()
{
	close();
}

//Loads an image takes sting p as path to image and Render w
bool Texture::loadImage( std::string p, SDL_Renderer* w )
{
	close();
	
	//Create texture
	SDL_Texture* imageTexture = NULL;
	
	//Load the image at path p
	SDL_Surface* loadedSurface = IMG_Load( p.c_str() );
	//Check that loadedSurface is not empty
	if( loadedSurface == NULL )
	{
		std::cerr << "ERROR: Image was not loaded " << p.c_str() << IMG_GetError() << std::endl; 
	}	
	else
	{	
		//Set the texture to the image
		imageTexture = SDL_CreateTextureFromSurface( w, loadedSurface );
		//Check if imageTexture is empty
		if( imageTexture == NULL )
		{
			std::cerr << "ERROR: Image texture was not created " << p.c_str() << SDL_GetError() << std::endl;
		}
		else
		{
			//Set image dimensions
			imageWidth = loadedSurface->w;
			imageHeight = loadedSurface->h;
		}  
		
		//Get rid of loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	
	hardTexture = imageTexture;
	return hardTexture != NULL;
}

//Deallocates texture
void Texture::close()
{
    //If the hardware texture exists
	if( hardTexture != NULL )
	{
        //Destroy the hardware texture
		SDL_DestroyTexture( hardTexture );
		hardTexture = NULL;
		imageWidth = 0;
		imageHeight = 0;
	}

}

//Renders texture at a given point
void Texture::render( int x, int y, SDL_Renderer* w, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering clip of the sprite sheet
	SDL_Rect renderClip = { x, y, imageWidth, imageHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderClip.w = clip->w;
		renderClip.h = clip->h;
	}

	//Render to the clipped portion of the texture to the screen
	SDL_RenderCopyEx( w, hardTexture, clip, &renderClip, angle, center, flip );
}

//Get image width
int Texture::getWidth()
{
	return imageWidth;
}

//Get image height
int Texture::getHeight()
{
	return imageHeight;
}


