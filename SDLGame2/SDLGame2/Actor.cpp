#include "Actor.h"
#include "Game.h"
#include "GameModeBase.h"
Actor::Actor(GameModeBase* _game, string _Name, Tag _tag)
{
	m_GameMode = _game;
	//use game to add actor
	
	m_Name = _Name;
	m_Tag = _tag;
	m_ActorState = ActorState::EActive;
	_game->AddActor(this);
	Game::GetInstance()->AddActor(this);
}

Actor::~Actor()
{
	Game::GetInstance()->RemoveActor(this);
}


