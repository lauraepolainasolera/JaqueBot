#pragma once
#include "Pieza.h"


class Rey :
    public Pieza
{
public:

	string imagen;

	
	//SpriteSequence reyn;
	
	Rey(color c) : Pieza(K, c) {}; //, imag (imagen, 1,1 20), imag.setCenter(5, 5); imag.setSize(10, 10);};


    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


