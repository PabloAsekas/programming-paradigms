/*
 * documental.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_DOCUMENTAL_H_
#define SRC_DOCUMENTAL_H_

#include "base.h"
#include "capitulos.h"

using namespace std;

class Documental: public Base {
public:
	Documental();
	Documental(string title, string description, vector<string> *gender, vector<Capitulos*> *episodes);
	~Documental();
	void insertEpisode(Capitulos *episode);
	void deleteEpisode(string episode);
	friend ostream& operator<<(ostream &os, Documental &obj);
	virtual ostream& imprimir(ostream &os);
	Capitulos* getEpisode(string episode) const;

private:
	vector<Capitulos *> *episodes;
};

#endif /* SRC_DOCUMENTAL_H_ */
