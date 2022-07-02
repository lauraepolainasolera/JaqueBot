#include "Peon.h"


bool Peon::movimientoValido(Vector2D origen, Vector2D destino) {

	Vector2D res = destino - origen;
	//cout << "resta" << res.x << res.y << endl;
	if (colour == BLANCA) { //piezas blancas
		if (origen.y == 1) //posicion de salida de los peones
		{
			if ((res.y == 2 && res.x == 0) || (res.y == 1 && res.x == 0))
				return true;
			else
				return false;
		}
		else {  //posicion en el resto del tablero
			if (res.y <= 7 && res.x == 0)
				return true;
			else
				return false;
		}
	}

	else { //piezas negras

		if (origen.y == 6)
		{
			if ((res.y == -2 && res.x == 0) || (res.y == -1 && res.x == 0)) //posicion de salida de los peones
				return true;
			else
				return false;
		}
		else {
			if (res.y == -1 && res.x == 0) //posicion en el resto del tablero
				return true;
			else
				return false;
		}
	}
}



bool Peon::movimientoComer(Vector2D origen, Vector2D destino) {
	Vector2D res = destino - origen;
	if (colour == BLANCA) {
		if (abs(res.x) == 1 && res.y == 1)
			return true;
		else
			return false;
	}
	else {
		if (abs(res.x) == 1 && res.y == -1)
			return true;
		else
			return false;
	}

}