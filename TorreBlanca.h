#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreBlanca :
    public Torre
{
public:
	SpriteSequence torreb;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	TorreBlanca() : Torre(BLANCA), torreb("bin/torreblanca.png", 1, 1, 20) { torreb.setCenter(0.7, 0.9); torreb.setSize(1.7, 1.7); }

	void dibuja(Vector2D p);

};

