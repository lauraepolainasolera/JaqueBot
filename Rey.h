#pragma once
#include "Pieza.h"

using ETSIDI::SpriteSequence;

class Rey :
	public Pieza
{
public:

	string im = getImagen();

	SpriteSequence im;


	//SpriteSequence reyn;

	Rey(color c) : Pieza(K, c),};


	Rey(color c): 
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
    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


