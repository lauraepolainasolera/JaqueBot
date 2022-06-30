#pragma once
class Vector2D
{
public:
	float x, y;
	Vector2D(float xv = 0, float yv = 0) : x(xv), y(yv) {};
	Vector2D operator - (Vector2D v);
	bool operator == (Vector2D v);
};

