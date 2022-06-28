#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include <string>
#include "V2D.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>


//#include "Mundo.h"
using namespace std;
using ETSIDI::SpriteSequence;

enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA }; //Torre,Caballo,Alfil, King,Queen,Peon, Vacia
enum color { BLANCA, NEGRA };

class Pieza
{
public:
	
	
	tipo type;
	color colour;

	//const char *imagen;
	//SpriteSequence piez;

	Pieza(tipo t, color c) : colour(c), type(t) {};// : colour(c), type(t), piez(imagen, 1, 1, 20) { piez.setCenter(5, 5); piez.setSize(10, 10) } ;

	//void dibuja(SpriteSequence piez);

	//virtual ~Pieza();
	//virtual void mueve() = 0;
	//virtual bool movimientoValido(V2D origen, V2D destino) = 0;

	string getImagen(Pieza *p);

};
