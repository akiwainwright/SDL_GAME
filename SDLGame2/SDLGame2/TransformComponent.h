#pragma once
#include "BasicIncludes.h"
#include "CustomMaths.h"
#include "Component.h"

//this is just for testing purpose
class TransformComponent : public Component
{
public:
	TransformComponent(GameObject* _owner);
	~TransformComponent();

	void Update(float _deltaTime)override;

	Vector2 m_Pos;
	Vector2 m_Scale;
	float m_Rotation;
private:

};

