#pragma once
#include "Peon.h"

using ETSIDI::SpriteSequence;

class PeonNegro :
    public Peon
{

public:

	SpriteSequence peonn;

	PeonNegro() :Peon(NEGRA), peonn("bin/peonnegro.png", 1, 1, 20) { peonn.setCenter(0.6, 0.9); peonn.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{

		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		peonn.flip(false, false);
		peonn.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}

};

