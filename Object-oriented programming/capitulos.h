/*
 * capitulos.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_CAPITULOS_H_
#define SRC_CAPITULOS_H_

#include <iostream>

using namespace std;

class Capitulos {
public:
	Capitulos();
	Capitulos(string name, int duration);
	virtual ~Capitulos();
	friend ostream& operator<<(ostream &os, Capitulos &obj);
	virtual ostream& imprimir(ostream &os);
	string getName() const;

private:
	string name;
	int duration;
};

#endif /* SRC_CAPITULOS_H_ */
