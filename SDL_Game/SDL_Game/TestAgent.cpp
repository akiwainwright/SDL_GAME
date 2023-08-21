#include "TestAgent.h"
#include "Game.h"


TestAgent::TestAgent(Game* _game, string _name, ActorState _state) : GameObject(_game, _name, _state)
{
	m_StateMachine = new StateMachine<TestAgent>(this);
}

void TestAgent::UpdateGameObject(float _deltaTime)
{
	m_StateMachine->UpdateState();
}


bool TestAgent::HandleMessage(const Telegram& _msg)
{
	return m_StateMachine->HandleMessage(_msg);
}

TestAgent::~TestAgent()
{
	delete m_StateMachine;
	m_StateMachine = nullptr;
}
