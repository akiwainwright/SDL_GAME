#include "Ball.h"
#include "FootballPlayer.h"
#include "Game.h"




Ball::Ball(Game* _game, SteeringVehicleParameter* _vehicleParams, string _name, ActorState _state, Vector2 _pos, float _ballSize, float _mass, vector<Walls2D>& _PitchBoundary) : VehicleAgent(_game, _name, _state,_vehicleParams), m_PitchBoundary(_PitchBoundary)
{

}

Ball::~Ball()
{
}

void Ball::Kick(Vector2 _direction, float _force)
{
    _direction.Normalised();

    Vector2 acceleration = (_direction * _force) / GetVehicleParams()->GetVehicleMass();
    SetVelocity(acceleration);
}

float Ball::TimeToCoverDistance(Vector2 _from, Vector2 _to, float _force) const
{
    //acceleration is equal to friction

    //this will be the velocity of the ball in the next step *if* the player was to make the pass.
    float speed = _force / GetVehicleParams()->GetVehicleMass();

    //calculate the velocity at the destination using the SUVAT equation - v^2 = u^2 +2as

    float distanceToCover = (_from - _to).Length();

    float finalVelocitySquared = powf(speed, 2) + 2 * distanceToCover;//* rigidBody2D.Friction
    //if (u^2 +2as) is negative it means the ball cannot reach the destination
    if (finalVelocitySquared <= 0) return -1.0f;
    
    float finalVelocity = sqrt(finalVelocitySquared);
    //if its possible for the ball to reach its destination, we calculate the time using the equation: t = (v - u)/a

    return (finalVelocity - speed);// divide by rigidBody2D.Friction

}

Vector2 Ball::FuturePosition(float _time)
{
    //using the equation x = ut + 0.5at^2, x= distance/displacement, a = friction, u = initial velocity
    //calculate ut, which is a vector

    Vector2 ut = GetVelocity() * _time;

    //calculate the 0.5at^2 which is scalar
    float halfATSquared = 0.5f * _time * _time;//* rigidbody.friction

    //turn the scalar quantity into a vector by multiplying the value with the normalized
    //velocity vector (because that gives the direction)
    Vector2 scalarToVector = Vector2::Normalized(GetVelocity()) *halfATSquared ;

    return m_Transform->m_Pos + ut + scalarToVector;
}

void Ball::Control(FootballPlayer* _owner)
{
}

Vector2 Ball::AddNoiseToKick(Vector2& _ballPos, Vector2& _ballTarget, FootballPlayer* _player)
{
    
    float displacement = (PI - (PI*0.2f)) * RandInRange(-1.0f, 1.0f);//kicking accuracy of _player
    Vector2 toTarget = _ballTarget - _ballPos;
    rotateVector2(toTarget, displacement);
}


void Ball::CheckCollisionWithWalls(const vector<Walls2D>& _walls)
{
}

void Ball::UpdateGameObject(float _deltaTime)
{
    //VehicleAgent::UpdateGameObject(_deltaTime);
    // 
    //record the old position for referance
    m_OldPos = GetTransform()->m_Pos;

    CheckCollisionWithWalls(m_PitchBoundary);

    //physics friction should be here (AKI)
}

void Ball::Render()
{

}
