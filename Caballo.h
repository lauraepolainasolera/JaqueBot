#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
	Caballo(color c) : Pieza(CABALLO, c) {};

	virtual void dibuja(Vector2D p)=0;

	//void mueve(V2D origen, V2D destino);
	bool movimientoValido(V2D origen, V2D destino) { return true; };
};

