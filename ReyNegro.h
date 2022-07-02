#pragma once
#include "Rey.h"

using ETSIDI::SpriteSequence;

class ReyNegro : public Rey
{

public:
	SpriteSequence reyn;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	ReyNegro() :Rey(NEGRA), reyn("bin/reynegro.png", 1, 1, 20) { reyn.setCenter(0.6, 1); reyn.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p);

};
