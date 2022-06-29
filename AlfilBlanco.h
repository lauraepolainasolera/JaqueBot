#pragma once
#include "Alfil.h"

using ETSIDI::SpriteSequence;

class AlfilBlanco :
    public Alfil
{

public:
	SpriteSequence alfilb;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	AlfilBlanco() : Alfil(BLANCA), alfilb("bin/alfilblanco.png", 1, 1, 20) { alfilb.setCenter(0.6, 1); alfilb.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		alfilb.flip(false, false);
		alfilb.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}

};

