#pragma once
#include "Component.h"
#include "BasicIncludes.h"
#include "Events.h"

class GameModeBase;

enum ActorState
{
	EActive,
	EPaused,
	EDead
};
//an object in the game or scene 

class Actor
{
public:
	Actor(GameModeBase* _gameMode);
	virtual void Update(float _deltaTime) {}
	virtual ~Actor();

	virtual bool HandleMessage(const Telegram& _msg) = 0;

protected:
	GameModeBase* m_GameMode;
	ActorState m_ActorState;

private:

};


