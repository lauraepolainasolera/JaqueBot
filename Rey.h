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

    static void mueve(V2D origen, V2D destino);
    static bool movimientoValido(V2D origen, V2D destino);
};


