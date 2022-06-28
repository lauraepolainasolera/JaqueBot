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
				PosicionReal[i][j].x = -4.2 + (j * 1.2);
				PosicionReal[i][j].y = 4.2 - (i * 1.2);
				//m[i][j].setPosicion(i, j);
			}

			else if ((j % 2) != 0 && (i % 2) == 0)
			{
				PosicionReal[i][j].x = -4.2 + (j * 1.2);
				PosicionReal[i][j].y = 4.2 - (i * 1.2);
				//m[i][j].setPosicion(i, j);
			}

			else if ((j % 2) == 0 && (i % 2) != 0)
			{
				PosicionReal[i][j].x = -4.2 + (j * 1.2);
				PosicionReal[i][j].y = 4.2 - (i * 1.2);
				//PosicionReal[i][j].setPosicion(i, j);
			}

			else if ((j % 2) != 0 && (i % 2) != 0)
			{
				PosicionReal[i][j].x = -4.2 + (j * 1.2);
				PosicionReal[i][j].y = 4.2 - (i * 1.2);
				//m[i][j].setPosicion(i, j);
			}

		}

	}

	p = new Pieza * [DIMENSION];
	for (int f = 0; f < DIMENSION; f++){
		p[f] = new Pieza [DIMENSION];
	}

}


void Tablero::setLado(float l)
//Definición del tamaño del tablero
{
	lado = l;
}


void Tablero::inicializa()
{
	p[0][0] = Pieza(T, B);
	p[7][0] = Pieza(T, B);
	p[1][0] = Pieza(C, B);
	p[6][0] = Pieza(C, B);
	p[2][0] = Pieza(A, B);
	p[5][0] = Pieza(A, B);
	p[3][0] = Pieza(Q, B);
	p[4][0] = Rey(B);

	p[0][7] = Pieza(T, N);//.setPieza(Tab[0][0].p, T, B);
	p[7][7] = Pieza(T, N);
	p[1][7] = Pieza(C, N);
	p[6][7] = Pieza(C, N);
	p[2][7] = Pieza(A, N);
	p[5][7] = Pieza(A, N);
	p[3][7] = Pieza(Q, N);
	p[4][7] = Rey(N);

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 1; j < DIMENSION - 1; j++) { //Y

			if (j == 1)
				p[i][j] =Pieza(P, B);
			else if (j == 6)
				p[i][j] = Pieza(P, N);
			else
				p[i][j] = Pieza(V, B);

		}
	}
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

void Tablero::dibujaPiezas(int i, int j)
{
	if (p[i][j].type == T) {
		glTranslatef(PosicionReal[i][j].x, PosicionReal[i][j].y, 0);
		glutSolidCube(1);
		glTranslatef(-PosicionReal[i][j].x, -PosicionReal[i][j].y, 0);
	}
	/*glTranslatef(PosicionReal[i][j].x, PosicionReal[i][j].y, 0);
	glutWireCube(1);
	glTranslatef(-PosicionReal[i][j].x, -PosicionReal[i][j].y, 0);
	*/
	
	
	
}

