#include "Rey.h"

//void Rey::mueve(Vector2D origen, Vector2D destino)
//{
//	bool mov = movimientoValido(origen,destino);
//	//eliminarPieza(origen);
//	//dibujarPieza(destino);
//}

bool Rey::movimientoValido(Vector2D origen, Vector2D destino)
{
	Vector2D res = destino - origen;

	if (abs(res.x) == 1 && res.y == 0)
		return true;
	else if (res.x == 0 && abs(res.y) == 1)
		return true;
	else if (abs(res.x) == abs(res.y))
		return true;
	else
		return false;
}
