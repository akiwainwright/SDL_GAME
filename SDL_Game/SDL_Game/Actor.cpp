#include "Actor.h"

Actor::Actor(Game* _game)
{
	m_Game = _game;
	//use game to add actor

	m_State = ActorState::EActive;
}

Actor::~Actor()
{
	//remove actor
}

