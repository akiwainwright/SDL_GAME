#include "GameObject.h"


GameObject::GameObject(Game* _game, string _name, ActorState _state, Actor* _parent) :Actor(_game, _name)
//GameObject::GameObject(GameModeBase* _gameMode, string _name, ActorState _state, Actor* _parent) :Actor(_gameMode)
{
	//m_Name = _name;
	m_ActorState = _state;
	m_Parent = _parent;
}

GameObject::~GameObject()
{
	while (!m_Components.empty())
	{
		delete m_Components.back();
	}
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

void GameObject::ProcessInput(const uint8_t* _keyState)
{
	if (m_ActorState != ActorState::EActive)
	{
		return;
	}
	for (auto comp : m_Components)
	{
		comp->ProcessInput(_keyState);
	}
	GameObjectInput(_keyState);
}

void GameObject::GameObjectInput(const uint8_t* _keyState)
{
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

bool GameObject::HasComponent(Component* _comp)
{
	auto iter = find(m_Components.begin(), m_Components.end(), _comp);
	if (iter != m_Components.end())
	{
		return true;
	}
	return false;
}
