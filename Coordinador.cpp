#include "Coordinador.h"
#include <iostream>



Tablero tablero;

Coordinador::Coordinador()
{
	width = 1.2;				//width of each cell in the grid	N = pb->getSize();		//Grid NxN
	center_z = 0;

	movimientohecho = false;
	origen_detectado = false;

	origen = 0;
	destino = 0;

	posicionAux.x = 0;
	posicionAux.y = 0;

	estado = INICIO;


}

void  Coordinador::MouseButton(int x, int y, int button, bool down)
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

		posicionAux = world2cell(posX, posY);

	}

	else movimientohecho = false;

	
}

void Coordinador::tecla(unsigned char key)
{
	switch (estado)
	{
	case INICIO:
	{
		switch (key) {
		case '1':
			estado = ModoNormal;
			cout << "Iniciando el Modo Normal, espere unos momentos..." << endl;
			tablero.inicializa();
			tablero.dibujaPiezas();
			break;
		case '2':
			estado = ModoLocura;
			cout << "Iniciando el Modo Locura, espere unos momentos..." << endl;
			tablero.inicializaModoLocura();
			tablero.dibujaPiezas();
			break;
		case '3':
			exit(0);
		}
		break;
	}
	case PantallaFinal:
	{
		switch (key) {
		case '1':
			estado = INICIO;
			tablero.jm = 0;
			tablero.movimiento = 0;
			break;
		case '2':
			exit;
			break;
		}
		break;
	}
	case ModoLocura:
	case ModoNormal:
		switch (key)
		{
		case ('p'):
			estado = Pausa;
			break;
		default:
			//exit(0);
			break;
		}
		break;
	case Pausa:
		switch (key)
		{
		case ('p'):
			estado = ModoNormal;
			break;
		case 'e':
			estado = INICIO;
			break;
		case 's':
			guardar();
			break;
		case 'r':
			tablero.reset();
			tablero.inicializa();
			estado = ModoNormal;
			break;
		case 'c':
			cargar();
			estado = ModoNormal;
			break;
		default:
			break;
		}
	}
}

void Coordinador::dibuja()
{
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("bin/droid-serif.italic.ttf", 14);

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


		if (movimientohecho == true && origen_detectado == false) {

			origen.x = posicionAux.x;
			origen.y = posicionAux.y;
			movimientohecho = false;
			origen_detectado = true;

		}

		if (movimientohecho == true && origen_detectado == true)
		{
			destino = posicionAux;
			movimientohecho = false;
			origen_detectado = false;
			tablero.mueve(origen, destino);
		}
		tablero.mostrarMovimiento(origen, destino);
		tablero.mostrarJaque();
	}

	else if (estado == Pausa) {	
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-3.5, 4.5, 0);
		glVertex3f(3.5, 4.5, 0);
		glVertex3f(3.5, -4.5, 0);
		glVertex3f(-3.5, -4.5, 0);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-3.5, 4.5, 0);
		glVertex3f(3.5, 4.5, 0);
		glVertex3f(3.5, -4.5, 0);
		glVertex3f(-3.5, -4.5, 0);
		glEnd();
		ETSIDI::printxy("   Pulsa P para volver a la partida", -3, 3);
		ETSIDI::printxy("   Pulsa R para resetear la partida", -3, 1);
		ETSIDI::printxy("   Pulsa S para guardar la partida", -3, -1);
		ETSIDI::printxy("   Pulsa E para salir de la partida", -3, -3);
		tablero.dibuja();
		
	}


	if (tablero.jm == true) {

		estado = PantallaFinal;

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/PANTALLA_FINAL.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-8, 8, 0);
		glVertex3f(8, 8, 0);
		glVertex3f(8, -8, 0);
		glVertex3f(-8, -8, 0);
		glTexCoord2d(0, 0); glVertex3f(-5, 5, 0);
		glTexCoord2d(1, 0); glVertex3f(5, 5, 0);
		glTexCoord2d(1, 1); glVertex3f(5, -5, 0);
		glTexCoord2d(0, 1); glVertex3f(-5, -5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}


}

void Coordinador::guardar() {
	save.open("bin/save.txt");
	for (int i = 0; i < DIMENSION; i++) for (int j = 0; j < DIMENSION; j++) if (tablero.pi[i][j] != nullptr) save << tablero.pi[i][j]->type << endl << tablero.pi[i][j]->colour << endl;
	save.close();
}

void Coordinador::cargar() {
	int t, c;
	tablero.reset();
	save.open("bin/save.txt");
	for (int i = 0; i < DIMENSION; i++) for (int j = 0; j < DIMENSION; j++) { 
		if (save.eof()) break;
		save >> t;
		save >> c;
		cout << "TIPO " << t << " COLOR " << c << endl;
		tablero.crearPieza(t, c, i, j); 
	}
	save.close();
}