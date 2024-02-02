#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* _game, string _Name, Tag _tag)
{
	m_GameMode = _game;
	//use game to add actor
	
	m_Name = _Name;
	m_Tag = _tag;
	m_ActorState = ActorState::EActive;
	_game->AddActor(this);
	
}

Actor::~Actor()
{
	m_GameMode->RemoveActor(this);
}


