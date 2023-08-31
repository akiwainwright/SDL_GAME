#include "Actor.h"

Actor::Actor(GameModeBase* _gameMode)
{
	m_GameMode = _gameMode;
	//use game to add actor

	m_ActorState = ActorState::EActive;
}

Actor::~Actor()
{
	//remove actor
}

