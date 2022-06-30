#include "Alfil.h"

bool Alfil::movimientoValido(Vector2D origen, Vector2D destino) {

	Vector2D res = destino - origen;

	if (abs(res.x) == abs(res.y))
		return true;
	else
		return false;

}