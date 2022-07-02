#include "Reina.h"

bool Reina::movimientoValido(Vector2D origen, Vector2D destino) {

	Vector2D res = destino - origen;

	if (res.x == 0 && res.y != 0)
		return true;

	else if (res.x != 0 && res.y == 0)
		return true;

	else if (abs(res.x) == abs(res.y))
		return true;

	else
		return false;
}

bool Reina::movimientoComer(Vector2D origen, Vector2D destino) {
	return movimientoValido(origen, destino);  //come en la misma direccion que se mueve
}