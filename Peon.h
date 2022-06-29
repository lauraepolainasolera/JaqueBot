#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Peon :
	public Pieza
{
public:

	Peon(color c) : Pieza(PEON, c) {};

	virtual void dibuja(Vector2D p);

	//void mueve(V2D origen, V2D destino);
	//bool movimientoValido(V2D origen, V2D destino);
};
