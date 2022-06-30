#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include <string>
#include "V2D.h"
#include "Vector2D.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>


//#include "Mundo.h"
using namespace std;

enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA, MUERTE }; //Torre,Caballo,Alfil, King,Queen,Peon, Vacia, Muerte
enum color { BLANCA, NEGRA };

class Pieza
{
public:
	tipo type;
	color colour;

	Vector2D pos;

	Pieza(tipo t, color c): colour(c), type(t){}
	Pieza() { colour = BLANCA; type = VACIA; }

	virtual void dibuja(Vector2D p) =0;

	//virtual ~Pieza();
	//virtual void mueve() = 0;
	virtual bool movimientoValido(Vector2D origen, Vector2D destino)=0;

};
