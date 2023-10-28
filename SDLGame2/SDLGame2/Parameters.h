#pragma once
//#define SteeringParam (*SteeringVehicleParameter::Instance())
//#define FootballParams (*FootballParameters::Instance())
#define FootballGameParams (*FootballGameParameters::Instance())

//FootballParameters* FootballParameters::m_Instance = nullptr;

#pragma region InstanceSteeringParameters
//class SteeringVehicleParameter
//{
//public:
//	static SteeringVehicleParameter* Instance() {
//		if (m_Instance == nullptr)
//		{
//			m_Instance = new SteeringVehicleParameter();
//		}
//		return m_Instance;
//	}
//
//	float m_MinObstacleRadius;
//	float m_MaxObstacleRadius;
//
//	//This tweaker affects all the steering force multipliers
//	float m_ForceTweaker;
//
//	float m_MaxSteeringForce;
//	float m_MaxSpeed;
//	float m_VehicleMass;
//	float m_MaxTurnRate;
//
//
//	float m_SeparationWeight;
//	float m_AlignmentWeight;
//	float m_CohesionWeight;
//	float m_ObstacleAvoidanceWeight;
//	float m_WallAvoidanceWeight;
//	float m_WanderWeight;
//	float m_SeekWeight;
//	float m_FleeWeight;
//	float m_ArriveWeight;
//	float m_PursuitWeight;
//	float m_OffsetPursuitWeight;
//	float m_InterposeWeight;
//	float m_HideWeight;
//	float m_EvadeWeight;
//	float m_FollowPathWeight;
//
//	float m_MinDetectionBoxLength;//obstacle avoidance 
//	float m_WallDetectionFeelerLength;//wall Avoidance
//
//	//these are the probabilities that a steering behavior will be used
//  //when the prioritized dither calculate method is used
//	float m_WallAvoidanceProbability;
//	float m_ObstacleAvoidanceProbability;
//	float m_SeparationProbability;
//	float m_AlignmentProbability;
//	float m_CohesionProbability;
//	float m_WanderProbability;
//	float m_SeekProbability;
//	float m_FleeProbability;
//	float m_EvadeProbability;
//	float m_HideProbability;
//	float m_ArriveProbability;
//
//	void SetSteeringBehaviourProbability() {
//
//	}
//
//	void SetSteeringBehaviourWeights() {
//
//	}
//
//	void SetSteeringBehaviourWeights() {
//
//	}
//
//private:
//	static SteeringVehicleParameter* m_Instance;
//	SteeringVehicleParameter() {}
//};
#pragma endregion

#pragma region SteeringParameters
class SteeringVehicleParameter
{
public:

	SteeringVehicleParameter() {
		m_MinDetectionBoxLength = -1.0f;
		m_WallDetectionFeelerLength = -1.0f;
		m_MinObstacleRadius = -1.0f;
		m_MaxObstacleRadius = -1.0f;
		m_ForceTweaker = -1.0f;
		m_MaxSteeringForce = -1.0f;
		m_MaxSpeed = -1.0f;
		m_VehicleMass = -1.0f;
		m_MaxTurnRate = -1.0f;
		m_SeparationWeight = -1.0f;
		m_AlignmentWeight = -1.0f;
		m_CohesionWeight = -1.0f;
		m_ObstacleAvoidanceWeight = -1.0f;
		m_WallAvoidanceWeight = -1.0f;
		m_WanderWeight = -1.0f;
		m_SeekWeight = -1.0f;
		m_FleeWeight = -1.0f;
		m_ArriveWeight = -1.0f;
		m_PursuitWeight = -1.0f;
		m_OffsetPursuitWeight = -1.0f;
		m_InterposeWeight = -1.0f;
		m_HideWeight = -1.0f;
		m_EvadeWeight = -1.0f;
		m_FollowPathWeight = -1.0f;
		m_MinDetectionBoxLength = -1.0f;		
		m_WallDetectionFeelerLength = -1.0f;
		m_WallAvoidanceProbability = -1.0f;
		m_ObstacleAvoidanceProbability = -1.0f;
		m_SeparationProbability = -1.0f;
		m_AlignmentProbability = -1.0f;
		m_CohesionProbability = -1.0f;
		m_WanderProbability = -1.0f;
		m_SeekProbability = -1.0f;
		m_FleeProbability = -1.0f;
		m_EvadeProbability = -1.0f;
		m_HideProbability = -1.0f;
		m_ArriveProbability = -1.0f;
	}

