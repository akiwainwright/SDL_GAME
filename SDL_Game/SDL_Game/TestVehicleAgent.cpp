#include "TestVehicleAgent.h"




TestVehicleAgent::TestVehicleAgent(class Game* _game, string _name, ActorState _state, Actor* _parent) : GameObject(_game, _name, _state, _parent)
{
}

void TestVehicleAgent::UpdateGameObject(float _deltaTime)
{
	//calculate the combined force from each steering behaviour in the vehicle's list
	Vector2 steeringForce = m_SteeringBehaviours->Calculate();
	//acceleration = force/mass
	Vector2 acceleration = steeringForce / m_Mass;
	//update velocity
	m_Velocity += acceleration * _deltaTime;
	m_Velocity.Truncate(m_MaxSpeed);
	
	m_Transform->m_Pos += m_Velocity * _deltaTime;

	//update the heading if the vehicle has a velocity has greater than a very small value
	if (m_Velocity.LenghtSqrd() > FLT_EPSILON)
	{
		m_Heading = m_Velocity.Normalise();
		m_Side = m_Heading.PerpendicularClockwise();
	}

}

TestVehicleAgent::~TestVehicleAgent()
{
}



