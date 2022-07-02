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
		int movimiento = 0;

	public:

		//void eliminarPieza(V2D origen);
		//void dibujarPieza(V2D destino);

		Tablero();

		//~Tablero();

		Vector2D PosicionReal[DIMENSION][DIMENSION];

		Pieza* pi[DIMENSION][DIMENSION];

		//Pieza p;

		Vector2D obtenerPosicionesReales(Vector2D);
		Pieza* obtenerPieza(Vector2D v);
		Vector2D obtenerPunteroPieza(Vector2D v);

		void setLado(float a);

		void inicializa();
		void dibuja();
		void dibujaPiezas();

		void mueve(Vector2D origen, Vector2D destino);
		void setPieza(Pieza* origen, Pieza* destino);
		void comerPieza(Pieza* origen, Pieza* destino);
		void coronar(Pieza* origen);
		Pieza* cambiarTipoPieza(Pieza* origen, tipo t, color c, Vector2D pos);

		bool obstaculo(Vector2D origen, Vector2D destino);
		bool casillaVacia(Vector2D pos);
		bool setTurno(int movimiento, Pieza* p);

		bool jaque(Vector2D rey, Pieza* ataq);
		int jaqueReal();
		bool evaluaEnclavamiento();
	};