	SteeringVehicleParameter(float _minDetectionBoxLength,float _wallDetectionFeelerLength, float _minObstacleRadius, float _maxObstacleRadius, float _forceTweaker, float _maxSteeringForce, float _maxSpeed, float _vehicleMass, float _maxTurnRate, float _separationWeight, float _alignmentWeight, float _cohesionWeight, float _obstacleAvoidanceWeight, float _wallAvoidanceWeight, float _wanderWeight, float _seekWeight, float _fleeWeight, float _arriveWeight, float _pursuitWeight, float _offsetPursuitWeight, float _interposeWeight, float _hideWeight, float _evadeWeight, float _followPathWeight, float _wallAvoidanceProbability, float _obstacleAvoidanceProbability,float _separationProbability, float _alignmentProbability, float _cohesionProbability, float _wanderProbability, float _seekProbability, float _fleeProbability, float _evadeProbability, float _hideProbability, float _arriveProbability) {
		SetSteeringBehaviour( _minDetectionBoxLength,  _wallDetectionFeelerLength,  _minObstacleRadius,  _maxObstacleRadius,  _forceTweaker,  _maxSteeringForce,  _maxSpeed,  _vehicleMass,  _maxTurnRate);
		SetSteeringBehaviourWeights( _separationWeight, _alignmentWeight,  _cohesionWeight, _obstacleAvoidanceWeight,  _wallAvoidanceWeight, _wanderWeight,  _seekWeight, _fleeWeight, _arriveWeight, _pursuitWeight, _offsetPursuitWeight, _interposeWeight, _hideWeight,  _evadeWeight,  _followPathWeight);
		SetSteeringBehaviourProbability( _wallAvoidanceProbability,  _obstacleAvoidanceProbability,  _separationProbability,  _alignmentProbability,  _cohesionProbability,  _wanderProbability, _seekProbability, _fleeProbability,  _evadeProbability,  _hideProbability, _arriveProbability);
	}



	void SetSteeringBehaviourProbability(float _wallAvoidanceProbability,float _obstacleAvoidanceProbability,float _separationProbability,float _alignmentProbability,float _cohesionProbability,float _wanderProbability,float _seekProbability,float _fleeProbability,float _evadeProbability, float _hideProbability, float _arriveProbability) {
		m_WallAvoidanceProbability = _wallAvoidanceProbability;
		m_ObstacleAvoidanceProbability = _obstacleAvoidanceProbability;
		m_SeparationProbability = _separationProbability;
		m_AlignmentProbability = _alignmentProbability;
		m_CohesionProbability = _cohesionProbability;
		m_WanderProbability = _wanderProbability;
		m_SeekProbability = _seekProbability;
		m_FleeProbability = _fleeProbability;
		m_EvadeProbability = _evadeProbability;
		m_HideProbability = _hideProbability;
		m_ArriveProbability = _arriveProbability;
	}



