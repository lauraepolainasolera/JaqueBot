#include "TorreBlanca.h"

void TorreBlanca::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	torreb.flip(false, false);
	torreb.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
