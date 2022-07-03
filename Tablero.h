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

		//funciones dibujar el tablero
		void inicializa();
		void dibuja();
		void dibujaPiezas();

		//funciones para el movimiento
		void mueve(Vector2D origen, Vector2D destino);
		void setPieza(Pieza* origen, Pieza* destino);
		Pieza* comerPieza(Pieza* origen, Pieza* destino);
		Pieza* coronar(Pieza* origen);
		Pieza* cambiarTipoPieza(Pieza* origen, tipo t, color c, Vector2D pos);

		bool obstaculo(Vector2D origen, Vector2D destino);
		bool casillaVacia(Vector2D pos);
		bool setTurno(int movimiento, Pieza* p);


		//funciones referentes al jaque
		bool jaque(Vector2D rey, Pieza* ataq);
		int jaqueReal();
		bool evaluaEnclavamiento();


		//funciones graficas
		void mostrarMovimiento(Vector2D origen, Vector2D destino);
		void mostrarJaque(Vector2D posicion);
	};