	void SetSteeringBehaviourWeights(float _separationWeight, float _alignmentWeight,float _cohesionWeight,float _obstacleAvoidanceWeight,float _wallAvoidanceWeight,float _wanderWeight,float _seekWeight,float _fleeWeight,float _arriveWeight,float _pursuitWeight,float _offsetPursuitWeight,float _interposeWeight,float _hideWeight,float _evadeWeight,float _followPathWeight) {
			m_SeparationWeight = _separationWeight;
			m_AlignmentWeight = _alignmentWeight;
			m_CohesionWeight = _cohesionWeight;
			m_ObstacleAvoidanceWeight = _obstacleAvoidanceWeight;
			m_WallAvoidanceWeight = _wallAvoidanceWeight;
			m_WanderWeight = _wanderWeight;
			m_SeekWeight = _seekWeight;
			m_FleeWeight = _fleeWeight;
			m_ArriveWeight = _arriveWeight;
			m_PursuitWeight = _pursuitWeight;
			m_OffsetPursuitWeight = _offsetPursuitWeight;
			m_InterposeWeight = _interposeWeight;
			m_HideWeight = _hideWeight;
			m_EvadeWeight = _evadeWeight;
			m_FollowPathWeight = _followPathWeight;
	}

	void SetSteeringBehaviour(float _minDetectionBoxLength,float _wallDetectionFeelerLength, float _minObstacleRadius,float _maxObstacleRadius,float _forceTweaker,float _maxSteeringForce,float _maxSpeed,float _vehicleMass,float _maxTurnRate) {
		m_MinDetectionBoxLength = _minDetectionBoxLength;
		m_WallDetectionFeelerLength = _wallDetectionFeelerLength;
		m_MinObstacleRadius = _minObstacleRadius;
		m_MaxObstacleRadius = _maxObstacleRadius;
		m_ForceTweaker = _forceTweaker;
		m_MaxSteeringForce = _maxSteeringForce;
		m_MaxSpeed = _maxSpeed;
		m_VehicleMass = _vehicleMass;
		m_MaxTurnRate = _maxTurnRate;
	}

	float GetMinObstacleRadius() { return m_MinObstacleRadius; }
	float GetMaxObstacleRadius() { return m_MaxObstacleRadius; }
	float GetForceTweaker() { return m_ForceTweaker; }
	float GetMaxSteeringForce() { return m_MaxSteeringForce * m_ForceTweaker; }
	float GetMaxSpeed() { return m_MaxSpeed; }
	float GetVehicleMass() { return m_VehicleMass; }
	float GetMaxTurnRate() { return m_MaxTurnRate; }
	
	float GetSeparationWeight() { return m_SeparationWeight * m_ForceTweaker; }
	float GetAlignmentWeight() { return m_AlignmentWeight * m_ForceTweaker; }
	float GetCohesionWeight(){return m_CohesionWeight * m_ForceTweaker;}
	float GetObstacleAvoidanceWeight(){return m_ObstacleAvoidanceWeight * m_ForceTweaker;}
	float GetWallAvoidanceWeight(){return m_WallAvoidanceWeight * m_ForceTweaker;}
	float GetWanderWeight(){return m_WanderWeight * m_ForceTweaker;}
	float GetSeekWeight(){return m_SeekWeight * m_ForceTweaker;}
	float GetFleeWeight(){return m_FleeWeight * m_ForceTweaker;}
	float GetArriveWeight(){return m_ArriveWeight * m_ForceTweaker;}
	float GetPursuitWeight(){return m_PursuitWeight * m_ForceTweaker;}
	float GetOffsetPursuitWeight(){return m_OffsetPursuitWeight * m_ForceTweaker;}
	float GetInterposeWeight(){return m_InterposeWeight * m_ForceTweaker;}
	float GetHideWeight(){return m_HideWeight * m_ForceTweaker;}
	float GetEvadeWeight(){return m_EvadeWeight * m_ForceTweaker;}
	float GetFollowPathWeight() {return m_FollowPathWeight * m_ForceTweaker;}

	float GetMinDetectionBoxLength() {return m_MinDetectionBoxLength;}
	float GetWallDetectionFeelerLength() { return m_WallDetectionFeelerLength; }

