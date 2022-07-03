#include "Coordinador.h"
#include <iostream>


Tablero tablero;

void Coordinador::MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey)

{
/////////
//computes cell coordinates from mouse coordinates

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x ;
	winY = (float)viewport[3] - (float)y ;

	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	winX = winX + 250;
	winY = winY + 250;

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates

	world2cell(posX , posY , xcell_sel, ycell_sel);
	
	//capture other mouse events
	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down)
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;
}

Coordinador::Coordinador()
{
	width = 1.2;				//width of each cell in the grid	N = pb->getSize();		//Grid NxN
	dist = 15 ;					//distance of viewpoint from center of the board
	center_z = 0;

	estado = INICIO;
	movs = 0;
	a = 0;
}

/*void Coordinador::teclaEspecial(unsigned char key)
{

}*/

void Coordinador::tecla(unsigned char key)
{
	if (key == '0')
	{
		movs++;
		a++;
	}

	if (estado == INICIO) {
		if (key == '1') {
			estado = ModoNormal;
			cout << "Iniciando el Modo Normal. Espere unos momentos." << endl;
			tablero.inicializa();
			tablero.dibujaPiezas();
		}
		else if (key == '2') {
			cout << "Iniciando el Modo Locura. Espere unos momentos." << endl;
			estado = ModoLocura;
			tablero.inicializaModoLocura();
			tablero.dibujaPiezas();
		}
	}
}


void Coordinador::dibuja()
{
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Ajedrez", -10, 11);

	if (estado == INICIO) {

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/PANTALLA_INICIO.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(-5, 5, 0);
		glTexCoord2d(1, 0); glVertex3f(5, 5, 0);
		glTexCoord2d(1, 1); glVertex3f(5, -5, 0);
		glTexCoord2d(0, 1); glVertex3f(-5, -5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	
	else if (estado == ModoNormal || estado == ModoLocura) {
		
		Vector2D origen, destino;

		tablero.dibuja();

		if (a == 0) {
			tablero.dibujaPiezas();
			//cout << "Estoy en el if" << endl;
			a++;
		}
		else {
		//cout << "Introduce posciones origen" << endl;
		//cin >> origen.x;
		//cin >> origen.y;
		////cout << "las posiciones origen son" << origen.x << origen.y << endl;
		//cout << "Introduce posciones destino" << endl;
		//cin >> destino.x;
		//cin >> destino.y;
		////cout << "las posiciones origen son" << destino.x << destino.y << endl;
		//tablero.mueve(origen, destino);
		}
	}	
}

