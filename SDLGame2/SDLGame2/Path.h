#pragma once
#include "BasicIncludes.h"
#include "CustomMaths.h"

class Path
{
public:
	Path() :m_IsClosedPath(false), m_CurrentWaypoint({}) {}

	Path(int _numWaypoints,float _minX,float _minY,float _maxX,float _maxY,bool _looped);
	~Path();
	Vector2 CurrentWayPoint()const;
	//returns true if the end of the list has been reached
	bool Finished();
	//moves the iterator on to the next waypoint in the list
	void SetNextWaypoint();

	//creates a random path which is bound by rectangle described by the min/max values
	list<Vector2> CreateRandomPath(int _numWaypoints, float _minX, float _minY, float _maxX, float _maxY);
	void LoopOn();
	void LoopOff();

	//adds a waypoint to the end of the path
	void AddWayPoint(Vector2 _newPoint);

	//setting the path with either another path or a list of vectors
	void Set(list<Vector2> _newPath);
	void Set(const Path& _path);

	void Clear();

	list<Vector2> GetPath()const;

	//aki this is you brooo
	void Render();

private:
	bool m_IsClosedPath;
	list<Vector2> m_Waypoints;
	//Vector2 m_CurrentWaypoint;
	list<Vector2>::iterator m_CurrentWaypoint;
};
