#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
public:

	Alfil(color c) : Pieza(ALFIL, c) {};

	virtual void dibuja(Vector2D p)=0;

	//void mueve(V2D origen, V2D destino);
	bool movimientoValido(V2D origen, V2D destino) { return true; };
};

