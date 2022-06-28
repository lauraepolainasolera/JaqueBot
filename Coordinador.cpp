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

	if (key == '0')
	{
		movs++;
	}

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
		if (int movs = 0)

		if (movs == 0)
		{
			tablero.inicializa();

			printf("yaestoy");

			for (int i = 0; i < DIMENSION; i++)
			{
				for (int j=0 ;j < DIMENSION;j++)
				{
					
					//cout << tablero.pi[i][j]->colour << tablero.pi[i][j]->type << endl;
					tablero.dibujaPiezas(i, j, 0);
				}
			}
			
		}

		else 
			for (int i = 0; i < DIMENSION; i++)
			{
				for (int j = 0;j < DIMENSION;j++)
				{
					
					tablero.dibujaPiezas(i, j, 0);
				}
			}

	}
	else if (estado == JvAI)
	{

	}

}

V2D Coordinador::seleccionarCasilla() {
	V2D retorno;
	if (ratonEstado == GLUT_DOWN) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (pulsaRect(270 + 34 * i, 170 + 34 * j, 300 + 34 * i, 200 + 34 * j)) {
					if (pi[i][j].type != VACIA) return retorno;
				}
			}
		}
		return NULL;
	}
	return NULL;
}

void Coordinador::setRaton(V2D pos, int e) {
	ratonPos = pos;
	ratonEstado = e;
}

bool Coordinador::pulsaRect(float x1, float y1, float x2, float y2) {
	if (x1 < ratonPos.x && ratonPos.x < x2 && y1 < ratonPos.y && ratonPos.y < y2) return true;
	else return false;
}
