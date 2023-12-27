#pragma once
#include <stdint.h>
class GameObject;

class Component
{
public:
	Component(GameObject* _owner);
	virtual ~Component();
	virtual void ProcessInput(const uint8_t* _keyState) {}

	virtual void Update(float _deltaTime) {}

protected:
	GameObject* m_Owner;
};



