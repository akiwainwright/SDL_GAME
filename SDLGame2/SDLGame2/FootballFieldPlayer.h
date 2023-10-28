#pragma once
#include "FootballPlayer.h"

class FootballFieldPlayer : public FootballPlayer
{
public:
	FootballFieldPlayer(class FootbalTeam* _homeTeam, int _homeRegion, State<FootballFieldPlayer>* _startState, Vector2 _heading, Vector2 _velocity,SteeringBehaviours* _SteeringBehaviours, FootballParameters* _FootballParams ,float _scale, Position _playerPosition);

	~FootballFieldPlayer();

	void UpdateGameObject(float _deltaTime) override;
	void Render()override;//remove override and implement in base class if there's a base class called SteeringGameObject (a base class GO that moves)

	//a ball doesnt need to handle messages
	bool HandleMessage(const Telegram& _msg)override { return false; }

	StateMachine<FootballFieldPlayer>* GetStateMachine() { return m_StateMachine; }

	bool BallWithinRangeForIntercept() const;

	bool FarFromGoal() const;
	
	bool IsReadyForNextKick()const;

private:
	StateMachine< FootballFieldPlayer>* m_StateMachine;

};

