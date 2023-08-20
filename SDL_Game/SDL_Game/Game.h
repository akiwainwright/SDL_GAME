#pragma once
#include <SDL.h>
#include "consts.h"
#include "BasicIncludes.h"


//make this a singleton for the different gamemodes
class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	class Actor* GetActor(class Actor*);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	bool m_IsRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	vector<class Actor*> m_Actors;

};

