#pragma once
#include "Reina.h"

using ETSIDI::SpriteSequence;

class ReinaNegra :
    public Reina
{
public:
	SpriteSequence reinan;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	ReinaNegra() : Reina(NEGRA), reinan("bin/reinanegra.png", 1, 1, 20) { reinan.setCenter(0.6, 0.9); reinan.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		reinan.flip(false, false);
		reinan.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}
};

