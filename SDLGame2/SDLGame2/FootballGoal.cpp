#include "FootballGoal.h"
#include "Ball.h"
#include "GameObject.h"

inline FootballGoal::FootballGoal(Vector2 _left, Vector2 _right, Vector2 _facing): m_LeftPost(_left), m_RightPost(_right), m_Centre((_left+_right)/2.0f), m_NumGoalsScored(0), m_Facing(_facing)
{
	m_Facing = (_right - _left).Normalise().PerpendicularClockwise();
}

FootballGoal::~FootballGoal()
{
}

//Given the current ball position and the previous ball position,
//this method returns true if the ball has crossed the goal line
//and increments m_iNumGoalsScored
bool FootballGoal::Scored( Ball* const _ball)
{
	if (LineIntersection(_ball->GetTransform()->m_Pos,_ball->GetOldPos(), m_LeftPost, m_RightPost))
	{
		++m_NumGoalsScored;
		return true;
	}
	return false;
}
