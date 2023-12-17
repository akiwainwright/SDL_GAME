#pragma once
#include <vector>
#include "BasicIncludes.h"
#include "CustomMaths.h"

class GameObject;
class Actor;
class VehicleAgent;

enum GameState {
	PREGAME,
	INGAME,
	PAUSEDGAME,
	POSTGAME
};

class GameModeBase
{
public:
	GameModeBase();

	Actor* GetActor(Actor* _actor);

	virtual void ProcessInput();
	virtual void UpdateGame(float _deltaTime);
	virtual void RenderLoop(float _deltaTime);

	void SetUpGameObjects();

	const vector<Walls2D*>& GetWalls();
	const vector <GameObject*>& GetObstacles();
	const vector <VehicleAgent*>& GetAllVehicleAgent();

	GameState GetGameState()const { m_GameState; }
	

protected:
	std::vector<class Actor*> m_Actors;

	GameObject* m_TestObject;

	GameModeBase* m_CurrentMode;

	vector <Walls2D*> m_Walls;
	vector <GameObject*> m_Obstacles;

	GameState m_GameState;
};

