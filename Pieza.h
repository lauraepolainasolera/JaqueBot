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

enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA }; //Torre,Caballo,Alfil, King,Queen,Peon, Vacia
enum color { BLANCA, NEGRA };

class Pieza
{
public:
	
	
	tipo type;
	color colour;

	//const char *imagen;
	
	Pieza(tipo t, color c): colour(c), type(t){}
	

	virtual void dibuja(Vector2D p);

	//virtual ~Pieza();
	//virtual void mueve() = 0;
	//virtual bool movimientoValido(V2D origen, V2D destino) = 0;

	
	
};
