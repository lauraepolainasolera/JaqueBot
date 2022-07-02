#pragma once
#include "Rey.h"

using ETSIDI::SpriteSequence;

class ReyBlanco : public Rey
{

public:
	SpriteSequence reyb;

		//informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco

		ReyBlanco():Rey(BLANCA), reyb("bin/reyblanco.png", 1, 1, 20) { reyb.setCenter(0.6, 1); reyb.setSize(1.5, 1.5); }
		
		void dibuja(Vector2D p);

};


