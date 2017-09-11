/*
 * capitulos.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "capitulos.h"

using namespace std;

Capitulos::Capitulos() {
	this->name = "";
	this->duration = 0;
}

Capitulos::Capitulos(string name, int duration) {
	this->name = name;
	this->duration = duration;
}

Capitulos::~Capitulos(){}

ostream& operator<<(ostream &os, Capitulos &obj) {
	return obj.imprimir(os);
}

ostream& Capitulos::imprimir(ostream &os) {
	os << " Capitulo: " << this->name;
	os << " duracion: " << this->duration << " minutos -";
	return os;
}

string Capitulos::getName() const {
	return this->name;
}
