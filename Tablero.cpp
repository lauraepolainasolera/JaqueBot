#include "Tablero.h"
#include "ReyBlanco.h"
#include "ReyNegro.h"
#define DIMENSION 8

using ETSIDI::SpriteSequence;

Tablero::Tablero() {
	

	for (int j = 0; j < DIMENSION;j++)
	{
		for (int i = 0; i < DIMENSION; i++)
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

	pi[0][0] = new Pieza(TORRE, BLANCA);
	pi[0][7] = new Pieza(TORRE, BLANCA);
	pi[0][1] = new Pieza(CABALLO, BLANCA);
	pi[0][6] = new Pieza(CABALLO, BLANCA);
	pi[0][2] = new Pieza(ALFIL, BLANCA);
	pi[0][5] = new Pieza(ALFIL, BLANCA);
	pi[0][3] = new ReyBlanco();
	pi[0][3]->dibuja(PosicionReal[0][3]);

	pi[0][4] = new Pieza(REINA, BLANCA);

	pi[7][0] = new Pieza(TORRE, NEGRA);//.setPieza(Tab[0][0].p, T, B);
	pi[7][7] = new Pieza(TORRE, NEGRA);
	pi[7][1] = new Pieza(CABALLO, NEGRA);
	pi[7][6] = new Pieza(CABALLO, NEGRA);
	pi[7][2] = new Pieza(ALFIL, NEGRA);
	pi[7][5] = new Pieza(ALFIL, NEGRA);
	pi[7][4] = new ReyNegro();
	pi[7][4]->dibuja(PosicionReal[7][4]);
	pi[7][3] = new Pieza(REINA, NEGRA);

	for (int i = 1; i < DIMENSION-1; i++) {  //X
		for (int j = 0; j < DIMENSION; j++) { //Y

			if (i == 1)
			{
				pi[i][j] = new Pieza(PEON, BLANCA);

			}

			else if (i == 6)
			{
				pi[i][j] = new Pieza(PEON, NEGRA);
				
			}
			else 
			{
				pi[i][j] = new Pieza(VACIA, NEGRA);
				
			}
		}
	}
	
}

