#pragma once
#include "ETSIDI.h"
#include "Tablero.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class Coordinador
{
public:
	Coordinador();
	//virtual ~Coordinador();

	int movs;

	int a;

	void tecla(unsigned char key);

	void dibuja();


//Event managers

	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);

	//info
	void setSize(int s) { N = s; }
	int getSize() { return N; }

	//coord

	void world2cell(double x, double y, int& cell_x, int& cell_y) {
		//world coordinates to cell
		cell_x = (int)((x) / width);
		cell_y = abs ((int)((y) / width)-7);
	}

protected:
	float width;

	enum Estado { INICIO, ModoNormal, ModoLocura, CONF };
	Estado estado;

	int N;								 //size 

	//visualization	
	double center_x, center_y, center_z;
	double dist;

	//mouse	
	int xcell_sel, ycell_sel;			//cell selected with mouse

	//mouse+special-keys combination state events 
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;



};