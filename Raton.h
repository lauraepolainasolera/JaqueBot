#pragma once
#include "freeglut.h"
#include "V2D.h"
#include <iostream>

class Raton
{
public:
	V2D Pos;
	bool Izq, Der;
	int Estado;
	Raton();
	void raton(int boton, int est, int x, int y);
	bool pulsaRect(float x1, float y1, float x2, float y2);
};

