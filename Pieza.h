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

	const char* imagen;
	SpriteSequence pie;

	Pieza() :type(V), colour(B) ,pie("bin/torrenegra.png",1,1,20) {};
	Pieza(tipo t, color c) : colour(c), type(t), pie("bin/torreblanca.png", 1, 1, 20) { cout <<"estoy construyendo"<<endl; };// pie(imagen, 1, 1, 20) { pie.setCenter(5, 5); pie.setSize(10, 10); };// : colour(c), type(t), piez(imagen, 1, 1, 20) { piez.setCenter(5, 5); piez.setSize(10, 10) } ;
	Pieza(const char* imag): imagen(imag), pie(imagen,1,1,20) { cout << imagen << endl; }
	
	void dibuja();
	
	
	//void dibuja(SpriteSequence piez);

	//virtual ~Pieza();
	//virtual void mueve() = 0;
	//virtual bool movimientoValido(V2D origen, V2D destino) = 0;

	//string getImagen(Pieza *p);

};
