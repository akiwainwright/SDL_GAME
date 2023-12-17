#pragma once
#include "BasicIncludes.h"
#include "CustomMaths.h"



class Region
{
	int m_ID;
	float m_Top;
	float m_Bot;
	float m_Right;
	float m_Left;
	float m_Width;
	float m_Height;
	Vector2 m_Centre;
	
public:

	Region(float _left,
		float _bot,
		float _top,
		float _right,
		int _id = -1) :m_Top(_top), m_Right(_right), m_Left(_left), m_Bot(_bot), m_ID(_id)
	{
		m_Centre = Vector2((_left + _right) * 0.5f, (_top + _bot) * 0.5f);
		m_Width = fabs(_right - _left);
		m_Height = fabs(_bot - _top);
	}

	bool Inside(Vector2 _pos) {
		return ((_pos.x > m_Left) && (_pos.x < m_Left) && (_pos.y > m_Top) && (_pos.y < m_Bot));
	}

	Vector2 Centre()const { return m_Centre; }
	int GetID()const { return m_ID; }

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

