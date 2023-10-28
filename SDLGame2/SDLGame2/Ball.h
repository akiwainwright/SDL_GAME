#pragma once
#include "CustomMaths.h"
#include "VehicleAgent.h"

class Ball: public VehicleAgent
{
public:
	Ball(Vector2 _pos, float _ballSize, float _mass, vector<Walls2D>& _PitchBoundary);
	~Ball();

	//tests to see if the ball has collided with a wall and reflects
//the ball's velocity accordingly
	void TestCollisionWithWalls(const vector<Walls2D>& _walls);

	void UpdateGameObject(float _deltaTime) override;
	void Render()override;//remove override and implement in base class if there's a base class called SteeringGameObject (a base class GO that moves)

	//a ball doesnt need to handle messages
	bool HandleMessage(const Telegram& _msg)override { return false; }

	//this method applies a directional force to the ball
	void Kick(Vector2 _direction, float _force);

	//given a kicking force and a distance to traverse defined by start and finish points, this methods calculates how long
	//it will take the ball to cover the distance
	float TimeToCoverDistance(Vector2 _from, Vector2 _to, float _force)const;

	//this method calculates where the ball will be at a given time
	Vector2 FuturePosition(float _time);

	//this is used by players and goalkeepers to "control" a ball -- to stop
//it dead. The controlling player is now in possession of
	void Control(class FootballPlayer* _owner);
	
	Vector2 GetOldPos()const { return m_OldPos; }

	void PlaceAtPosition(Vector2 _newPos) { m_Transform->m_Pos = _newPos; }

	Vector2 AddNoiseToKick(Vector2& _ballPos, Vector2& _ballTarget);

private:
	//keeps a record of the ball's position at the last update
	Vector2 m_OldPos;

	//a pointer to the player(or goal keeper who posses the ball)
	class GameObject* m_Owner;

	//a local reference to the walls that make up the pitch boundary
//(used in the collision detection)
	vector<Walls2D>& m_PitchBoundary;




};

