#ifndef CUSTOM_MATHS_H
#define CUSTOM_MATHS_H

#include <cmath>


float degToRad(float degrees)
{
	return degrees * M_PI / 180;
}

float radToDeg(float radians)
{
	return radians * 180 / M_PI;
}

struct Vector2
{
	float x;
	float y;

	Vector2(float xpos = 0, float ypos = 0)
	{
		x = xpos;
		y = ypos;
	}

	float Length()
	{
		return SDL_sqrt((x * x) + (y * y));
	}

	float LenghtSqrd()
	{
		return (x * x) + (y * y);
	}

	Vector2 operator+(const Vector2& vector)
	{
		Vector2 result;
		
		result.x = this->x + vector.x;
		result.y = this->y + vector.y;

		return result;
	}

	Vector2 operator-(const Vector2& vector)
	{
		Vector2 result;

		result.x = this->x - vector.x;
		result.y = this->y - vector.y;

		return result;
	}

	Vector2 operator*(const float& scalar)
	{
		Vector2 result;

		result.x = this->x * scalar;
		result.y = this->y * scalar;

		return result;
	}

	Vector2 operator/(const float& scalar)
	{
		Vector2 result;

		result.x = this->x / scalar;
		result.y = this->y / scalar;

		return result;
	}

	Vector2 Normalise()
	{
		Vector2 temp = Vector2(x, y);

		return temp / Length();
	}
};


Vector2 translateVector2(Vector2 startPos, Vector2 displacementVector)
{
	return startPos + displacementVector;
}

// need to do rotate vectors next

Vector2 rotateVector2()
{
	return Vector2();
}

Vector2 rotateVector2pivot()
{
	return Vector2();
}

#endif // CUSTOM_MATHS_H

