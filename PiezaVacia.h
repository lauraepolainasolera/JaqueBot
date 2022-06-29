#pragma once
#include "Pieza.h"
class PiezaVacia :
    public Pieza
{
public:
    PiezaVacia() :Pieza(VACIA, BLANCA) { };

    void dibuja(Vector2D p) {};
    bool movimientoValido(Vector2D origen, Vector2D destino) { return true; };
};

