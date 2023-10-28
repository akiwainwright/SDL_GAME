#include "FootballFieldPlayer.h"
#include "FieldPlayerStates.h"


FootballFieldPlayer::FootballFieldPlayer(FootbalTeam* _homeTeam, int _homeRegion, State<FootballFieldPlayer>* _startState, Vector2 _heading, Vector2 _velocity, SteeringBehaviours* _SteeringBehaviours, FootballParameters* _FootballParams, float _scale, Position _playerPosition)
{
	m_StateMachine = new StateMachine<FootballFieldPlayer>(this);
	if (_startState)
	{
		m_StateMachine->SetStartState(_startState);
		m_StateMachine->SetGlobalState(GlobalFieldPlayerState::Instance());
		m_StateMachine->CurrentState()->Enter(this);
	}

	//activate separation for players

	//set kick frequency
}

FootballFieldPlayer::~FootballFieldPlayer()
{
}

void FootballFieldPlayer::UpdateGameObject(float _deltaTime)
{
	FootballPlayer::UpdateGameObject(_deltaTime);

	m_StateMachine->UpdateState();

	//steering behaviour calculate

}

void FootballFieldPlayer::Render()
{
}

bool FootballFieldPlayer::BallWithinRangeForIntercept() const
{
	return false;
}

bool FootballFieldPlayer::FarFromGoal() const
{
	return false;
}

bool FootballFieldPlayer::IsReadyForNextKick() const
{
	return false;
}
