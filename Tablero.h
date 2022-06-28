#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "V2D.h"
#include "Pieza.h"
#include "Rey.h"
#include "Vector2D.h"

#define DIMENSION 8



	class Tablero
	{
	private:

		float lado;


	public:

		//void eliminarPieza(V2D origen);
		//void dibujarPieza(V2D destino);

		Tablero();

		//~Tablero();

		Vector2D PosicionReal[DIMENSION][DIMENSION];

		Pieza** p;


		void setLado(float a);

		void dibuja(); //dibuja el tablero

		void dibujaPiezas(int, int); //dibuja las piezas

		void inicializa();


	};

