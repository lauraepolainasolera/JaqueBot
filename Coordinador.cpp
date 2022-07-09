#include "Coordinador.h"
#include <iostream>



Tablero tablero;

Coordinador::Coordinador()
{
	width = 1.2;			
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
			tablero.partida++;
			break;
		case '2':
			tablero.fin = true;
			tablero.reset();
			exit(0);
			break;
		}
		break;
	}
	case ModoLocura:
	case ModoNormal:
		switch (key)
		{
		case 'p':
		case 'P':
			estadoAux = estado;
			cout << estadoAux << endl;
			estado = Pausa;
			break;
		}
		break;
	case Pausa:
		switch (key)
		{
		case 'p':
		case 'P':
			estado = estadoAux;
			break;
		case 'e':
		case 'E':
			estado = INICIO;
			break;
		case 's':
		case 'S':
			guardar();
			break;
		case 'r':
		case 'R':
			tablero.reset();
			if (estadoAux == ModoNormal)
				tablero.inicializa();
			else if(estadoAux == ModoLocura)
				tablero.inicializaModoLocura();
			estado = estadoAux;
			break;
		case 'c':
		case 'C':
			cargar();
			estado = estadoAux;
			break;
		default:
			tablero.fin = true;
			tablero.reset();
			break;
		}
	}
}

void Coordinador::dibuja()
{
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("droid-serif.italic.ttf", 14);

	if (estado == INICIO) {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("PANTALLA_INICIO.png").id);
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

		if (movimientohecho == true && origen_detectado == false) 
		{
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
		ETSIDI::printxy("   Pulsa S para guardar partida", -3, -1);
		ETSIDI::printxy("   Pulsa C para cargar partida", -3, -3);
		tablero.dibuja();
		
	}

	if (tablero.jm == true) {

		estado = PantallaFinal;

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("PANTALLA_FINAL.png").id);
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
	
}

void Coordinador::guardar() {
	save.open("save.txt");
	for (int i = 0; i < DIMENSION; i++) for (int j = 0; j < DIMENSION; j++) if (tablero.pi[i][j] != nullptr) save << tablero.pi[i][j]->type << endl << tablero.pi[i][j]->colour << endl 
		<< tablero.pi[i][j]->pos.x << endl << tablero.pi[i][j]->pos.y << endl;
	save << tablero.movimiento;
	save.close();
}

void Coordinador::cargar() 
{
	int t, c, x, y;
	tablero.reset();
	save.open("save.txt");
	for (int i = 0; i < DIMENSION; i++) for (int j = 0; j < DIMENSION; j++) { 
		save >> t;
		save >> c;
		save >> x;
		save >> y;
		cout << "TIPO " << t << " COLOR " << c << endl;
		tablero.crearPieza(t, c, x, y, i, j); 
	}
	save >> tablero.movimiento;
	save.close();
}