#include "FieldPlayerStates.h"
#include "State.h"
#include "FootballTeam.h"
#include "Ball.h"
#include "Events.h"

GlobalFieldPlayerState* GlobalFieldPlayerState::m_Instance = nullptr;
ChaseBallState* ChaseBallState::m_Instance = nullptr;
DribbleState* DribbleState::m_Instance = nullptr;
KickBallState* KickBallState::m_Instance = nullptr;
ReceiveBallState* ReceiveBallState::m_Instance = nullptr;
SupportAttackerState* SupportAttackerState::m_Instance = nullptr;
ReturnToHomeRegionState* ReturnToHomeRegionState::m_Instance = nullptr;
WaitState* WaitState::m_Instance = nullptr;




void GlobalFieldPlayerState::Enter(FootballFieldPlayer* _agent)
{

}

void GlobalFieldPlayerState::Execute(FootballFieldPlayer* _agent)
{
	//if a playeris in possession and close to the ball, the speed reduces
	if (_agent->BallWithinReceivingRange() && _agent->IsPossessingPlayer())
	{
		//_agent->SetMaxSpeed();//create a class for parameter//maxspeed with ball
	}
	else
	{
		//_agent->SetMaxSpeed();//create a class for parameter//maxspeed without  ball
	}

}

void GlobalFieldPlayerState::Exit(FootballFieldPlayer* _agent)
{

}

bool GlobalFieldPlayerState::OnMessage(FootballFieldPlayer* _agent, const Telegram& _telegram)
{
	switch (_telegram.m_Msg)
	{
	case MSG_ReceiveBall:
	{
		_agent->SetTarget(*static_cast<Vector2*>(_telegram.m_ExtraInfo));
		_agent->GetStateMachine()->ChangeState(ReceiveBallState::Instance());
		return true;
	}
	break;

	case MSG_SupportAttacker:
	{
		//if player is already supporting then return
		if (_agent->GetStateMachine()->IsInState(*SupportAttackerState::Instance()))
		{
			return true;
		}

		//set the target to be in the best supporting position
		_agent->SetTarget(_agent->GetTeam()->GetSupportSpot());
		_agent->GetStateMachine()->ChangeState(SupportAttackerState::Instance());

		return true;
	}
	break;

	case MSG_Wait:
	{
		_agent->GetStateMachine()->ChangeState(WaitState::Instance());
		return true;
	}
	break;

	case MSG_GoHome:
	{
		_agent->SetDefaultHomeRegion();
		_agent->GetStateMachine()->ChangeState(ReturnToHomeRegionState::Instance());

		return true;

	}

	break;

	case MSG_PassToMe:
	{
		//This gets the position of the player requesting the pass
		FootballFieldPlayer* receiver = static_cast<FootballFieldPlayer*>(_telegram.m_ExtraInfo);

		//if the ball is not in kicking range or there's already a receiving player, this player cannot shoot or pass the ball to the player making the request
		if (_agent->GetTeam()->Receiver() != nullptr || _agent->BallWithinKickingRange())
		{
			cout << "Cannot kick the ball or receive" << endl;
			return true;

		}

		_agent->GetFootball()->Kick((receiver->GetTransform()->m_Pos - _agent->GetFootball()->GetTransform()->m_Pos), 50);//create a parameter class and put the variable max passing force here
		
		//this sends an event to let the receiver know a pass is coming
		MessageDispatcher::Instance()->DispatchMessage(0, _agent, receiver, MSG_ReceiveBall, &receiver->GetTransform()->m_Pos);

		_agent->GetStateMachine()->ChangeState(WaitState::Instance());

		//_agent-> //find support

		return true;

	}
	break;

	

	}
	return false;
}





void ChaseBallState::Enter(FootballFieldPlayer* _agent)
{
	//_agent->seek //activate seek
}

void ChaseBallState::Execute(FootballFieldPlayer* _agent)
{

	//if the ball is in kicking range, the player 
	if (_agent->BallWithinKickingRange())
	{
		_agent->GetStateMachine()->ChangeState(KickBallState::Instance());
		return;
	}

	//if the player is the closest to the ball then he should keep chasing it
	if (_agent->IsClosestTeamMemberToBall())
	{
		_agent->SetTarget(_agent->GetFootball()->GetTransform()->m_Pos);
		return;
	}

	//if the player is not the closest to the ball anymore, they should return back to their home region
	_agent->GetStateMachine()->ChangeState(ReturnToHomeRegionState::Instance());

}

void ChaseBallState::Exit(FootballFieldPlayer* _agent)
{
	//deactivate seek
}

bool ChaseBallState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}






void DribbleState::Enter(FootballFieldPlayer* _agent)
{
	_agent->GetTeam()->SetControllingPlayer(_agent);
}

