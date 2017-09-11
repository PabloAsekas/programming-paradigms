/*
 * serie.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_SERIE_H_
#define SRC_SERIE_H_

#include "base.h"
#include "capitulos.h"
#include <map>

using namespace std;

class Serie: public Base {
public:
	Serie();
	Serie(string title, string description, vector<string> *gender, map<string, vector<Capitulos*>* > *seassons);
	~Serie();
	void insertSeasson(string seasson, vector<Capitulos*> *episodes);
	void deleteSeasson(string seasson);
	void insertEpisode(string seasson, Capitulos *episode);
	void deleteEpisode (string seasson, string episode);
	friend ostream& operator<<(ostream &os, Serie &obj);
	virtual ostream& imprimir(ostream &os);
	Capitulos* getEpisode(string seasson, string episode);
private:
	map<string, vector<Capitulos*>* > *seassons;
};

#endif /* SRC_SERIE_H_ */
