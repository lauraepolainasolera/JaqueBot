#pragma once
#include "Caballo.h"

using ETSIDI::SpriteSequence;

class CaballoBlanco :
    public Caballo
{
public:
	SpriteSequence caballob;

	CaballoBlanco() : Caballo(BLANCA), caballob("bin/caballoblanco.png", 1, 1, 20) { caballob.setCenter(0.6, 0.9); caballob.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		caballob.flip(false, false);
		caballob.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}
};

