#pragma once
#include <SDL.h>
#include "consts.h"


class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();


private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	bool m_IsRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