void DribbleState::Execute(FootballFieldPlayer* _agent)
{

	float dot = Vector2::DotProduct( , _agent->m_Heading);//home goal facing dir 

	//if the ball is between the player and the home goal, the player needs to turn around with the ball by doing multiple small kicks and turns until the player is facing in the correct direction
	if (dot < 0)
	{
		//the player's heading is going to be rotated by a small amount (Pi/4) and then the ball will be kicked in that direction 
		Vector2 dir = _agent->m_Heading;

		//then calculate the sign (+/-) of the angle between the player heading and the facing direction of the goal so that the player rotates around in the correct direction 
		float angle = PI / 4.0f * -1.0f;//* home goal facing dir
		
		//rotate dir around origin
		dir = rotateVector2(dir, angle);

		//this value works well when the player is attempting to control the ball and turn at the same time

		_agent->GetFootball()->Kick(dir, 0.8f);//create a parameter class and put the variable turn dribbling force here

	}
	else //kick the ball down the field
	{
		_agent->GetFootball()->Kick( ,1.2f);//create a parameter class and put the variable max dribbling force here
	}


	_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());
	
	//adding logic to prevent the attacker from moving too far ahead of the supporting player.

}

void DribbleState::Exit(FootballFieldPlayer* _agent)
{
}

bool DribbleState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}






void KickBallState::Enter(FootballFieldPlayer* _agent)
{
	_agent->GetTeam()->SetControllingPlayer(_agent);
	
	//The player can only make so many kick attempts per second
	if (_agent->)//isReadyForNextKick
	{
		_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());

	}

}

void KickBallState::Execute(FootballFieldPlayer* _agent)
{
	//calculates the dot product of the vector pointing to the ball and the player's heading
	Vector2 toBall = _agent->GetFootball()->GetTransform()->m_Pos - _agent->GetTransform()->m_Pos;
	Vector2 normalizedToBall = Vector2::Normalized(toBall);
	float dot = Vector2::DotProduct(_agent->m_Heading, normalizedToBall);

	//cannot kick the ball if the goalkeeper is in possession or if it is behind the player or if there is already an assigned receiver. so just chase the ball
	if (_agent->GetTeam()->Receiver() != nullptr || dot < 0 || _agent)//goal keeper has the ball
	{
		_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());
		return;
	}

	/* Attempt a shot at the goal */

 //if a shot is possible, this vector will hold the position along the 
 //opponent's goal line the player should aim for.
	Vector2 ballTarget;

	//the dot product is used to adjust the shooting force. The more directly the ball is ahead the more forceful the kick
	float power = dot * 50;//create a parameter class and put the variable max shooting force here

	//if the player can score a goal from this position or if they should just kick the ball and the player will attempt to shoot
	if (_agent->GetTeam()->CanShoot(_agent->GetFootball()->GetTransform()->m_Pos, power, ballTarget)||RandFloat() < 10)//create a parameter class and put the variable chancePlayerAttemptsShot here
	{
		//Add some noise to the kick. The amount of noise can be adjusted by altering the kickaccuracy variable in the parameter class
		ballTarget = _agent->GetFootball()->AddNoiseToKick(_agent->GetFootball()->GetTransform()->m_Pos, ballTarget);

		Vector2 kickDirection = ballTarget - _agent->GetFootball()->GetTransform()->m_Pos;

		_agent->GetFootball()->Kick(kickDirection, power);

		_agent->GetStateMachine()->ChangeState(WaitState::Instance());
		_agent->FindSupport();

		return;
	}

	/* Attempt a pass to a player */

	FootballPlayer* receiver = nullptr;
	power = dot * 10;//create a parameter class and put the variable max passing force here
	if (_agent->IsBeingPressured() && _agent->GetTeam()->FindPass(_agent,receiver, ballTarget, power, 10))//create a parameter class and put the variable min passing distance here
	{
		ballTarget = _agent->GetFootball()->AddNoiseToKick(_agent->GetFootball()->GetTransform()->m_Pos, ballTarget);

		Vector2 kickDirection = ballTarget - _agent->GetFootball()->GetTransform()->m_Pos;

		_agent->GetFootball()->Kick(kickDirection, power);
		
		MessageDispatcher::Instance()->DispatchMessage(0, _agent, receiver, MSG_ReceiveBall, &ballTarget);

		_agent->GetStateMachine()->ChangeState(WaitState::Instance());

		_agent->FindSupport();

		return;

	}
	else //cannot shoot or pass, so dribble the ball
	{
		_agent->FindSupport();

		_agent->GetStateMachine()->ChangeState(DribbleState::Instance());
	}

}

void KickBallState::Exit(FootballFieldPlayer* _agent)
{
}

bool KickBallState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}






void ReceiveBallState::Enter(FootballFieldPlayer* _agent)
{
	//let the team know this player is receiving the ball
	_agent->GetTeam()->SetReceiver(_agent);

	_agent->GetTeam()->SetControllingPlayer(_agent);

	//there are 2 receive behaviour, one uses arrive to direct the receiver to the position sent by the passer in its telegram. The other uses the pursuit behaviour to pursue the ball
	//we choose between them depending on the probability (in the parameter class - ChanceOfUsingArriveBehaviour) of whethere or not an opposing player is close to the receiving player, and whether or not the receiving player
	//is in the opponents half

	const float passThreatRadius = 70.0f;
	if (_agent-> || )//in opp's region
	{
		//activate arrive
	}
	else
	{
		//activate pursuit

	}

}

