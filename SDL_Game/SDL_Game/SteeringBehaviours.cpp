#include "SteeringBehaviours.h"
#include "TestVehicleAgent.h"


SteeringBehaviours::SteeringBehaviours(TestVehicleAgent* _agent) : m_Agent(_agent)
{

}

SteeringBehaviours::~SteeringBehaviours()
{
}

Vector2 SteeringBehaviours::Calculate()
{
	return Vector2();
}

Vector2 SteeringBehaviours::ForwardComponent()
{
	return Vector2();
}

Vector2 SteeringBehaviours::SideComponent()
{
	return Vector2();
}

void SteeringBehaviours::SetPath()
{
}

void SteeringBehaviours::SetTarget(Vector2 _pos)
{
}

void SteeringBehaviours::SetTargetAgent(Actor* _agent)
{
}

void SteeringBehaviours::SeekOn()
{
}

void SteeringBehaviours::FleeOn()
{
}

void SteeringBehaviours::ArriveOn()
{
}

void SteeringBehaviours::SeekOff()
{
}

void SteeringBehaviours::FleeOff()
{
}

void SteeringBehaviours::ArriveOff()
{
}

Vector2 SteeringBehaviours::Seek(Vector2& _target)
{
	Vector2 desiredVelocity = Vector2::Normalized(_target - m_Agent->GetTransform()->m_Pos) * (m_Agent)->m_MaxSpeed;

	return (desiredVelocity - (m_Agent)->m_Velocity);

}

Vector2 SteeringBehaviours::Flee(Vector2& _target)
{
	Vector2 desiredVelocity = Vector2::Normalized(m_Agent->GetTransform()->m_Pos - _target) * m_Agent->m_MaxSpeed;

	return (desiredVelocity - (m_Agent)->m_Velocity);

}

Vector2 SteeringBehaviours::Arrive(Vector2& _target, float _deceleration)
{
	Vector2 toTarget = _target - m_Agent->GetTransform()->m_Pos;

	//calculate the distance to the target position
	double dist = toTarget.Length();

	if (dist > 0)
	{
		//this value is required to provide fine tweaking of the deceleration.
		const double decelerationTweaker = 0.3f;

		//calculate the speed required to reach the target given the desired deceleration 
		float speed = dist / ((double)_deceleration * decelerationTweaker);

		speed = min(speed, m_Agent->m_MaxSpeed);

		//then seek but we dont need to normalize the toTarget vector 
		// because we have already calculated the length(dist)
		Vector2 desiredVelocity = toTarget * speed / dist;

		return (desiredVelocity - m_Agent->m_Velocity);


	}
	return Vector2(0, 0);

}

Vector2 SteeringBehaviours::Pursuit(TestVehicleAgent* _target)
{
	//if the evaderis ahead and facing the agent then we can just seek for the evader's current position
	Vector2 toEvader = _target->GetTransform()->m_Pos - m_Agent->GetTransform()->m_Pos;

	double relativeHeading = Vector2::DotProduct(m_Agent->m_Heading, _target->m_Heading);
	if ((Vector2::DotProduct(toEvader, m_Agent->m_Heading)>0) && (relativeHeading < -0.95f))
	{
		return Seek(_target->GetTransform()->m_Pos);
	}

	//not considered ahead so we predict where the evader will be

	//the look-ahead time is proportional to the distance between the evader and the pursuer, 
	// and is inversely proportional to the sum of the agents velocities
	double LookAheadTime = toEvader.Length() / (m_Agent->m_MaxSpeed + _target->m_Velocity.Length());

	//then seek to the predicted future position of the evader
	auto targetPos = ((_target->GetTransform()->m_Pos + _target->m_Velocity) * LookAheadTime);
	return Seek(targetPos);


}

Vector2 SteeringBehaviours::Evade(TestVehicleAgent* _target)
{
	//not necessary to include the check for facing direction this time
	Vector2 toPursuer = _target->GetTransform()->m_Pos - m_Agent->GetTransform()->m_Pos;

	//the look-ahead time is proportional to the distance between the pursuer
	//and the evader, and is inversely proportional to the sum of the agents' velocities
	float lookAheadTime = toPursuer.Length() / (m_Agent->m_MaxSpeed + _target->m_Velocity.Length());

	//now flee away from predicted future position of the pursuer
	auto targetPos = _target->GetTransform()->m_Pos + _target->m_Velocity * lookAheadTime;
	return Flee(targetPos);

}

Vector2 SteeringBehaviours::Wander()
{
	//add a small random vector to the targets position
	float randomNumber = (rand() % 2) - 1;
	m_WanderTarget += Vector2(randomNumber * m_WanderJitter, randomNumber * m_WanderJitter);
	return Vector2(0, 0);
	
}

Vector2 SteeringBehaviours::ObstacleAvoidance(const vector<class GameObject*>& _obstacles)
{
	return Vector2();
}

Vector2 SteeringBehaviours::WallAvoidance(const vector<class GameObject*>& _walls)
{
	return Vector2();
}
