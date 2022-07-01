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

	void dibuja();

protected:

	enum Estado { INICIO, ModoNormal, ModoLocura, CONF };
	Estado estado;
};

