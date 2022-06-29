#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Rey :
	public Pieza
{
public:
	Rey(color c) : Pieza(REY, c) {}; 

	virtual void dibuja(Vector2D p);

    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


