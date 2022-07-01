#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
	Caballo(color c) : Pieza(CABALLO, c) {};

	virtual void dibuja(Vector2D p)=0;

	bool movimientoValido(Vector2D origen, Vector2D destino);

};

