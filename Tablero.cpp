#include "Tablero.h"
#include "ReyBlanco.h"
#include "ReyNegro.h"
#include "TorreBlanca.h"
#include "TorreNegra.h"
#include "CaballoBlanco.h"
#include "CaballoNegro.h"
#include "AlfilBlanco.h"
#include "AlfilNegro.h"
#include "ReinaBlanca.h"
#include "ReinaNegra.h"
#include "PeonBlanco.h"
#include "PeonNegro.h"

#define DIMENSION 8

using ETSIDI::SpriteSequence;

Tablero::Tablero() {
	

	for (int j = 0; j < DIMENSION;j++)
	{
		for (int i = 0; i < DIMENSION; i++)
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
	glTexCoord2d(0, 0); glVertex3f(5, 5, 0);
	glTexCoord2d(1, 0); glVertex3f(5, -5, 0);
	glTexCoord2d(1, 1); glVertex3f(-5, -5, 0);
	glTexCoord2d(0, 1); glVertex3f(-5, 5, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tablero::dibujaPiezas(int i, int j, int movs)
{
	
	
}

void Tablero::inicializa()
{
	//se que esta mal, pero quiero saber como hacerlo bien

	pi[0][0] = new TorreBlanca();
	pi[0][0]->dibuja(PosicionReal[0][0]);
	pi[7][0] = new TorreBlanca();
	pi[7][0]->dibuja(PosicionReal[7][0]);
	pi[1][0] = new CaballoBlanco();
	pi[1][0]->dibuja(PosicionReal[1][0]);
	pi[6][0] = new CaballoBlanco();
	pi[6][0]->dibuja(PosicionReal[6][0]);
	pi[2][0] = new AlfilBlanco();
	pi[2][0]->dibuja(PosicionReal[2][0]);
	pi[5][0] = new AlfilBlanco();
	pi[5][0]->dibuja(PosicionReal[5][0]);
	pi[4][0] = new ReyBlanco();
	pi[4][0]->dibuja(PosicionReal[4][0]);

	pi[3][0] = new ReinaBlanca();
	pi[3][0]->dibuja(PosicionReal[3][0]);

	pi[0][7] = new TorreNegra();//.setPieza(Tab[0][0].p, T, B);
	pi[0][7]->dibuja(PosicionReal[0][7]);
	pi[7][7] = new TorreNegra();
	pi[7][7]->dibuja(PosicionReal[7][7]);
	pi[1][7] = new CaballoNegro();
	pi[1][7]->dibuja(PosicionReal[1][7]);
	pi[6][7] = new CaballoNegro();
	pi[6][7]->dibuja(PosicionReal[6][7]);
	pi[2][7] = new AlfilNegro();
	pi[2][7]->dibuja(PosicionReal[2][7]);
	pi[5][7] = new AlfilNegro();
	pi[5][7]->dibuja(PosicionReal[5][7]);
	pi[4][7] = new ReyNegro();
	pi[4][7]->dibuja(PosicionReal[4][7]);
	pi[3][7] = new ReinaNegra();
	pi[3][7]->dibuja(PosicionReal[3][7]);

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 1; j < DIMENSION-1; j++) { //Y

			if (j == 1)
			{
				pi[i][j] = new PeonBlanco();
				pi[i][j]->dibuja(PosicionReal[i][j]);

			}

			else if (j == 6)
			{
				pi[i][j] = new PeonNegro();
				pi[i][j]->dibuja(PosicionReal[i][j]);
				
			}
			else 
			{
				pi[i][j] = new Pieza(VACIA, NEGRA);
				pi[i][j]->dibuja(PosicionReal[i][j]);
				
			}
		}
	}
	
}

