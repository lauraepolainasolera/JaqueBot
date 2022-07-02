#include "Raton.h"

Raton::Raton() {
	Pos.x = 0;
	Pos.y = 0;
	Izq = 0;
	Der = 0;
	Estado = 0;
}

bool Raton::pulsaRect(float x1, float y1, float x2, float y2) {
	if (x1 < Pos.x && Pos.x < x2 && y1 < Pos.y && Pos.y < y2) return true;
	else return false;
}

