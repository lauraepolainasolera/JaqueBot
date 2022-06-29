#pragma once
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"

class Coordinador
{
public:
	Coordinador();
	//virtual ~Coordinador();
	
	int movs;
	int ratonEstado;
	V2D ratonPos;
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	V2D seleccionarCasilla();

	//void setRaton(V2D pos, int e);

	//bool pulsaRect(float x1, float y1, float x2, float y2);


protected:
	//Tablero tablero;

	enum Estado { INICIO, JvJ, JvAI, CONF };
	Estado estado;
};

