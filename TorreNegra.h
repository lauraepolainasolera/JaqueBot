#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreNegra :
    public Torre
{
public:
	SpriteSequence torren;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	TorreNegra() : Torre(NEGRA), torren("bin/torrenegra.png", 1, 1, 20) { torren.setCenter(0.7, 0.9); torren.setSize(1.7, 1.7); }

	void dibuja(Vector2D p);
};

