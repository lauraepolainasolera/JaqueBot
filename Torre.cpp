#include "Torre.h"

bool Torre::movimientoValido(Vector2D origen, Vector2D destino) {

	Vector2D res = destino - origen;

	if (res.x == 0 && res.y != 0)
		return true;
	if (res.y == 0 && res.x != 0)
		return true;
	else return false;
}
