#pragma once
#include "Pieza.h"
using ETSIDI::SpriteSequence;

class PiezaVacia :
    public Pieza
{
public:
	SpriteSequence piezav;
    PiezaVacia() :Pieza(VACIA, BLANCA), piezav("bin/piezavacia.png", 1, 1, 20) { piezav.setCenter(0.6, 1); piezav.setSize(0, 0); }

    void dibuja(Vector2D p) {
		glPushMatrix();
		glTranslatef(p.x, p.y, 0.5);
		piezav.flip(false, false);
		piezav.draw();
		glTranslatef(-p.x, -p.y, 0.5);
		glPopMatrix();
	};
	
	//PiezaVacia() :Pieza(VACIA, BLANCA) {};
	//void dibuja(Vector2D p) {}; //cambiar por la otra funcion
    bool movimientoValido(Vector2D origen, Vector2D destino) { return false; };
	bool movimientoComer(Vector2D origen, Vector2D destino) { return false; };

};

