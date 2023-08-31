#pragma once
#include "CustomMaths.h"
#include "BasicIncludes.h"

class TestVehcicleAgent;
class GameObject;
class Actor;

class SteeringBehaviours
{
public:
	SteeringBehaviours(TestVehicleAgent* _agent);
	~SteeringBehaviours();

	Vector2 Calculate();
	Vector2 ForwardComponent();
	Vector2 SideComponent();

	void SetPath();
	void SetTarget(Vector2 _pos);
	void SetTargetAgent(Actor* _agent);
	void SeekOn();
	void FleeOn();
	void ArriveOn();
	void SeekOff();
	void FleeOff();
	void ArriveOff();

private:
	Vector2 Seek(Vector2& _target);
	Vector2 Flee(Vector2& _target);
	Vector2 Arrive(Vector2& _target, float _deceleration = 2);
	Vector2 Pursuit(TestVehicleAgent* _target);
	Vector2 Evade(TestVehicleAgent* _target);
	Vector2 Wander();
	Vector2 ObstacleAvoidance(const vector<GameObject*>& _obstacles);
	Vector2 WallAvoidance(const vector<GameObject*>& _walls);

	TestVehicleAgent* m_Agent;

	double m_WanderRadius;
	double m_WanderDistance;
	double m_WanderJitter;

	Vector2 m_WanderTarget;

};

