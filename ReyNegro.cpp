#include "ReyNegro.h"

void ReyNegro::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	reyn.flip(false, false);
	reyn.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
