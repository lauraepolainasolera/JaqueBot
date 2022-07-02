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
#include "PiezaVacia.h"

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

Vector2D Tablero::obtenerPosicionesReales(Vector2D v) {
	int i = v.x;
	int j = v.y;

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
	return PosicionReal[i][j];
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

void Tablero::dibujaPiezas()
{
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			Vector2D posR = { 0,0 };
			posR = obtenerPosicionesReales(pi[i][j]->pos);
			pi[i][j]->dibuja(posR);
		}
	}
}


void Tablero::inicializa()
{
	pi[0][0] = new TorreBlanca();
	pi[7][0] = new TorreBlanca();
	pi[1][0] = new CaballoBlanco();
	pi[6][0] = new CaballoBlanco();
	pi[2][0] = new AlfilBlanco();
	pi[5][0] = new AlfilBlanco();
	pi[4][0] = new ReyBlanco();
	pi[3][0] = new ReinaBlanca();

	pi[0][7] = new TorreNegra();//.setPieza(Tab[0][0].p, T, B);
	pi[7][7] = new TorreNegra();
	pi[1][7] = new CaballoNegro();
	pi[6][7] = new CaballoNegro();
	pi[2][7] = new AlfilNegro();
	pi[5][7] = new AlfilNegro();
	pi[4][7] = new ReyNegro();
	pi[3][7] = new ReinaNegra();

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 1; j < DIMENSION-1; j++) { //Y

			if (j == 1)
			{
				pi[i][j] = new PeonBlanco();
			}

			else if (j == 6)
			{
				pi[i][j] = new PeonNegro();
			}
			else 
			{
				pi[i][j] = new PiezaVacia();
			}
		}
	}

	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			pi[i][j]->pos.x = i;
			pi[i][j]->pos.y = j;
		}
	}

	//dibujaPiezas();
	
}


Pieza* Tablero::obtenerPieza(Vector2D v) {
	int piezax = 0, piezay = 0;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (pi[i][j]->pos.x == v.x && pi[i][j]->pos.y == v.y) { //sobrecargar operador igual
				piezax = i;
				piezay = j;
				//cout << "Esta es su pieza:" << piezax << piezay << endl;
				return pi[piezax][piezay];
			}
			//cout << i << " " << j << " "<< pi[i][j]->pos.x<< " "<<pi[i][j]->pos.y<<endl;
		}
	}
}

Vector2D Tablero::obtenerPunteroPieza (Vector2D v) {
	Vector2D punt = { 0,0 };
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (pi[i][j]->pos.x == v.x && pi[i][j]->pos.y == v.y) { //sobrecargar operador igual
				punt.x = i;
				punt.y = j;
				return punt;
			}
		}
	}
}

void Tablero::setPieza(Pieza* origen, Pieza* destino) {
	Vector2D aux;
	//cout << "mi origen era" << origen->pos.x << origen->pos.y << endl;
	aux = destino->pos;
	destino->pos = origen->pos;
	origen->pos = aux;

	dibujaPiezas();
	//cout << "mi destino es" << origen->pos.x << origen->pos.y << endl;
	//cout << "soy la pieza origen y me he cambiado" << endl;
}

void Tablero::comerPieza(Pieza *destino) {
	Vector2D aux = destino->pos;
	Vector2D puntero = obtenerPunteroPieza(destino->pos);

	delete pi[(int)puntero.x][(int)puntero.y];
	pi[(int)puntero.x][(int)puntero.y] = new PiezaVacia();
	pi[(int)puntero.x][(int)puntero.y]->pos = aux;

	dibujaPiezas();

	cout << "soy la pieza comida" << destino->type << endl;
	  //situa la pieza vacia en la posicion correpondiente
	cout << "soy la pieza comida y tengo la posicion" << destino->pos.x << destino->pos.y << endl;
	
	cout << "he comido" << endl;
}

void Tablero::mueve(Vector2D origen, Vector2D destino) {
	cout << "es el movimiento numero " << movimiento << endl;

	Pieza* orig = obtenerPieza(origen);
	Pieza* dest = obtenerPieza(destino);

	//cout << orig->movimientoValido(origen, destino) << endl;
	if (orig->movimientoValido(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento,orig) && casillaVacia(destino))
	{
		setPieza(orig, dest);
		if (evaluaEnclavamiento()) setPieza(dest, orig);
	}

	else if (orig->movimientoComer(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento, orig) && (casillaVacia(destino) == false))
	{
		setPieza(orig, dest);
		comerPieza(dest);
		if (evaluaEnclavamiento()) setPieza(dest, orig);
		//else comerPieza();
	}

	else
	{
		cout << "movimiento invalido" << endl;
		dibujaPiezas();
	}
}

