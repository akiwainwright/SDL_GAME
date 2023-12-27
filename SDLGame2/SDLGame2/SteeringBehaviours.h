#pragma once
#include "CustomMaths.h"
#include "BasicIncludes.h"
#include "Path.h"

class VehicleAgent;
class GameObject;
class Actor;
//TODO: Dfferent summing method, flocking behaviours + offset pursuit, Space Partitioning(AKI)
class SteeringBehaviours
{
public:
	SteeringBehaviours(VehicleAgent* _agent);
	~SteeringBehaviours();

	Vector2 Calculate();
	Vector2 GetSteeringForce()const { m_SteeringForce; }
	float ForwardComponent();
	float SideComponent();

	void CreatePath(int _numWaypoints, int _mx, int _my, int _cx, int _cy) { m_Path->CreateRandomPath(_numWaypoints, _mx, _my, _cx, _cy); }
	void SetTarget(Vector2 _pos);
	Vector2 GetTarget() { return m_Target; }
	void SetTargetAgent(VehicleAgent* _agent);
	void SetTargetAgent2(VehicleAgent* _agent) { m_TargetAgent2 = _agent; }
	void SetTargetAgents(VehicleAgent* _agent, VehicleAgent* _agent2) { m_TargetAgent = _agent; m_TargetAgent2 = _agent2; }
	void SetPath(list<Vector2> _newPath) { m_Path->Set(_newPath); }
	void CSP(bool _Activate){ m_bCSP = _Activate; }
	void Seek(bool _Activate){ m_bSeek = _Activate; }
	void Flee(bool _Activate) { m_bFlee = _Activate; }
	void Arrive(bool _Activate) { m_bArrive = _Activate; }
	void Wander(bool _Activate) { m_bWander = _Activate; }
	void Pursuit(bool _Activate, VehicleAgent* _agent) { m_bPursuit = _Activate; m_TargetAgent = _agent; }
	bool IsPursuit() { return m_bPursuit; }
	void Evade(bool _Activate, VehicleAgent* _agent) { m_bEvade = _Activate;  m_TargetAgent = _agent;}
	void Cohesion(bool _Activate) { m_bCohesion = _Activate; }
	void Separation(bool _Activate) { m_bSeparation = _Activate; }
	void Alignment(bool _Activate) { m_bAlignment = _Activate; }
	void ObstacleAvoidance(bool _Activate){m_bObstacleAvoidance = _Activate;}
	void WallAvoidance(bool _Activate){m_bWallAvoidance = _Activate;}
	void FollowPath(bool _Activate){m_bFollowPath = _Activate;}
	void Interpose(bool _Activate, VehicleAgent* _agent, VehicleAgent* _agent2) { m_bInterpose = _Activate; SetTargetAgents(_agent,_agent2); }
	void Hide(bool _Activate){m_bHide = _Activate;}
	void Flocking(bool _Activate) { Cohesion(_Activate); Alignment(_Activate); Separation(_Activate); Wander(_Activate); }

	void FindNeighbours();
	bool AccumulateForce(Vector2& _steeringForce, Vector2 _forceToAdd);
	const vector<Vector2>& GetFeelers()const { return m_Feelers; }

private:
	Vector2 Seek(const Vector2& _target);
	Vector2 Flee(Vector2& _target);
	Vector2 Arrive(const Vector2& _target, float _deceleration = 2);  //Arrive makes use of these to determine how quickly a vehicle should decelerate to its target 3 is slow and 1 is fast
	Vector2 Pursuit(class VehicleAgent* _target);
	Vector2 Evade(class VehicleAgent* _target);
	Vector2 Wander();
	Vector2 ObstacleAvoidance(const vector<class GameObject*>& _obstacles);
	Vector2 WallAvoidance(const vector<class Walls2D*>& _walls);
	Vector2 Interpose(class VehicleAgent* _agent1, class VehicleAgent* _agent2);
	Vector2 GetHidingPos(const Vector2& _posOb, const float _radiusOb, const Vector2& _posTarget);
	Vector2 Hide(class VehicleAgent* _agent,const vector<class GameObject*>& _obstacle);
	Vector2 FollowPath();

	void CreateFeelers();

	//Group behaviours
	
	//Vector2 Cohesion(const vector<VehicleAgent*> &_agents);
	//Vector2 Alignment(const vector<VehicleAgent*>& _agents);
	//Vector2 Separation(const vector<VehicleAgent*>& _agents);

	////cell space partitioning
	//Vector2 CohesionCSP(const vector<VehicleAgent*>& _agents);
	//Vector2 AlignmentCSP(const vector<VehicleAgent*>& _agents);
	//Vector2 SeparationCSP(const vector<VehicleAgent*>& _agents);

	Vector2 CalculateWeightedSum();


	class VehicleAgent* m_Agent;
	class VehicleAgent* m_TargetAgent;
	class VehicleAgent* m_TargetAgent2;
	Vector2 m_Target;

	Vector2 m_WanderTarget;

	Vector2 m_SteeringForce;
	

	vector<Vector2> m_Feelers;

	Path* m_Path;
	float m_WayPointsSeekDist;

	bool m_bCSP;
	bool m_bFlee;
	bool m_bSeek;
	bool m_bArrive;
	bool m_bPursuit;
	bool m_bEvade;
	bool m_bWander;
	bool m_bObstacleAvoidance;
	bool m_bWallAvoidance;
	bool m_bInterpose;
	bool m_bHide;
	bool m_bSeparation;
	bool m_bAlignment;
	bool m_bCohesion;
	bool m_bFollowPath;
};

