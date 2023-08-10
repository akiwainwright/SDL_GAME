#pragma once
#include "Component.h"
#include "BasicIncludes.h"


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
	virtual ~Actor();



protected:
	class Game* m_Game;
	ActorState m_State;

private:
	
};