	float GetWallAvoidanceProbability() { return m_WallAvoidanceProbability; }
	float GetObstacleAvoidanceProbability(){return m_ObstacleAvoidanceProbability;}
	float GetSeparationProbability() { return m_SeparationProbability ;}
	float GetAlignmentProbability() { return m_AlignmentProbability ;}
	float GetCohesionProbability() { return m_CohesionProbability ;}
	float GetWanderProbability() { return m_WanderProbability ;}
	float GetSeekProbability() { return m_SeekProbability ;}
	float GetFleeProbability() { return m_FleeProbability ;}
	float GetEvadeProbability() { return m_EvadeProbability ;}
	float GetHideProbability() { return m_HideProbability ;}
	float GetArriveProbability() { return m_ArriveProbability; }



	void SetMinObstacleRadius(float& _val) { m_MinObstacleRadius = _val;}
	void SetMaxObstacleRadius(float& _val) { m_MaxObstacleRadius = _val;}
	void SetForceTweaker(float& _val) { m_ForceTweaker = _val;}
	void SetMaxSteeringForce(float& _val) { m_MaxSteeringForce = _val;}
	void SetMaxSpeed(float& _val) { m_MaxSpeed = _val;}
	void SetVehicleMass(float& _val) { m_VehicleMass = _val;}
	void SetMaxTurnRate(float& _val) { m_MaxTurnRate = _val; }

	void SetSeparationWeight(float& _val) { m_SeparationWeight = _val;}
	void SetAlignmentWeight(float& _val) { m_AlignmentWeight = _val;}
	void SetCohesionWeight(float& _val) { m_CohesionWeight = _val;}
	void SetObstacleAvoidanceWeight(float& _val) { m_ObstacleAvoidanceWeight = _val;}
	void SetWallAvoidanceWeight(float& _val) { m_WallAvoidanceWeight = _val;}
	void SetWanderWeight(float& _val) { m_WanderWeight = _val;}
	void SetSeekWeight(float& _val) { m_SeekWeight = _val;}
	void SetFleeWeight(float& _val) { m_FleeWeight = _val;}
	void SetArriveWeight(float& _val) { m_ArriveWeight = _val;}
	void SetPursuitWeight(float& _val) { m_PursuitWeight = _val;}
	void SetOffsetPursuitWeight(float& _val) { m_OffsetPursuitWeight = _val;}
	void SetInterposeWeight(float& _val) { m_InterposeWeight = _val;}
	void SetHideWeight(float& _val) { m_HideWeight = _val;}
	void SetEvadeWeight(float& _val) { m_EvadeWeight = _val;}
	void SetFollowPathWeight(float& _val) { m_FollowPathWeight = _val; }

	void SetMinDetectionBoxLength(float& _val) { m_MinDetectionBoxLength = _val;}
	void SetWallDetectionFeelerLength(float& _val) { m_WallDetectionFeelerLength = _val; }

	void SetWallAvoidanceProbability(float& _val) { m_WallAvoidanceProbability = _val;}
	void SetObstacleAvoidanceProbability(float& _val) { m_ObstacleAvoidanceProbability = _val;}
	void SetSeparationProbability(float& _val) { m_SeparationProbability = _val;}
	void SetAlignmentProbability(float& _val) { m_AlignmentProbability = _val;}
	void SetCohesionProbability(float& _val) { m_CohesionProbability = _val;}
	void SetWanderProbability(float& _val) { m_WanderProbability = _val;}
	void SetSeekProbability(float& _val) { m_SeekProbability = _val;}
	void SetFleeProbability(float& _val) { m_FleeProbability = _val;}
	void SetEvadeProbability(float& _val) { m_EvadeProbability = _val;}
	void SetHideProbability(float& _val) { m_HideProbability = _val;}
	void SetArriveProbability(float& _val) { m_ArriveProbability = _val; }

private:
	float m_MinObstacleRadius;
	float m_MaxObstacleRadius;

	//This tweaker affects all the steering force multipliers
	float m_ForceTweaker;

	float m_MaxSteeringForce;
	float m_MaxSpeed;
	float m_VehicleMass;
	float m_MaxTurnRate;





