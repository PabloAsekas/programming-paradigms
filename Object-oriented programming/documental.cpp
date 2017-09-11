/*
 * documental.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "documental.h"

using namespace std;

Documental::Documental() {
	Base();
	this->episodes = NULL;
}

Documental::Documental(string title, string description, vector<string> *gender, vector<Capitulos*> *episodes): Base(title, description, gender), episodes(episodes){}

Documental::~Documental(){}

void Documental::insertEpisode(Capitulos *episode) {
	this->episodes->push_back(episode);
}

void Documental::deleteEpisode(string episode) {
	vector<Capitulos*>::iterator iv;
	for (iv = this->episodes->begin(); iv != this->episodes->end(); iv++) {
		if ((*iv)->getName() == episode) {
			this->episodes->erase(iv);
			break;
		}
	}
}

ostream& operator<<(ostream &os, Documental &obj) {
	return obj.imprimir(os);
}

ostream& Documental::imprimir(ostream &os) {
	Base::imprimir(os);
	os << endl;
	os << "- Episodios:";
	vector<Capitulos*>::iterator it;
	for (it = this->episodes->begin(); it != this->episodes->end(); it++) {
		os << *(*it);
	}
	return os;
}

Capitulos* Documental::getEpisode(string episode) const{
	vector<Capitulos*>::iterator iv;
	for (iv = this->episodes->begin(); iv != this->episodes->end(); iv++) {
		if ((*iv)->getName() == episode) {
			break;
		}
	}
	return *(iv);
}
