#include "Path.h"





Path::Path(int _numWaypoints, float _minX, float _minY, float _maxX, float _maxY, bool _looped) : m_IsClosedPath(_looped)
{
	CreateRandomPath(_numWaypoints, _minX, _minY, _maxX, _maxY);
	m_CurrentWaypoint = m_Waypoints.begin();
}

Path::~Path()
{
}

Vector2 Path::CurrentWayPoint() const
{
	assert(m_CurrentWaypoint != m_Waypoints.end());
	return *m_CurrentWaypoint;

}

bool Path::Finished()
{
	return !(m_CurrentWaypoint != m_Waypoints.end());
}

void Path::SetNextWaypoint()
{
	assert(m_Waypoints.size() > 0);
	if (++m_CurrentWaypoint == m_Waypoints.end())
	{
		if (m_IsClosedPath)
		{
			m_CurrentWaypoint = m_Waypoints.begin();
		}
	}
}

list<Vector2> Path::CreateRandomPath(int _numWaypoints, float _minX, float _minY, float _maxX, float _maxY)
{
	m_Waypoints.clear();
	float midX = (_maxX + _minX) / 2.0f;
	float midY = (_maxY + _minY) / 2.0f;

	float smaller = min(midX, midY);
	float spacing = (PI * 2) / (float)_numWaypoints;

	for (int i = 0; i < _numWaypoints; i++)
	{
		float radialDist = RandInRange(smaller * 0.2f, smaller);
		Vector2 temp(radialDist, 0.0f);
		temp = rotateVector2pivot(Vector2(0, 0), temp, i * spacing);
		temp.x += midX;
		temp.y += midY;
		m_Waypoints.push_back(temp);

	}
	m_CurrentWaypoint = m_Waypoints.begin();
	return m_Waypoints;

}

void Path::LoopOn()
{
	m_IsClosedPath = true;
	
}

void Path::LoopOff()
{
	m_IsClosedPath = false;
}

void Path::AddWayPoint(Vector2 _newPoint)
{
	m_Waypoints.push_back(_newPoint);
}

void Path::Set(list<Vector2> _newPath)
{
	m_Waypoints = _newPath;
	m_CurrentWaypoint = m_Waypoints.begin();
}

void Path::Set(const Path& _path)
{
	m_Waypoints = _path.GetPath();
	m_CurrentWaypoint = m_Waypoints.begin();
}

void Path::Clear()
{
	m_Waypoints.clear();
}

list<Vector2> Path::GetPath() const
{
	return m_Waypoints;
}


