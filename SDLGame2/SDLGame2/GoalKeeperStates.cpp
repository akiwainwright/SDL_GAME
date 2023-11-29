#include "GoalKeeperStates.h"
#include "FootballGoalKeeper.h"
#include "VehicleAgent.h"
#include "Ball.h"
#include "FootballPitch.h"
#include "FootballTeam.h"



GlobalKeeperState* GlobalKeeperState::m_Instance = nullptr;
TendGoalState* TendGoalState::m_Instance = nullptr;
InterceptBallState* InterceptBallState::m_Instance = nullptr;
ReturnHomeState* ReturnHomeState::m_Instance = nullptr;
PutBallBackInPlayState* PutBallBackInPlayState::m_Instance = nullptr;


void GlobalKeeperState::Enter(FootballGoalKeeper* _agent)
{
}

void GlobalKeeperState::Execute(FootballGoalKeeper* _agent)
{
}

void GlobalKeeperState::Exit(FootballGoalKeeper* _agent)
{
}

bool GlobalKeeperState::OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram)
{
	switch (_telegram.m_Msg)
	{
	case MSG_GoHome:
	{
		_agent->SetDefaultHomeRegion();
		_agent->GetStateMachine()->ChangeState(ReturnHomeState::Instance());
		//return true;
	}
	break;

	case MSG_ReceiveBall:
	{
		_agent->GetStateMachine()->ChangeState(InterceptBallState::Instance());
		//return true;
	}

	default:
		break;
	}
	return false;
}


//----------------------------------------------------------------------------------------------------------------------

/// <summary>
/// This is the main state for the goalkeeper. When in this the keeper will move left and right across the goal mouth using the interpose steering
/// behaviour to put themself between the ball and the back of the net
/// if the ball comes within the goalkeeper range he moves out of the goalmouth to attempt to intercept it
/// 
/// </summary>
/// <param name="_agent"></param>
void TendGoalState::Enter(FootballGoalKeeper* _agent)
{
	//activate interpose
	_agent->GetSteering()->Interpose(true);
	_agent->SetTarget();
}

void TendGoalState::Execute(FootballGoalKeeper* _agent)
{
	//the rear interpose target will change as the ball's position changes so it must be updated each update-step
	_agent->SetTarget();

	//If the ball comes in range the keeper controls it and then change state to put the ball back in play
	if (_agent->BallWithinKeeperRange())
	{
		_agent->GetFootball()->Control();
		_agent->GetFootballPitch()->SetGoalKeeperHasBall(true);
		_agent->GetStateMachine()->ChangeState(PutBallBackInPlayState::Instance());
		return;
	}

	//if the ball is within a certain distance the goalkeeper goes to intercept it
	if (_agent->BallWithinRangeForIntercept() && !_agent->GetTeam()->InPossession())
	{
		_agent->GetStateMachine()->ChangeState(InterceptBallState::Instance());
	}

	//if the keeper has ventured too far away from the goal line and there is no threat toowards it, it should move back
	if (_agent->FarFromGoal() && _agent->GetTeam()->InPossession())
	{
		_agent->GetStateMachine()->ChangeState(ReturnHomeState::Instance());
		return;
	}
}

void TendGoalState::Exit(FootballGoalKeeper* _agent)
{
	//deactivate interpose
}

bool TendGoalState::OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram)
{
	return false;
}


//----------------------------------------------------------------------------------------------------------------------


void InterceptBallState::Enter(FootballGoalKeeper* _agent)
{
	//activate pursuit
}

void InterceptBallState::Execute(FootballGoalKeeper* _agent)
{
	//if the goalkeeper moves far away from the goal and is not the closest to the ball they should go back home
	if (_agent->FarFromGoal() && !_agent->IsClosestPlayerOnPitchToBall())
	{
		_agent->GetStateMachine()->ChangeState(ReturnHomeState::Instance());
		return;
	}

	//if the ball is in range of the goalkeeper they control it and put it back in play
	if (_agent->BallWithinKeeperRange())
	{
		_agent->GetFootball()->Control();
		_agent->GetFootballPitch()->SetGoalKeeperHasBall(true);
		_agent->GetStateMachine()->ChangeState(PutBallBackInPlayState::Instance());
		return;
	}

}

void InterceptBallState::Exit(FootballGoalKeeper* _agent)
{
	//deactivate pursuit
}

bool InterceptBallState::OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram)
{
	return false;
}


//----------------------------------------------------------------------------------------------------------------------


void ReturnHomeState::Enter(FootballGoalKeeper* _agent)
{
	//activate arrive
}

void ReturnHomeState::Execute(FootballGoalKeeper* _agent)
{
	_agent->SetTarget();
	if (_agent->InHomeRegion() || !_agent->GetTeam()->InPossession())
	{
		_agent->GetStateMachine()->ChangeState(TendGoalState::Instance());
	}
}

void ReturnHomeState::Exit(FootballGoalKeeper* _agent)
{
	// deactivate arrive
}

bool ReturnHomeState::OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram)
{
	return false;
}


//----------------------------------------------------------------------------------------------------------------------


void PutBallBackInPlayState::Enter(FootballGoalKeeper* _agent)
{
	_agent->GetTeam()->SetControllingPlayer(_agent);

	_agent->GetTeam()->Opponents()->ReturnAllFieldPlayersToHome();
	_agent->GetTeam()->ReturnAllFieldPlayersToHome();
}

void PutBallBackInPlayState::Execute(FootballGoalKeeper* _agent)
{
	FootballPlayer* receiver = nullptr;
	Vector2 ballTarget;

	if (_agent->GetTeam()->FindPass(_agent,receiver, ballTarget,10, 35))//create a parameter class and put the variable min passing force and goalkeeper min passing distance here
	{
		_agent->GetFootball()->Kick(Vector2::Normalized(ballTarget - _agent->GetFootball()->GetTransform()->m_Pos), 20);//create a parameter class and put the variable min passing force here
		_agent->GetFootballPitch()->SetGoalKeeperHasBall(false);

		MessageDispatcher::Instance()->DispatchMessage(0, _agent, receiver, MSG_ReceiveBall, &ballTarget);

		_agent->GetStateMachine()->ChangeState(TendGoalState::Instance());
		return;
	}

	_agent->SetVelocity(Vector2(0, 0));

}

void PutBallBackInPlayState::Exit(FootballGoalKeeper* _agent)
{
}

bool PutBallBackInPlayState::OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram)
{
	return false;
}
