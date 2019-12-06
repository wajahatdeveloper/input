
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
		keyboard_state_clear();
		mouse_state_clear();

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
			else if ( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
			{
				b32 isDown = (e.type == SDL_MOUSEBUTTONDOWN)?1:0;

				// get mouse button left
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					process_mouse_button(MouseButton0, isDown);
				}
				// get mouse button middle
				if (e.button.button == SDL_BUTTON_MIDDLE)
				{
					process_mouse_button(MouseButton1, isDown);
				}
				// get mouse button right
				if (e.button.button == SDL_BUTTON_RIGHT)
				{
					process_mouse_button(MouseButton2, isDown);
				}
				
				
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				// get mouse wheel offset
				process_mouse_wheel(e.wheel.y);
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				// get mouse position
				int x, y;
				SDL_GetMouseState(&x, &y);
				process_mouse_position(x, y);
			}
		}

		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);
		SDL_Rect rect;
		rect.x = 10;
		rect.y = 10;
		rect.w = 50;
		rect.h = 50;
	/*	if (is_key_pressed(KeySpace))
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
		}*/
		if (is_button_pressed(MouseButton2))
		{
			rect.x = 100;
		}
		if (is_button_down(MouseButton2))
		{
			rect.y = 100;
		}
		if (is_button_released(MouseButton2))
		{
			rect.x = 100;
			rect.y = 100;
		}
		/*rect.x = get_mouse_position_x();
		rect.y = get_mouse_position_y();
		rect.h += get_mouse_wheel_offset();*/
		SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(mRenderer, &rect);
		SDL_RenderPresent(mRenderer);

	}

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;
}