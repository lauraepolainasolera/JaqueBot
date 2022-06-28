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


enum tipo { T, C, A, K, Q, P, V }; //Torre,Caballo,Alfil, King,Queen,Peon, Vacia
enum color { B, N };

class Pieza
{
public:
	tipo type;
	color colour;

	string imagen;

	//SpriteSequence imagen;

	Pieza(tipo t, color c) : colour(c), type(t) {};

	void dibuja(string imagen);

	//virtual ~Pieza();

	//virtual void mueve() = 0;
	//virtual bool movimientoValido(V2D origen, V2D destino) = 0;

	string getImagen(Pieza *p);

};
