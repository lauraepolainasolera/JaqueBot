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

		


	public:

		int movimiento = 0;
		Tablero();

		//~Tablero();

		Vector2D PosicionReal[DIMENSION][DIMENSION];

		Pieza* pi[DIMENSION][DIMENSION];

		Vector2D obtenerPosicionesReales(Vector2D);

		Pieza* obtenerPieza(Vector2D v);
		Vector2D obtenerPunteroPieza(Vector2D v);

		void setLado(float a);

		void inicializa();
		void dibuja();
		void dibujaPiezas();

		void inicializaModoLocura();


		void mueve(Vector2D origen, Vector2D destino);
		
		void setPieza(Pieza* origen, Pieza* destino);
		Pieza* comerPieza(Pieza* origen, Pieza* destino);
		Pieza* coronar(Pieza* origen);
		Pieza* cambiarTipoPieza(Pieza* origen, tipo t, color c, Vector2D pos);

		bool obstaculo(Vector2D origen, Vector2D destino);
		
		bool casillaVacia(Vector2D pos);
		bool setTurno(int movimiento, Pieza* p);


		bool jaque(Vector2D rey, Pieza* ataq);
		int jaqueReal();
		bool evaluaEnclavamiento();

		void mostrarMovimiento(Vector2D origen,Vector2D destino);
		void mostrarJaque();

	};

