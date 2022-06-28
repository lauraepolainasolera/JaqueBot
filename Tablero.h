#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "V2D.h"
#include "Pieza.h"
#include "Vector2D.h"



	class Tablero
	{
	private:

		float lado;


	public:

		//void eliminarPieza(V2D origen);
		//void dibujarPieza(V2D destino);

		Tablero();

		//~Tablero();

		Vector2D PosicionReal[8][8];

		Pieza* pi[8][8];

		void setLado(float a);

		void dibuja();

		void dibujaPiezas(int, int, int);

		void inicializa();


	};

