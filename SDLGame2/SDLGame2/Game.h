#pragma once
#include <SDL.h>
#include "consts.h"
#include "BasicIncludes.h"
#include "GameTime.h"


class GameModeBase;

//make this a singleton for the different gamemodes
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	SDL_Window* GetWindow() { return m_Window; }

	SDL_Renderer* GetRenderer() { return m_Renderer; }

	bool GetRunning() { return m_IsRunning; }

	void SetRunning(bool running) { m_IsRunning = running;  }

	static Game* GetInstance();

private:
	Game();
	~Game();

	static Game* s_Instance;

	bool m_IsRunning;

	float m_deltaTime;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	GameModeBase* MainMenu;

};
