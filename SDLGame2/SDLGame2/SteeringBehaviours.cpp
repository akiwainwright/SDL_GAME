#include "SteeringBehaviours.h"
#include "VehicleAgent.h"
#include "Path.h"


SteeringBehaviours::SteeringBehaviours(VehicleAgent* _agent) : m_Agent(_agent)
{

}

SteeringBehaviours::~SteeringBehaviours()
{
}

Vector2 SteeringBehaviours::Calculate()
{
	m_SteeringForce.Zero();

	//steeringForce = the combination of chosen forces

	m_SteeringForce.Truncate(m_Agent->GetVehicleParams()->GetMaxSteeringForce());
	return m_SteeringForce;
}

float SteeringBehaviours::ForwardComponent()
{
	return Vector2::DotProduct(m_Agent->Heading(), m_SteeringForce);
}

float SteeringBehaviours::SideComponent()
{
	return Vector2::DotProduct(m_Agent->Side(),( m_SteeringForce* m_Agent->GetVehicleParams()->GetMaxTurnRate()));
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

void SteeringBehaviours::FindNeighbours()
{
}

/// <summary>
/// this calculates how much of its max steering force the vehicle has left to apply and then applies that amount of force to add
/// </summary>
/// <param name="_steeringForce"></param>
/// <param name="_forceToAdd"></param>
/// <returns></returns>
bool SteeringBehaviours::AccumulateForce(Vector2& _steeringForce, Vector2 _forceToAdd)
{
	float magnitudeSoFar = _steeringForce.Length();

	float remainingMagnitude = m_Agent->GetVehicleParams()->GetMaxSteeringForce() - magnitudeSoFar;

	if (remainingMagnitude <= 0.0f)
	{
		return false;
	}

	//calculates the magnitude of the force we want to add
	float magnitudeToAdd = _forceToAdd.Length();

	if (magnitudeToAdd < remainingMagnitude)
	{
		_steeringForce += magnitudeToAdd;
	}
	else
	{
		_steeringForce += (Vector2::Normalized(_forceToAdd) * remainingMagnitude);
	}
	return true;
}

Vector2 SteeringBehaviours::Seek(const Vector2& _target)
{
	Vector2 desiredVelocity = Vector2::Normalized(_target - m_Agent->GetTransform()->m_Pos) * (m_Agent)->m_MaxSpeed;

	return (desiredVelocity - (m_Agent)->GetVelocity());

}

Vector2 SteeringBehaviours::Flee(Vector2& _target)
{
	Vector2 desiredVelocity = Vector2::Normalized(m_Agent->GetTransform()->m_Pos - _target) * m_Agent->m_MaxSpeed;

	return (desiredVelocity - (m_Agent)->GetVelocity());

}

Vector2 SteeringBehaviours::Arrive(const Vector2& _target, float _deceleration)
{
	Vector2 toTarget = _target - m_Agent->GetTransform()->m_Pos;

	//calculate the distance to the target position
	double dist = toTarget.Length();

	if (dist > 0)
	{
		//this value is required to provide fine tweaking of the deceleration.
		const double decelerationTweaker = 0.3f;

		//calculate the speed required to reach the target given the desired deceleration 
		double speed = dist / ((double)_deceleration * decelerationTweaker);

		speed = (double)min((float)speed, m_Agent->m_MaxSpeed);

		//then seek but we dont need to normalize the toTarget vector 
		// because we have already calculated the length(dist)
		Vector2 desiredVelocity = toTarget * (float)(speed / dist);

		return (desiredVelocity - m_Agent->m_Velocity);


	}
	return Vector2(0, 0);

}

Vector2 SteeringBehaviours::Pursuit(VehicleAgent* _target)
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
	float LookAheadTime = toEvader.Length() / (m_Agent->m_MaxSpeed + _target->m_Velocity.Length());

	//then seek to the predicted future position of the evader
	auto targetPos = ((_target->GetTransform()->m_Pos + _target->m_Velocity) * LookAheadTime);
	return Seek(targetPos);


}

Vector2 SteeringBehaviours::Evade(VehicleAgent* _target)
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
	int randomNumber = (rand() % 2) - 1;
	m_WanderTarget += Vector2(randomNumber * (float)m_WanderJitter, randomNumber * (float)m_WanderJitter);
	m_WanderTarget.Normalised();

	//move the target into a position wanderDist in front of the agent
	Vector2 targetLocal = m_WanderTarget + Vector2(m_WanderDistance, 0);

	//project the target into world space
	Vector2 targetWorld = Vector2::LocalPointToWorld(targetLocal, m_Agent->m_Heading, m_Agent->m_Side, m_Agent->GetTransform()->m_Pos);

	//steer towards it
	return targetWorld - m_Agent->GetTransform()->m_Pos;
	
}

Vector2 SteeringBehaviours::ObstacleAvoidance(const vector< GameObject*>& _obstacles)
{
	//box length is proportional to the agent's velocity
	m_BoxLength = m_MinDetectionBoxLength + (m_Agent->m_Velocity.Length() / m_Agent->m_MaxSpeed) * m_MinDetectionBoxLength;

	return Vector2();
}

