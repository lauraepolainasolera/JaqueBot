#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include <string>
#include "Vector2D.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA, MUERTE }; //Torre,Caballo,Alfil, King,Queen,Peon, Vacia, Muerte
enum color { BLANCA, NEGRA };

class Pieza
{
public:
	tipo type;
	color colour;

	int mov = 0;

	Vector2D pos;

	Pieza(tipo t, color c): colour(c), type(t){}
	Pieza() { colour = BLANCA; type = VACIA; }

	virtual void dibuja(Vector2D p) =0;

	virtual bool movimientoValido(Vector2D origen, Vector2D destino)=0;
	virtual bool movimientoComer(Vector2D origen, Vector2D destino) = 0;

};
