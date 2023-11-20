#pragma once
#include "VehicleAgent.h"
#include "State.h"
#include "FootballTeam.h"


class Ball;

enum Position
{
	GOALKEEPER,
	DEFENDER,
	MIDFIELDER,
	EGOIST
};

class FootballPlayer : public VehicleAgent
{
public:
	FootballPlayer(FootballTeam* _homeTeam, int _homeRegion, Vector2 _heading, Vector2 _velocity,  FootballParameters* _FootballParams, float _scale, Position _playerPosition);
	virtual ~FootballPlayer();

	void UpdateGameObject(float _deltaTime) override;
	void Render()override;//remove override and implement in base class if there's a base class called SteeringGameObject (a base class GO that moves)

	//a ball doesnt need to handle messages
	bool HandleMessage(const Telegram& _msg)override { return false; }

	bool CanPassForward();
	bool CanPassBackward();
	bool IsBeingPressured();
	bool BallWithinKickingRange()const;
	bool BallWithinKeeperRange()const;
	bool BallWithinReceivingRange()const;
	bool InHomeRegion()const;
	bool IsWithinSupportSpotRange()const;
	bool IsWithinTargetRange()const;
	bool IsClosestTeamMemberToBall()const;
	bool IsClosestPlayerOnPitchToBall()const;
	bool AtTarget()const;
	bool IsPossessingPlayer()const;
	bool InHomeRegion()const;
	bool IsAheadOfAttacker()const;
	bool PositionInFrontOfPlayer(Vector2 _position)const;
	bool NextToOppGoal();

	void TrackBall();//rotates the player to face the ball 
	void TrackTarget();//rotates the player to face the target 

	class FootballPitch* GetFootballPitch();

	void SetDefaultHomeRegion();

	Ball* const GetFootball()const;

	void FindSupport()const;

	class FootballTeam* GetTeam();

	Position PlayerPosition()const { return m_PlayerPosition; }

	float DistSqToBall()const { return m_DistSqToBall; }
	void SetDistSqToBall(float _val) { m_DistSqToBall = _val; }

	float DistToOppGoal()const;
	float DistToHomeGoal()const;

	void SetDefaultHomeRegion() { m_HomeRegion = m_DefaultRegion; }

	const Region* const HomeRegion();


protected:
	class FootballTeam* m_Team;
	int m_HomeRegion;
	Position m_PlayerPosition;
	int m_HomeRegion;
	int m_DefaultRegion;
	float m_DistSqToBall;



private:

};
