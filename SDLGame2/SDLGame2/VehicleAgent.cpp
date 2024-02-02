#include "VehicleAgent.h"

#include "Game.h"
#include "AnimatorComponent.h"


VehicleAgent::VehicleAgent( Game* _game, string _name, ActorState _state,SteeringVehicleParameter* _vehicleParams, Actor* _parent) : GameObject(_game, _name, _state, _parent)
{
	m_SteeringBehaviours = new SteeringBehaviours(this);
	m_VehicleParams = _vehicleParams;

	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(m_GameMode->GetTextures("Assets/Textures/Ship01.png"));

}

void VehicleAgent::UpdateGameObject(float _deltaTime)
{
	////calculate the combined force from each steering behaviour in the vehicle's list
	//Vector2 steeringForce = m_SteeringBehaviours->Calculate();
	////acceleration = force/mass
	//Vector2 acceleration = steeringForce / m_Mass;
	////update velocity
	//m_Velocity += acceleration * _deltaTime;
	//m_Velocity.Truncate(m_MaxSpeed);

	//m_Transform->GetPosition() += m_Velocity * _deltaTime;

	////update the heading if the vehicle has a velocity has greater than a very small value
	//if (m_Velocity.LenghtSqrd() > FLT_EPSILON)
	//{
	//	m_Heading = m_Velocity.Normalise();
	//	m_Side = m_Heading.PerpendicularClockwise();
	//}

}

void VehicleAgent::RotateToFaceDirection()
{
}

void VehicleAgent::SetHeading(Vector2 _heading)
{
}

VehicleAgent::~VehicleAgent()
{

}

