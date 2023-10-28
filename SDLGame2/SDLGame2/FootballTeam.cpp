#include "FootballTeam.h"

Vector2 SupportSpotCalculator::DetermineBestSupportSpot()
{
	//only update spot every few frames
	if (!m_BestSupportingSpot)
	{
		return m_BestSupportingSpot->m_Pos;
	}

	//reset the spot
	m_BestSupportingSpot = nullptr;

	float bestScoreSoFar = 0.0f;

	vector<SupportSpot>::iterator currentSpot;
	for (currentSpot = m_Spots.begin(); currentSpot != m_Spots.end(); ++currentSpot)
	{
		//first remove any previous score. (the score is set to 1 so that the viewer can see 
		// the position of all the spots if he has the aids turned )
		currentSpot->m_Score = 1.0f;

		//test 1. is it possible to make a safe pass from the ball's position to this position
		if (m_Team->)
		{

		}



	}
}
