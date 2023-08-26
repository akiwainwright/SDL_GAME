#pragma once
#include <SDL.h>
#include "consts.h"

class GameObject;

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
	void RenderLoop(float _deltaTime);

	bool m_IsRunning;

	float m_deltaTime;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	GameObject* m_TestObject;
};

