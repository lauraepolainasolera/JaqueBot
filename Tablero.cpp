#include "Tablero.h"
#define DIMENSION 8

Tablero::Tablero() :tablero0("bin/tablero0.png", 1, 1, 220) 
//Constructor de tablero y definición de cada espacio de la matriz respecto al espacio de dibujo
{
	

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

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("tablero0.png").id);
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

void Tablero::dibujaPiezas(int i, int j, int mov)
{

	
}

void Tablero::inicializa()
{
	//sequeestamal, pero quiero saber como hacerlo bien

	/*
	Pieza p(P, N);

	m[0][0] = p(T, B);//.setPieza(Tab[0][0].p, T, B);

	m[7][0](T, B);

	m[1][0] = Pieza(C, B);

	m[6][0] = Pieza * (C, B);
	m[2][0] = Pieza * (A, B);
	m[5][0] = Pieza * (A, B);
	m[3][0] = Pieza * (K, B);
	m[4][0] = Pieza * (Q, B);

	m[0][0] = Pieza * (T, N);//.setPieza(Tab[0][0].p, T, B);
	m[7][0] = Pieza * (T, N);
	m[1][0] = Pieza * (C, N);
	m[6][0] = Pieza * (C, N);
	m[2][0] = Pieza * (A, N);
	Tab[5][0] = Pieza * (A, N);
	Tab[3][0] = Pieza * (K, N);
	Tab[4][0] = Pieza * (Q, N);

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 0; j < DIMENSION; j++) { //Y

			if (j == 1)
				m[i][j] = Pieza * (P, B);
			else if (j == 6)
				m[i][j] = Pieza * (P, N);
			else
				m[i][j] == NULL;

		}
	}
	*/
}

