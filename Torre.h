#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
public:

	Torre(color c) : Pieza(TORRE, c) {};

	virtual void dibuja(Vector2D p)=0;

	bool movimientoValido(Vector2D origen, Vector2D destino);
	bool movimientoComer(Vector2D origen, Vector2D destino);
};

