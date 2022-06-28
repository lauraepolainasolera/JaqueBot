#include "Tablero.h"
#define DIMENSION 8

using ETSIDI::SpriteSequence;

Tablero::Tablero() {
	

	for (int i = 0; i < DIMENSION;i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			if ((j % 2) == 0 && (i % 2) == 0)
			{
				PosicionReal[i][j].x = -4.2 + (i * 1.2);
				PosicionReal[i][j].y = 4.2 - (j * 1.2);
				//m[i][j].setPosicion(i, j);
			}

			else if ((j % 2) != 0 && (i % 2) == 0)
			{
				PosicionReal[i][j].x = -4.2 + (i * 1.2);
				PosicionReal[i][j].y = 4.2 - (j * 1.2);
				//m[i][j].setPosicion(i, j);
			}

			else if ((j % 2) == 0 && (i % 2) != 0)
			{
				PosicionReal[i][j].x = -4.2 + (i * 1.2);
				PosicionReal[i][j].y = 4.2 - (j * 1.2);
				//PosicionReal[i][j].setPosicion(i, j);
			}

			else if ((j % 2) != 0 && (i % 2) != 0)
			{
				PosicionReal[i][j].x = -4.2 + (i * 1.2);
				PosicionReal[i][j].y = 4.2 - (j * 1.2);
				//m[i][j].setPosicion(i, j);
			}

		}

	}

}


void Tablero::setLado(float l)
//Definición del tamaño del tablero
{
	lado = l;
}

void Tablero::dibuja()
//Dibujo del tablero
{

	
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/tablero0.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(-5, -5, 0);
	glTexCoord2d(1, 0); glVertex3f(-5, 5, 0);
	glTexCoord2d(1, 1); glVertex3f(5, 5, 0);
	glTexCoord2d(0, 1); glVertex3f(5, -5, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tablero::dibujaPiezas(int i, int j, int movs)
{
	//if (pi[i][j]->type == P) {

		glTranslatef(PosicionReal[i][j].x, PosicionReal[i][j].y, 0);
		glutSolidCube(1);
		glTranslatef(-PosicionReal[i][j].x, -PosicionReal[i][j].y, 0);

	

	/*glTranslatef(PosicionReal[i][j].x, PosicionReal[i][j].y, 0);
	glutWireCube(1);
	glTranslatef(-PosicionReal[i][j].x, -PosicionReal[i][j].y, 0);
	*/
	
	
	
}

void Tablero::inicializa()
{
	//se que esta mal, pero quiero saber como hacerlo bien

	pi[0][0] = new Pieza(TORRE, BLANCA);


	pi[7][0] = new Pieza(TORRE, BLANCA);
	pi[1][0] = new Pieza(CABALLO, BLANCA);
	pi[6][0] = new Pieza(CABALLO, BLANCA);
	pi[2][0] = new Pieza(ALFIL, BLANCA);
	pi[5][0] = new Pieza(ALFIL, BLANCA);
	pi[3][0] = new Pieza(REY, BLANCA);
	pi[4][0] = new Pieza(REINA, BLANCA);

	pi[0][7] = new Pieza(TORRE, NEGRA);//.setPieza(Tab[0][0].p, T, B);
	pi[7][7] = new Pieza(TORRE, NEGRA);
	pi[1][7] = new Pieza(CABALLO, NEGRA);
	pi[6][7] = new Pieza(CABALLO, NEGRA);
	pi[2][7] = new Pieza(ALFIL, NEGRA);
	pi[5][7] = new Pieza(ALFIL, NEGRA);
	pi[3][7] = new Pieza(REY, NEGRA);
	pi[4][7] = new Pieza(REINA, NEGRA);

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 1; j < DIMENSION-1; j++) { //Y

			if (j == 1)
				pi[i][j] = new Pieza(PEON, BLANCA);
			else if (j == 6)
				pi[i][j] = new Pieza(PEON, NEGRA);
			else
				pi[i][j] == new Pieza(VACIA, BLANCA);

		}
	}
	
}

