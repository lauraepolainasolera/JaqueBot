#include "CaballoNegro.h"

void CaballoNegro::dibuja(Vector2D p)
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0.5);
	caballon.flip(false, false);
	caballon.draw();
	glTranslatef(-p.x, -p.y, 0.5);
	glPopMatrix();

}
