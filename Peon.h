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

	//void mueve(V2D origen, V2D destino);
	bool movimientoValido(Vector2D origen, Vector2D destino);

	bool movimientoComer(Vector2D origen, Vector2D destino);
	//bool comerPeon(Vector2D origen, Vector2D destino);
};
