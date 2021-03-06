#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


class Peon :
	public Pieza
{
public:

	Peon(color c) : Pieza(PEON, c) {};

	virtual void dibuja(Vector2D p)=0;

	bool movimientoValido(Vector2D origen, Vector2D destino);
	bool movimientoComer(Vector2D origen, Vector2D destino);

};
