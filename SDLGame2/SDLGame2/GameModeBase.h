#pragma once
#include <vector>

class GameObject;
class Actor;

class GameModeBase
{
public:
	GameModeBase();

	Actor* GetActor(Actor* _actor);

	virtual void ProcessInput();
	virtual void UpdateGame(float _deltaTime);
	virtual void RenderLoop(float _deltaTime);

	void SetUpGameObjects();

protected:
	std::vector<class Actor*> m_Actors;

	GameObject* m_TestObject;

	GameModeBase* m_CurrentMode;

};

