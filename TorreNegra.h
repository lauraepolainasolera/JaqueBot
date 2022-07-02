#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreNegra :
    public Torre
{
public:
	SpriteSequence torren;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	TorreNegra() : Torre(NEGRA), torren("bin/torrenegra.png", 1, 1, 20) { torren.setCenter(0.6, 1); torren.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);
};

