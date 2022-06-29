#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Rey :
	public Pieza
{
public:



	//SpriteSequence reyn;

	Rey(color c) : Pieza(REY, c){};

	/*
	void dibuja() {
		
		glPushMatrix();
		glTranslatef(0, 0, 0);
		im.flip(false, false);
		im.draw();
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
	*/


	virtual void dibuja(Vector2D p);

    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


