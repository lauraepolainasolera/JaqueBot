#include "TorreNegra.h"

void TorreNegra::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	torren.flip(false, false);
	torren.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
