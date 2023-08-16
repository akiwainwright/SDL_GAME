#pragma once
#include <SDL.h>
#include "consts.h"
#include "GameTime.h"





//make this a singleton for the different gamemodes
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
	void UpdateGame(float _deltaTime);
	void GenerateOutput();

	bool m_IsRunning;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	GameTime m_Timer;
};

