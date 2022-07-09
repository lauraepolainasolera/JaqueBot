#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreNegra :
    public Torre
{
public:
	SpriteSequence torren;

	TorreNegra() : Torre(NEGRA), torren("torrenegra.png", 1.0, 1.0, 20) { torren.setCenter(0.7, 0.9); torren.setSize(1.7, 1.7); }

	void dibuja(Vector2D p);
};

