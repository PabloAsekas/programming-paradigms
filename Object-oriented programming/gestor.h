/*
 * gestor.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_GESTOR_H_
#define SRC_GESTOR_H_

#include "pelicula.h"
#include "serie.h"
#include "documental.h"
#include <fstream>
#include <map> //he decidido incluir aquí <map> porque, a pesar de que puede usarla porque la clase Serie la implementa, debe haber una independencia entre estas dos clases

using namespace std;

class Gestor {
public:
	Gestor();
	~Gestor();
	void backup(const char *filename);
	void showForGenders (vector<string> *genders);
	//Peliculas
	void insert(Pelicula *film);
	void remove(Pelicula *film);
	void show(Pelicula *film);
	void mostrarPeliculas();
	//Series
	void insert(Serie *sitcom);
	void remove(Serie *sitcom);
	void insert(string sitcom, string seasson, vector<Capitulos*> *episodes);
	void remove(Serie *sitcom, string seasson);
	void insert(Serie *sitcom, string seasson, Capitulos *episode);
	void remove(Serie *sitcom, string seasson, string episode);
	void show(Serie *sictom);
	void show(Serie *sitcom, string seasson, string cap);
	void mostrarSeries();
	//Documentales
	void insert(Documental *documentary);
	void remove(Documental *documentary);
	void insert(Documental *documentary, Capitulos *episode);
	void remove(Documental *documentary, string episode);
	void show(Documental *documentary);
	void show(Documental *documentary, string cap);
	void mostrarDocumentales();

private:
	map<string, Pelicula*> films;
	map<string, Serie*> sitcoms;
	map<string, Documental*> documentaries;
};

#endif /* SRC_GESTOR_H_ */
