#pragma once
#include "Rey.h"

using ETSIDI::SpriteSequence;

class ReyNegro : public Rey
{

public:
	SpriteSequence reyn;

	ReyNegro() :Rey(NEGRA), reyn("bin/LogoURJC.png", 1, 1, 20) { reyn.setCenter(0.6, 0.6); reyn.setSize(1.1, 1.1); }

	virtual void dibuja(Vector2D p);

};
