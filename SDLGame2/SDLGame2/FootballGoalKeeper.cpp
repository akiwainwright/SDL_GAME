#include "FootballGoalKeeper.h"
#include "GoalKeeperStates.h"

FootballGoalKeeper::FootballGoalKeeper(FootballTeam* _homeTeam, int _homeRegion, State<FootballGoalKeeper>* _startState, Vector2 _heading, Vector2 _velocity, float _mass, float _maxForce, float _maxSpeed, float _maxTurnRate, float _scale) : FootballPlayer(_homeTeam, _homeRegion, _heading, _velocity, _mass, _maxForce, _maxSpeed, _maxTurnRate, _scale, FootballPlayer::GoalKeeper)
{
	m_StateMachine = new StateMachine<FootballGoalKeeper>(this);
	m_StateMachine->SetStartState(_startState);
	m_StateMachine->SetGlobalState(GlobalKeeperState::Instance());

	m_StateMachine->CurrentState()->Enter(this);
}

void FootballGoalKeeper::UpdateGameObject(float _deltaTime)
{
	FootballPlayer::UpdateGameObject(_deltaTime);//clean this 
	m_StateMachine->UpdateState();

	//calculate the steering force

}

void FootballGoalKeeper::Render()
{
}

bool FootballGoalKeeper::BallWithinRangeForIntercept() const
{
	return false;
}

bool FootballGoalKeeper::FarFromGoal() const
{
	return false;
}

Vector2 FootballGoalKeeper::GetRearInterposeTarget() const
{
	return Vector2();
}