#pragma once
#include "Caballo.h"

using ETSIDI::SpriteSequence;

class CaballoBlanco :
    public Caballo
{
public:
	SpriteSequence caballob;

	CaballoBlanco() : Caballo(BLANCA), caballob("caballoblanco.png", 1.0, 1.0, 20) { caballob.setCenter(0.6, 0.9); caballob.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);
};

