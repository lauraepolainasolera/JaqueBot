#include "Rey.h"

bool Rey::movimientoValido(Vector2D origen, Vector2D destino)
{
	Vector2D res = destino - origen;

	if (abs(res.x) == 1 && res.y == 0)
		return true;
	else if (res.x == 0 && abs(res.y) == 1)
		return true;
	else if ((abs(res.x) == abs(res.y)) && (abs(res.x)==1))
		return true;
	else
		return false;
}


bool Rey::movimientoComer(Vector2D origen, Vector2D destino) {
	return movimientoValido(origen, destino);  //come en la misma direccion que se mueve
}
