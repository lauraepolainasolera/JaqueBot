#include "AlfilNegro.h"

void AlfilNegro::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	alfiln.flip(false, false);
	alfiln.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();

}
