#include "SDL.h"
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 2048;
const int SCREEN_HEIGHT = 1024;

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window *win = NULL;
	SDL_Renderer *ren;
	SDL_Surface *bmp;
	SDL_Texture *tex;
	SDL_Texture *tex2;
	SDL_Rect 	bmp_RECT;
	SDL_Event 	e;
	int			quit = 0;
	int			state = 1;

	// //The surface contained by the window
	// SDL_Surface *screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0 )
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	else
	{
		//Create window
		win = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(!win)
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		else
		{
			bmp_RECT.x = SCREEN_WIDTH / 2;   //Смещение полотна по Х
			bmp_RECT.y = SCREEN_HEIGHT / 2;   //Смещение полотна по Y
			bmp_RECT.w = 333; //Ширина полотна
			bmp_RECT.h = 227; //Высота полотна
			ren = SDL_CreateRenderer(win, -1, 0);
			bmp = SDL_LoadBMP("hello.bmp");
			tex = SDL_CreateTextureFromSurface(ren, bmp);
			SDL_FreeSurface(bmp);
			SDL_SetRenderDrawColor(ren, 0, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(ren);
			// IMG_LoadTexture(ren, "hello.bmp");

			while(!quit)
			{
				if (state)
					SDL_RenderCopy(ren, tex, NULL, &bmp_RECT);
				else if (!state)
				{
					SDL_SetRenderDrawColor(ren, 0, 255, 255, SDL_ALPHA_OPAQUE);
					SDL_RenderClear(ren);
				}
				while (SDL_PollEvent(&e))
				{
					// if (e.type == SDL_KEYDOWN)
					// {
						if (e.key.keysym.sym == SDLK_ESCAPE)
							quit = 1;
					// }
					if(e.type == SDL_MOUSEBUTTONDOWN)
					{
						if(e.button.button == SDL_BUTTON_RIGHT)
							state = 1;
						if((e.button.button == SDL_BUTTON_LEFT) && (e.button.x >= bmp_RECT.x) &&
							(e.button.y >= bmp_RECT.y) &&
							(e.button.x <= bmp_RECT.w + bmp_RECT.x) &&
							(e.button.y <= bmp_RECT.h + bmp_RECT.y))
							state = 0;
					}
				}
				// SDL_Delay(4000);
				}
				SDL_RenderPresent(ren);
			}
	}
	//Destroy block
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	//Quit SDL subsystems
	SDL_Quit();
  	return 0;
}