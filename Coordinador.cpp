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

	for (int i = 0; i < JUGADORES; i++) jugadores[i] = new Jugador;
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
			copiarRanking();
			break;
		case '2':
			estado = ModoLocura;
			cout << "Iniciando el Modo Locura, espere unos momentos..." << endl;
			tablero.inicializaModoLocura();
			tablero.dibujaPiezas();
			break;
		case '3':
			tablero.fin = true;
			tablero.reset();
			exit(0);
		}
		break;
	}
	case PantallaFinal:
	{
		switch (key) {
		case '1':
			añadirRanking();
			estado = INICIO;
			tablero.jm = 0;
			tablero.movimiento = 0;
			tablero.partida++;
			break;
		case '2':
			añadirRanking();
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
		case 's':
		case 'S':
			tablero.reset();
			estado = INICIO;
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
		mostrarRanking();
		ETSIDI::printxy("   Pulsa P para volver a la partida", -3, 2);
		ETSIDI::printxy("   Pulsa R para resetear la partida", -3, 0);
		ETSIDI::printxy("   Pulsa S para volver al inicio", -3, -2);
		/*/ETSIDI::printxy("   Pulsa C para cargar partida", -3, -3); */
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
		save >> t; save >> c; save >> x; save >> y;
		tablero.crearPieza(t, c, x, y, i, j); 
	}
	save >> tablero.movimiento;
	save.close();
}

void Coordinador::copiarRanking() {
	ranking.open("bin/ranking.txt");	
	int p;
	string n;
	for (int i = 0; i < JUGADORES - 1; i++) {
		ranking >> n;
		if ((i > 0 && n == jugadores[i - 1]->getNombre()) || n == "") break;
		jugadores[i]->setNombre(n);
		ranking >> p;
		jugadores[i]->setPuntos(p);
	}
	ranking.close();
}

void Coordinador::añadirRanking() {
	string n;
	do {
		cout << "Introduce el nombre del ganador (max. 8 caracteres): ";
		cin >> n;
	} while (n.length() > 8 || n == "");

	for (int i = 0; i < JUGADORES; i++) {
		if (n == jugadores[i]->getNombre()) { 
			jugadores[i]->sumarPunto(); 
			break; 
		}
		else if (jugadores[i]->getPuntos() == 0) { 
			jugadores[i]->setNombre(n); 
			jugadores[i]->setPuntos(1); 
			break; 
		}
	}

	ranking.open("bin/ranking.txt");

	for (int i = 0; i < JUGADORES; i++) {
		if (jugadores[i]->getPuntos() != 0) ranking << jugadores[i]->getNombre() << endl << jugadores[i]->getPuntos() << endl;
	}

	ranking.close();
}

void Coordinador::mostrarRanking() {
	string s;
	const char* c;
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-7, 3.5, 0);
	glVertex3f(-3.5, 3.5, 0);
	glVertex3f(-3.5, -3.5, 0);
	glVertex3f(-7, -3.5, 0);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-7, 3.5, 0);
	glVertex3f(-3.5, 3.5, 0);
	glVertex3f(-3.5, -3.5, 0);
	glVertex3f(-7, -3.5, 0);
	glEnd();
	ETSIDI::printxy("            Ranking", -7, 3);
	for (int i = 0; i < 5; i++) {
		if (jugadores[i]->getPuntos() == 0) break;
		s = "     " + to_string(i + 1) + ". " + jugadores[i]->getNombre() + " " + to_string(jugadores[i]->getPuntos());
		c = s.c_str();
		ETSIDI::printxy(c, -7, 2 - i);
	}
}