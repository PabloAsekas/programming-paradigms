/*
 * pelicula.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "pelicula.h"

Pelicula::Pelicula() {
	Base();
	this->duration = 0;
}

Pelicula::Pelicula(string title, string description, vector<string> *gender, int duration): Base(title, description, gender), duration(duration) {}

Pelicula::~Pelicula(){}

ostream& operator<<(ostream &os, Pelicula &obj) {
	return obj.imprimir(os);
}

ostream& Pelicula::imprimir(ostream &os) {
	Base::imprimir(os);
	os << "- Duracion: " << this->duration << " minutos";
	return os;
}
