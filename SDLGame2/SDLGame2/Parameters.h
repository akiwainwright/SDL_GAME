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
		m_WanderRadius = -1.0f;
		m_WanderDistance = -1.0f;
		m_WanderJitter = -1.0f;
		m_BoxLength = -1.0f;
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

	SteeringVehicleParameter(float _wanderRadius, float _wanderDistance, float _wanderJitter, float _boxLength, float _minDetectionBoxLength,float _wallDetectionFeelerLength, float _minObstacleRadius, float _maxObstacleRadius, float _forceTweaker, float _maxSteeringForce, float _maxSpeed, float _vehicleMass, float _maxTurnRate, float _separationWeight, float _alignmentWeight, float _cohesionWeight, float _obstacleAvoidanceWeight, float _wallAvoidanceWeight, float _wanderWeight, float _seekWeight, float _fleeWeight, float _arriveWeight, float _pursuitWeight, float _offsetPursuitWeight, float _interposeWeight, float _hideWeight, float _evadeWeight, float _followPathWeight, float _wallAvoidanceProbability, float _obstacleAvoidanceProbability,float _separationProbability, float _alignmentProbability, float _cohesionProbability, float _wanderProbability, float _seekProbability, float _fleeProbability, float _evadeProbability, float _hideProbability, float _arriveProbability) {
		SetSteeringBehaviour(_wanderRadius,  _wanderDistance,  _wanderJitter,  _boxLength, _minDetectionBoxLength,  _wallDetectionFeelerLength,  _minObstacleRadius,  _maxObstacleRadius,  _forceTweaker,  _maxSteeringForce,  _maxSpeed,  _vehicleMass,  _maxTurnRate);
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

	void SetSteeringBehaviour(float _wanderRadius, float _wanderDistance, float _wanderJitter, float _boxLength, float _minDetectionBoxLength,float _wallDetectionFeelerLength, float _minObstacleRadius,float _maxObstacleRadius,float _forceTweaker,float _maxSteeringForce,float _maxSpeed,float _vehicleMass,float _maxTurnRate) {
		m_WanderRadius = _wanderRadius;
		m_WanderDistance = _wanderDistance;
		m_WanderJitter = _wanderJitter;
		m_BoxLength = _boxLength;
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

	float GetWanderRadius(){return m_WanderRadius;}
	float GetWanderDistance() { return m_WanderDistance;}
	float GetWanderJitter() { return m_WanderJitter;}
	float GetBoxLength() { return m_BoxLength; }

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


	void SetWanderRadius(float& _val) { m_WanderRadius = _val; }
	void SetWanderDistance(float& _val) { m_WanderDistance = _val; }
	void SetWanderJitter(float& _val) { m_WanderJitter = _val; }
	void SetBoxLength(float& _val) { m_BoxLength = _val; }
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

	float m_WanderRadius;
	float m_WanderDistance;
	float m_WanderJitter;

	float m_BoxLength;
	//float m_WallDetectorLength;

	float m_MinDetectionBoxLength;//obstacle avoidance 
	float m_WallDetectionFeelerLength;//wall Avoidance

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


class FootballPlayerParameters
{
public:
	FootballPlayerParameters() {}

	int GetNumSupportSpotsX(){return m_NumSupportSpotsX;}
	int GetNumSupportSpotsY() { return m_NumSupportSpotsY; }
	void SetNumSupportSpotsX(int& _val){ m_NumSupportSpotsX = _val;}
	void SetNumSupportSpotsY(int& _val) { m_NumSupportSpotsY = _val; }


	void SetSpotPassSafeScore(float& _val){ m_SpotPassSafeScore = _val;}
	void SetSpotCanScoreFromPositionScore(float& _val) { m_SpotCanScoreFromPositionScore = _val;}
	void SetSpotDistFromControllingPlayerScore(float& _val) { m_SpotDistFromControllingPlayerScore = _val;}
	void SetSpotClosenessToSupportingPlayerScore(float& _val) { m_SpotClosenessToSupportingPlayerScore = _val;}
	void SetSpotAheadOfAttackerScore(float& _val) { m_SpotAheadOfAttackerScore = _val;}
	void SetSupportSpotUpdateFreq(float& _val) { m_SupportSpotUpdateFreq = _val;}
	void SetChancePlayerAttemptsPotShot(float& _val) { m_ChancePlayerAttemptsPotShot = _val;}
	void SetChanceOfUsingArriveTypeReceiveBehavior(float& _val) { m_ChanceOfUsingArriveTypeReceiveBehavior = _val;}
	void SetKeeperInBallRange(float& _val) { m_KeeperInBallRange = _val;}
	void SetKeeperInBallRangeSq(float& _val) { m_KeeperInBallRangeSq = _val;}
	void SetPlayerInTargetRange(float& _val) { m_PlayerInTargetRange = _val;}
	void SetPlayerInTargetRangeSq(float& _val) { m_PlayerInTargetRangeSq = _val;}
	void SetPlayerMaxSpeedWithBall(float& _val) { m_PlayerMaxSpeedWithBall = _val;}
	void SetPlayerMaxSpeedWithoutBall(float& _val) { m_PlayerMaxSpeedWithoutBall = _val;}
	void SetPlayerMaxTurnRate(float& _val) { m_PlayerMaxTurnRate = _val;}
	void SetPlayerComfortZone(float& _val) { m_PlayerComfortZone = _val;}
	void SetPlayerKickingDistance(float& _val) { m_PlayerKickingDistance = _val;}
	void SetPlayerKickingDistanceSq(float& _val) { m_PlayerKickingDistanceSq = _val;}
	void SetPlayerKickFrequency(float& _val) { m_PlayerKickFrequency = _val;}
	void SetMaxDribbleForce(float& _val) { m_MaxDribbleForce = _val;}
	void SetMaxShootingForce(float& _val) { m_MaxShootingForce = _val;}
	void SetMaxPassingForce(float& _val) { m_MaxPassingForce = _val;}
	void SetPlayerComfortZoneSq(float& _val) { m_PlayerComfortZoneSq = _val;}
	void SetPlayerKickingAccuracy(float& _val) { m_PlayerKickingAccuracy = _val;}
	void SetNumAttemptsToFindValidStrike(int& _val) { m_NumAttemptsToFindValidStrike = _val;}
	void SetWithinRangeOfHome(float& _val) { m_WithinRangeOfHome = _val;}
	void SetWithinRangeOfSupportSpot(float& _val) { m_WithinRangeOfSupportSpot = _val;}
	void SetWithinRangeOfSupportSpotSq(float& _val) { m_WithinRangeOfSupportSpotSq = _val;}
	void SetMinPassDist(float& _val) { m_MinPassDist = _val;}
	void SetGoalkeeperMinPassDist(float& _val) { m_GoalkeeperMinPassDist = _val;}
	void SetGoalKeeperTendingDistance(float& _val) { m_GoalKeeperTendingDistance = _val;}
	void SetGoalKeeperInterceptRange(float& _val) { m_GoalKeeperInterceptRange = _val;}
	void SetGoalKeeperInterceptRangeSq(float& _val) { m_GoalKeeperInterceptRangeSq = _val;}
	void SetBallWithinReceivingRange(float& _val) { m_BallWithinReceivingRange = _val;}
	void SetBallWithinReceivingRangeSq(float& _val) { m_BallWithinReceivingRangeSq = _val; }


	float& GetSpotPassSafeScore(){ return m_SpotPassSafeScore; }
	float& GetSpotCanScoreFromPositionScore() { return m_SpotCanScoreFromPositionScore; }
	float& GetSpotDistFromControllingPlayerScore() { return m_SpotDistFromControllingPlayerScore; }
	float& GetSpotClosenessToSupportingPlayerScore() { return m_SpotClosenessToSupportingPlayerScore; }
	float& GetSpotAheadOfAttackerScore() { return m_SpotAheadOfAttackerScore; }
	float& GetSupportSpotUpdateFreq() { return m_SupportSpotUpdateFreq; }
	float& GetChancePlayerAttemptsPotShot() { return m_ChancePlayerAttemptsPotShot; }
	float& GetChanceOfUsingArriveTypeReceiveBehavior() { return m_ChanceOfUsingArriveTypeReceiveBehavior; }
	float& GetKeeperInBallRange() { return m_KeeperInBallRange; }
	float& GetKeeperInBallRangeSq() { return m_KeeperInBallRangeSq; }
	float& GetPlayerInTargetRange() { return m_PlayerInTargetRange; }
	float& GetPlayerInTargetRangeSq() { return m_PlayerInTargetRangeSq; }
	float& GetPlayerMaxSpeedWithBall() { return m_PlayerMaxSpeedWithBall; }
	float& GetPlayerMaxSpeedWithoutBall() { return m_PlayerMaxSpeedWithoutBall; }
	float& GetPlayerMaxTurnRate() { return m_PlayerMaxTurnRate; }
	float& GetPlayerComfortZone() { return m_PlayerComfortZone; }
	float& GetPlayerKickingDistance() { return m_PlayerKickingDistance; }
	float& GetPlayerKickingDistanceSq() { return m_PlayerKickingDistanceSq; }
	float& GetPlayerKickFrequency() { return m_PlayerKickFrequency; }
	float& GetMaxDribbleForce() { return m_MaxDribbleForce; }
	float& GetMaxShootingForce() { return m_MaxShootingForce; }
	float& GetMaxPassingForce() { return m_MaxPassingForce; }
	float& GetPlayerComfortZoneSq() { return m_PlayerComfortZoneSq; }
	float& GetPlayerKickingAccuracy() { return m_PlayerKickingAccuracy; }
	int  & GetNumAttemptsToFindValidStrike() { return m_NumAttemptsToFindValidStrike; }
	float& GetWithinRangeOfHome() { return m_WithinRangeOfHome; }
	float& GetWithinRangeOfSupportSpot() { return m_WithinRangeOfSupportSpot; }
	float& GetWithinRangeOfSupportSpotSq() { return m_WithinRangeOfSupportSpotSq; }
	float& GetMinPassDist() { return m_MinPassDist; }
	float& GetGoalkeeperMinPassDist() { return m_GoalkeeperMinPassDist; }
	float& GetGoalKeeperTendingDistance() { return m_GoalKeeperTendingDistance; }
	float& GetGoalKeeperInterceptRange() { return m_GoalKeeperInterceptRange; }
	float& GetGoalKeeperInterceptRangeSq() { return m_GoalKeeperInterceptRangeSq; }
	float& GetBallWithinReceivingRange() { return m_BallWithinReceivingRange; }
	float& GetBallWithinReceivingRangeSq() { return m_BallWithinReceivingRangeSq; }

	private:

	int   m_NumSupportSpotsX;
	int   m_NumSupportSpotsY;

	//these values tweak the various rules used to calculate the support spots
	float m_SpotPassSafeScore;
	float m_SpotCanScoreFromPositionScore;
	float m_SpotDistFromControllingPlayerScore;
	float m_SpotClosenessToSupportingPlayerScore;
	float m_SpotAheadOfAttackerScore;

	float m_SupportSpotUpdateFreq;

	float m_ChancePlayerAttemptsPotShot;
	float m_ChanceOfUsingArriveTypeReceiveBehavior;

	float m_KeeperInBallRange;
	float m_KeeperInBallRangeSq;

	float m_PlayerInTargetRange;
	float m_PlayerInTargetRangeSq;


	//max steering force
	float m_PlayerMaxSpeedWithBall;
	float m_PlayerMaxSpeedWithoutBall;
	float m_PlayerMaxTurnRate;
	float m_PlayerComfortZone;

	float m_PlayerKickingDistance;
	float m_PlayerKickingDistanceSq;

	float m_PlayerKickFrequency;

	float  m_MaxDribbleForce;
	float  m_MaxShootingForce;
	float  m_MaxPassingForce;

	float  m_PlayerComfortZoneSq;

	//in the range zero to 1.0. adjusts the amount of noise added to a kick,
	//the lower the value the worse the players get
	float  m_PlayerKickingAccuracy;

	//the number of times the SoccerTeam::CanShoot method attempts to find
	//a valid shot
	int    m_NumAttemptsToFindValidStrike;

	//the distance away from the center of its home region a player
	//must be to be considered at home
	float m_WithinRangeOfHome;

	//how close a player must get to a sweet spot before he can change state
	float m_WithinRangeOfSupportSpot;
	float m_WithinRangeOfSupportSpotSq;


	//the minimum distance a receiving player must be from the passing player
	float m_MinPassDist;
	float m_GoalkeeperMinPassDist;

	//this is the distance the keeper puts between the back of the net
	//and the ball when using the interpose steering behavior
	float  m_GoalKeeperTendingDistance;

	//when the ball becomes within this distance of the goalkeeper he
	//changes state to intercept the ball
	float  m_GoalKeeperInterceptRange;
	float  m_GoalKeeperInterceptRangeSq;

	//how close the ball must be to a receiver before he starts chasing it
	float  m_BallWithinReceivingRange;
	float  m_BallWithinReceivingRangeSq;

	
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

float m_BallSize;
float m_BallMass;
float m_Friction;
float m_GoalWidth;

};

