#ifndef CUSTOM_MATHS_H
#define CUSTOM_MATHS_H

#include <float.h>
#include <cmath>

#define PI 3.141592653589793f


inline float degToRad(float degrees)
{
	return degrees * PI / 180;
}

inline float radToDeg(float radians)
{
	return radians * 180 / PI;
}

inline void floatEpsilonCheck(float &num)
{
	if (num <= FLT_EPSILON && num >= -FLT_EPSILON)
	{
		num = 0;
	}
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
		return sqrt((x * x) + (y * y));
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


inline Vector2 translateVector2(Vector2 startPos, Vector2 displacementVector) { return startPos + displacementVector; }

/// <summary>
/// Rotate a vector around the origin anti-clockwise by given angle in radians
/// </summary>
/// <param name="position">Position to rotate</param>
/// <param name="angle">Angle in radians</param>
/// <returns>New position after being rotated</returns>
Vector2 rotateVector2(Vector2 position, float angle);

/// <summary>
/// Rotates a point around a given pivot anti-clockwise by a given angle in radians
/// </summary>
/// <param name="position">position to rotate</param>
/// <param name="pivot">point to rotate around</param>
/// <param name="angle">angle to rotate in radians</param>
/// <returns></returns>
Vector2 rotateVector2pivot(Vector2 position, Vector2 pivot, float angle);

#endif // CUSTOM_MATHS_H

