#include "PeonNegro.h"

void PeonNegro::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	peonn.flip(false, false);
	peonn.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();
}
