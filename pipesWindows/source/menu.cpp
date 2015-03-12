#include "headers/menu.hpp"

extern SDL_Renderer* windowRenderer; //Window renderer from initialize.cpp
extern Texture titleTexture; //tileTexture from initialize.cpp

//Main menu buttons
Button playButton = Button(359, 400);
Button levelSelectButton = Button(359, 480 );
Button quitButton = Button(359, 560);

//Level select buttons
Button backButton = Button(359, 680);
Button level1Button = Button(16,380);
Button level2Button = Button(16,440);
Button level3Button = Button(16,500);
Button level4Button = Button(16,560);
Button level5Button = Button(16,620);
Button level6Button = Button(359,380);
Button level7Button = Button(359,440);
Button level8Button = Button(359,500);
Button level9Button = Button(359,560);
Button level10Button = Button(359,620);
Button level11Button = Button(702,380);
Button level12Button = Button(702,440);
Button level13Button = Button(702,500);
Button level14Button = Button(702,560);
Button level15Button = Button(702,620);

//SDL event to handle user input
SDL_Event menuEvent;

//returns 0 for play 1 for levelSelect 2 for quit
int mainMenu()
{
	while( true )
	{
		while( SDL_PollEvent( &menuEvent ) != 0 )
			{
                //If the user has quit the program
				if( menuEvent.type == SDL_QUIT )
				{
					return 2;
				}
                //If the user has selected a button
				if( menuEvent.type == SDL_MOUSEBUTTONDOWN )
				{
					if( playButton.selected() )
						return 0;
					if( levelSelectButton.selected() )
						return 1;
					if( quitButton.selected() )
						return 2;
				}
			}
        //Render the background as black
		SDL_SetRenderDrawColor( windowRenderer, 0, 0, 0, 0xFF );
		SDL_RenderClear( windowRenderer );
        //Render all buttons
		titleTexture.render(0,0,windowRenderer);
		playButton.render(windowRenderer,2);
		levelSelectButton.render(windowRenderer,4);
		quitButton.render(windowRenderer,6);	
        //Update screen
		SDL_RenderPresent( windowRenderer );
	}
}

//returns number of selected level -1 for back
int levelSelect()
{
	while( true )
	{
		while( SDL_PollEvent( &menuEvent ) != 0 )
			{
                //If the user has quit the program
				if( menuEvent.type == SDL_QUIT )
				{
					return 0;
				}
                //If the user has selected a button
				if( menuEvent.type == SDL_MOUSEBUTTONDOWN )
				{
					if( level1Button.selected() )
						return 1;
					if( level2Button.selected() )
						return 2;
					if( level3Button.selected() )
						return 3;
					if( level4Button.selected() )
						return 4;
					if( level5Button.selected() )
						return 5;
					if( level6Button.selected() )
						return 6;
					if( level7Button.selected() )
						return 7;
					if( level8Button.selected() )
						return 8;
					if( level9Button.selected() )
						return 9;
					if( level10Button.selected() )
						return 10;
					if( level11Button.selected() )
						return 11;
					if( level12Button.selected() )
						return 12;
					if( level13Button.selected() )
						return 13;
					if( level14Button.selected() )
						return 14;
					if( level15Button.selected() )
						return 15;
					if( backButton.selected() )
						return -1;
				}
			}
        //Render the background as black
		SDL_SetRenderDrawColor( windowRenderer, 0, 0, 0, 0xFF );
		SDL_RenderClear( windowRenderer );
        //Render title
		titleTexture.render(0,0,windowRenderer);
        //Render all buttons
		level1Button.render(windowRenderer,14);
		level2Button.render(windowRenderer,16);
		level3Button.render(windowRenderer,18);
		level4Button.render(windowRenderer,20);
		level5Button.render(windowRenderer,22);
		level6Button.render(windowRenderer,24);
		level7Button.render(windowRenderer,26);
		level8Button.render(windowRenderer,28);
		level9Button.render(windowRenderer,30);
		level10Button.render(windowRenderer,32);
		level11Button.render(windowRenderer,34);
		level12Button.render(windowRenderer,36);
		level13Button.render(windowRenderer,38);
		level14Button.render(windowRenderer,40);
		level15Button.render(windowRenderer,42);
		backButton.render(windowRenderer,12);	
        //Update screen
		SDL_RenderPresent( windowRenderer );
	}
}
