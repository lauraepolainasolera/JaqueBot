#include "Coordinador.h"
#include <iostream>


Tablero tablero;

Coordinador::Coordinador()
{
	estado = INICIO;
	movs = 0;
}

/*void Coordinador::teclaEspecial(unsigned char key)
{

}*/

void Coordinador::tecla(unsigned char key)
{


	if (estado == INICIO) {
		if (key == '1' ) {
			estado = JvJ;
			printf("cambio");
		}
		else if (key == '2' ) {
			//estado = JVAI;
		}
		else if (key == 'c' || key == 'e') {
			exit(0);
		}
	}
	else if (estado == JvJ) {
		//mundo.tecla(key);
		if (key == 's' || key == 'S') {
			exit(0);
		}
	}
}

void Coordinador::mueve()
{

//gestiona cuando mueve cada jugador


}

void Coordinador::dibuja()
{
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Ajedrez", -10, 11);

	if (estado == INICIO) {
		
		//cout << "Inicio" << endl;
		
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
	else if (estado == JvJ) {
		tablero.dibuja();

		if (movs == 0)
		{
			tablero.inicializa();

			movs++;
		}

		else 
			tablero.dibujaPiezas(0);
			
	}
	else if (estado == JvAI)
	{

	}

}

