#include "PeonBlanco.h"

void PeonBlanco::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	peonb.flip(false, false);
	peonb.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
