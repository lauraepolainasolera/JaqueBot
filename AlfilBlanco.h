#pragma once
#include "Alfil.h"

using ETSIDI::SpriteSequence;

class AlfilBlanco :
    public Alfil
{

public:
	SpriteSequence alfilb;

	AlfilBlanco() : Alfil(BLANCA), alfilb("bin/alfilblanco.png", 1, 1, 20) { alfilb.setCenter(float(0.6), float(0.9)); alfilb.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);


};

