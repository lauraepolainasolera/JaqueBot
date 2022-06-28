#pragma once
#include "Pieza.h"


class Rey :
    public Pieza
{
public:
    const char* reyblanco = "bin/reyblanco.png";
    const char* reynegro = "bin/reynegro.png";
    Rey(color c); 

    void mueve(V2D origen, V2D destino);
    bool movimientoValido(V2D origen, V2D destino);
};


