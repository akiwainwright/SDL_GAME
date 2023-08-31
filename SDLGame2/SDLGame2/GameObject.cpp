#include "GameObject.h"


GameObject::GameObject(GameModeBase* _gameMode, string _name, ActorState _state, Actor* _parent) :Actor(_gameMode)
{
	m_Name = _name;
	m_ActorState = _state;
	m_Parent = _parent;
}

GameObject::~GameObject()
{
	//remove components
}

void GameObject::Update(float _deltaTime)
{
	if (m_ActorState == EActive)
	{
		UpdateComponents(_deltaTime);
		UpdateGameObject(_deltaTime);
	}
}

void GameObject::UpdateComponents(float _deltaTime)
{
	for (Component* comp : m_Components)
	{
		comp->Update(_deltaTime);
	}
}

void GameObject::AddComponent(Component* _comp)
{

	auto iter = m_Components.begin();
	//if we want to do order
	//for (;iter
	//	 != m_Components.end();++iter)
	//{

	//}

	m_Components.insert(iter, _comp);

	//m_Components.emplace_back(_comp);
}

void GameObject::RemoveComponent(Component* _comp)
{
	auto iter = find(m_Components.begin(), m_Components.end(), _comp);
	if (iter != m_Components.end())
	{
		m_Components.erase(iter);
	}
}

Actor* GameObject::GetParent()
{
	return m_Parent;
}
