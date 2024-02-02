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

enum Tag
{
	UNTAGGED
};

//an object in the game or scene 

class Actor
{
public:
	Actor(class GameModeBase* _game, string _Name, Tag _tag = UNTAGGED);
	virtual void Update(float _deltaTime) {}
	virtual void Render(){}
	virtual ~Actor();
	ActorState GetState() const{ return m_ActorState; }
	Tag GetTag()const {}

	virtual bool HandleMessage(const Telegram& _msg) = 0;

	GameModeBase* GetGameModeBase()const { return m_GameMode; }

protected:
	GameModeBase* m_GameMode;
	
	ActorState m_ActorState;
	string m_Name;
	Tag m_Tag;
private:

};


