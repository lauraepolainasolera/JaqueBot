#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
public:

	Alfil(color c) : Pieza(ALFIL, c) {};

	virtual void dibuja(Vector2D p)=0;

	bool movimientoValido(Vector2D origen, Vector2D destino);

};

