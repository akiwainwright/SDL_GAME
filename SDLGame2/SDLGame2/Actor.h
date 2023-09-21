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

enum Tag
{
	UNTAGGED
};

//an object in the game or scene 

class Actor
{
public:
	Actor(class Game* _game, string _Name, Tag _tag = UNTAGGED);
	virtual void Update(float _deltaTime) {}
	virtual ~Actor();
	ActorState GetState() const{ return m_ActorState; }
	Tag GetTag()const {}

	virtual bool HandleMessage(const Telegram& _msg) = 0;

protected:
	class Game* m_Game;
	ActorState m_ActorState;
	string m_Name;
	Tag m_Tag;
private:

};


