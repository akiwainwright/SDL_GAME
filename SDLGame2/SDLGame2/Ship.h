#pragma once
#include "GameObject.h"
class Ship : public GameObject
{
public:
	Ship(class Game* game, string _name, ActorState _state, Actor* _parent = nullptr);
	void UpdateGameObject(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
private:
	float mRightSpeed;
	float mDownSpeed;
};
