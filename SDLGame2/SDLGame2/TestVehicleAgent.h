#pragma once
#include "GameObject.h"
#include "SteeringBehaviours.h"
#include "BasicIncludes.h"
#include "consts.h"
#include "CustomMaths.h"


class TestVehicleAgent : public GameObject
{
public:
	TestVehicleAgent(class Game* _game, string _name, ActorState _state, Actor* _parent = nullptr);

	void UpdateGameObject(float _deltaTime)override;

	~TestVehicleAgent();

public:

	SteeringBehaviours* m_SteeringBehaviours;

	//make public getters

	Vector2 m_Velocity;

	//a normalized vector pointing in the direction the gameobject is heading
	Vector2 m_Heading;

	//a vector perpendicular to the heading vector
	Vector2 m_Side;

	float m_Mass;

	//the maximum speed the gameObject can travel
	float m_MaxSpeed;

	//the maximum force the gameObject can produce to power itself
	float m_MaxForce;

	//the maximum rate (radians per seconds) at which this vehicle can rotate
	float m_MaxTurnRate;


};