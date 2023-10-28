#pragma once
#include "CustomMaths.h"
#include "State.h"



class FootballPlayer;
class FootballFieldPlayer;
class FootballGoal;
class FootballGoalKeeper;
class FootballPitch;

class SupportSpotCalculator
{

	struct SupportSpot
	{
		Vector2 m_Pos;
		float m_Score;
		SupportSpot(Vector2 _pos, float _val) : m_Pos(_pos), m_Score(_val) {}
	};

	class FootballTeam* m_Team;
	vector<SupportSpot> m_Spots;

	SupportSpot* m_BestSupportingSpot;
public:
	SupportSpotCalculator(int _numX,int _numY, FootballTeam* _team);
	~SupportSpotCalculator();


	void Render()const;

	Vector2 DetermineBestSupportSpot();

	Vector2 GetBestSupportSpot();

};
enum Team
{
	ARSENAL,
	MANCITY,
	UBER,
	BASTARD_MUNCHEN,
	MANSHINE_CITY
};

class FootballTeam : public Actor
{
public:
	FootballTeam( FootballGoal* _homeGoal,  FootballGoal* _oppGoal);
	~FootballTeam();

	//this is the update fuction that will be called from the game class
	void Update(float _deltaTime)override;
	void Render() override {}
	bool HandleMessage(const Telegram& _msg) override { return false; }


	bool CanShoot(Vector2 _ballPos, float _power,const Vector2& _shotTarget= Vector2(0.0f,0.0f))const;
	bool FindPass(const  FootballPlayer* const _passer, FootballPlayer*& _receiver,
	Vector2&  _passTarget, float _power, float _minPassingDistance
	)const;
	bool GetBestPassToReceiver(const  FootballPlayer* const _passer, const  FootballPlayer* const _receiver, Vector2& _passTarget, const float _power)const;
	bool IsPassSafeFromOpponent(Vector2 _from, Vector2 _target, const  FootballPlayer* const _receiver, const FootballPlayer* const _opp, float _passingForce);
	bool IsPassSafeFromAllOpponents(Vector2 _from, Vector2 _target, const  FootballPlayer* const _receiver, float _passingForce)const;
	bool IsOpponentWithinRadius(Vector2 _pos, float _rad);
	
	void RequestPass( FootballFieldPlayer* _requester)const;
	class FootballPlayer* DetermineBestSupportingPlayer();
	const vector< FootballPlayer*>& Members()const { return m_Players; }
	StateMachine<FootballTeam>*  GetStateMachine() { return m_StateMachine; }

	FootballGoal* const HomeGoal()const { return m_HomeGoal; }
	FootballGoal* const OppGoal() const { return m_OpponentsGoal; }
	FootballPitch* const GetPitch() { return m_Pitch; }
	FootballTeam* const Opponents() const { return m_Opponents; }
	void SetOpponents(FootballTeam* _opps) { m_Opponents = _opps; }


	Vector2 GetSupportSpot()const { return m_SupportsSpotCalc->GetBestSupportSpot(); }
	bool InPossession()const { if (m_PlayerInPossession)return true; return false; }
	void LostPossession() { m_PlayerInPossession = nullptr; }
	FootballPlayer* Receiver() { return m_ReceivingPlayer; }
	FootballPlayer* PlayerInPossession() { return m_PlayerInPossession; }
	FootballPlayer* PlayerClosestToBall() { return m_PlayerClosestToBall; }
	void SetReceiver(FootballPlayer* _receiver) { m_ReceivingPlayer = _receiver; }
	void SetControllingPlayer(FootballPlayer* _player) {
		m_PlayerInPossession = _player; 
		m_Opponents->LostPossession();
	}
	void SetPlayerClosestToBall(FootballPlayer* _player) { m_PlayerClosestToBall = _player; }

	FootballPlayer* SupportingPlayer()const { return m_SupportingPlayer; }
	void SetSupportingPlayer(FootballPlayer* _player) { m_SupportingPlayer = _player; }

	void ReturnAllFieldPlayersToHome()const;


	FootballPlayer* GetPlayer(const string& _name)const;//search the players
	//set each playyers home region on the grid map 

	void GetBestSupportingPosition()const { m_SupportsSpotCalc->DetermineBestSupportSpot(); }

	void UpdateTargetsOfWaitingPlayer()const;

	bool AllPlayersAtHome()const;

	void UpdateTargetsOfWaitingPlayers()const;

	Team GetTeamName() { return m_Team; }

	void SetPlayerHomeRegion(FootballPlayer* _player, int _region)const;

	bool AllPlayersAtHome()const;

private:
	bool m_GameOn;
	bool m_GoalKeeperHasBall;
	StateMachine<FootballTeam>* m_StateMachine;
	FootballGoalKeeper* m_GoalKeeper;
	vector<FootballPlayer*> m_Players;

	 FootballPlayer* m_ReceivingPlayer;
	 FootballPlayer* m_PlayerClosestToBall;
	 FootballPlayer* m_PlayerInPossession;
	 FootballPlayer* m_SupportingPlayer;

	 FootballPitch* m_Pitch;

	 FootballGoal* m_OpponentsGoal;
	 FootballGoal* m_HomeGoal;

	FootballTeam* m_Opponents;

	float m_DistSqToBallOfClosestPlayer;

	SupportSpotCalculator* m_SupportsSpotCalc;


	void CreatePlayers();

	void CalculateClosestPlayerToBall();

	Team m_Team;

};


