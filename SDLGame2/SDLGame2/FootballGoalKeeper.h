#pragma once
#include "FootballPlayer.h"



class FootballGoalKeeper: public FootballPlayer
{
public:
	FootballGoalKeeper(FootballTeam* _homeTeam, int _homeRegion, State<FootballGoalKeeper>* _startState, Vector2 _heading, Vector2 _velocity, float _mass, float _maxForce, float _maxSpeed, float _maxTurnRate, float _scale);
	~FootballGoalKeeper() { delete m_StateMachine; }

	void UpdateGameObject(float _deltaTime) override;
	void Render()override;//remove override and implement in base class if there's a base class called SteeringGameObject (a base class GO that moves)


	bool BallWithinRangeForIntercept()const;
	bool FarFromGoal()const;

	StateMachine<FootballGoalKeeper>* GetStateMachine() { return m_StateMachine; }

	
	/// <summary>
	/// this is called by the intercept state to determine the spot along the goal which will act as one of the interpose targets 
	/// (the other is the ball). the specific point at the goal line that the keeper is trying to cover is flexible and can move depending on where
	/// the ball is on the field . This is done by scaling the ball's y value by the ratio of the goal width to the field's width
	/// </summary>
	/// <returns></returns>
	Vector2 GetRearInterposeTarget()const;

	Vector2 GetLookAt()const { return m_LookAt; }
	void SetLookAt(Vector2 _dir) { m_LookAt = _dir; }

private:
	StateMachine< FootballGoalKeeper>* m_StateMachine;

	//this is in update to point towards the ball and is used when rendering the GK to ensure the GK looks at the ball
	Vector2 m_LookAt;
};

