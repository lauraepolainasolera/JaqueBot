#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
#include "Vector2D.h"
#include "ReyBlanco.h"
#include "ReyNegro.h"
#include "TorreBlanca.h"
#include "TorreNegra.h"
#include "CaballoBlanco.h"
#include "CaballoNegro.h"
#include "AlfilBlanco.h"
#include "AlfilNegro.h"
#include "ReinaBlanca.h"
#include "ReinaNegra.h"
#include "PeonBlanco.h"
#include "PeonNegro.h"
#include "PiezaVacia.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

#define DIMENSION 8

using namespace std;

class Tablero
{
public:

	int movimiento;
	
	bool jm;

	Tablero();

	//~Tablero();

	Vector2D PosicionReal[DIMENSION][DIMENSION];

	Pieza* pi[DIMENSION][DIMENSION];
	
	Vector2D obtenerPunteroPieza(Vector2D v);

	void inicializa();
	
	void dibuja();
	
	void inicializaModoLocura();

	void dibujaPiezas();

	void crearPieza(int tipo, int color, int x, int y, int i, int j);

	Vector2D obtenerPosicionesReales(Vector2D);

	Pieza* obtenerPieza(Vector2D v);

	void mueve(Vector2D origen, Vector2D destino);

	bool capturaAlPaso(Vector2D origen, Vector2D destino);
		
	void setPieza(Pieza* origen, Pieza* destino);

	Pieza* comerPieza(Pieza* origen, Pieza* destino);
	
	Pieza* coronar(Pieza* origen);

	Pieza* cambiarTipoPieza(Pieza* origen, tipo t, color c, Vector2D pos);


	bool obstaculo(Vector2D origen, Vector2D destino);
		
	bool casillaVacia(Vector2D pos);
	
	bool setTurno(int movimiento, Pieza* p);

	bool jaque(Vector2D rey, Pieza* ataq);

	bool capturaAlPaso(Vector2D origen, Vector2D destino);

	int jaqueReal();
		
	bool evaluaEnclavamiento();

	void mostrarMovimiento(Vector2D origen,Vector2D destino);
		
	void mostrarJaque();

	int buscaAdyacentes(Vector2D p, Vector2D* prox[8]);

	Pieza* piezaJaque();

	int trayectoria(Vector2D origen, Vector2D destino, Vector2D* tray[6]);

	bool jaqueMate();

	bool enroque(Vector2D origen, Vector2D destino);

	void enroque(Pieza* origen, Pieza* destino);

	void desEnroque(Pieza* origen, Pieza* destino);


	void reset();
};

