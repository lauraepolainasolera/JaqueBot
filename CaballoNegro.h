#pragma once
#include "Caballo.h"
using ETSIDI::SpriteSequence;

class CaballoNegro :
    public Caballo
{
public:
	SpriteSequence caballon;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	CaballoNegro() : Caballo(NEGRA), caballon("bin/caballonegro.png", 1, 1, 20) { caballon.setCenter(0.6, 0.9); caballon.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p);
};

