#pragma once
#include "Torre.h"

using ETSIDI::SpriteSequence;

class TorreNegra :
    public Torre
{
public:
	SpriteSequence torren;

	TorreNegra() : Torre(NEGRA), torren("bin/torrenegra.png", 1, 1, 20) { torren.setCenter(0.6, 1); torren.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		torren.flip(false, false);
		torren.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}
};

