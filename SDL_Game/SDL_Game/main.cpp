#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "consts.h"
#include "Custom_Maths.h"


int main(int argc, char* args[])
{

	//maths testing

	Vector2 postion = Vector2(5, 6);

	std::cout << "New Vector2 --> (" << postion.x << ", " << postion.y << ")" << std::endl;

	float andgleRadians = 0.5;
	float angleDegrees = 180;

	std::cout << "0.5 radians is " << radToDeg(andgleRadians) << " degrees" << std::endl;
	std::cout << "180 degrees is " << degToRad(angleDegrees) << " radians" << std::endl;

	Vector2 newPos = postion / 2;

	std::cout << "Moved to --> (" << newPos.x << ", " << newPos.y << ")" << std::endl;

	Vector2 lengthCheck = Vector2(6, 2);
	Vector2 direction = lengthCheck.Normalise();

	std::cout << "direction is: (" << direction.x << "," << direction.y << ") " << std::endl;

	//maths end


	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	SDL_Event e;

	bool running = true;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Failed to initilize SDL! SDL_error: " << SDL_GetError() << std::endl;

		return 1;
	}

	if (!(window = SDL_CreateWindow("SDL_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN)))
	{
		std::cout << "Failed to create window! SDL_error: " << SDL_GetError() << std::endl;

		return 1;
	}

	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

	SDL_UpdateWindowSurface(window);

	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();


	return 0;
}
