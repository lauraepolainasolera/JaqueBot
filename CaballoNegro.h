#pragma once
#include "Caballo.h"
using ETSIDI::SpriteSequence;

class CaballoNegro :
    public Caballo
{
public:
	SpriteSequence caballon;

	CaballoNegro() : Caballo(NEGRA), caballon("caballonegro.png", 1.0, 1.0, 20) { caballon.setCenter(0.6, 0.9); caballon.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p);
};

