#pragma once
#include "ETSIDI.h"
#include "Tablero.h"

class Coordinador
{
public:
	Coordinador();
	//virtual ~Coordinador();
	
	int movs;

	void tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	//Tablero tablero;

	enum Estado { INICIO, ModoNormal, ModoLocura, CONF };
	Estado estado;
};

