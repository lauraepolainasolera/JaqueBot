#include "Tablero.h"

#define DIMENSION 8

using ETSIDI::SpriteSequence;
using namespace std;

ofstream out("partida.txt");

Tablero::Tablero() {
	
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
		
			pi[i][j] = new PiezaVacia();
		}
	}
	jm = false;
	movimiento = 0;
}

Vector2D Tablero::obtenerPosicionesReales(Vector2D v) {
	int i = v.x;
	int j = v.y;
	
		PosicionReal[i][j].x = -float(4.2) + (j * 1.2);
		PosicionReal[i][j].y = 4.2 - (i * 1.2);

	return PosicionReal[i][j];
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
	out << "Modo de juego Locura" << endl;
	srand(time(0));
	int a,b,c,d,e,f,g,h;

	do{
		a = rand() % DIMENSION;
		b = rand() % DIMENSION;
		c = rand() % DIMENSION;
		d = rand() % DIMENSION;
		e = rand() % DIMENSION;
		f = rand() % DIMENSION;
		g = rand() % DIMENSION;
		h = rand() % DIMENSION;
	} while (a == c || a == e || a==g || c == e || c==g|| e==g || b == d || b == f || b==h || d == f || d ==h || f==h );

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
		if (a == j || c == j ) {
			pi[j][1] = new TorreBlanca();
		}
		else if (e == j || g==j)
			pi[j][1] = new AlfilBlanco();
		else 
			pi[j][1] = new PeonBlanco();
	}

	for (int j = 0; j < DIMENSION; j++) {
		if (b == j || d==j) {
			pi[j][6] = new TorreNegra();
		}
		else if (f == j || h == j)
			pi[j][6] = new AlfilNegro();
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
	out << "Modo de juego Normal" << endl;

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

	Pieza* orig = obtenerPieza(origen);
	Pieza* dest = obtenerPieza(destino);

	if (orig->movimientoValido(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento, orig) && casillaVacia(destino) && (enroque(origen, destino) == false)){
		
		setPieza(orig, dest);
		orig->mov++;
		if (evaluaEnclavamiento()) {
			setPieza(dest, orig);
			orig->mov--;
		}
		else
		{
			cout << "Es el movimiento numero " << (movimiento) << endl;
			out << "Es el movimiento numero " << (movimiento) << endl;
			cout << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")" << endl;
			out << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")"<<endl;
	
			ETSIDI::play("bin/mover.wav");
		}
		orig=coronar(orig);				//comprueba si la pieza ha coronado
		jm = jaqueMate();
		dibujaPiezas();
	}
	else if (setTurno(movimiento, orig) && (enroque(origen, destino) == true))
	{
		enroque(orig, dest);
		orig->mov++;
		if (evaluaEnclavamiento()) {
			desEnroque(dest, orig);
			orig->mov--;
		}
		else
			ETSIDI::play("bin/mover.wav");

		jm = jaqueMate();
	}


	else if (orig->movimientoComer(origen, destino) && (obstaculo(origen, destino) == false) && setTurno(movimiento, orig) && (casillaVacia(destino) == false) && (dest->colour != orig->colour)) {
		tipo t = dest->type;
		color c = dest->colour;

		dest = comerPieza(orig, dest);
		orig->mov++;
		if (evaluaEnclavamiento()) {
			dest = cambiarTipoPieza(dest, t, c, dest->pos);
			setPieza(dest, orig);
			orig->mov--;
		}
		else
		{
			cout << "Es el movimiento numero " << (movimiento) << endl;
			out << "Es el movimiento numero " << (movimiento) << endl;
			ETSIDI::play("bin/comer.wav");
			cout << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")" << endl;
			out << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")" << endl;
			out << "Se ha comido una pieza." << endl;
		}
		orig = coronar(orig);
		jm = jaqueMate();
		dibujaPiezas();
	}
	else if (capturaAlPaso(origen, destino) && casillaVacia(destino)) {

		int suma = 0;
		setPieza(orig, dest);
		(orig->colour == BLANCA) ? suma = -1 : suma = 1;
		Pieza* peoncapt = obtenerPieza({ orig->pos.x, (orig->pos.y) + suma });
		color c = peoncapt->colour;
		peoncapt = cambiarTipoPieza(peoncapt, VACIA, BLANCA, peoncapt->pos);
		orig->mov++;

		if (evaluaEnclavamiento()) {
			peoncapt = cambiarTipoPieza(peoncapt, PEON, c, { orig->pos.x,(orig->pos.y) + suma });
			setPieza(dest, orig);
			orig->mov--;
		}
		else
		{
			cout << "Es el movimiento numero " << (movimiento) << endl;
			out << "Es el movimiento numero " << (movimiento) << endl;
			ETSIDI::play("bin/comer.wav");
			cout << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")" << endl;
			out << "Se ha movido de (" << dest->pos.x << "," << dest->pos.y << ") a (" << orig->pos.x << "," << orig->pos.y << ")" << endl;
			out << "Se ha realizado captura al paso" << endl;
		}

		jm = jaqueMate();
		dibujaPiezas();
	}

	else{
		cout << "Movimiento invalido." << endl;
		ETSIDI::play("bin/error.wav");
		dibujaPiezas();
	}
}

