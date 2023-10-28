#pragma once
#include "BasicIncludes.h"
#include "CustomMaths.h"



struct Region
{
	Vector2 m_TopLeft;
	Vector2 m_BotLeft;
	Vector2 m_TopRight;
	Vector2 m_BotRight;
	Vector2 m_Centre;
	


	Region(Vector2 m_TopLeft,
		Vector2 m_BotLeft,
		Vector2 m_TopRight,
		Vector2 m_BotRight,
		Vector2 m_Centre){}
};

class FootballPitch
{
public:
	FootballPitch(int _cxClient, int _cyClient);
	~FootballPitch();

	void Update(float _deltaTime);
	bool Render();
	
	void TogglePause() { m_GameIsPaused = !m_GameIsPaused; }
	bool Paused()const { return m_GameIsPaused; }

	bool GoalKeeperHasBall()const { return m_GoalKeeperHasBall; }
	void SetGoalKeeperHasBall(bool _hasBall) { m_GoalKeeperHasBall = _hasBall; }

	const Region* const GetFootballArea() { return m_FootballArea; }
	const vector<Walls2D>& Walls() { return m_WallList; }
	class Ball* const Ball()const { return m_Ball; }

	const Region* const GetRegionFromIndex(int _index) {
		assert((_index > 0) && (_index < m_Regions.size()));
		return m_Regions[_index];
	}
	bool GameIsActive()const { return m_GameIsActive; }
	void SetGameActive(){ m_GameIsActive = true; }
	void SetGameInActive(){ m_GameIsActive = false; }

private:

	class Ball* m_Ball;

	class FootballTeam* m_Team1;
	class FootballTeam* m_Team2;

	class FootballGoal* m_Team1Goal;
	class FootballGoal* m_Team2Goal;
	vector<Walls2D> m_BoundaryWalls;
	vector<Walls2D> m_WallList;
	class Region* m_FootballArea;

	vector<class Region*> m_Regions;
	bool m_GoalKeeperHasBall;
	bool m_GameIsActive;
	bool m_GameIsPaused;

	void CreateRegions(float _width, float _height);

};

