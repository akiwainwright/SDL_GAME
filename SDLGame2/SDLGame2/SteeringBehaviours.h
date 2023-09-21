#pragma once
#include "CustomMaths.h"
#include "BasicIncludes.h"

class SteeringBehaviours
{
public:
	SteeringBehaviours(class TestVehicleAgent* _agent);
	~SteeringBehaviours();

	Vector2 Calculate();
	Vector2 ForwardComponent();
	Vector2 SideComponent();

	void SetPath();
	void SetTarget(Vector2 _pos);
	void SetTargetAgent(class Actor* _agent);
	void SeekOn();
	void FleeOn();
	void ArriveOn();
	void SeekOff();
	void FleeOff();
	void ArriveOff();

private:
	Vector2 Seek(const Vector2& _target);
	Vector2 Flee(Vector2& _target);
	Vector2 Arrive(const Vector2& _target, float _deceleration = 2);
	Vector2 Pursuit(class TestVehicleAgent* _target);
	Vector2 Evade(class TestVehicleAgent* _target);
	Vector2 Wander();
	Vector2 ObstacleAvoidance(const vector<class GameObject*>& _obstacles);
	Vector2 WallAvoidance(const vector<class Walls2D*>& _walls);
	Vector2 Interpose(class TestVehicleAgent* _agent1, class TestVehicleAgent* _agent2);
	Vector2 GetHidingPos(const Vector2& _posOb, const float _radiusOb, const Vector2& _posTarget);
	Vector2 Hide(class TestVehicleAgent* _agent, vector<class GameObject*>& _obstacle);
	Vector2 FollowPath();

	void CreateFeelers();

	class TestVehicleAgent* m_Agent;
	Vector2 m_Target;

	double m_WanderRadius;
	double m_WanderDistance;
	double m_WanderJitter;

	Vector2 m_WanderTarget;


	//length of the detection box
	float m_BoxLength;
	float m_MinDetectionBoxLength;
	
	float m_WallDetectorLength;

	vector<Vector2> m_Feelers;

	class Path* m_Path;
	float m_WayPointsSeekDist;

};

