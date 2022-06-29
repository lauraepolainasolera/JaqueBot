#include "Rey.h"

//darle una vuelta

void Rey::dibuja(Vector2D p)
{
}

void Rey::mueve(V2D origen, V2D destino)
{
	bool mov = movimientoValido(origen,destino);
	
	//eliminarPieza(origen);
	//dibujarPieza(destino);
}

bool Rey::movimientoValido(V2D origen, V2D destino)
{
	V2D res = origen - destino;
	
	if (abs(res.x) == 1 && abs(res.y) == 0)
		return true;
	else if (abs(res.x == 0) && abs(res.y) == 1)
		return true;
	else if (abs(res.x) == 1 && abs(res.y) == 1)
		return true;
	else
		return false;
}
