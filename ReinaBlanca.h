#pragma once
#include "Reina.h"

using ETSIDI::SpriteSequence;

class ReinaBlanca :
    public Reina
{
public:
	SpriteSequence reinab;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	ReinaBlanca() : Reina(BLANCA), reinab("bin/reinablanca.png", 1, 1, 20) { reinab.setCenter(0.6, 1); reinab.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);
};

