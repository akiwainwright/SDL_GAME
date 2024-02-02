#pragma once
#include "Actor.h"

#include "TransformComponent.h"
#include "CustomMaths.h"

class TextureComponent;
class Component;

class GameObject : public Actor
{
public:
	GameObject(class Game* _gameMode, string _name, ActorState _state, Actor* _parent = nullptr);
	
	virtual ~GameObject();

	//this is the update fuction that will be called from the game class
	void Update(float _deltaTime)override;
	void UpdateComponents(float _deltaTime);

	//game object specific update code i.e. move 
	virtual void UpdateGameObject(float _deltaTime) {}

	void ProcessInput(const uint8_t* _keyState);
	virtual void GameObjectInput(const uint8_t* _keyState);

	virtual bool HandleMessage(const Telegram& _msg) { return false; }

	void AddComponent(Component* _comp);
	void RemoveComponent(Component* _comp);

	Actor* GetParent();

	template <typename T>
	T* GetComponent() {
		for (auto comp : m_Components)
		{
			if (dynamic_cast<T*>(comp))
			{
				return static_cast<T*>(comp);
			}
		}
		return nullptr;
	}

	bool HasComponent(Component* _comp);

	inline TransformComponent* GetTransform() { return m_Transform; }

	//inline TextureComponent* GetTexture() { return m_Texture; }

protected:
	vector<Component*> m_Components;
	Actor* m_Parent;
	TransformComponent* m_Transform;
	TextureComponent* m_Texture;

private:


};

