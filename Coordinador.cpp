#include "Coordinador.h"
#include <iostream>


Tablero tablero;

Coordinador::Coordinador()
{
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
		cout << "Introduce posciones origen" << endl;
		cin >> origen.x;
		cin >> origen.y;
		//cout << "las posiciones origen son" << origen.x << origen.y << endl;
		cout << "Introduce posciones destino" << endl;
		cin >> destino.x;
		cin >> destino.y;
		//cout << "las posiciones origen son" << destino.x << destino.y << endl;
		tablero.mueve(origen, destino);
		}
	}	
}