bool Tablero::obstaculo(Vector2D origen, Vector2D destino) {
	//cout << "he entrado" << endl;
	//cout << "origen:" << origen.x << origen.y << endl;
	//cout << "destino:" << destino.x << destino.y << endl;
	Vector2D res = destino - origen;
	//cout << "resta" << res.x << res.y << endl;

	int ocupacion = 0;
	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x,y positiva
		//cout << "diagonal con coordenadas x,y positiva" << endl;
		int i = origen.x + 1;
		int j = origen.y + 1;

		while (i < destino.x && j<destino.y) {
			Vector2D v;
			v.x = i;
			v.y = j;
			if (casillaVacia(v) == false)
				ocupacion++;
			i++;
			j++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x,y negativa
		//cout << "diagonal con coordenadas x,y negativa" << endl;
		int i = origen.x - 1;
		int j = origen.y - 1;

		while (i > destino.x && j > destino.y) {
			Vector2D v;
			v.x = i;
			v.y = j;
			if (casillaVacia(v) == false)
				ocupacion++;
			i--;
			j--;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x negativa, y positiva
		//cout << "diagonal con coordenadas x negativa y positiva" << endl;
		int i = origen.x - 1;
		int j = origen.y + 1;

		while (i > destino.x && j < destino.y) {
			Vector2D v;
			v.x = i;
			v.y = j;
			if (casillaVacia(v) == false)
				ocupacion++;
			i--;
			j++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x positiva, y negativa
		//cout << "diagonal con coordenadas x positiva y negativa" << endl;
		int i = origen.x + 1;
		int j = origen.y-1;
	
		while (i < destino.x && j>destino.y) {
			Vector2D v;
			v.x = i;
			v.y = j;
			if (casillaVacia(v) == false)
				ocupacion++;
			i++;
			j--;
		}
	}

	if ((origen.x == destino.x) && (origen.y < destino.y)) { // desplazarse en y positiva
		//cout << "desplazarse y positiva" << endl;
		for (int j = origen.y + 1; j < destino.y; j++) {
			Vector2D v;
			v.x = origen.x;
			v.y = j;

			if (casillaVacia(v) == false)
				ocupacion++;
			//cout << casillaVacia(v) << endl;
		}
	}

	if ((origen.x == destino.x) && (origen.y > destino.y)) { //desplazarse y negativa
		//cout << "desplazarse y negativa" << endl;
		for (int j = origen.y - 1; j > destino.y; j--) {
			Vector2D v;
			v.x = origen.x;
			v.y = j;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}

	if ((origen.x < destino.x) && (origen.y == destino.y)) { //Desplazarse x positiva
		//cout << "desplazarse x positiva" << endl;
		for (int i = origen.x + 1; i < destino.x; i++) {
			Vector2D v;
			v.x = i;
			v.y = origen.y;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}

	if ((origen.x > destino.x) && (origen.y == destino.y)) { //desplazarse x negativa
		//cout << "desplazarse x negativa" << endl;
		for (int i = origen.x - 1; i > destino.x; i--) {
			Vector2D v;
			v.x = i;
			v.y = origen.y;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}
	if (ocupacion >= 1) {
		//cout << "hay un obstaculo" << endl;
		return true;
	}
	else
		return false; //tambien puede ser un caballo
}


bool Tablero::casillaVacia(Vector2D pos) {
	//cout << "soy casilla vacia" << endl;
	Pieza* p = obtenerPieza(pos);
	//cout << "soy del tipo" << obtenerTipo(p) << endl;
	if (obtenerTipo(p) == VACIA)
		return true;
	else
		return false;
}

bool Tablero::setTurno(int mov, Pieza* p) {
	if ((mov % 2 == 0) && p->colour == BLANCA)
		return true;
	else if ((mov % 2 != 0) && p->colour == NEGRA)
		return true;
	else
	{
		cout << "es el turno del otro jugador" << endl;
		return false;
	}
}

bool Tablero::jaque(Vector2D rey, Pieza* ataq)
{
	if (ataq->movimientoValido(ataq->pos, rey) && obstaculo(rey, ataq->pos) == false) {
		//cout << "jaque" << endl;
		return true;
	}
	else return false;
}

int Tablero::jaqueReal()
{
	if (movimiento % 2 == 0) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { float(i),float(j) };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == NEGRA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { float(k), float(l) };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) {
								cout << "jaque NEGRAS1" << endl;
								return 1;
							}
						}
					}
				}
				else if (aux->type == REY && aux->colour == BLANCA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { float(k), float(l) };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) {
								cout << "jaque BLANCAS1" << endl;
								return 2;
							}
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { float(i),float(j) };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == BLANCA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { float(k), float(l) };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) {
								cout << "jaque BLANCAS2" << endl;
								return 2;
							}
						}
					}
				}
				else if (aux->type == REY && aux->colour == NEGRA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { float(k), float(l) };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) {
								cout << "jaque NEGRAS2" << endl;
								return 1;
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}

bool Tablero::evaluaEnclavamiento()
{
	int jr = jaqueReal();
	cout << "Hay jaque del tipo" << jr << endl;
	if (jr == 1 && movimiento % 2 == 0) {
		//cout << "jaque" << endl;
		movimiento++;
		cout << "es el turno de las negras" << endl;
		return false;
	}
	else if (jr == 2 && movimiento % 2 == 0) {
		cout << "Con ese movimiento te produces un jaque" << endl;
		return true;
	}
	else if (jr == 1 && movimiento % 2 == 1) {
		cout << "Con ese movimiento te produces un jaque" << endl;
		return true;
	}
	else if (jr == 2 && movimiento % 2 == 1) {
		//cout << "jaque" << endl;
		movimiento++;
		cout << "es el turno de las blancas" << endl;
		return false;
	}
	else movimiento++; return false;
}
