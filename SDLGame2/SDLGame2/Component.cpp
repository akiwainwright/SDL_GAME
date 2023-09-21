#include "Component.h"
#include "GameObject.h"


Component::Component(GameObject* _owner)
{
	m_Owner = _owner;
	if (!m_Owner->HasComponent(this))
	{
		m_Owner->AddComponent(this);
	}
	
	
}

Component::~Component()
{
	m_Owner->RemoveComponent(this);
}
