#include "ReyBlanco.h"

void ReyBlanco::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	reyb.flip(false, false);
	reyb.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();

}
