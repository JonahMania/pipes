#include "headers/initialize.hpp"

const int screenWidth = 1024; //Width of the game window
const int screenHeight = 768; //Height of the game window

SDL_Window* window = NULL;
SDL_Renderer* windowRenderer = NULL;
SDL_Rect windowRect = { 0, 0, screenWidth, screenHeight };

//Declaration of all textures
Texture boardTexture;
Texture straightTexture;
Texture bendTexture;
Texture slowTexture;
Texture slowTextureExt;
Texture speedTexture;
Texture startTexture;
Texture questionTexture;
Texture buttonsTexture;
Texture titleTexture;
Texture finalTexture;
//Array of SDL rectangles to store information about cutting up sprite sheets
SDL_Rect boardClips[40];
SDL_Rect startClips[30];
SDL_Rect straightClips[36];
SDL_Rect bendClips[36];
SDL_Rect slowClips[66];
SDL_Rect speedClips[36];
SDL_Rect buttonsClips[46];
SDL_Rect finalClips[2];

//Initialize the window and screen
bool initialize()
{
    //Initialize SDL library
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cerr << "ERROR: SDL could not initialize " << SDL_GetError() << std::endl;
		return false;
	}
	else 	
	{
		//Create window
		window = SDL_CreateWindow( "Pipes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			std::cerr << "ERROR: Window was not created " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			//Create rendering context for window
    		windowRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_PRESENTVSYNC );
    		if( windowRenderer == NULL )
    		{
    			std::cerr << "ERROR: renderer cound not be created " << SDL_GetError() << std::endl;
    			return false;
    		}
			else
			{
				//Initilize PNG loading
				if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
				{
					std::cerr << "ERROR: PNG loading was not initilized " << IMG_GetError() << std::endl;
					return false;
				}
			}
		}
	}

	return true;	
}

