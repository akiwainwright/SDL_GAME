#pragma once
#include "GameObject.h"
#include "SteeringBehaviours.h"
#include "BasicIncludes.h"
#include "consts.h"
#include "CustomMaths.h"
#include "Parameters.h"
//#define SteeringParam (*VehicleAgent::m_VehicleParams)




class GameModeBase;

class VehicleAgent : public GameObject
{
public:
	VehicleAgent(class Game* _gameMode, std::string _name, ActorState _state, SteeringVehicleParameter* _vehicleParams, Actor* _parent = nullptr);
	virtual ~VehicleAgent();
	void SetVelocity(const Vector2& _val) { m_Velocity = _val; }
	void SetTarget(const Vector2& _target) { m_SteeringBehaviours->SetTarget(_target); }
	Vector2 GetTarget()const { return m_SteeringBehaviours->GetTarget(); }
	void UpdateGameObject(float _deltaTime)override;

	void RotateToFaceDirection();
	Vector2 Side(){ return m_Side; }
	void SetSide(Vector2 _side) { m_Side = _side; }
	Vector2 Heading() { return m_Heading; }
	void SetHeading(Vector2 _heading);
	float GetSpeed() { return m_Velocity.Length(); }
	float GetSpeedSq() { return m_Velocity.LenghtSqrd(); }


	SteeringBehaviours* GetSteering() { return m_SteeringBehaviours; }

	Vector2 GetVelocity()const { return m_Velocity; }
	//void SetVelocity(Vector2 _velocity) { m_Velocity = _velocity;  }

	SteeringVehicleParameter* GetVehicleParams() const { return m_VehicleParams; }

	bool IsSpeedMaxedOut() { return (m_VehicleParams->GetMaxSpeed() * m_VehicleParams->GetMaxSpeed() >= m_Velocity.LenghtSqrd()); }

	//GameModeBase* GetGamemode();// improve this
	//Game* GetGame();// improve this
	
private:

	SteeringBehaviours* m_SteeringBehaviours;
	SteeringVehicleParameter* m_VehicleParams;


	//make public getters

	Vector2 m_Velocity;

	//a normalized vector pointing in the direction the gameobject is heading (forward direction)
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