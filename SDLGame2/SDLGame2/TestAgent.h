#pragma once
#include "GameObject.h"
#include "State.h"

class GameModeBase;

class TestAgent : public GameObject
{
public:
	TestAgent(GameModeBase* _gameMode, string _name, ActorState _state);
	//TestAgent(Game* _gameMode, string _name, ActorState _state);
	void UpdateGameObject(float _deltaTime) override;
	virtual bool HandleMessage(const Telegram& _msg);
	~TestAgent();

private:
	StateMachine<TestAgent>* m_StateMachine;
};
