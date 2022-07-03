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
	jm = false;
}

Vector2D Tablero::obtenerPosicionesReales(Vector2D v) {
	int i = v.x;
	int j = v.y;
	
		PosicionReal[i][j].x = -4.2 + (j * 1.2);
		PosicionReal[i][j].y = 4.2 - (i * 1.2);

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
	//Dibujo de las casillas del tablero
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/tablero0.png").id);
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

	//Dibujo de las coordenadas del tablero
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/CoordenadasTab.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(5.7, 5.8, 0);
	glTexCoord2d(1, 0); glVertex3f(5.7, -5.8, 0);
	glTexCoord2d(1, 1); glVertex3f(-5.9, -5.8, 0);
	glTexCoord2d(0, 1); glVertex3f(-5.9, 5.8, 0);
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

void Tablero::inicializaModoLocura()
{

	int a;
	int b;

	a = rand() %DIMENSION - 1; 
	b = rand() %DIMENSION - 1;
	
	
	pi[0][0] = new TorreBlanca();
	pi[7][0] = new TorreBlanca();
	pi[1][0] = new CaballoBlanco();
	pi[6][0] = new CaballoBlanco();
	pi[2][0] = new AlfilBlanco();
	pi[5][0] = new AlfilBlanco();
	pi[4][0] = new ReyBlanco();
	pi[3][0] = new ReinaBlanca();
	pi[0][7] = new TorreNegra();
	pi[7][7] = new TorreNegra();
	pi[1][7] = new CaballoNegro();
	pi[6][7] = new CaballoNegro();
	pi[2][7] = new AlfilNegro();
	pi[5][7] = new AlfilNegro();
	pi[4][7] = new ReyNegro();
	pi[3][7] = new ReinaNegra();

	for (int i = 0; i < DIMENSION; i++) {  //X
		for (int j = 2 ; j < 6; j++) { //Y
			{
				pi[i][j] = new PiezaVacia();
			}
		}
	}

	for (int j = 0; j < DIMENSION; j++) {
		if (a == j) {
			pi[j][1] = new TorreBlanca();
		}
		else 
			pi[j][1] = new PeonBlanco();
	}

	for (int j = 0; j < DIMENSION; j++) {
		if (b == j) {
			pi[j][6] = new TorreNegra();
		}
		else
			pi[j][6] = new PeonNegro();
	}

	
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			pi[i][j]->pos.x = i;
			pi[i][j]->pos.y = j;
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

	pi[0][7] = new TorreNegra();
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
	
}

Pieza* Tablero::obtenerPieza(Vector2D v) {
	int piezax = 0, piezay = 0;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (pi[i][j]->pos.x == v.x && pi[i][j]->pos.y == v.y) { //sobrecargar operador igual
				piezax = i;
				piezay = j;
				return pi[piezax][piezay];
			}
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

void Tablero::mueve(Vector2D origen, Vector2D destino) {

	cout << "es el movimiento numero " << movimiento << endl;

	Pieza* orig = obtenerPieza(origen);
	Pieza* dest = obtenerPieza(destino);

	/*cout << orig->movimientoValido(origen, destino) << endl*/;
	if (orig->movimientoValido(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento, orig) && (casillaVacia(destino)) && (enroque(origen, destino) == false)) {

		setPieza(orig, dest);
		if (evaluaEnclavamiento()) {
			setPieza(dest, orig);
		}
		else 
			ETSIDI::play("bin/sonidos/mover.wav");


		orig=coronar(orig);				//comprueba si la pieza ha coronado
		jm = jaqueMate();
	}

	else if (setTurno(movimiento, orig) && (enroque(origen, destino) == true)) {
		//cout << "voy a enrocar" << endl;
		enroque(orig, dest);
		orig->mov;
		if (evaluaEnclavamiento()) {
			desEnroque(dest, orig);
			orig->mov--;
		}
		else
			ETSIDI::play("bin/sonidos/mover.wav");

		jm = jaqueMate();
	}


	else if (orig->movimientoComer(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento, orig) && (casillaVacia(destino) == false) && (dest->colour != orig->colour)) {
		tipo t = dest->type;
		color c = dest->colour;
	
		dest = comerPieza(orig, dest);

			if (evaluaEnclavamiento()) {
				dest = cambiarTipoPieza(dest, t, c, dest->pos);
				setPieza(dest, orig);
			}
			else
				ETSIDI::play("bin/sonidos/comer.wav");
			
		orig=coronar(orig);
		jm = jaqueMate();
	}

	else{
		cout << "movimiento invalido" << endl;
		ETSIDI::play("bin/sonidos/error.wav");
	}

	dibujaPiezas();
}

void Tablero::setPieza(Pieza* origen, Pieza* destino) {
	Vector2D aux;
	aux = destino->pos;
	destino->pos = origen->pos;
	origen->pos = aux;

}

Pieza* Tablero::comerPieza(Pieza* origen, Pieza *destino) {

	setPieza(origen, destino);
	destino = cambiarTipoPieza(destino, VACIA, BLANCA, destino->pos);

	return destino;

}

Pieza* Tablero::coronar(Pieza* p) {
	char letra;

	Vector2D aux = p->pos;

	if ((p->colour == BLANCA && p->pos.y == 7 && p->type == PEON) || (p->colour == NEGRA && p->pos.y == 1 && p->type == PEON)) {
		cout << "Has coronado. Pulsa la inicial de la pieza que quieras" << endl;
		cin >> letra;
		switch (letra) {
		case 'r':
			p=cambiarTipoPieza(p, REINA, p->colour,aux);
			break;
		case 't':
			p=cambiarTipoPieza(p, TORRE, p->colour,aux);
			break;
		case 'a':
			p=cambiarTipoPieza(p, ALFIL, p->colour,aux);
			break;
		case 'c':
			p=cambiarTipoPieza(p, CABALLO, p->colour,aux);
			break;
		case 'p':
			p=cambiarTipoPieza(p, PEON, p->colour,aux);
			break;
		}
		dibujaPiezas();
		return p;
	}
}

Pieza* Tablero::cambiarTipoPieza(Pieza* p, tipo t, color c, Vector2D posicion) {
	Vector2D puntero = { 0,0 };
	puntero = obtenerPunteroPieza(p->pos);
	delete pi[(int)puntero.x][(int)puntero.y];				//eliminamos el puntero de la pieza comida

	switch (t) {
	case VACIA:
		pi[(int)puntero.x][(int)puntero.y] = new PiezaVacia(); //creamos ese mismo puntero, pero de la clase concreta
		break;
	case ALFIL:
		if (c == BLANCA)
			pi[(int)puntero.x][(int)puntero.y] = new AlfilBlanco();
		else
			pi[(int)puntero.x][(int)puntero.y] = new AlfilNegro();
		break;
	case CABALLO:
		if (c == BLANCA)
			pi[(int)puntero.x][(int)puntero.y] = new CaballoBlanco();
		else
			pi[(int)puntero.x][(int)puntero.y] = new CaballoNegro();
		break;
	case TORRE:
		if (c == BLANCA)
			pi[(int)puntero.x][(int)puntero.y] = new TorreBlanca();
		else
			pi[(int)puntero.x][(int)puntero.y] = new TorreNegra();
		break;
	case REINA:
		if (c == BLANCA)
			pi[(int)puntero.x][(int)puntero.y] = new ReinaBlanca();
		else
			pi[(int)puntero.x][(int)puntero.y] = new ReinaNegra();
		break;
	case PEON:
		if (c == BLANCA)
			pi[(int)puntero.x][(int)puntero.y] = new PeonBlanco();
		else
			pi[(int)puntero.x][(int)puntero.y] = new PeonNegro();
		break;

	}

	pi[(int)puntero.x][(int)puntero.y]->pos = posicion;
	return pi[(int)puntero.x][(int)puntero.y];

}

bool Tablero::obstaculo(Vector2D origen, Vector2D destino) {
	Vector2D res = destino - origen;

	int ocupacion = 0;
	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x,y positiva
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
		for (int j = origen.y + 1; j < destino.y; j++) {
			Vector2D v;
			v.x = origen.x;
			v.y = j;

			if (casillaVacia(v) == false)
				ocupacion++;
			cout << casillaVacia(v) << endl;
		}
	}

	if ((origen.x == destino.x) && (origen.y > destino.y)) { //desplazarse y negativa
		for (int j = origen.y - 1; j > destino.y; j--) {
			Vector2D v;
			v.x = origen.x;
			v.y = j;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}

	if ((origen.x < destino.x) && (origen.y == destino.y)) { //Desplazarse x positiva
		for (int i = origen.x + 1; i < destino.x; i++) {
			Vector2D v;
			v.x = i;
			v.y = origen.y;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}

	if ((origen.x > destino.x) && (origen.y == destino.y)) { //desplazarse x negativa
		for (int i = origen.x - 1; i > destino.x; i--) {
			Vector2D v;
			v.x = i;
			v.y = origen.y;

			if (casillaVacia(v) == false)
				ocupacion++;
		}
	}
	if (ocupacion >= 1) {
		cout << "hay un obstaculo" << endl;
		return true;
	}
	else
		return false; //tambien puede ser un caballo
}

bool Tablero::casillaVacia(Vector2D pos) {
	Pieza* p = obtenerPieza(pos);
	if (p->type == VACIA)
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
	if (ataq->movimientoComer(ataq->pos, rey) && obstaculo(rey, ataq->pos) == false) {
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
				Vector2D pos = { 0,0 };
				pos.x = i;
				pos.y = j;
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == NEGRA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
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
							Vector2D pos2 = { (float)k, (float)l };
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
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);

				if (aux->type == REY && aux->colour == BLANCA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
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
							Vector2D pos2 = { (float)k, (float)l };
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
	//cout << "Hay jaque del tipo" << jr << endl;
	if (jr == 1 && movimiento % 2 == 0) {
		//cout << "jaque" << endl;
		movimiento++;
		cout << "Turno negras" << endl;
		return false;
	}
	else if (jr == 2 && movimiento % 2 == 0) {
		cout << "Con ese movimiento te produces un jaque. Turno blancas" << endl;
		return true;
	}
	else if (jr == 1 && movimiento % 2 == 1) {
		cout << "Con ese movimiento te produces un jaque. Turno negras" << endl;
		return true;
	}
	else if (jr == 2 && movimiento % 2 == 1) {
		//cout << "jaque" << endl;
		movimiento++;
		cout << "Turno blancas" << endl;
		return false;
	}
	else movimiento++; return false;
}

void Tablero::mostrarMovimiento(Vector2D origen, Vector2D destino) {

	Vector2D posRealOrigen = obtenerPosicionesReales(origen), posRealDestino = obtenerPosicionesReales(destino);
	glColor3ub(255, 255, 0);
	glTranslatef(posRealOrigen.x, posRealOrigen.y, 0);
	glutSolidCube(1.0);
	glTranslatef(-posRealOrigen.x, -posRealOrigen.y, 0);

	glColor3ub(255, 255, 0);
	glTranslatef(posRealDestino.x, posRealDestino.y, 0);
	glutWireCube(1.0);
	glTranslatef(-posRealDestino.x, -posRealDestino.y, 0);

}

void Tablero::mostrarJaque() {
	if (jaqueReal() == 1) {
		Vector2D posRealRey = obtenerPosicionesReales(pi[4][7]->pos);
		glColor3ub(255, 0, 0);
		glTranslatef(posRealRey.x +0.1, posRealRey.y, 0);
		glutSolidTorus(0.05, 0.5, 100, 100);
		glTranslatef(-posRealRey.x -0.1, -posRealRey.y, 0);
	}

	if (jaqueReal() == 2) {
		Vector2D posRealRey = obtenerPosicionesReales(pi[4][0]->pos);
		glColor3ub(255, 0, 0);
		glTranslatef(posRealRey.x -0.1, posRealRey.y, 0);
		glutSolidTorus(0.05, 0.5, 100, 100);
		glTranslatef(-posRealRey.x +0.1, -posRealRey.y, 0);
	}
	

}

int Tablero::buscaAdyacentes(Vector2D p, Vector2D* prox[8])
{

	int k = 0;
	for (int i = p.x - 1; i <= p.x + 1; i++) {
		for (int j = p.y - 1; j <= p.y + 1; j++) {
			if ((i == p.x && j == p.y) || (j == DIMENSION) || (i == DIMENSION) || (j < 0) || (i < 0))continue;
			prox[k] = new Vector2D{ (float)i,(float)j };
			//cout << "Coordenadas proximas al rey" << prox[k]->x << prox[k]->y << endl;
			k++;
		}
	}

	return k;
}

Pieza* Tablero::piezaJaque()
{
	if (movimiento % 2 == 0) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == NEGRA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if ((aux2->colour != aux->colour || aux2->type != VACIA) && jaque(pos, aux2)) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
				else if (aux->type == REY && aux->colour == BLANCA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == BLANCA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
				else if (aux->type == REY && aux->colour == NEGRA) {
					//cout << "Tengo un rey de color "<< aux->colour << endl;
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							//cout << "Tengo..." << aux2->type << "de color" << aux2->colour << endl;
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								//cout << "Evita" << endl;
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
			}
		}
	}
}

int Tablero::trayectoria(Vector2D origen, Vector2D destino, Vector2D* tray[6])
{
	Vector2D res = destino - origen;
	int k = 0;
	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x,y positiva
		//cout << "diagonal con coordenadas x,y positiva" << endl;
		int i = origen.x + 1;
		int j = origen.y + 1;
		while (i < destino.x && j < destino.y) {
			//cout << "la trayectoria es" << i << j << endl;
			tray[k] = new Vector2D{ (float)i, (float)j };
			i++;
			j++;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x,y negativa
		//cout << "diagonal con coordenadas x,y negativa" << endl;
		int i = origen.x - 1;
		int j = origen.y - 1;

		while (i > destino.x && j > destino.y) {
			//cout << "la trayectoria es" << i << j << endl;
			tray[k] = new Vector2D{ (float)i, (float)j };
			i--;
			j--;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x negativa, y positiva
		//cout << "diagonal con coordenadas x negativa y positiva" << endl;
		int i = origen.x - 1;
		int j = origen.y + 1;

		while (i > destino.x && j < destino.y) {
			//cout << "la trayectoria es" << i << j << endl;
			tray[k] = new Vector2D{ (float)i, (float)j };
			i--;
			j++;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x positiva, y negativa
		//cout << "diagonal con coordenadas x positiva y negativa" << endl;
		int i = origen.x + 1;
		int j = origen.y - 1;

		while (i < destino.x && j>destino.y) {
			//cout << "la trayectoria es" << i << j << endl;
			tray[k] = new Vector2D{ (float)i, (float)j };
			i++;
			j--;
			k++;
		}
	}

	if ((origen.x == destino.x) && (origen.y < destino.y)) { // desplazarse en y positiva
		//cout << "desplazarse y positiva" << endl;
		for (int j = origen.y + 1; j < destino.y; j++) {
			//cout << "la trayectoria es" << origen.x << j << endl;
			tray[k] = new Vector2D{ (float)origen.x, (float)j };
			k++;
		}
	}

	if ((origen.x == destino.x) && (origen.y > destino.y)) { //desplazarse y negativa
		//cout << "desplazarse y negativa" << endl;
		for (int j = origen.y - 1; j > destino.y; j--) {
			//cout << "la trayectoria es" << origen.x << j << endl;
			tray[k] = new Vector2D{ (float)origen.x, (float)j };
			k++;
		}
	}

	if ((origen.x < destino.x) && (origen.y == destino.y)) { //Desplazarse x positiva
		//cout << "desplazarse x positiva" << endl;
		for (int i = origen.x + 1; i < destino.x; i++) {
			//cout << "la trayectoria es" << i << origen.y << endl;
			tray[k] = new Vector2D{ (float)i, (float)origen.y };
			k++;
		}
	}

	if ((origen.x > destino.x) && (origen.y == destino.y)) { //desplazarse x negativa
		//cout << "desplazarse x negativa" << endl;
		for (int i = origen.x - 1; i > destino.x; i--) {
			//cout << "la trayectoria es" << i << origen.y << endl;
			tray[k] = new Vector2D{ (float)i, (float)origen.y };
			k++;
		}
	}
	return k;
}

bool Tablero::jaqueMate()
{
	
	int jr = jaqueReal();
	int jm = 0;
	//Vector2D* aux[8];
	Pieza* rey;

	if (jr == 1) {
		Pieza* aux3 = piezaJaque();
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == NEGRA) { //busca el rey negro
					Vector2D* prox[8];
					int numero = buscaAdyacentes(aux->pos, prox);
					//cout << "el numero es " << numero << endl;
					for (int k = 0; k < numero; k++) {
						//cout << prox[k]->x << prox[k]->y << endl;
						Pieza* aux2 = obtenerPieza(*prox[k]);
						//cout << aux2->type << aux2->colour << endl;
						if (aux2->type == VACIA) {
							setPieza(aux, aux2);
							if (jaqueReal() != 1) jm++;
							setPieza(aux2, aux);
						}
					}
					rey = aux;
				}
			}
		}
		Vector2D* tray[10];
		int numero2 = trayectoria(rey->pos, aux3->pos, tray);
		//cout << "el tamaño de las trayectorias es..." << numero2 << endl;
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type != REY && aux->colour == NEGRA) { //busca el resto de las piezas negras
					for (int l = 0; l < numero2; l++) {
						//cout << tray[l]->x << tray[l]->y << endl;
						if (aux->movimientoValido(aux->pos, *tray[l]) || aux->movimientoComer(aux->pos, aux3->pos)) jm++;
					}
				}
			}
		}
		if (jm >= 1) {
			cout << "tienes salvacion" << endl;
			return false;
		}
		else {
			cout << "Has perdido amigo. GANAN LAS BLANCAS" << endl;
			return true;
		}

	}
	else if (jr == 2) {
		Pieza* aux3 = piezaJaque();
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type == REY && aux->colour == BLANCA) { //busca el rey BLANCO
					Vector2D* prox[8];
					int numero = buscaAdyacentes(aux->pos, prox);
					//cout << "el numero es " << numero << endl;
					for (int k = 0; k < numero; k++) {
						//cout << prox[k]->x << prox[k]->y << endl;
						Pieza* aux2 = obtenerPieza(*prox[k]);
						//cout << aux2->type << aux2->colour << endl;
						if (aux2->type == VACIA) {
							setPieza(aux, aux2);
							if (jaqueReal() != 1) jm++;
							setPieza(aux2, aux);
						}
					}
					rey = aux;
				}
			}
		}
		Vector2D* tray[10];
		int numero2 = trayectoria(rey->pos, aux3->pos, tray);
		//cout << "el tamaño de las trayectorias es..." << numero2 << endl;
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type != REY && aux->colour == BLANCA) { //busca el resto de las piezas BLANCAS
					for (int l = 0; l < numero2; l++) {
						//cout << tray[l]->x << tray[l]->y << endl;
						if (aux->movimientoValido(aux->pos, *tray[l]) || aux->movimientoComer(aux->pos, aux3->pos)) jm++;
					}
				}
			}
		}
		if (jm >= 1) {
			cout << "tienes salvacion" << endl;
			return false;
		}
		else {
			cout << "Has perdido amigo. GANAN LAS NEGRAS" << endl;
			return true;
		}
	}
}

