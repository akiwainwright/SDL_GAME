#pragma once

class GameObject;

class Component
{
public:
	Component(GameObject* _owner);
	virtual ~Component();

	virtual void Update(float _deltaTime) {}

protected:
	GameObject* m_Owner;
};



