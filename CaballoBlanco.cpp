#include "CaballoBlanco.h"

void CaballoBlanco::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	caballob.flip(false, false);
	caballob.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
