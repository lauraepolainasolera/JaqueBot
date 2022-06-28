#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "V2D.h"
#include "Pieza.h"

	using ETSIDI::SpriteSequence;

	class Tablero
	{
	private:

		SpriteSequence tablero0;
		float lado;


	public:

		//void eliminarPieza(V2D origen);
		//void dibujarPieza(V2D destino);

		Tablero();

		//~Tablero();

		V2D PosicionReal[8][8];

		Pieza* pi[8][8];

		void setLado(float a);

		void dibuja();

		void dibujaPiezas(int, int, int);

		void inicializa();


	};

