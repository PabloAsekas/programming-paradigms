/*
 * base.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

using namespace std;

#include "base.h"

Base::Base() {
	this->title = "";
	this->description = "";
	this->genders = NULL;
}

Base::Base(string title, string description, vector<string> *genders){
	this->title = title;
	this->description = description;
	this->genders = genders;
}

Base::~Base(){}

ostream& operator<<(ostream &os, Base &obj) {
	return obj.imprimir(os);
}

ostream& Base::imprimir(ostream &os) {
	os << "Titulo: " << this->title << " - ";
	os << "Descripcion: " << this->description << " - ";
	os << "Genero/s: ";
	vector<string>::iterator it;
	for (it = this->genders->begin(); it != this->genders->end(); it++) {
		os << *it << ", ";
	}
	return os;
}

string Base::getTitle() const{
	return this->title;
}

vector<string>* Base::getGenders() const {
	return this->genders;
}
