#include "SDL.h"
#include "SDL_ttf.h"
#include "libft.h"
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 2048;
const int SCREEN_HEIGHT = 1024;

void move_UP(SDL_Renderer* render, SDL_Texture *texture, SDL_Rect *destrect)
{
	int offset = 5;
	destrect->y -= offset;
	// SDL_RenderClear(render);
	// SDL_RenderCopy(render, texture,NULL, destrect);
}
void move_DOWN(SDL_Renderer* render, SDL_Texture *texture, SDL_Rect *destrect)
{
	int offset = 5;
	destrect->y += offset;
	// SDL_RenderClear(render);
	// SDL_RenderCopy(render, texture,NULL, destrect);
}
void move_LEFT(SDL_Renderer* render, SDL_Texture *texture, SDL_Rect *destrect)
{
	int offset = 5;
	destrect->x -= offset;
	// SDL_RenderClear(render);
	// SDL_RenderCopy(render, texture,NULL, destrect);
}
void move_RIGHT(SDL_Renderer* render, SDL_Texture *texture, SDL_Rect *destrect)
{
	int offset = 5;
	if((destrect->x + offset) < (SCREEN_WIDTH - destrect->w))
		destrect->x += offset;
	// SDL_RenderClear(render);
	// SDL_RenderCopy(render, texture,NULL, destrect);
}

void move_bmp(int y, int x, SDL_Rect *dest)
{
	int current_x;
	int current_y;

	SDL_GetMouseState(&current_x, &current_y);
	dest->x = current_x - x;
	dest->y = current_y - y;
}

void increment_dicrement_count(SDL_Texture **tex_count, TTF_Font *font, int *count, SDL_Renderer *ren, SDL_Keycode key, SDL_Rect *text_Rect)
{
	SDL_Color	color = {255, 0, 255};
	SDL_Surface *text_surface;
	int			w;
	int			h;

	if (key == SDLK_KP_PLUS)
		++*count;
	else
		--*count;
	// printf("%d\n", *count);
	TTF_SizeText(font,ft_itoa(*count),&w,&h);
	text_Rect->w = w;
	text_Rect->h = h;
	text_surface = TTF_RenderText_Blended(font, ft_itoa(*count), color);
	*tex_count = SDL_CreateTextureFromSurface(ren, text_surface);
	SDL_FreeSurface(text_surface);
}

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window *win = NULL;
	SDL_Renderer *ren;
	SDL_Surface *bmp;
	SDL_Texture *tex;
	SDL_Texture *tex_count;
	int			count = 0;
	SDL_Color	color = {0, 0, 0};
	SDL_Color	color_bg = {255, 255, 0};
	SDL_Surface *text_surface;
	TTF_Font	*font;
	SDL_Rect	text_Rect;
	SDL_Rect 	bmp_RECT;
	SDL_Event 	e;
	int			quit = 0;
	int			state = 0;
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
	int 		x;
	int 		y;

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
			TTF_Init();
			bmp_RECT.x = (SCREEN_WIDTH - 333) / 2;   //Смещение полотна по Х
			bmp_RECT.y = (SCREEN_HEIGHT - 227) / 2;   //Смещение полотна по Y
			bmp_RECT.w = 333; //Ширина полотна
			bmp_RECT.h = 227; //Высота полотна
			text_Rect.x = SCREEN_WIDTH / 2;   //Смещение полотна по Х
			text_Rect.y = SCREEN_HEIGHT / 2;   //Смещение полотна по Y
			// text_Rect.w = 200; //Ширина полотна
			// text_Rect.h = 150; //Высота полотна
			ren = SDL_CreateRenderer(win, -1, 0);
			bmp = SDL_LoadBMP("hello.bmp");
			tex = SDL_CreateTextureFromSurface(ren, bmp);
			SDL_FreeSurface(bmp);
			SDL_SetRenderDrawColor(ren, 0, 255, 255, SDL_ALPHA_OPAQUE);

			font = TTF_OpenFont("FuturaPT-Light.ttf", 40);
			// text_surface = TTF_RenderText_Blended(font,ft_itoa(count),color);
			// tex_count = SDL_CreateTextureFromSurface(ren, text_surface);
			// SDL_FreeSurface(text_surface);
			while(!quit)
			{
				if(SDL_PollEvent(&e))
				{
					if (keyState[SDL_SCANCODE_ESCAPE] || e.type == SDL_QUIT)
						quit = 1;
					if(e.type == SDL_MOUSEBUTTONDOWN)
					{
						if((e.button.button == SDL_BUTTON_LEFT) && (e.button.x >= bmp_RECT.x) &&
							(e.button.y >= bmp_RECT.y) &&
							(e.button.x <= bmp_RECT.w + bmp_RECT.x) &&
							(e.button.y <= bmp_RECT.h + bmp_RECT.y))
							{
								x = e.button.x - bmp_RECT.x;
								y = e.button.y - bmp_RECT.y;
								state = 1;
							}
					}
					if (e.type == SDL_MOUSEBUTTONUP)
						state = 0;
					if (state)
						move_bmp(y, x, &bmp_RECT);
					if(keyState[SDL_SCANCODE_UP])
						move_UP(ren, tex, &bmp_RECT);
					if(keyState[SDL_SCANCODE_DOWN])
						move_DOWN(ren, tex, &bmp_RECT);
					if(keyState[SDL_SCANCODE_LEFT])
						move_LEFT(ren, tex, &bmp_RECT);
					if(keyState[SDL_SCANCODE_RIGHT])
						move_RIGHT(ren, tex, &bmp_RECT);
					if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_KP_MINUS || e.key.keysym.sym == SDLK_KP_PLUS))
					{
						// text_surface = TTF_RenderText_Solid(font,ft_itoa(count++),color);
						// tex_count = SDL_CreateTextureFromSurface(ren, text_surface);
						// SDL_FreeSurface(text_surface);
						increment_dicrement_count(&tex_count, font, &count, ren, e.key.keysym.sym, &text_Rect);
					}
					SDL_RenderClear(ren);
					SDL_RenderCopy(ren, tex, NULL, &bmp_RECT);
					SDL_RenderCopy(ren, tex_count, NULL, &text_Rect);
					SDL_RenderPresent(ren);
				}
				// SDL_Delay(4000);
			}
		}
	}
	//Destroy block
	TTF_CloseFont(font);
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(tex_count);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	//Quit SDL subsystems
	SDL_Quit();
	TTF_Quit();
  	return 0;
}