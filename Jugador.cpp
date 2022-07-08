#include "Jugador.h"

int Jugador::getPuntos() { return puntos; }

string Jugador::getNombre() { return nombre; }

void Jugador::setNombre(string s) { nombre = s; }

void Jugador::setPuntos(int p) { puntos = p; }

void Jugador::sumarPunto() { puntos += 1; }

Jugador& Jugador::operator=(const Jugador& J) {
	nombre = J.nombre;
	puntos = J.puntos;
	return *this;
}