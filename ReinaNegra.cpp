#include "ReinaNegra.h"

void ReinaNegra::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	reinan.flip(false, false);
	reinan.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
