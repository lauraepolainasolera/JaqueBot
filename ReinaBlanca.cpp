#include "ReinaBlanca.h"

void ReinaBlanca::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	reinab.flip(false, false);
	reinab.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();

}
