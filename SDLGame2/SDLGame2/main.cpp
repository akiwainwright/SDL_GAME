#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "consts.h"
#include <iostream>
#include "Game.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(int argc, char* args[])
{
	srand(time(NULL));
	float f = (float)(rand()) / (float)(rand());
	cout << f << endl;
	Game game;

	if (game.Initialize())
	{
		game.RunLoop();
	}

	game.Shutdown();


	return 0;
}
