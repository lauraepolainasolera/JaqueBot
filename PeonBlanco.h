#pragma once
#include "Peon.h"

using ETSIDI::SpriteSequence;

class PeonBlanco : public Peon
{

public:

	SpriteSequence peonb;

	PeonBlanco() :Peon(BLANCA), peonb("bin/peonblanco.png", 1, 1, 20) { peonb.setCenter(0.6, 0.9); peonb.setSize(1.5, 1.5); }

	virtual void dibuja(Vector2D p)
	{
		
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		peonb.flip(false, false);
		peonb.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();

	}

};
