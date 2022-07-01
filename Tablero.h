#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
#include "Vector2D.h"

#define DIMENSION 8



	class Tablero
	{
	private:

		float lado;
		int movimiento = 0;

	public:
		Tablero();

		//~Tablero();

		Vector2D PosicionReal[DIMENSION][DIMENSION];

		Pieza* pi[DIMENSION][DIMENSION];

		Vector2D obtenerPosicionesReales(Vector2D);

		Pieza* obtenerPieza(Vector2D v);
		
		tipo obtenerTipo(Pieza* p) { return p->type; };

		void setLado(float a);

		void dibuja();

		void dibujaPiezas();

		void inicializaModoLocura();

		void inicializa();
		
		void mueve(Vector2D origen, Vector2D destino);
		
		void setPieza(Pieza* origen, Pieza* destino);
		
		bool obstaculo(Vector2D origen, Vector2D destino);
		
		bool casillaVacia(Vector2D pos);
		
		void comerPieza(Pieza* origen, Pieza *destino);
		
		bool setTurno(int movimiento, Pieza* p);

	};

