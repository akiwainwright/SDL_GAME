#include "Actor.h"
#include "Game.h"
#include "GameModeBase.h"


Actor::Actor(GameModeBase* _gameMode, string _Name, Tag _tag)
{
	m_GameMode = _gameMode;
	//use game to add actor
	m_Name = _Name;
	m_Tag = _tag;
	m_ActorState = ActorState::EActive;
	m_GameMode->AddActor(this);
}

Actor::~Actor()
{
	m_GameMode->RemoveActor(this);
}


