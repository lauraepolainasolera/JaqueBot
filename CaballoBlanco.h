#pragma once
#include "Caballo.h"

using ETSIDI::SpriteSequence;

class CaballoBlanco :
    public Caballo
{
public:
	SpriteSequence caballob;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	CaballoBlanco() : Caballo(BLANCA), caballob("bin/caballoblanco.png", 1, 1, 20) { caballob.setCenter(0.6, 0.9); caballob.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);
};

