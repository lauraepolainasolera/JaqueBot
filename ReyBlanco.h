#pragma once
#include "Rey.h"

using ETSIDI::SpriteSequence;

class ReyBlanco : public Rey
{

public:
	SpriteSequence reyb;

	ReyBlanco():Rey(BLANCA), reyb("bin/LogoUPM.png", 1, 1, 20) {reyb.setCenter(float(0.6), float(0.7)); reyb.setSize(1.3, 1.3); }
		
	void dibuja(Vector2D p);

};