void ReceiveBallState::Execute(FootballFieldPlayer* _agent)
{//if the ball comes close enough to the player or if their team loses control they should chase the ball
	if (_agent->BallWithinReceivingRange() || !_agent->GetTeam()->InPossession())
	{
		_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());
		return;

	}

	if (_agent->)//pursuit is activate
	{
		_agent->SetTarget(_agent->GetFootball()->GetTransform()->m_Pos);
	}

	if (_agent->AtTarget())
	{
		//deactivate pursuit
		//deactivate arrive
		_agent->TrackBall();
		_agent->SetVelocity(Vector2(0, 0));
	}

}

void ReceiveBallState::Exit(FootballFieldPlayer* _agent)
{
	//deactivate arrive
	//deactivate pursuit
	_agent->GetTeam()->SetReceiver(nullptr);
}

bool ReceiveBallState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}





void SupportAttackerState::Enter(FootballFieldPlayer* _agent)
{
	//activate arrive
	_agent->SetTarget(_agent->GetTeam()->GetSupportSpot());
}

void SupportAttackerState::Execute(FootballFieldPlayer* _agent)
{
	//if his team loses control, go back home
	if (_agent->GetTeam()->InPossession())
	{
		_agent->GetStateMachine()->ChangeState(ReturnToHomeRegionState::Instance());
		return;
	}

	//if the best supporting spot changes, change the steering target
	if (_agent->GetTeam()->GetSupportSpot() != _agent->GetTarget())
	{
		_agent->SetTarget(_agent->GetTeam()->GetSupportSpot());

		//activate arrive
	}

	//if this player has a shot at the goal and the attacker can pass the ball to him, the attacker should pass the ball to this player
	if (_agent->GetTeam()->CanShoot(_agent->GetTransform()->m_Pos, 10))//create a parameter class and put the variable max SHOOTING force here
	{
		_agent->GetTeam()->RequestPass(_agent);
	}

	//If the player is located at the support spot and the team still have the ball, they should remain still and turn to face the ball
	if (_agent->AtTarget())
	{
		//deactivate arrive
		_agent->TrackBall();

		_agent->SetVelocity(Vector2(0,0));

		//if the player is not being pressed by another player, then they should ask for the ball
		if (!_agent->IsBeingPressured())
		{
			_agent->GetTeam()->RequestPass(_agent);
		}

	}

}

void SupportAttackerState::Exit(FootballFieldPlayer* _agent)
{
	_agent->GetTeam()->SetSupportingPlayer(nullptr);

	//deactivate arrive
}

bool SupportAttackerState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}




void ReturnToHomeRegionState::Enter(FootballFieldPlayer* _agent)
{
	//activate arrive
	//if (!_agent) //region code
	{
		_agent->SetTarget();//home region
	}
}

void ReturnToHomeRegionState::Execute(FootballFieldPlayer* _agent)
{
	if (_agent->GetFootballPitch()->GameOn)
	{
		//if the ball is nearer this player than any other team member and the receiver is null and the goalkeeper does not have the ball then chase it
		if (_agent->IsClosestTeamMemberToBall() && _agent->GetTeam()->Receiver() == nullptr && !_agent->GetFootballPitch())
		{
			_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());
			return;
		}

	}

	//if game is in play and close enough to home, change state to wait and set the player target to his current position.
	//So that if they gets pushed out of the position they can move back
	if ()
	{
		_agent->SetTarget(_agent->GetTransform()->m_Pos);
		_agent->GetStateMachine()->ChangeState(WaitState::Instance());
	}

	//if game is not in play the player must return much closer to the center of their home region
	else if ()
	{
		_agent->GetStateMachine()->ChangeState(WaitState::Instance());
	}

}

void ReturnToHomeRegionState::Exit(FootballFieldPlayer* _agent)
{
	//_agent->//deactivate arrive
}

bool ReturnToHomeRegionState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}





void WaitState::Enter(FootballFieldPlayer* _agent)
{
	//if the game is not in play, make sure the target is the center of the player's home region. This makes sure all the players are in the correct region
	if ()//game is not in play
	{
		_agent->SetTarget(_agent);//region centre

	}
}

void WaitState::Execute(FootballFieldPlayer* _agent)
{
	if (!_agent->AtTarget())
	{
		//activate arrive
		return;
	}
	else
	{
		//deactivate arrive
		_agent->SetVelocity(Vector2(0, 0));
		_agent->TrackBall();
	}

	if (_agent->GetTeam()->InPossession() && !_agent->IsPossessingPlayer() && _agent->IS)
	{
		_agent->GetTeam()->RequestPass(_agent);
		return;

	}

	if ()//pitch is in play
	{
		if (_agent->IsClosestTeamMemberToBall() && _agent->GetTeam()->Receiver == nullptr && )//goal keeper does not have the ball
		{
			_agent->GetStateMachine()->ChangeState(ChaseBallState::Instance());
		}
	}

}

void WaitState::Exit(FootballFieldPlayer* _agent)
{
}

bool WaitState::OnMessage(FootballFieldPlayer* _agent, const Telegram&)
{
	return false;
}
