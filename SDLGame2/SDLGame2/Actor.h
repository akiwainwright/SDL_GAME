#pragma once
#include "Component.h"
#include "BasicIncludes.h"
#include "Events.h"

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
	Actor(class Game* _game);
	virtual void Update(float _deltaTime) {}
	virtual ~Actor();

	virtual bool HandleMessage(const Telegram& _msg) = 0;

protected:
	class Game* m_Game;
	ActorState m_ActorState;

private:

};


