#pragma once
#include "CustomMaths.h"


class FootballGoal
{
public:
	FootballGoal(Vector2 _left, Vector2 _Right, Vector2 _facing);
	~FootballGoal();


	bool Scored( class Ball* const _ball);


	Vector2 Center()const { return m_Centre; }
	Vector2 Facing()const { return m_Facing; }
	Vector2 LeftPos()const { return m_LeftPost; }
	Vector2 RightPost()const { return m_RightPost; }

	int NumGoalsScored()const { return m_NumGoalsScored; }
	void ResetGoalsScored() { m_NumGoalsScored = 0; }

private:
	Vector2 m_LeftPost;
	Vector2 m_RightPost;

	//a vector representing the facing direction of the goal
	Vector2 m_Facing;

	//the position of the centre pf the goal line
	Vector2 m_Centre;

	//each time Scored() detects a goal this is incremented
	int m_NumGoalsScored;



};


