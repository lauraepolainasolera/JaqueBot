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

		tipo obtenerTipo(Pieza* p) { return p->type; };

		void setLado(float a);

		void dibuja();

		void dibujaPiezas();
		//void dibujaPiezas(int, int,int);

		void inicializa();
		void mueve(Vector2D origen, Vector2D destino);
		void setPieza(Pieza* origen, Pieza* destino);
		bool obstaculo(Vector2D origen, Vector2D destino);
		bool casillaVacia(Vector2D pos);
		void comerPieza(Pieza *destino);
		bool setTurno(int movimiento, Pieza* p);

		bool jaque(Vector2D rey, Pieza*);
		int jaqueReal(); // 0 no hay jaque, 1 jaque NEGRAS, 2 jaque BLANCAS
		bool evaluaEnclavamiento();

	};

