/*
 * gestor.c
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "gestor.h"

using namespace std;

Gestor::Gestor(){}
Gestor::~Gestor() {}

void Gestor::backup(const char *filename){
	ofstream archive;
	archive.open(filename);
	archive << "Copia de seguridad del gestor de Netflix" << endl;
	archive << endl;
	archive << "Peliculas" << endl;
	map<string, Pelicula*>::iterator imf;
	for (imf = this->films.begin(); imf != this->films.end(); imf++) {
		archive << *(imf->second) << endl;
	}
	archive << endl;
	archive << "Series" << endl;
	map<string, Serie*>::iterator ims;
	for (ims = this->sitcoms.begin(); ims != this->sitcoms.end(); ims++) {
		archive << *(ims->second) << endl;
	}
	archive << endl;
	archive << "Documentales" << endl;
	map<string, Documental*>::iterator imd;
	for (imd = this->documentaries.begin(); imd != this->documentaries.end(); imd++) {
		archive << *(imd->second) << endl;
	}

	archive.close();
}

void Gestor::showForGenders (vector<string> *genders) {
	vector<Base *> content;
	map<string, Pelicula*>::iterator im1;
	for (im1 = this->films.begin(); im1 != this->films.end(); im1++) {
		content.push_back(im1->second);
	}
	map<string, Serie*>::iterator im2;
	for (im2 = this->sitcoms.begin(); im2 != this->sitcoms.end(); im2++) {
		content.push_back(im2->second);
	}
	map<string, Documental*>::iterator im3;
	for (im3 = this->documentaries.begin(); im3 != this->documentaries.end(); im3++) {
		content.push_back(im3->second);
	}
	vector<Base *>::iterator iv1;
	vector<string>::iterator iv2;
	vector<string>::iterator iv3;
	for (iv1 = content.begin(); iv1 != content.end(); iv1++) {
		vector<string> *object = new vector<string>;
		object = (*iv1)->getGenders();
		for (iv2 = genders->begin(); iv2 != genders->end(); iv2++) {
			bool esta = false;
			for (iv3 = object->begin(); iv3 != object->end(); iv3++){
				if (*iv2 == *iv3) {
					esta = true;
				}
			}
			if (!esta) {
				content.erase(iv1);
				iv1--;
				break;
			}
		}
	}
	for (iv1 = content.begin(); iv1 != content.end(); iv1++) {
		cout << *(*iv1) << endl;
	}
}

void Gestor::insert(Pelicula *film){
	this->films.insert(pair<string, Pelicula*>(film->getTitle(), film));
}

void Gestor::remove(Pelicula *film)  {
	this->films.erase(this->films.find(film->getTitle()));
}

void Gestor::show(Pelicula *film) {
	cout << *(this->films.find(film->getTitle())->second) << endl;
}

void Gestor::mostrarPeliculas() {//este método solo existe para demostrar la efectividad de otros metodos
	map<string, Pelicula*>::iterator im;
	for (im = this->films.begin(); im != this->films.end(); im++) {
		cout << *(im->second) << endl;
	}
}

void Gestor::insert(Serie *sitcom) {
	this->sitcoms.insert(pair<string, Serie*>(sitcom->getTitle(), sitcom));
}

void Gestor::remove(Serie *sitcom) {
	this->sitcoms.erase(this->sitcoms.find(sitcom->getTitle()));
}

void Gestor::insert(string sitcom, string seasson, vector<Capitulos*> *episodes){
	(this->sitcoms.find(sitcom)->second)->insertSeasson(seasson, episodes);
}

void Gestor::remove(Serie *sitcom, string seasson) {
	(this->sitcoms.find(sitcom->getTitle())->second)->deleteSeasson(seasson);
}

void Gestor::insert(Serie *sitcom, string seasson, Capitulos *episode) {
	(this->sitcoms.find(sitcom->getTitle())->second)->insertEpisode(seasson, episode);
}

void Gestor::remove(Serie *sitcom, string seasson, string episode) {
	(this->sitcoms.find(sitcom->getTitle())->second)->deleteEpisode(seasson, episode);
}

void Gestor::show(Serie *sitcom) {
	cout << *(this->sitcoms.find(sitcom->getTitle())->second) << endl;
}

void Gestor::show(Serie *sitcom, string seasson, string cap) {
	cout << *(this->sitcoms.find(sitcom->getTitle())->second)->getEpisode(seasson, cap) << endl;
}

void Gestor::mostrarSeries() {//este método solo existe para demostrar la efectividad de otros metodos
	map<string, Serie*>::iterator im;
	for (im = this->sitcoms.begin(); im != this->sitcoms.end(); im++) {
		cout << *(im->second) << endl;
	}
}

void Gestor::insert(Documental *documentary){
	this->documentaries.insert(pair<string, Documental*>(documentary->getTitle(), documentary));
}

void Gestor::remove(Documental *documentary) {
	this->documentaries.erase(this->documentaries.find(documentary->getTitle()));
}

void Gestor::insert(Documental *documentary, Capitulos *episode) {
	(this->documentaries.find(documentary->getTitle())->second)->insertEpisode(episode);
}

void Gestor::remove(Documental *documentary, string episode) {
	(this->documentaries.find(documentary->getTitle())->second)->deleteEpisode(episode);
}

void Gestor::show(Documental *documentary) {
	cout << *(this->documentaries.find(documentary->getTitle())->second) << endl;
}

void Gestor::show(Documental *documentary, string cap) {
	cout << *(this->documentaries.find(documentary->getTitle())->second)->getEpisode(cap) << endl;
}

void Gestor::mostrarDocumentales() {//este método solo existe para demostrar la efectividad de otros metodos
	map<string, Documental*>::iterator im;
	for (im = this->documentaries.begin(); im != this->documentaries.end(); im++) {
		cout << *(im->second) << endl;
	}
}
