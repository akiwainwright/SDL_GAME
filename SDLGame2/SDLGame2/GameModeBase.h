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


	void AddActor(Actor* _actor);
	void RemoveActor(Actor* _actor);

	GameState GetGameState()const { m_GameState; }
	

protected:
	GameObject* m_TestObject;

	GameModeBase* m_CurrentMode;

	vector <Walls2D*> m_Walls;
	vector <GameObject*> m_Obstacles;


	vector<Actor*> m_Actors;
	vector<Actor*> m_PendingActors;
	bool m_UpdatingActor;
	GameState m_GameState;
};

//Add this function
//while (!m_Actors.empty())
//{
//	delete m_Actors.back();
//}
