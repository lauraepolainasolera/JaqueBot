#pragma once
class V2D
{
public:
	V2D(int xv = 0, int yv = 0) : x(xv), y(yv) {};
	int x, y;

	V2D operator - (V2D v);
	bool operator == (V2D v);
};
