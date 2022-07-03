#pragma once
#include "Peon.h"

using ETSIDI::SpriteSequence;

class PeonNegro :
    public Peon
{

public:

	SpriteSequence peonn;

	PeonNegro() :Peon(NEGRA), peonn("bin/peonnegro.png", 1, 1, 20) { peonn.setCenter(0.6, 0.9); peonn.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);

};