	float m_SeparationWeight;
	float m_AlignmentWeight;
	float m_CohesionWeight;
	float m_ObstacleAvoidanceWeight;
	float m_WallAvoidanceWeight;
	float m_WanderWeight;
	float m_SeekWeight;
	float m_FleeWeight;
	float m_ArriveWeight;
	float m_PursuitWeight;
	float m_OffsetPursuitWeight;
	float m_InterposeWeight;
	float m_HideWeight;
	float m_EvadeWeight;
	float m_FollowPathWeight;

	float m_MinDetectionBoxLength;//obstacle avoidance 
	float m_WallDetectionFeelerLength;//wall Avoidance

	//these are the probabilities that a steering behavior will be used
  //when the prioritized dither calculate method is used
	float m_WallAvoidanceProbability;
	float m_ObstacleAvoidanceProbability;
	float m_SeparationProbability;
	float m_AlignmentProbability;
	float m_CohesionProbability;
	float m_WanderProbability;
	float m_SeekProbability;
	float m_FleeProbability;
	float m_EvadeProbability;
	float m_HideProbability;
	float m_ArriveProbability;
};
#pragma endregion


class FootballParameters
{
public:
	FootballParameters() {}



	int   NumSupportSpotsX;
	int   NumSupportSpotsY;

	//these values tweak the various rules used to calculate the support spots
	double Spot_PassSafeScore;
	double Spot_CanScoreFromPositionScore;
	double Spot_DistFromControllingPlayerScore;
	double Spot_ClosenessToSupportingPlayerScore;
	double Spot_AheadOfAttackerScore;

	double SupportSpotUpdateFreq;

	double ChancePlayerAttemptsPotShot;
	double ChanceOfUsingArriveTypeReceiveBehavior;

	double KeeperInBallRange;
	double KeeperInBallRangeSq;

	double PlayerInTargetRange;
	double PlayerInTargetRangeSq;


	//max steering force
	double PlayerMaxForce;
	double PlayerMaxSpeedWithBall;
	double PlayerMaxSpeedWithoutBall;
	double PlayerMaxTurnRate;
	double PlayerScale;
	double PlayerComfortZone;

	double PlayerKickingDistance;
	double PlayerKickingDistanceSq;

	double PlayerKickFrequency;

	double  MaxDribbleForce;
	double  MaxShootingForce;
	double  MaxPassingForce;

	double  PlayerComfortZoneSq;

	//in the range zero to 1.0. adjusts the amount of noise added to a kick,
	//the lower the value the worse the players get
	double  PlayerKickingAccuracy;

	//the number of times the SoccerTeam::CanShoot method attempts to find
	//a valid shot
	int    NumAttemptsToFindValidStrike;

	//the distance away from the center of its home region a player
	//must be to be considered at home
	double WithinRangeOfHome;

	//how close a player must get to a sweet spot before he can change state
	double WithinRangeOfSupportSpot;
	double WithinRangeOfSupportSpotSq;


	//the minimum distance a receiving player must be from the passing player
	double   MinPassDist;
	double   GoalkeeperMinPassDist;

	//this is the distance the keeper puts between the back of the net
	//and the ball when using the interpose steering behavior
	double  GoalKeeperTendingDistance;

	//when the ball becomes within this distance of the goalkeeper he
	//changes state to intercept the ball
	double  GoalKeeperInterceptRange;
	double  GoalKeeperInterceptRangeSq;

	//how close the ball must be to a receiver before he starts chasing it
	double  BallWithinReceivingRange;
	double  BallWithinReceivingRangeSq;


private:
	
};





class FootballGameParameters
{
public:
	static FootballGameParameters* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new FootballGameParameters();
		}
		return m_Instance;
	}

private:
	static FootballGameParameters* m_Instance;
FootballGameParameters(){}

double BallSize;
double BallMass;
double Friction;
double GoalWidth;

};

