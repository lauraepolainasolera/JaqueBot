#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "V2D.h"
#include "Pieza.h"
#include "Vector2D.h"

#define DIMENSION 8



	class Tablero
	{
	private:

		float lado;

		bool turno = 0;

	public:

		//void eliminarPieza(V2D origen);
		//void dibujarPieza(V2D destino);

		Tablero();

		//~Tablero();

		Vector2D PosicionReal[DIMENSION][DIMENSION];

		Pieza* pi[DIMENSION][DIMENSION];

		//Pieza p;

		void setLado(float a);

		void dibuja();

		void dibujaPiezas(int);

		void inicializa();

		void moverPiezas();

		bool igualdadTipo(Pieza* p, Pieza* m);

		bool igualdadColor(Pieza* p, Pieza* m);


	};

