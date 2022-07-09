#pragma once
#include <string>
using namespace std;

class Jugador
{
private:
	int puntos;
	string nombre;
public:
	Jugador() : puntos(0), nombre("") {};
	Jugador(int p, string n) : puntos(p) , nombre(n) {};
	int getPuntos();
	string getNombre();
	void setNombre(string s);
	void setPuntos(int p);
	void sumarPunto();
	Jugador& operator=(const Jugador& J);
};

