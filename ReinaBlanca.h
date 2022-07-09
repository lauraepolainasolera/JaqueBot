#pragma once
#include "Reina.h"

using ETSIDI::SpriteSequence;

class ReinaBlanca :
    public Reina
{
public:
	SpriteSequence reinab;

	ReinaBlanca() : Reina(BLANCA), reinab("reinablanca.png", 1, 1, 20) { reinab.setCenter(0.6, 0.9); reinab.setSize(1.5, 1.5); }

	void dibuja(Vector2D p);
};

