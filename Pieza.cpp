#include "Pieza.h"

using ETSIDI::SpriteSequence;



void Pieza::dibuja(string imag)
{

	SpriteSequence imag;
	glPushMatrix();
	glTranslatef(0, 0, 0);
	imag.flip(false, false);
	imag.draw();
	glTranslatef(0, 0, 0);
	glPopMatrix();
	

}

string Pieza::getImagen(Pieza* p)
{
    string imagen;
    if (colour == B) {
        switch (type) {
        case A:
            imagen = "bin/alfilblanco.png";
            break;
        case C:
            imagen = "bin/caballoblanco.png";
            break;
        case T:
            imagen = "bin/torreblanco.png";
            break;
        case K:
            imagen = "bin/reyblanco.png";
            break;
        case Q:
            imagen = "bin/reinablanco.png";
            break;
        case P:
            imagen = "bin/peonblanco.png";
            break;
        case V:
            imagen = "bin/vacia.png";
            break;
        }
        if (colour == N) {
            switch (type) {
            case A:
                imagen = "bin/alfilnegro.png";
                break;
            case C:
                imagen = "bin/caballonegro.png";
                break;
            case T:
                imagen = "bin/torrenegro.png";
                break;
            case K:
                imagen = "bin/reynegro.png";
                break;
            case Q:
                imagen = "bin/reinanegro.png";
                break;
            case P:
                imagen = "bin/peonnegro.png";
                break;
            }

        }
        return imagen;

}
