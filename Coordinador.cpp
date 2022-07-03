#include "Coordinador.h"
#include <iostream>



Tablero tablero;

void  Coordinador::MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey)

{
	if (down == true)
	{
		movimientohecho = true;
		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		GLfloat winX, winY, winZ;
		GLdouble posX, posY, posZ;

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;

		glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

		winX = winX + 250;
		winY = winY + 250;

		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

		//finally cell coordinates

		posicionAux = world2cell(posX, posY, xcell_sel, ycell_sel);

	}

	else movimientohecho = false;

	
}


Coordinador::Coordinador()
{
	width = 1.2;				//width of each cell in the grid	N = pb->getSize();		//Grid NxN
	dist = 15 ;					//distance of viewpoint from center of the board
	center_z = 0;

	movimientohecho = false;
	origen_detectado = false;

	origen = 0;
	destino = 0;

	posicionAux.x = 0;
	posicionAux.y = 0;

	estado = INICIO;
	movs = 0;
	a = 0;
}

void Coordinador::tecla(unsigned char key)
{

	if (estado == INICIO) {
		switch(key){
		case '1':
			estado = ModoNormal;
			cout << "Iniciando el Modo Normal. Espere unos momentos." << endl;
			tablero.inicializa();
			tablero.dibujaPiezas();
			break;
		case '2':
			cout << "Iniciando el Modo Locura. Espere unos momentos." << endl;
			estado = ModoLocura;
			tablero.inicializaModoLocura();
			tablero.dibujaPiezas();
			break;
		case '3':
			exit;
		}
	}
	if (estado == PantallaFinal)
	{
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/PANTALLA_FINAL.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(5, 5, 0);
		glTexCoord2d(1, 0); glVertex3f(5, -5, 0);
		glTexCoord2d(1, 1); glVertex3f(-5, -5, 0);
		glTexCoord2d(0, 1); glVertex3f(-5, 5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		switch (key) {
		case '1':
			estado = INICIO;
			break;
		case '2':
			exit;
			break;
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

	

	tablero.dibuja();

	tablero.dibujaPiezas();


		if (movimientohecho == true && origen_detectado== false) {

			origen.x = posicionAux.x;
			origen.y = posicionAux.y;
			movimientohecho = false;
			origen_detectado = true;

		}

			/*cout << "Introduce posciones destino" << endl;*/
		if (movimientohecho == true && origen_detectado==true)
		{
			destino = posicionAux;
			movimientohecho = false;
			origen_detectado = false;
			tablero.mueve(origen, destino);
			tablero.mostrarMovimiento(origen, destino);
		  tablero.mostrarJaque();
		}
		
	}


			}

		/*if (JaqueMate) {
			estado = PantallaFinal;
		}*/
		//Implementar correctamente cuando se compruebe el jaque mate
		}


}


