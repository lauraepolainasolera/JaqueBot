#pragma once
#include "ETSIDI.h"
#include "Tablero.h"

class Coordinador
{
public:
	Coordinador();
	//virtual ~Coordinador();
	
	int movs;
	Tablero tablero;

	void tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:

	enum Estado { INICIO, JvJ, JvAI, CONF };
	Estado estado;
};

