#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Rey :
    public Pieza
{
public:

	string imagen;

	
	//SpriteSequence reyn;
	
	Rey(color c) : Pieza(REY, c) {}; //, imag (imagen, 1,1 20), imag.setCenter(5, 5); imag.setSize(10, 10);};

	virtual void dibuja(Vector2D p);

    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


