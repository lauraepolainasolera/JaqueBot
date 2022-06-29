#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Rey :
	public Pieza
{
public:

<<<<<<< HEAD
<<<<<<< HEAD
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
=======
	
=======
>>>>>>> 0ebb92baff6846ba550945611fd8053f1508e766
	Rey(color c) : Pieza(REY, c) {}; 

	virtual void dibuja(Vector2D p);

>>>>>>> 34ca342f95af05c54dfe4caa2d2bc1a980fcf1b7
    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