//Loads all images for the game
bool loadImages()
{
	bool ret = true;	
	
	if( !straightTexture.loadImage( "images/pipeStraight.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load straight pipe image" << std::endl;
		ret = false;
	}
	else
	{
		straightClips[0].x = 0; // <--- transparent
		straightClips[0].y = 0;
		straightClips[0].w = 96;
		straightClips[0].h = 96;
	
		straightClips[1].x = 96; // <---still
		straightClips[1].y = 0;
		straightClips[1].w = 96;
		straightClips[1].h = 96;

		straightClips[1].x = 96;
		straightClips[2].x = 192; // <--- animation
		straightClips[2].y = 0;
		straightClips[2].w = 96;
		straightClips[2].h = 96;

		straightClips[3].x = 288;
		straightClips[3].y = 0;
		straightClips[3].w = 96;
		straightClips[3].h = 96;

		straightClips[4].x = 0;
		straightClips[4].y = 96;
		straightClips[4].w = 96;
		straightClips[4].h = 96;
	
		straightClips[5].x = 96;
		straightClips[5].y = 96;
		straightClips[5].w = 96;
		straightClips[5].h = 96;

		straightClips[6].x = 192;
		straightClips[6].y = 96;
		straightClips[6].w = 96;
		straightClips[6].h = 96;

		straightClips[7].x = 288;
		straightClips[7].y = 96;
		straightClips[7].w = 96;
		straightClips[7].h = 96; 
		
		straightClips[8].x = 0; 
		straightClips[8].y = 192;
		straightClips[8].w = 96;
		straightClips[8].h = 96;
		
		straightClips[9].x = 96;
		straightClips[9].y = 192;
		straightClips[9].w = 96;
		straightClips[9].h = 96;
		
		straightClips[10].x = 192;
		straightClips[10].y = 192;
		straightClips[10].w = 96;
		straightClips[10].h = 96;
		
		straightClips[11].x = 288;
		straightClips[11].y = 192;
		straightClips[11].w = 96;
		straightClips[11].h = 96;
		
		straightClips[12].x = 0;
		straightClips[12].y = 288;
		straightClips[12].w = 96;
		straightClips[12].h = 96;
		
		straightClips[13].x = 96;
		straightClips[13].y = 288;
		straightClips[13].w = 96;
		straightClips[13].h = 96;
		
		straightClips[14].x = 192;
		straightClips[14].y = 288;
		straightClips[14].w = 96;
		straightClips[14].h = 96;
		
		straightClips[15].x = 288;
		straightClips[15].y = 288;
		straightClips[15].w = 96;
		straightClips[15].h = 96;
		
		straightClips[16].x = 0; 
		straightClips[16].y = 384;
		straightClips[16].w = 96;
		straightClips[16].h = 96;
		
		straightClips[17].x = 96;
		straightClips[17].y = 384;
		straightClips[17].w = 96;
		straightClips[17].h = 96;
		
		straightClips[18].x = 192;
		straightClips[18].y = 384;
		straightClips[18].w = 96;
		straightClips[18].h = 96;
		
		straightClips[19].x = 288;
		straightClips[19].y = 384;
		straightClips[19].w = 96;
		straightClips[19].h = 96;
		
		straightClips[20].x = 0;
		straightClips[20].y = 480;
		straightClips[20].w = 96;
		straightClips[20].h = 96;
		
		straightClips[21].x = 96;
		straightClips[21].y = 480;
		straightClips[21].w = 96;
		straightClips[21].h = 96;
		
		straightClips[22].x = 192;
		straightClips[22].y = 480;
		straightClips[22].w = 96;
		straightClips[22].h = 96;
		
		straightClips[23].x = 288;
		straightClips[23].y = 480;
		straightClips[23].w = 96;
		straightClips[23].h = 96;
		
		straightClips[24].x = 0;
		straightClips[24].y = 576;
		straightClips[24].w = 96;
		straightClips[24].h = 96;
		
		straightClips[25].x = 96;
		straightClips[25].y = 576;
		straightClips[25].w = 96;
		straightClips[25].h = 96;
		
		straightClips[26].x = 192;
		straightClips[26].y = 576;
		straightClips[26].w = 96;
		straightClips[26].h = 96;
		
		straightClips[27].x = 288;
		straightClips[27].y = 576;
		straightClips[27].w = 96;
		straightClips[27].h = 96;
		
		straightClips[28].x = 0;
		straightClips[28].y = 672;
		straightClips[28].w = 96;
		straightClips[28].h = 96;
		
		straightClips[29].x = 96;
		straightClips[29].y = 672;
		straightClips[29].w = 96;
		straightClips[29].h = 96;
		
		straightClips[30].x = 192;
		straightClips[30].y = 672;
		straightClips[30].w = 96;
		straightClips[30].h = 96;
		
		straightClips[31].x = 288;
		straightClips[31].y = 672;
		straightClips[31].w = 96;
		straightClips[31].h = 96;
		
		straightClips[32].x = 0;
		straightClips[32].y = 768;
		straightClips[32].w = 96;
		straightClips[32].h = 96;
		
		straightClips[33].x = 96;
		straightClips[33].y = 768;
		straightClips[33].w = 96;
		straightClips[33].h = 96;
		
		straightClips[34].x = 192;
		straightClips[34].y = 768;
		straightClips[34].w = 96;
		straightClips[34].h = 96;
		
		straightClips[35].x = 288;
		straightClips[35].y = 768;
		straightClips[35].w = 96;
		straightClips[35].h = 96;
	}

	if( !bendTexture.loadImage( "images/pipeBend.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load bend pipe image" << std::endl;
		ret = false;
	}
	else
	{
		bendClips[0].x = 0; // <--- transparent
		bendClips[0].y = 0;
		bendClips[0].w = 96;
		bendClips[0].h = 96;
	
		bendClips[1].x = 96; // <---still
		bendClips[1].y = 0;
		bendClips[1].w = 96;
		bendClips[1].h = 96;

		bendClips[1].x = 96;
		bendClips[2].x = 192; // <--- animation
		bendClips[2].y = 0;
		bendClips[2].w = 96;
		bendClips[2].h = 96;

		bendClips[3].x = 288;
		bendClips[3].y = 0;
		bendClips[3].w = 96;
		bendClips[3].h = 96;

		bendClips[4].x = 0;
		bendClips[4].y = 96;
		bendClips[4].w = 96;
		bendClips[4].h = 96;
	
		bendClips[5].x = 96;
		bendClips[5].y = 96;
		bendClips[5].w = 96;
		bendClips[5].h = 96;

		bendClips[6].x = 192;
		bendClips[6].y = 96;
		bendClips[6].w = 96;
		bendClips[6].h = 96;

		bendClips[7].x = 288;
		bendClips[7].y = 96;
		bendClips[7].w = 96;
		bendClips[7].h = 96; 
		
		bendClips[8].x = 0; 
		bendClips[8].y = 192;
		bendClips[8].w = 96;
		bendClips[8].h = 96;
		
		bendClips[9].x = 96;
		bendClips[9].y = 192;
		bendClips[9].w = 96;
		bendClips[9].h = 96;
		
		bendClips[10].x = 192;
		bendClips[10].y = 192;
		bendClips[10].w = 96;
		bendClips[10].h = 96;
		
		bendClips[11].x = 288;
		bendClips[11].y = 192;
		bendClips[11].w = 96;
		bendClips[11].h = 96;
		
		bendClips[12].x = 0;
		bendClips[12].y = 288;
		bendClips[12].w = 96;
		bendClips[12].h = 96;
		
		bendClips[13].x = 96;
		bendClips[13].y = 288;
		bendClips[13].w = 96;
		bendClips[13].h = 96;
		
		bendClips[14].x = 192;
		bendClips[14].y = 288;
		bendClips[14].w = 96;
		bendClips[14].h = 96;
		
		bendClips[15].x = 288;
		bendClips[15].y = 288;
		bendClips[15].w = 96;
		bendClips[15].h = 96;
		
		bendClips[16].x = 0; 
		bendClips[16].y = 384;
		bendClips[16].w = 96;
		bendClips[16].h = 96;
		
		bendClips[17].x = 96;
		bendClips[17].y = 384;
		bendClips[17].w = 96;
		bendClips[17].h = 96;
		
		bendClips[18].x = 192;
		bendClips[18].y = 384;
		bendClips[18].w = 96;
		bendClips[18].h = 96;
		
		bendClips[19].x = 288;
		bendClips[19].y = 384;
		bendClips[19].w = 96;
		bendClips[19].h = 96;
		
		bendClips[20].x = 0;
		bendClips[20].y = 480;
		bendClips[20].w = 96;
		bendClips[20].h = 96;
		
		bendClips[21].x = 96;
		bendClips[21].y = 480;
		bendClips[21].w = 96;
		bendClips[21].h = 96;
		
		bendClips[22].x = 192;
		bendClips[22].y = 480;
		bendClips[22].w = 96;
		bendClips[22].h = 96;
		
		bendClips[23].x = 288;
		bendClips[23].y = 480;
		bendClips[23].w = 96;
		bendClips[23].h = 96;
		
		bendClips[24].x = 0;
		bendClips[24].y = 576;
		bendClips[24].w = 96;
		bendClips[24].h = 96;
		
		bendClips[25].x = 96;
		bendClips[25].y = 576;
		bendClips[25].w = 96;
		bendClips[25].h = 96;
		
		bendClips[26].x = 192;
		bendClips[26].y = 576;
		bendClips[26].w = 96;
		bendClips[26].h = 96;
		
		bendClips[27].x = 288;
		bendClips[27].y = 576;
		bendClips[27].w = 96;
		bendClips[27].h = 96;
		
		bendClips[28].x = 0;
		bendClips[28].y = 672;
		bendClips[28].w = 96;
		bendClips[28].h = 96;
		
		bendClips[29].x = 96;
		bendClips[29].y = 672;
		bendClips[29].w = 96;
		bendClips[29].h = 96;
		
		bendClips[30].x = 192;
		bendClips[30].y = 672;
		bendClips[30].w = 96;
		bendClips[30].h = 96;
		
		bendClips[31].x = 288;
		bendClips[31].y = 672;
		bendClips[31].w = 96;
		bendClips[31].h = 96;
		
		bendClips[32].x = 0;
		bendClips[32].y = 768;
		bendClips[32].w = 96;
		bendClips[32].h = 96;
		
		bendClips[33].x = 96;
		bendClips[33].y = 768;
		bendClips[33].w = 96;
		bendClips[33].h = 96;
		
		bendClips[34].x = 192;
		bendClips[34].y = 768;
		bendClips[34].w = 96;
		bendClips[34].h = 96;
		
		bendClips[35].x = 288;
		bendClips[35].y = 768;
		bendClips[35].w = 96;
		bendClips[35].h = 96;
		
	}
	
	if( !slowTexture.loadImage( "images/pipeSlow.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load slow pipe image" << std::endl;
		ret = false;
	}
	else
	{
		slowClips[0].x = 0; // <--- transparent
		slowClips[0].y = 0;
		slowClips[0].w = 96;
		slowClips[0].h = 96;
	
		slowClips[1].x = 96; // <---still
		slowClips[1].y = 0;
		slowClips[1].w = 96;
		slowClips[1].h = 96;

		slowClips[2].x = 192; // <--- animation
		slowClips[2].y = 0;
		slowClips[2].w = 96;
		slowClips[2].h = 96;

		slowClips[3].x = 288;
		slowClips[3].y = 0;
		slowClips[3].w = 96;
		slowClips[3].h = 96;

		slowClips[4].x = 0;
		slowClips[4].y = 96;
		slowClips[4].w = 96;
		slowClips[4].h = 96;
	
		slowClips[5].x = 96;
		slowClips[5].y = 96;
		slowClips[5].w = 96;
		slowClips[5].h = 96;

		slowClips[6].x = 192;
		slowClips[6].y = 96;
		slowClips[6].w = 96;
		slowClips[6].h = 96;

		slowClips[7].x = 288;
		slowClips[7].y = 96;
		slowClips[7].w = 96;
		slowClips[7].h = 96; 
		
		slowClips[8].x = 0; 
		slowClips[8].y = 192;
		slowClips[8].w = 96;
		slowClips[8].h = 96;
		
		slowClips[9].x = 96;
		slowClips[9].y = 192;
		slowClips[9].w = 96;
		slowClips[9].h = 96;
		
		slowClips[10].x = 192;
		slowClips[10].y = 192;
		slowClips[10].w = 96;
		slowClips[10].h = 96;
		
		slowClips[11].x = 288;
		slowClips[11].y = 192;
		slowClips[11].w = 96;
		slowClips[11].h = 96;
		
		slowClips[12].x = 0;
		slowClips[12].y = 288;
		slowClips[12].w = 96;
		slowClips[12].h = 96;
		
		slowClips[13].x = 96;
		slowClips[13].y = 288;
		slowClips[13].w = 96;
		slowClips[13].h = 96;
		
		slowClips[14].x = 192;
		slowClips[14].y = 288;
		slowClips[14].w = 96;
		slowClips[14].h = 96;
		
		slowClips[15].x = 288;
		slowClips[15].y = 288;
		slowClips[15].w = 96;
		slowClips[15].h = 96;
		
		slowClips[16].x = 0; 
		slowClips[16].y = 384;
		slowClips[16].w = 96;
		slowClips[16].h = 96;
		
		slowClips[17].x = 96;
		slowClips[17].y = 384;
		slowClips[17].w = 96;
		slowClips[17].h = 96;
		
		slowClips[18].x = 192;
		slowClips[18].y = 384;
		slowClips[18].w = 96;
		slowClips[18].h = 96;
		
		slowClips[19].x = 288;
		slowClips[19].y = 384;
		slowClips[19].w = 96;
		slowClips[19].h = 96;
		
		slowClips[20].x = 0;
		slowClips[20].y = 480;
		slowClips[20].w = 96;
		slowClips[20].h = 96;
		
		slowClips[21].x = 96;
		slowClips[21].y = 480;
		slowClips[21].w = 96;
		slowClips[21].h = 96;
		
		slowClips[22].x = 192;
		slowClips[22].y = 480;
		slowClips[22].w = 96;
		slowClips[22].h = 96;
		
		slowClips[23].x = 288;
		slowClips[23].y = 480;
		slowClips[23].w = 96;
		slowClips[23].h = 96;
		
		slowClips[24].x = 0;
		slowClips[24].y = 576;
		slowClips[24].w = 96;
		slowClips[24].h = 96;
		
		slowClips[25].x = 96;
		slowClips[25].y = 576;
		slowClips[25].w = 96;
		slowClips[25].h = 96;
		
		slowClips[26].x = 192;
		slowClips[26].y = 576;
		slowClips[26].w = 96;
		slowClips[26].h = 96;
		
		slowClips[27].x = 288;
		slowClips[27].y = 576;
		slowClips[27].w = 96;
		slowClips[27].h = 96;
		
		slowClips[28].x = 0;
		slowClips[28].y = 672;
		slowClips[28].w = 96;
		slowClips[28].h = 96;
		
		slowClips[29].x = 96;
		slowClips[29].y = 672;
		slowClips[29].w = 96;
		slowClips[29].h = 96;
		
		slowClips[30].x = 192;
		slowClips[30].y = 672;
		slowClips[30].w = 96;
		slowClips[30].h = 96;
		
		slowClips[31].x = 288;
		slowClips[31].y = 672;
		slowClips[31].w = 96;
		slowClips[31].h = 96;
		
		slowClips[32].x = 0;
		slowClips[32].y = 768;
		slowClips[32].w = 96;
		slowClips[32].h = 96;
		
		slowClips[33].x = 96;
		slowClips[33].y = 768;
		slowClips[33].w = 96;
		slowClips[33].h = 96;
		
		slowClips[34].x = 192;
		slowClips[34].y = 768;
		slowClips[34].w = 96;
		slowClips[34].h = 96;
		
		slowClips[35].x = 288;
		slowClips[35].y = 768;
		slowClips[35].w = 96;
		slowClips[35].h = 96;
	}
	
	if( !slowTextureExt.loadImage( "images/pipeSlowExt.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load slow pipe extend image" << std::endl;
		ret = false;
    }
    else
    {
		slowClips[36].x = 0; // <--- animation
		slowClips[36].y = 0;
		slowClips[36].w = 96;
		slowClips[36].h = 96;
	
		slowClips[37].x = 96;
		slowClips[37].y = 0;
		slowClips[37].w = 96;
		slowClips[37].h = 96;

		slowClips[38].x = 192;
		slowClips[38].y = 0;
		slowClips[38].w = 96;
		slowClips[38].h = 96;

		slowClips[39].x = 288;
		slowClips[39].y = 0;
		slowClips[39].w = 96;
		slowClips[39].h = 96;

		slowClips[40].x = 0;
		slowClips[40].y = 96;
		slowClips[40].w = 96;
		slowClips[40].h = 96;
	
		slowClips[41].x = 96;
		slowClips[41].y = 96;
		slowClips[41].w = 96;
		slowClips[41].h = 96;

		slowClips[42].x = 192;
		slowClips[42].y = 96;
		slowClips[42].w = 96;
		slowClips[42].h = 96;

		slowClips[43].x = 288;
		slowClips[43].y = 96;
		slowClips[43].w = 96;
		slowClips[43].h = 96; 
		
		slowClips[44].x = 0; 
		slowClips[44].y = 192;
		slowClips[44].w = 96;
		slowClips[44].h = 96;
		
		slowClips[45].x = 96;
		slowClips[45].y = 192;
		slowClips[45].w = 96;
		slowClips[45].h = 96;
		
		slowClips[46].x = 192;
		slowClips[46].y = 192;
		slowClips[46].w = 96;
		slowClips[46].h = 96;
	
		slowClips[47].x = 288;
		slowClips[47].y = 192;
		slowClips[47].w = 96;
		slowClips[47].h = 96;
		
		slowClips[48].x = 0;
		slowClips[48].y = 288;
		slowClips[48].w = 96;
		slowClips[48].h = 96;
		
		slowClips[49].x = 96;
		slowClips[49].y = 288;
		slowClips[49].w = 96;
		slowClips[49].h = 96;
		
		slowClips[50].x = 192;
		slowClips[50].y = 288;
		slowClips[50].w = 96;
		slowClips[50].h = 96;
		
		slowClips[51].x = 288;
		slowClips[51].y = 288;
		slowClips[51].w = 96;
		slowClips[51].h = 96;
		
		slowClips[52].x = 0; 
		slowClips[52].y = 384;
		slowClips[52].w = 96;
		slowClips[52].h = 96;
		
		slowClips[53].x = 96;
		slowClips[53].y = 384;
		slowClips[53].w = 96;
		slowClips[53].h = 96;
		
		slowClips[54].x = 192;
		slowClips[54].y = 384;
		slowClips[54].w = 96;
		slowClips[54].h = 96;
		
		slowClips[55].x = 288;
		slowClips[55].y = 384;
		slowClips[55].w = 96;
		slowClips[55].h = 96;
		
		slowClips[56].x = 0;
		slowClips[56].y = 480;
		slowClips[56].w = 96;
		slowClips[56].h = 96;
		
		slowClips[57].x = 96;
		slowClips[57].y = 480;
		slowClips[57].w = 96;
		slowClips[57].h = 96;
		
		slowClips[58].x = 192;
		slowClips[58].y = 480;
		slowClips[58].w = 96;
		slowClips[58].h = 96;
		
		slowClips[59].x = 288;
		slowClips[59].y = 480;
		slowClips[59].w = 96;
		slowClips[59].h = 96;
		
		slowClips[60].x = 0;
		slowClips[60].y = 576;
		slowClips[60].w = 96;
		slowClips[60].h = 96;
		
		slowClips[61].x = 96;
		slowClips[61].y = 576;
		slowClips[61].w = 96;
		slowClips[61].h = 96;
		
		slowClips[62].x = 192;
		slowClips[62].y = 576;
		slowClips[62].w = 96;
		slowClips[62].h = 96;
		
		slowClips[63].x = 288;
		slowClips[63].y = 576;
		slowClips[63].w = 96;
		slowClips[63].h = 96;
		
		slowClips[64].x = 0;
		slowClips[64].y = 672;
		slowClips[64].w = 96;
		slowClips[64].h = 96;
		
		slowClips[65].x = 96;
		slowClips[65].y = 672;
		slowClips[65].w = 96;
		slowClips[65].h = 96;
    }

	if( !speedTexture.loadImage( "images/pipeSpeed.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load speed pipe image" << std::endl;
		ret = false;
	}
	else
	{
		speedClips[0].x = 0; // <--- transparent
		speedClips[0].y = 0;
		speedClips[0].w = 96;
		speedClips[0].h = 96;
	
		speedClips[1].x = 96; // <---still
		speedClips[1].y = 0;
		speedClips[1].w = 96;
		speedClips[1].h = 96;

		speedClips[1].x = 96;
		speedClips[2].x = 192; // <--- animation
		speedClips[2].y = 0;
		speedClips[2].w = 96;
		speedClips[2].h = 96;

		speedClips[3].x = 288;
		speedClips[3].y = 0;
		speedClips[3].w = 96;
		speedClips[3].h = 96;

		speedClips[4].x = 0;
		speedClips[4].y = 96;
		speedClips[4].w = 96;
		speedClips[4].h = 96;
	
		speedClips[5].x = 96;
		speedClips[5].y = 96;
		speedClips[5].w = 96;
		speedClips[5].h = 96;

		speedClips[6].x = 192;
		speedClips[6].y = 96;
		speedClips[6].w = 96;
		speedClips[6].h = 96;

		speedClips[7].x = 288;
		speedClips[7].y = 96;
		speedClips[7].w = 96;
		speedClips[7].h = 96; 
		
		speedClips[8].x = 0; 
		speedClips[8].y = 192;
		speedClips[8].w = 96;
		speedClips[8].h = 96;
		
		speedClips[9].x = 96;
		speedClips[9].y = 192;
		speedClips[9].w = 96;
		speedClips[9].h = 96;
		
		speedClips[10].x = 192;
		speedClips[10].y = 192;
		speedClips[10].w = 96;
		speedClips[10].h = 96;
		
		speedClips[11].x = 288;
		speedClips[11].y = 192;
		speedClips[11].w = 96;
		speedClips[11].h = 96;
		
		speedClips[12].x = 0;
		speedClips[12].y = 288;
		speedClips[12].w = 96;
		speedClips[12].h = 96;
		
		speedClips[13].x = 96;
		speedClips[13].y = 288;
		speedClips[13].w = 96;
		speedClips[13].h = 96;
		
		speedClips[14].x = 192;
		speedClips[14].y = 288;
		speedClips[14].w = 96;
		speedClips[14].h = 96;
		
		speedClips[15].x = 288;
		speedClips[15].y = 288;
		speedClips[15].w = 96;
		speedClips[15].h = 96;
		
		speedClips[16].x = 0; 
		speedClips[16].y = 384;
		speedClips[16].w = 96;
		speedClips[16].h = 96;
		
		speedClips[17].x = 96;
		speedClips[17].y = 384;
		speedClips[17].w = 96;
		speedClips[17].h = 96;
		
		speedClips[18].x = 192;
		speedClips[18].y = 384;
		speedClips[18].w = 96;
		speedClips[18].h = 96;
		
		speedClips[19].x = 288;
		speedClips[19].y = 384;
		speedClips[19].w = 96;
		speedClips[19].h = 96;
		
		speedClips[20].x = 0;
		speedClips[20].y = 480;
		speedClips[20].w = 96;
		speedClips[20].h = 96;
		
		speedClips[21].x = 96;
		speedClips[21].y = 480;
		speedClips[21].w = 96;
		speedClips[21].h = 96;
		
		speedClips[22].x = 192;
		speedClips[22].y = 480;
		speedClips[22].w = 96;
		speedClips[22].h = 96;
		
		speedClips[23].x = 288;
		speedClips[23].y = 480;
		speedClips[23].w = 96;
		speedClips[23].h = 96;
		
		speedClips[24].x = 0;
		speedClips[24].y = 576;
		speedClips[24].w = 96;
		speedClips[24].h = 96;
		
		speedClips[25].x = 96;
		speedClips[25].y = 576;
		speedClips[25].w = 96;
		speedClips[25].h = 96;
		
		speedClips[26].x = 192;
		speedClips[26].y = 576;
		speedClips[26].w = 96;
		speedClips[26].h = 96;
		
		speedClips[27].x = 288;
		speedClips[27].y = 576;
		speedClips[27].w = 96;
		speedClips[27].h = 96;
		
		speedClips[28].x = 0;
		speedClips[28].y = 672;
		speedClips[28].w = 96;
		speedClips[28].h = 96;
		
		speedClips[29].x = 96;
		speedClips[29].y = 672;
		speedClips[29].w = 96;
		speedClips[29].h = 96;
		
		speedClips[30].x = 192;
		speedClips[30].y = 672;
		speedClips[30].w = 96;
		speedClips[30].h = 96;
		
		speedClips[31].x = 288;
		speedClips[31].y = 672;
		speedClips[31].w = 96;
		speedClips[31].h = 96;
		
		speedClips[32].x = 0;
		speedClips[32].y = 768;
		speedClips[32].w = 96;
		speedClips[32].h = 96;
		
		speedClips[33].x = 96;
		speedClips[33].y = 768;
		speedClips[33].w = 96;
		speedClips[33].h = 96;
		
		speedClips[34].x = 192;
		speedClips[34].y = 768;
		speedClips[34].w = 96;
		speedClips[34].h = 96;
		
		speedClips[35].x = 288;
		speedClips[35].y = 768;
		speedClips[35].w = 96;
		speedClips[35].h = 96;
	}

	if( !startTexture.loadImage( "images/pipeStart.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load start pipe image" << std::endl;
	}
    else
    {
		startClips[0].x = 0;
		startClips[0].y = 0;
		startClips[0].w = 96;
		startClips[0].h = 96;
	
		startClips[1].x = 96; 
		startClips[1].y = 0;
		startClips[1].w = 96;
		startClips[1].h = 96;

		startClips[1].x = 96;
		startClips[2].x = 192; 
		startClips[2].y = 0;
		startClips[2].w = 96;
		startClips[2].h = 96;

		startClips[3].x = 288;
		startClips[3].y = 0;
		startClips[3].w = 96;
		startClips[3].h = 96;

		startClips[4].x = 0;
		startClips[4].y = 96;
		startClips[4].w = 96;
		startClips[4].h = 96;
	
		startClips[5].x = 96;
		startClips[5].y = 96;
		startClips[5].w = 96;
		startClips[5].h = 96;

		startClips[6].x = 192;
		startClips[6].y = 96;
		startClips[6].w = 96;
		startClips[6].h = 96;

		startClips[7].x = 288;
		startClips[7].y = 96;
		startClips[7].w = 96;
		startClips[7].h = 96; 
		
		startClips[8].x = 0; 
		startClips[8].y = 192;
		startClips[8].w = 96;
		startClips[8].h = 96;
		
		startClips[9].x = 96;
		startClips[9].y = 192;
		startClips[9].w = 96;
		startClips[9].h = 96;
		
		startClips[10].x = 192;
		startClips[10].y = 192;
		startClips[10].w = 96;
		startClips[10].h = 96;
		
		startClips[11].x = 288;
		startClips[11].y = 192;
		startClips[11].w = 96;
		startClips[11].h = 96;
		
		startClips[12].x = 0;
		startClips[12].y = 288;
		startClips[12].w = 96;
		startClips[12].h = 96;
		
		startClips[13].x = 96;
		startClips[13].y = 288;
		startClips[13].w = 96;
		startClips[13].h = 96;
		
		startClips[14].x = 192;
		startClips[14].y = 288;
		startClips[14].w = 96;
		startClips[14].h = 96;
		
		startClips[15].x = 288;
		startClips[15].y = 288;
		startClips[15].w = 96;
		startClips[15].h = 96;
		
		startClips[16].x = 0; 
		startClips[16].y = 384;
		startClips[16].w = 96;
		startClips[16].h = 96;
		
		startClips[17].x = 96;
		startClips[17].y = 384;
		startClips[17].w = 96;
		startClips[17].h = 96;
		
		startClips[18].x = 192;
		startClips[18].y = 384;
		startClips[18].w = 96;
		startClips[18].h = 96;
		
		startClips[19].x = 288;
		startClips[19].y = 384;
		startClips[19].w = 96;
		startClips[19].h = 96;
		
		startClips[20].x = 0;
		startClips[20].y = 480;
		startClips[20].w = 96;
		startClips[20].h = 96;
		
		startClips[21].x = 96;
		startClips[21].y = 480;
		startClips[21].w = 96;
		startClips[21].h = 96;
		
		startClips[22].x = 192;
		startClips[22].y = 480;
		startClips[22].w = 96;
		startClips[22].h = 96;
		
		startClips[23].x = 288;
		startClips[23].y = 480;
		startClips[23].w = 96;
		startClips[23].h = 96;
		
		startClips[24].x = 0;
		startClips[24].y = 576;
		startClips[24].w = 96;
		startClips[24].h = 96;
		
		startClips[25].x = 96;
		startClips[25].y = 576;
		startClips[25].w = 96;
		startClips[25].h = 96;
		
		startClips[26].x = 192;
		startClips[26].y = 576;
		startClips[26].w = 96;
		startClips[26].h = 96;
		
		startClips[27].x = 288;
		startClips[27].y = 576;
		startClips[27].w = 96;
		startClips[27].h = 96;
		
		startClips[28].x = 0;
		startClips[28].y = 672;
		startClips[28].w = 96;
		startClips[28].h = 96;
		
		startClips[29].x = 96;
		startClips[29].y = 672;
		startClips[29].w = 96;
		startClips[29].h = 96;
    }
	
	if( !questionTexture.loadImage( "images/question.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load question pipe image" << std::endl;
	} 
	
	
	if( !buttonsTexture.loadImage( "images/buttons.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load buttons image" << std::endl;
	} 
	else
	{
		buttonsClips[0].x = 0; // <--- Increase flow speed
		buttonsClips[0].y = 0;
		buttonsClips[0].w = 306;
		buttonsClips[0].h = 40;
	
		buttonsClips[1].x = 0; // <--- Increase flow speed hover
		buttonsClips[1].y = 40;
		buttonsClips[1].w = 306;
		buttonsClips[1].h = 40;
		
		buttonsClips[2].x = 0; // <--- Play
		buttonsClips[2].y = 80;
		buttonsClips[2].w = 306;
		buttonsClips[2].h = 40;

		buttonsClips[3].x = 0; // <--- Play hover
		buttonsClips[3].y = 120;
		buttonsClips[3].w = 306;
		buttonsClips[3].h = 40;

		buttonsClips[4].x = 0; // <--- LevelSelect
		buttonsClips[4].y = 160;
		buttonsClips[4].w = 306;
		buttonsClips[4].h = 40;

		buttonsClips[5].x = 0; // <--- LevelSelect hover
		buttonsClips[5].y = 200;
		buttonsClips[5].w = 306;
		buttonsClips[5].h = 40;

		buttonsClips[6].x = 0; // <--- Quit
		buttonsClips[6].y = 240;
		buttonsClips[6].w = 306;
		buttonsClips[6].h = 40;
	
		buttonsClips[7].x = 0; // <--- Quit hover
		buttonsClips[7].y = 280;
		buttonsClips[7].w = 306;
		buttonsClips[7].h = 40;

		buttonsClips[8].x = 0; // <--- Restart
		buttonsClips[8].y = 320;
		buttonsClips[8].w = 306;
		buttonsClips[8].h = 40;
	
		buttonsClips[9].x = 0; // <--- Restart hover
		buttonsClips[9].y = 360;
		buttonsClips[9].w = 306;
		buttonsClips[9].h = 40;

		buttonsClips[10].x = 0; // <--- Continue
		buttonsClips[10].y = 400;
		buttonsClips[10].w = 306;
		buttonsClips[10].h = 40;

		buttonsClips[11].x = 0; // <--- Continue hover
		buttonsClips[11].y = 440;
		buttonsClips[11].w = 306;
		buttonsClips[11].h = 40;

		buttonsClips[12].x = 0; // <--- Back
		buttonsClips[12].y = 480;
		buttonsClips[12].w = 306;
		buttonsClips[12].h = 40;

		buttonsClips[13].x = 0; // <--- Back hover
		buttonsClips[13].y = 520;
		buttonsClips[13].w = 306;
		buttonsClips[13].h = 40;

		buttonsClips[14].x = 0; // <--- Level 1
		buttonsClips[14].y = 560;
		buttonsClips[14].w = 306;
		buttonsClips[14].h = 40;

		buttonsClips[15].x = 0; // <--- Level 1 hover
		buttonsClips[15].y = 600;
		buttonsClips[15].w = 306;
		buttonsClips[15].h = 40;

		buttonsClips[16].x = 0; // <--- Level 2
		buttonsClips[16].y = 640;
		buttonsClips[16].w = 306;
		buttonsClips[16].h = 40;

		buttonsClips[17].x = 0; // <--- Level 2 hover
		buttonsClips[17].y = 680;
		buttonsClips[17].w = 306;
		buttonsClips[17].h = 40;

		buttonsClips[18].x = 0; // <--- Level 3
		buttonsClips[18].y = 720;
		buttonsClips[18].w = 306;
		buttonsClips[18].h = 40;

		buttonsClips[19].x = 0; // <--- Level 3 hover
		buttonsClips[19].y = 760;
		buttonsClips[19].w = 306;
		buttonsClips[19].h = 40;

		buttonsClips[20].x = 0; // <--- Level 4
		buttonsClips[20].y = 800;
		buttonsClips[20].w = 306;
		buttonsClips[20].h = 40;

		buttonsClips[21].x = 0; // <--- Level 4 hover
		buttonsClips[21].y = 840;
		buttonsClips[21].w = 306;
		buttonsClips[21].h = 40;

		buttonsClips[22].x = 0; // <--- Level 5
		buttonsClips[22].y = 880;
		buttonsClips[22].w = 306;
		buttonsClips[22].h = 40;

		buttonsClips[23].x = 306; // <--- Level 5 hover
		buttonsClips[23].y = 0;
		buttonsClips[23].w = 306;
		buttonsClips[23].h = 40;

		buttonsClips[24].x = 306; // <--- Level 6
		buttonsClips[24].y = 40;
		buttonsClips[24].w = 306;
		buttonsClips[24].h = 40;

		buttonsClips[25].x = 306; // <--- Level 6 hover
		buttonsClips[25].y = 80;
		buttonsClips[25].w = 306;
		buttonsClips[25].h = 40;

		buttonsClips[26].x = 306; // <--- Level 7
		buttonsClips[26].y = 120;
		buttonsClips[26].w = 306;
		buttonsClips[26].h = 40;

		buttonsClips[27].x = 306; // <--- Level 7 hover
		buttonsClips[27].y = 160;
		buttonsClips[27].w = 306;
		buttonsClips[27].h = 40;

		buttonsClips[28].x = 306; // <--- Level 8
		buttonsClips[28].y = 200;
		buttonsClips[28].w = 306;
		buttonsClips[28].h = 40;

		buttonsClips[29].x = 306; // <--- Level 8 hover
		buttonsClips[29].y = 240;
		buttonsClips[29].w = 306;
		buttonsClips[29].h = 40;

		buttonsClips[30].x = 306; // <--- Level 9
		buttonsClips[30].y = 280;
		buttonsClips[30].w = 306;
		buttonsClips[30].h = 40;

		buttonsClips[31].x = 306; // <--- Level 9 hover
		buttonsClips[31].y = 320;
		buttonsClips[31].w = 306;
		buttonsClips[31].h = 40;

		buttonsClips[32].x = 306; // <--- Level 10
		buttonsClips[32].y = 360;
		buttonsClips[32].w = 306;
		buttonsClips[32].h = 40;

		buttonsClips[33].x = 306; // <--- Level 10 hover
		buttonsClips[33].y = 400;
		buttonsClips[33].w = 306;
		buttonsClips[33].h = 40;

		buttonsClips[34].x = 306; // <--- Level 11
		buttonsClips[34].y = 440;
		buttonsClips[34].w = 306;
		buttonsClips[34].h = 40;

		buttonsClips[35].x = 306; // <--- Level 11 hover
		buttonsClips[35].y = 480;
		buttonsClips[35].w = 306;
		buttonsClips[35].h = 40;

		buttonsClips[36].x = 306; // <--- Level 12
		buttonsClips[36].y = 520;
		buttonsClips[36].w = 306;
		buttonsClips[36].h = 40;

		buttonsClips[37].x = 306; // <--- Level 12 hover
		buttonsClips[37].y = 560;
		buttonsClips[37].w = 306;
		buttonsClips[37].h = 40;

		buttonsClips[38].x = 306; // <--- Level 13
		buttonsClips[38].y = 600;
		buttonsClips[38].w = 306;
		buttonsClips[38].h = 40;

		buttonsClips[39].x = 306; // <--- Level 13 hover
		buttonsClips[39].y = 640;
		buttonsClips[39].w = 306;
		buttonsClips[39].h = 40;

		buttonsClips[40].x = 306; // <--- Level 14
		buttonsClips[40].y = 680;
		buttonsClips[40].w = 306;
		buttonsClips[40].h = 40;

		buttonsClips[41].x = 306; // <--- Level 14 hover
		buttonsClips[41].y = 720;
		buttonsClips[41].w = 306;
		buttonsClips[41].h = 40;

		buttonsClips[42].x = 306; // <--- Level 15
		buttonsClips[42].y = 760;
		buttonsClips[42].w = 306;
		buttonsClips[42].h = 40;

		buttonsClips[43].x = 306; // <--- Level 15 hover
		buttonsClips[43].y = 800;
		buttonsClips[43].w = 306;
		buttonsClips[43].h = 40;
	}
	
	
	if( !boardTexture.loadImage( "images/board.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load board image" << std::endl;
		ret = false;
	}
	else
	{
		boardClips[0].x = 0; // <--- straight pipe animation
		boardClips[0].y = 0;
		boardClips[0].w = 96;
		boardClips[0].h = 96;
	
		boardClips[1].x = 96;
		boardClips[1].y = 0;
		boardClips[1].w = 96;
		boardClips[1].h = 96;

		boardClips[2].x = 192;
		boardClips[2].y = 0;
		boardClips[2].w = 96;
		boardClips[2].h = 96;

		boardClips[3].x = 288;
		boardClips[3].y = 0;
		boardClips[3].w = 96;
		boardClips[3].h = 96;

		boardClips[4].x = 0;
		boardClips[4].y = 96;
		boardClips[4].w = 96;
		boardClips[4].h = 96;
	
		boardClips[5].x = 96;
		boardClips[5].y = 96;
		boardClips[5].w = 96;
		boardClips[5].h = 96;

		boardClips[6].x = 192;
		boardClips[6].y = 96;
		boardClips[6].w = 96;
		boardClips[6].h = 96;

		boardClips[7].x = 288;
		boardClips[7].y = 96;
		boardClips[7].w = 96;
		boardClips[7].h = 96; 
		
		boardClips[8].x = 0; // <--- bend pipe animation
		boardClips[8].y = 192;
		boardClips[8].w = 96;
		boardClips[8].h = 96;
		
		boardClips[9].x = 96;
		boardClips[9].y = 192;
		boardClips[9].w = 96;
		boardClips[9].h = 96;
		
		boardClips[10].x = 192;
		boardClips[10].y = 192;
		boardClips[10].w = 96;
		boardClips[10].h = 96;
		
		boardClips[11].x = 288;
		boardClips[11].y = 192;
		boardClips[11].w = 96;
		boardClips[11].h = 96;
		
		boardClips[12].x = 0;
		boardClips[12].y = 288;
		boardClips[12].w = 96;
		boardClips[12].h = 96;
		
		boardClips[13].x = 96;
		boardClips[13].y = 288;
		boardClips[13].w = 96;
		boardClips[13].h = 96;
		
		boardClips[14].x = 192;
		boardClips[14].y = 288;
		boardClips[14].w = 96;
		boardClips[14].h = 96;
		
		boardClips[15].x = 288;
		boardClips[15].y = 288;
		boardClips[15].w = 96;
		boardClips[15].h = 96;
		
		boardClips[16].x = 0; // <--- slow pipe animation
		boardClips[16].y = 384;
		boardClips[16].w = 96;
		boardClips[16].h = 96;
		
		boardClips[17].x = 96;
		boardClips[17].y = 384;
		boardClips[17].w = 96;
		boardClips[17].h = 96;
		
		boardClips[18].x = 192;
		boardClips[18].y = 384;
		boardClips[18].w = 96;
		boardClips[18].h = 96;
		
		boardClips[19].x = 288;
		boardClips[19].y = 384;
		boardClips[19].w = 96;
		boardClips[19].h = 96;
		
		boardClips[20].x = 0;
		boardClips[20].y = 480;
		boardClips[20].w = 96;
		boardClips[20].h = 96;
		
		boardClips[21].x = 96;
		boardClips[21].y = 480;
		boardClips[21].w = 96;
		boardClips[21].h = 96;
		
		boardClips[22].x = 192;
		boardClips[22].y = 480;
		boardClips[22].w = 96;
		boardClips[22].h = 96;
		
		boardClips[23].x = 288;
		boardClips[23].y = 480;
		boardClips[23].w = 96;
		boardClips[23].h = 96;
		
		boardClips[24].x = 0; // <--- speed pipe animation
		boardClips[24].y = 576;
		boardClips[24].w = 96;
		boardClips[24].h = 96;
		
		boardClips[25].x = 96;
		boardClips[25].y = 576;
		boardClips[25].w = 96;
		boardClips[25].h = 96;
		
		boardClips[26].x = 192;
		boardClips[26].y = 576;
		boardClips[26].w = 96;
		boardClips[26].h = 96;
		
		boardClips[27].x = 288;
		boardClips[27].y = 576;
		boardClips[27].w = 96;
		boardClips[27].h = 96;
		
		boardClips[28].x = 0;
		boardClips[28].y = 672;
		boardClips[28].w = 96;
		boardClips[28].h = 96;
		
		boardClips[29].x = 96;
		boardClips[29].y = 672;
		boardClips[29].w = 96;
		boardClips[29].h = 96;
		
		boardClips[30].x = 192;
		boardClips[30].y = 672;
		boardClips[30].w = 96;
		boardClips[30].h = 96;
		
		boardClips[31].x = 288;
		boardClips[31].y = 672;
		boardClips[31].w = 96;
		boardClips[31].h = 96;
		
		boardClips[32].x = 0; // <--- alarm
		boardClips[32].y = 768;
		boardClips[32].w = 96;
		boardClips[32].h = 96;
		
		boardClips[33].x = 96; // <--- end pipe animation
		boardClips[33].y = 768;
		boardClips[33].w = 96;
		boardClips[33].h = 96;
		
		boardClips[34].x = 192;
		boardClips[34].y = 768;
		boardClips[34].w = 96;
		boardClips[34].h = 96;
		
		boardClips[35].x = 288;
		boardClips[35].y = 768;
		boardClips[35].w = 96;
		boardClips[35].h = 96;
		
		boardClips[36].x = 0;
		boardClips[36].y = 864;
		boardClips[36].w = 96;
		boardClips[36].h = 96;
		
		boardClips[37].x = 96;
		boardClips[37].y = 864;
		boardClips[37].w = 96;
		boardClips[37].h = 96;
		
		boardClips[38].x = 192;
		boardClips[38].y = 864;
		boardClips[38].w = 96;
		boardClips[38].h = 96;
		
		boardClips[39].x = 288; // <--- empty cell 
		boardClips[39].y = 864;
		boardClips[39].w = 96;
		boardClips[39].h = 96;
		
	}

	if( !titleTexture.loadImage( "images/title.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load title image" << std::endl;
		ret = false;
	}

	if( !finalTexture.loadImage( "images/final.png", windowRenderer ) )
	{
		std::cerr << "ERROR: Could not load final image" << std::endl;
		ret = false;
	}
	else
	{
		finalClips[0].x = 0; // <--- Successes
		finalClips[0].y = 0;
		finalClips[0].w = 517;
		finalClips[0].h = 96;
	
		finalClips[1].x = 0; // <--- fail
		finalClips[1].y = 96;
		finalClips[1].w = 517;
		finalClips[1].h = 96;
	}


	return ret;
}

//Free memory for all loaded textures and close SDL
void close()
{
	boardTexture.close();
	straightTexture.close();
	bendTexture.close();
	slowTexture.close();
	slowTextureExt.close();
	speedTexture.close();
	startTexture.close();
	questionTexture.close();
	buttonsTexture.close();
    titleTexture.close();
	finalTexture.close();

	SDL_DestroyRenderer( windowRenderer );
	SDL_DestroyWindow( window );
	windowRenderer = NULL;
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}
