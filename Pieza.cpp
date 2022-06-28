#include "Pieza.h"

using ETSIDI::SpriteSequence;


string Pieza::getImagen(Pieza* p)
{
    string imagen;
    if (colour == BLANCA) {
        switch (type) {
        case ALFIL:
            imagen = "bin/alfilblanco.png";
            break;
        case CABALLO:
            imagen = "bin/caballoblanco.png";
            break;
        case TORRE:
            imagen = "bin/torreblanco.png";
            break;
        case REY:
            imagen = "bin/reyblanco.png";
            break;
        case REINA:
            imagen = "bin/reinablanco.png";
            break;
        case PEON:
            imagen = "bin/peonblanco.png";
            break;
        case VACIA:
            imagen = "bin/vacia.png";
            break;
        }
        if (colour == NEGRA) {
            switch (type) {
            case ALFIL:
                imagen = "bin/alfilnegro.png";
                break;
            case CABALLO:
                imagen = "bin/caballonegro.png";
                break;
            case TORRE:
                imagen = "bin/torrenegro.png";
                break;
            case REY:
                imagen = "bin/reynegro.png";
                break;
            case REINA:
                imagen = "bin/reinanegro.png";
                break;
            case PEON:
                imagen = "bin/peonnegro.png";
                break;
            case VACIA:
                imagen = "bin/vacia.png";
                break;
            }

        }
        return imagen;

    }

    void dibuja(SpriteSequence piez) { 
            glPushMatrix();
            glTranslatef(0, 0, 0);
            piez.flip(false, false);
            piez.draw();
            glTranslatef(0, 0, 0);
            glPopMatrix();
}
