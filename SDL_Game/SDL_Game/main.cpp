#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "consts.h"
#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* args[])
{
	Game game;
;
	if (game.Initialize())
	{
		game.RunLoop();
	}

	game.Shutdown();


	return 0;
}
