#pragma once
#include "Peon.h"

using ETSIDI::SpriteSequence;

class PeonBlanco : public Peon
{

public:

	SpriteSequence peonb;

	PeonBlanco() :Peon(BLANCA), peonb("bin/peonblanco.png", 1, 1, 20) { peonb.setCenter(0.6, 0.9); peonb.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);

};
