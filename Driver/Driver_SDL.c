
#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "InputLibrary/InputLibrary.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* mRenderer = NULL;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	screenSurface = SDL_GetWindowSurface(window);

	b32 running = true;

	SDL_Event e;
	
	while (running)
	{
		keyboardStateClear();

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					process_key(KeySpace, true);
					break;

				default:
					break;
				}
			}
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					process_key(KeySpace, false);
					break;

				default:
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);
		SDL_Rect rect;
		rect.x = 10;
		rect.y = 10;
		rect.w = 50;
		rect.h = 50;
		if (is_key_pressed(KeySpace))
		{
			rect.x = 100;
		}
		if (is_key_down(KeySpace))
		{
			rect.y = 100;
		}
		if (is_key_released(KeySpace))
		{
			rect.x = 100;
			rect.y = 100;
		}
		SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(mRenderer, &rect);
		SDL_RenderPresent(mRenderer);

	}

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;
}