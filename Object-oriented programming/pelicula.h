/*
 * pelicula.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_PELICULA_H_
#define SRC_PELICULA_H_

#include "base.h"

class Pelicula: public Base {
public:
	Pelicula();
	Pelicula(string title, string description, vector<string> *gender, int duration);
	~Pelicula();
	friend ostream& operator<<(ostream &os, Pelicula &obj);
	virtual ostream& imprimir(ostream &os);

private:
	int duration;
};

#endif /* SRC_PELICULA_H_ */
