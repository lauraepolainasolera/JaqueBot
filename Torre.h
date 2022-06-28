#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
public:

	Torre(color c) : Pieza(TORRE, c) {};

	virtual void dibuja(Vector2D p);

	//void mueve(V2D origen, V2D destino);
	//bool movimientoValido(V2D origen, V2D destino);
};

