#pragma once


class Component
{
public:
	Component(class GameObject* _owner);
	virtual ~Component();
	virtual void ProcessInput(const uint8_t* _keyState) {}

	virtual void Update(float _deltaTime) {}

protected:
	class GameObject* m_Owner;
};



