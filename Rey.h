#pragma once
#include "Pieza.h"

using ETSIDI::SpriteSequence;

class Rey :
    public Pieza
{
public:
	SpriteSequence reyb;
	//SpriteSequence reyn;
	
    Rey(color c) : Pieza(K, c), reyb("bin/reyblanco.png", 1, 1, 20) { reyb.setCenter(5, 5); reyb.setSize(10, 10); };
	void dibuja() {
		glPushMatrix();
		glTranslatef(0, 0, 0);
		reyb.flip(false, false);
		reyb.draw();
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


