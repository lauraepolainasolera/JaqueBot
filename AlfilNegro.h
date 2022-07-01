#pragma once
#include "Alfil.h"

using ETSIDI::SpriteSequence;

class AlfilNegro :
    public Alfil
{
public:
	SpriteSequence alfiln;

	AlfilNegro() : Alfil(NEGRA), alfiln("bin/alfilnegro.png", 1, 1, 20) { alfiln.setCenter(0.6, 0.9); alfiln.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		alfiln.flip(false, false);
		alfiln.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}
};

