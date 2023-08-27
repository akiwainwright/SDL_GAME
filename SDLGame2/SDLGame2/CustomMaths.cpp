#include "CustomMaths.h"

Vector2 rotateVector2(Vector2 position, float angle)
{
	Vector2 result;

	result.x = (position.x * cos(angle)) - (position.y * sin(angle));
	result.y = (position.x * sin(angle)) + (position.y * cos(angle));

	floatEpsilonCheck(result.x);
	floatEpsilonCheck(result.y);

	return result;
}

Vector2 rotateVector2pivot(Vector2 position, Vector2 pivot, float angle)
{
	Vector2 rotPosition = position - pivot;

	Vector2 result = rotateVector2(rotPosition, angle);

	result = result + pivot;

	return result;
}

