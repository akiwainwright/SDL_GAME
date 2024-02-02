#pragma once
#include <SDL.h>
#include "consts.h"
#include "BasicIncludes.h"
#include "GameTime.h"



class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void AddActor(class Actor* _actor);
	void RemoveActor(class Actor* _actor);
	class Actor* GetActor(class Actor* _actor);

	vector <Actor*>& GetAllActors();
	SDL_Window* GetWindow() { return m_Window; }

	SDL_Renderer* GetRenderer() { return m_Renderer; }

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	bool GetRunning() { return m_IsRunning; }

	void SetRunning(bool running) { m_IsRunning = running;  }

	SDL_Texture* GetTextures(const string& fileName);
private:
	std::vector<class SpriteComponent*> mSprites;


	 void ProcessInput();
	 void UpdateGame(float _deltaTime);
	 void RenderLoop(float _deltaTime);
	 void LoadData();
	 void UnloadData();

	bool m_IsRunning;

	float m_deltaTime;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	vector<class Actor*> m_Actors;
	vector<class Actor*> m_PendingActors;
	bool m_UpdatingActor;

	class VehicleAgent* m_TestObject;
	class Ship* mShip;
		
	
	std::unordered_map<string, SDL_Texture*> m_Textures;
};
