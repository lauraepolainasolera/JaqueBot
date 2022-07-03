#include "AlfilBlanco.h"

void AlfilBlanco::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	alfilb.flip(false, false);
	alfilb.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();

}
