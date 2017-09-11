/*
 * base.h
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#ifndef SRC_BASE_H_
#define SRC_BASE_H_

#include <vector>
#include <iostream>

using namespace std;

class Base {
public:
	Base ();
	Base (string title, string description, vector<string> *genders);
	virtual ~Base();
	friend ostream& operator<<(ostream &os, Base &obj);
	virtual ostream& imprimir(ostream &os);
	string getTitle() const;
	vector<string>* getGenders() const;

private:
	string title;
	string description;
	vector<string> *genders;
};

#endif /* SRC_BASE_H_ */
