#pragma once
#include "GameObject.h"
#include "State.h"





class TestAgent : public GameObject
{
public:
	TestAgent(class GameModeBase* _gameMode, string _name, ActorState _state);
	void UpdateGameObject(float _deltaTime) override;
	virtual bool HandleMessage(const Telegram& _msg);
	~TestAgent();

private:
	StateMachine<TestAgent>* m_StateMachine;
};