bool Tablero::capturaAlPaso(Vector2D origen, Vector2D destino) {
	int suma = 0;
	Pieza* peon = obtenerPieza(origen);
	(peon->colour == BLANCA) ? suma = -1 : suma = 1;

	Pieza* casVacia = obtenerPieza(destino);
	Pieza* peoncapt = obtenerPieza({ casVacia->pos.x, (casVacia->pos.y) + suma });

	if (peon->type == PEON && peon->movimientoComer(origen, destino) && casillaVacia(casVacia->pos) && peoncapt->type == PEON && peoncapt->mov == 1)
		return true;

	else
		return false;
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

	if ((p->colour == BLANCA && p->pos.y == 7 && p->type == PEON) || (p->colour == NEGRA && p->pos.y == 0 && p->type == PEON)) {
		ETSIDI::play("bin/coronao.wav");
		cout << "Has coronado. Pulsa la inicial de la pieza que quieras." << endl;
		out << "Se ha coronado." << endl;
		cin >> letra;
		
			switch (letra) {
			case 'r':
			case 'R':
				p = cambiarTipoPieza(p, REINA, p->colour, aux);
				out << "Se cambia el peon por una reina." << endl;
				break;
			case 't':
			case 'T':
				p = cambiarTipoPieza(p, TORRE, p->colour, aux);
				out << "Se cambia el peon por una torre." << endl;
				break;
			case 'a':
			case 'A':
				p = cambiarTipoPieza(p, ALFIL, p->colour, aux);
				out << "Se cambia el peon por una alfil." << endl;
				break;
			case 'c':
			case 'C':
				p = cambiarTipoPieza(p, CABALLO, p->colour, aux);
				out << "Se cambia el peon por una caballo." << endl;
				break;
			case 'p':
			case 'P':
				p = cambiarTipoPieza(p, PEON, p->colour, aux);
				out << "No se cambia el peon." << endl;
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
		cout << "Es el turno del otro jugador" << endl;
		return false;
	}
}

bool Tablero::jaque(Vector2D rey, Pieza* ataq)
{
	if (ataq->movimientoComer(ataq->pos, rey) && obstaculo(rey, ataq->pos) == false) {
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
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
								continue;
							}
							if (jaque(pos, aux2)) {
								return 1;
							}
						}
					}
				}
				else if (aux->type == REY && aux->colour == BLANCA) {
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
								continue;
							}
							if (jaque(pos, aux2)) {
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
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (/*pos2 == pos || */ aux2->colour == aux->colour || aux2->type == VACIA) {
								continue;
							}
							if (jaque(pos, aux2)) {
								return 2;
							}
						}
					}
				}
				else if (aux->type == REY && aux->colour == NEGRA) {
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
								continue;
							}
							if (jaque(pos, aux2)) {
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
	if (jr == 1 && movimiento % 2 == 0) {
		movimiento++;
		cout << "Es el turno de las negras" << endl;
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
		movimiento++;
		cout << "Es el turno de las blancas" << endl;
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
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if ((aux2->colour != aux->colour || aux2->type != VACIA) && jaque(pos, aux2)) {
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
				else if (aux->type == REY && aux->colour == BLANCA) {
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
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
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
								continue;
							}
							if (jaque(pos, aux2)) return aux2;
						}
					}
				}
				else if (aux->type == REY && aux->colour == NEGRA) {
					for (int k = 0; k < DIMENSION; k++) {
						for (int l = 0; l < DIMENSION; l++) {
							Vector2D pos2 = { (float)k, (float)l };
							Pieza* aux2 = obtenerPieza(pos2);
							if (aux2->colour == aux->colour || aux2->type == VACIA) {
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
		int i = origen.x + 1;
		int j = origen.y + 1;
		while (i < destino.x && j < destino.y) {
			tray[k] = new Vector2D{ (float)i, (float)j };
			i++;
			j++;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x,y negativa
		int i = origen.x - 1;
		int j = origen.y - 1;

		while (i > destino.x && j > destino.y) {
			tray[k] = new Vector2D{ (float)i, (float)j };
			i--;
			j--;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x > destino.x) && (origen.y < destino.y)) { //diagonal con coordenadas x negativa, y positiva
		int i = origen.x - 1;
		int j = origen.y + 1;

		while (i > destino.x && j < destino.y) {
			tray[k] = new Vector2D{ (float)i, (float)j };
			i--;
			j++;
			k++;
		}
	}

	if ((abs(res.x) == abs(res.y)) && (origen.x < destino.x) && (origen.y > destino.y)) { //diagonal con coordenadas x positiva, y negativa
		int i = origen.x + 1;
		int j = origen.y - 1;

		while (i < destino.x && j>destino.y) {
			tray[k] = new Vector2D{ (float)i, (float)j };
			i++;
			j--;
			k++;
		}
	}

	if ((origen.x == destino.x) && (origen.y < destino.y)) { // desplazarse en y positiva
		for (int j = origen.y + 1; j < destino.y; j++) {
			tray[k] = new Vector2D{ (float)origen.x, (float)j };
			k++;
		}
	}

	if ((origen.x == destino.x) && (origen.y > destino.y)) { //desplazarse y negativa
		for (int j = origen.y - 1; j > destino.y; j--) {
			tray[k] = new Vector2D{ (float)origen.x, (float)j };
			k++;
		}
	}

	if ((origen.x < destino.x) && (origen.y == destino.y)) { //Desplazarse x positiva
		for (int i = origen.x + 1; i < destino.x; i++) {
			tray[k] = new Vector2D{ (float)i, (float)origen.y };
			k++;
		}
	}

	if ((origen.x > destino.x) && (origen.y == destino.y)) { //desplazarse x negativa
		for (int i = origen.x - 1; i > destino.x; i--) {
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
					for (int k = 0; k < numero; k++) {
						Pieza* aux2 = obtenerPieza(*prox[k]);
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
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type != REY && aux->colour == NEGRA) { //busca el resto de las piezas negras
					for (int l = 0; l < numero2; l++) {
						if ((aux->movimientoValido(aux->pos, *tray[l]) &&obstaculo(aux->pos, *tray[l])==false) || (aux->movimientoComer(aux->pos, aux3->pos) && obstaculo(aux->pos, aux3->pos) == false)) jm++;
					}
				}
			}
		}
		if (jm >= 1) {
			cout << "Tienes salvacion" << endl;
			out << "Se produce un jaque" << endl;
			return false;
		}
		else {
			ETSIDI::play("bin/JaqueMate.wav");
			cout << "Has perdido amigo. GANAN LAS BLANCAS." << endl;
			cout << "Espera a la pantalla final." << endl;
			out << "Se produce jaque mate. Ganan las blancas." << endl;
			out.close();
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
					for (int k = 0; k < numero; k++) {
						Pieza* aux2 = obtenerPieza(*prox[k]);
						if (aux2->type == VACIA) {
							setPieza(aux, aux2);
							if (jaqueReal() != 2) jm++;
							setPieza(aux2, aux);
						}
					}
					rey = aux;
				}
			}
		}
		Vector2D* tray[10];
		int numero2 = trayectoria(rey->pos, aux3->pos, tray);
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				Vector2D pos = { (float)i,(float)j };
				Pieza* aux = obtenerPieza(pos);
				if (aux->type != REY && aux->colour == BLANCA) { //busca el resto de las piezas BLANCAS
					for (int l = 0; l < numero2; l++) {
						if ((aux->movimientoValido(aux->pos, *tray[l]) && obstaculo(aux->pos, *tray[l]) == false) || (aux->movimientoComer(aux->pos, aux3->pos) && obstaculo(aux->pos, aux3->pos) == false)) jm++;
					}
				}
			}
		}
		if (jm >= 1) {
			cout << "Tienes salvacion" << endl;
			out << "Se produce un jaque" << endl;
			return false;
		}
		else {
			ETSIDI::play("bin/JaqueMate.wav");
			cout << "Has perdido amigo. GANAN LAS NEGRAS" << endl;
			cout << "Espera a la pantalla final." << endl;
			out << "Se produce jaque mate. Ganan las negras." << endl;
			out.close();
			return true;
		}
	}
}

bool Tablero::enroque(Vector2D origen, Vector2D destino)
{
	if (((origen.x == destino.x - 2) || (origen.x == destino.x + 2)) && (origen.y == destino.y)) {
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
		setPieza(destino, origen);
		Vector2D des = { origen->pos.x - 2, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { destino->pos.x - 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux, aux2);
	}
	else {
		setPieza(destino, origen);
		Vector2D des = { destino->pos.x + 1, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { origen->pos.x + 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux, aux2);
	}
}

void Tablero::desEnroque(Pieza* origen, Pieza* destino)
{
	if (destino->pos.x < origen->pos.x) {
		setPieza(origen, destino);
		Vector2D des = { origen->pos.x - 2, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { destino->pos.x - 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux2, aux);
	}
	else {
		setPieza(destino, origen);
		Vector2D des = { destino->pos.x + 1, origen->pos.y };
		Pieza* aux = obtenerPieza(des);
		Vector2D des2 = { origen->pos.x + 1, origen->pos.y };
		Pieza* aux2 = obtenerPieza(des2);
		setPieza(aux2, aux);
	}
}
