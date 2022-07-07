#pragma once
#include "ETSIDI.h"
#include "Tablero.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };
enum Estado { INICIO, ModoNormal, ModoLocura, PantallaFinal, Pausa };

class Coordinador
{
public:
	Coordinador();
	//virtual ~Coordinador();

	void tecla(unsigned char key);

	void dibuja();

	void MouseButton(int x, int y, int button, bool down);

	void setSize(int s) { N = s; }

	int getSize() { return N; }

	Vector2D world2cell(double x, double y) {
		//world coordinates to cell

		Vector2D posicion;
		posicion.y = (int)((x) / width);
		posicion.x= abs ((int)((y) / width)-7);

		return posicion;
	}

protected:

	bool movimientohecho;

	bool origen_detectado;

	Vector2D posicionAux;

	Vector2D origen, destino;

	float width;

	Estado estado;

	int N;								 //size 

	double center_x, center_y, center_z;

};