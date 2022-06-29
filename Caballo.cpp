#include "Caballo.h"

bool Caballo::movimientoValido(Vector2D origen, Vector2D destino) {
	Vector2D res = destino - origen;
	if (abs(res.x) == 2 && abs(res.y) == 1)
		return true;
	if (abs(res.y) == 2 && abs(res.x) == 1)
		return true;
	else
		return false;
}