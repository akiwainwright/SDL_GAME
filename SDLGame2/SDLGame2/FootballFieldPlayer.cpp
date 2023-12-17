#include "FootballFieldPlayer.h"
#include "FieldPlayerStates.h"


FootballFieldPlayer::FootballFieldPlayer(FootbalTeam* _homeTeam, int _homeRegion, State<FootballFieldPlayer>* _startState, Vector2 _heading, Vector2 _velocity, FootballParameters* _FootballParams, float _scale, Position _playerPosition) : FootballPlayer(_homeTeam,_homeRegion,_heading,_velocity,_FootballParams,_scale,_playerPosition)
{
	m_StateMachine = new StateMachine<FootballFieldPlayer>(this);
	if (_startState)
	{
		m_StateMachine->SetStartState(_startState);
		m_StateMachine->SetGlobalState(GlobalFieldPlayerState::Instance());
		m_StateMachine->CurrentState()->Enter(this);
	}
	GetSteering()->Separation(true);
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
	GetSteering()->Calculate();


	//if no steering force is produced decelerate the player by applying a braking force
	if (GetSteering()->GetSteeringForce().IsZero())
	{
		const double brakingRate = 0.8;
		SetVelocity(GetVelocity() * brakingRate);
	}
	//the steering force's side component is a force that rotates the 
  //player about its axis. We must limit the rotation so that a player
  //can only turn by PlayerMaxTurnRate rads per update.
	double TurningForce = GetSteering()->SideComponent();

	 SDL_clamp(TurningForce,-GetFootballPlayerParameters()->GetPlayerMaxTurnRate(), GetFootballPlayerParameters()->GetPlayerMaxTurnRate());

	//rotate the heading vector
	rotateVector2(Heading(), TurningForce);


	//this could be physics

	//make sure the velocity vector points in the same direction as
	//the heading vector
	SetVelocity( Heading() * GetVelocity().Length());

	//and recreate m_vSide
	SetSide( Heading().PerpendicularClockwise());


	//now to calculate the acceleration due to the force exerted by
	//the forward component of the steering force in the direction
	//of the player's heading
	Vector2 accel = Heading() * GetSteering()->ForwardComponent() / GetVehicleParams()->GetVehicleMass();

	SetVelocity( GetVelocity() + accel);

	//make sure player does not exceed maximum velocity
	GetVelocity().Truncate(GetVehicleParams()->GetMaxSpeed());

	//update the position
	GetTransform()->m_Pos += GetVelocity();
}

void FootballFieldPlayer::Render()
{
}

bool FootballFieldPlayer::HandleMessage(const Telegram& _msg)
{
	m_StateMachine->HandleMessage(_msg);
}



bool FootballFieldPlayer::IsReadyForNextKick() const
{
	return false;
}