bool Tablero::enroque(Vector2D origen, Vector2D destino)
{
	if (((origen.x == destino.x - 2) || (origen.x == destino.x + 2)) && (origen.y == destino.y)) {
		//cout << "estoy dentro" << endl;
		Pieza* rey = obtenerPieza(origen);
		Vector2D aux1 = { destino.x - 2, destino.y };
		Pieza* torre1 = obtenerPieza(aux1);
		Vector2D aux2 = { destino.x + 1, destino.y };
		Pieza* torre2 = obtenerPieza(aux2);
		if ((rey->colour == torre1->colour) && (rey->type == REY) && (torre1->type == TORRE) && (obstaculo(origen, aux1) == false) && (rey->mov == 0) && torre1->mov == 0) { return true; }
		else if ((rey->colour == torre2->colour) && (rey->type == REY) && (torre2->type == TORRE) && (obstaculo(origen, aux2) == false) && (rey->mov == 0) && torre2->mov == 0) return true;
		else return false;
	}
	else return false;

}

void Tablero::enroque(Pieza* origen, Pieza* destino)
{
	if (destino->pos.x < origen->pos.x) {
		//cout << "enroque LARGO" << endl;
		setPieza(destino, origen);
		Vector2D des = { origen->pos.x - 2, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { destino->pos.x - 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux, aux2);
	}
	else {
		//cout << "enroque CORTO" << endl;
		setPieza(destino, origen);
		Vector2D des = { destino->pos.x + 1, origen->pos.y };
		//cout << "des " << des.x << des.y << endl;
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { origen->pos.x + 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		//cout << "des " << des2.x << des2.y << endl;
		setPieza(aux, aux2);
	}
}

void Tablero::desEnroque(Pieza* origen, Pieza* destino)
{
	if (destino->pos.x < origen->pos.x) {
		//cout << "desenroque LARGO" << endl;
		setPieza(origen, destino);
		Vector2D des = { origen->pos.x - 2, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { destino->pos.x - 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux2, aux);
	}
	else {
		//cout << "desenroque CORTO" << endl;
		setPieza(destino, origen);
		Vector2D des = { destino->pos.x + 1, origen->pos.y };
		//cout << "des " << des.x << des.y << endl;
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { origen->pos.x + 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		//cout << "des " << des2.x << des2.y << endl;
		setPieza(aux2, aux);
	}
}