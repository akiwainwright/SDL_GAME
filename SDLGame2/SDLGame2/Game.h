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
	void AddActor(class Actor* _actor);
	void RemoveActor(class Actor* _actor);
	class Actor* GetActor(class Actor* _actor);

	SDL_Window* GetWindow() { return m_Window; }

	SDL_Renderer* GetRenderer() { return m_Renderer; }

	bool GetRunning() { return m_IsRunning; }

	void SetRunning(bool running) { m_IsRunning = running;  }

	static Game* GetInstance();

private:
	Game();
	~Game();

	static Game* s_Instance;


	 void ProcessInput();
	 void UpdateGame(float _deltaTime);
	 void RenderLoop(float _deltaTime);

	bool m_IsRunning;

	float m_deltaTime;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	vector<class Actor*> m_Actors;
	vector<class Actor*> m_PendingActors;
	bool m_UpdatingActor;

	class GameObject* m_TestObject;

	//GameModeBase* MainMenu;

};
