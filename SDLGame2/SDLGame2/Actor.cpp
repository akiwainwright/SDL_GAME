#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* _game, string _Name, Tag _tag)
{
	m_GameMode = _gameMode;
	//use game to add actor
	m_Name = _Name;
	m_Tag = _tag;
	m_ActorState = ActorState::EActive;
	m_Game->AddActor(this);
}

Actor::~Actor()
{
	m_Game->RemoveActor(this);
}


