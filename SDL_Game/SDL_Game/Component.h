#pragma once


class Component
{
public:
	Component(class GameObject* _owner);
	virtual ~Component();

	virtual void Update(float _deltaTime){}

protected:
	class GameObject* m_Owner;
};


