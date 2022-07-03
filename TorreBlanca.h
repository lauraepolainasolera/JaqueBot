#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreBlanca :
    public Torre
{
public:
	SpriteSequence torreb;

	TorreBlanca() : Torre(BLANCA), torreb("bin/torreblanca.png", 1, 1, 20) { torreb.setCenter(0.7, 0.9); torreb.setSize(1.7, 1.7); }

	void dibuja(Vector2D p);

};

