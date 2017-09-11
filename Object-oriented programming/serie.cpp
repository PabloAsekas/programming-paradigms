/*
 * serie.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "serie.h"

Serie::Serie():Base(){
	this->seassons = NULL;
}

Serie::Serie(string title, string description, vector<string> *gender, map<string, vector<Capitulos*>* > *seassons): Base(title, description, gender), seassons(seassons){}

Serie::~Serie() {}

void Serie::insertSeasson(string seasson, vector<Capitulos*> *episodes) {
	this->seassons->insert(pair<string,vector<Capitulos*> *>(seasson, episodes));
}

void Serie::deleteSeasson(string seasson) {
	this->seassons->erase(this->seassons->find(seasson));
}

void Serie::insertEpisode(string seasson, Capitulos *episode) {
	this->seassons->find(seasson)->second->push_back(episode);
}

void Serie::deleteEpisode(string seasson, string episode) {
	map<string, vector<Capitulos*>* >::iterator im = this->seassons->find(seasson);
	vector<Capitulos*>::iterator iv;
	for (iv = im->second->begin(); iv != im->second->end(); iv++) {
		if ((*iv)->getName() == episode) {
			*(*im->second).erase(iv);
			break;
		}
	}
}

ostream& operator<<(ostream &os, Serie &obj) {
	return obj.imprimir(os);
}

ostream& Serie::imprimir(ostream &os) {
	Base::imprimir(os);
	os << "Temporadas: ";
	string temps;
	map<string, vector<Capitulos*>* >::iterator im;
	for (im = this->seassons->begin(); im != this->seassons->end(); im++) {
		os << endl;
		os << "- " + im->first + ":";
		vector<Capitulos*>::iterator iv;
		for (iv = im->second->begin(); iv != im->second->end(); iv++) {
			os << *(*iv);
		}
	}
	return os;
}

Capitulos* Serie::getEpisode(string seasson, string episode) {
	map<string, vector<Capitulos*>* >::iterator im = this->seassons->find(seasson);
	vector<Capitulos*>::iterator iv;
	for (iv = im->second->begin(); iv != im->second->end(); iv++) {
		if ((*iv)->getName() == episode) {
			break;
		}
	}
	return (*iv);
}