Vector2 SteeringBehaviours::WallAvoidance(const vector< Walls2D*>& _walls)
{
	CreateFeelers();

	float distToThisIP = 0.0f;
	float distToClosestIP = FLT_MAX;

	//hold and index to the vector of walls
	int closestWall = -1;

	Vector2 steeringForce, 
		point //used for storing temporary info
		, closestPoint;//holds the closest intersection point

	//examine each feeler in turn
	for (int i = 0; i < m_Feelers.size(); i++)
	{
		//run through each wall checking for any intersection points 
		for (int j = 0; j < _walls.size(); j++)
		{
			if (LineIntersection(m_Agent->GetTransform()->m_Pos, m_Feelers[i], _walls[j]->From(), _walls[j]->To(), distToThisIP, point))
			{
				//is this the closest found so far? if so keep a record
				if (distToThisIP < distToClosestIP)
				{
					distToClosestIP = distToThisIP;
					closestWall = j;
					closestPoint = point;
				}
			}
		}//next wall
		//if an intersection point has been detected, calculate a force that will direct the agent the right way
		if (closestWall >= 0)
		{
			//calculate by what distance the projected position of the agent will overshoot the wall
			Vector2 overShoot = m_Feelers[i] - closestPoint;

			//create a force in the direction of the wall normal, with a magnitude of the overshoot
			steeringForce = _walls[closestWall]->Normal() * overShoot.Length();
		}
	}//next feeler

	return steeringForce;

}

Vector2 SteeringBehaviours::Interpose( VehicleAgent* _agent1, VehicleAgent* _agent2)
{
	//first we need to figure out where the 2 agents are going to be at time T in the future. This is approximated by determining the time taken to reach the midway point at the current time and max speed
	Vector2 midPoint = (_agent1->GetTransform()->m_Pos + _agent2->GetTransform()->m_Pos) / 2.0f;

	float timeToReachMidPoint = (midPoint - m_Agent->GetTransform()->m_Pos).Length() / m_Agent->m_MaxSpeed;

	//now we have T, we assume that agent A and agent B will continue on a straight trajectory and extrapolate the midpoint of these predicted positions
	Vector2 aPos = _agent1->GetTransform()->m_Pos + _agent1->m_Velocity * timeToReachMidPoint;
	Vector2 bPos = _agent2->GetTransform()->m_Pos + _agent2->m_Velocity * timeToReachMidPoint;

	//calculate the midpoint of these predicted positions
	midPoint = (aPos + bPos) / 2.0f;

	//then steer to arrive at it
	return Arrive(midPoint);

}

Vector2 SteeringBehaviours::GetHidingPos(const Vector2& _posOb, const float _radiusOb, const Vector2& _posTarget)
{
	//calculate how far away the agent is to be from the chosen obstacle's bounding radius
	const float distanceFromBoundary = 30.0f;
	float distAway = _radiusOb + distanceFromBoundary;

	//calculate the heading towards the object from the target
	Vector2 toOb = (_posOb - _posTarget).Normalise();

	//scale it to size and add to the obstacle's position to the hiding spot 
	return (toOb * distAway) + _posOb;

}

Vector2 SteeringBehaviours::Hide( VehicleAgent* _agent, vector<class GameObject*>& _obstacle)
{
	float distToClosest = FLT_MAX;
	Vector2 bestHidingSpot;
	vector<GameObject*>::iterator curOb = _obstacle.begin();
	while (curOb != _obstacle.end())
	{
		Vector2 hidingSpot = GetHidingPos((*curOb)->GetTransform()->m_Pos, 10, _agent->GetTransform()->m_Pos);
		//work in distance squared space to find the closest hiding spot to the agent
		float dist = (m_Agent->GetTransform()->m_Pos - hidingSpot).Length();

		if (dist < distToClosest)
		{
			distToClosest = dist;

			bestHidingSpot = hidingSpot;

		}
		++curOb;

	}

	//if there's no suitable obstacles found then invade the target
	if (distToClosest == FLT_MAX)
	{
		return Evade(_agent);
	}
	//use arrive on hiding spot
	return Arrive(bestHidingSpot);
}

Vector2 SteeringBehaviours::FollowPath()
{
	//move to next target if close enough to the current waypoint
	if ((m_Agent->GetTransform()->m_Pos - m_Path->CurrentWayPoint()).LenghtSqrd() < m_WayPointsSeekDist)
	{
		m_Path->SetNextWaypoint();
	}
	if (!m_Path->Finished())
	{
		return Seek(m_Path->CurrentWayPoint());
	}
	else
	{
		return Arrive(m_Path->CurrentWayPoint());
	}
}



void SteeringBehaviours::CreateFeelers()
{
	//straightt forward feeler/walldetector
	m_Feelers[0] = m_Agent->GetTransform()->m_Pos + ( m_Agent->m_Heading * m_WallDetectorLength);
	
	//left wall detector 
	Vector2 temp = m_Agent->GetTransform()->m_Pos + (m_Agent->m_Heading * m_WallDetectorLength / 2.0f);
	temp = rotateVector2(temp, PI * (0.5f * 3.5f), false);
	m_Feelers[1] = temp;
	
	//right wall detector 
	Vector2 temp = m_Agent->GetTransform()->m_Pos + (m_Agent->m_Heading * m_WallDetectorLength / 2.0f);
	temp = rotateVector2(temp, PI * 0.25f, true);
	m_Feelers[2] = temp;

}

