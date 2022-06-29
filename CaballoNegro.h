#pragma once
#include "Caballo.h"
using ETSIDI::SpriteSequence;

class CaballoNegro :
    public Caballo
{
public:
	SpriteSequence caballon;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	CaballoNegro() : Caballo(NEGRA), caballon("bin/caballonegro.png", 1, 1, 20) { caballon.setCenter(0.6, 1); caballon.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		caballon.flip(false, false);
		caballon.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}
};

