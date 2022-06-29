#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreBlanca :
    public Torre
{
public:
	SpriteSequence torreb;

	//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

	TorreBlanca() : Torre(BLANCA), torreb("bin/torreblanca.png", 1, 1, 20) { torreb.setCenter(0.6, 1); torreb.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		torreb.flip(false, false);
		torreb.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}

};

