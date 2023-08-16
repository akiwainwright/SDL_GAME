#pragma once
#include "Actor.h"


class GameObject : public Actor
{
public:
	GameObject(class Game* _game, string _name, ActorState _state, Actor* _parent = nullptr);
	virtual ~GameObject();

	//this is the update fuction that will be called from the game class
	void Update(float _deltaTime);
	void UpdateComponents(float _deltaTime);

	//game object specific update code i.e. move 
	virtual void UpdateGameObject(float _deltaTime){}


	void AddComponent(Component* _comp);
	void RemoveComponent(Component* _comp);

	Actor* GetParent();

	template <typename T>
	T* GetComponent() {
		for (auto comp : m_Components)
		{
			if (dynamic_cast<T*>(comp))
			{
				return (T*)comp;
			}
		}
		return nullptr;
	}

protected:
	string m_Name;

private:
	vector<Component*> m_Components;
	Actor* m_Parent;
	///Transform Component
};


