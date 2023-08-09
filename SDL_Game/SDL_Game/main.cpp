#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "consts.h"

int main(int argc, char* args[])
{
	
	//This is just a temporary window it will probably be changed
	//Just wanted something to start with

	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Failed to initilize SDL! SDL_error: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow("SDL_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);

		if (!window)
		{
			std::cout << "Failed to create window! SDL_error: " << SDL_GetError() << std::endl; 
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

			SDL_UpdateWindowSurface(window);

			SDL_Event e;

			bool quit = false;

			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}
		}

		SDL_DestroyWindow(window);

		SDL_Quit();
	}

	return 0;
}
