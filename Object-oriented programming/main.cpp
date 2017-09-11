/*
 * main.cpp
 *
 * Pablo Bermejo
 * https://github.com/PabloAsekas/
 */

#include "gestor.h"

int main (){
	/*
	Películas:
		- Una película se debe crear de forma dinámica y al constructor hay que pasarle el nombre, la descripcion, el/los genero/s y la duracion
		- Nombre: String
		- Descripcion: String
		- Genero/s: Puntero a vector de strings
		- Duracion: Integer
	*/

	//Creamos varias peliculas para insertar luego en el gestor
	vector<string> *generoP1 = new vector<string>;
	generoP1->push_back("Biografia");
	Pelicula *jobs = new Pelicula("Jobs", "Los inicios del fundador de Apple...", generoP1, 132);

	vector<string> *generoP2 = new vector<string>;
	generoP2->push_back("Accion");
	generoP2->push_back("Aventuras");
	Pelicula *hp = new Pelicula("Harry Potter", "Harry es un niño normal que descubre...", generoP2, 124);

	vector<string> *generoP3 = new vector<string>;
	generoP3->push_back("Aventuras");
	generoP3->push_back("Comedia");
	Pelicula *ts = new Pelicula("Toy Story", "Que pasaria si tus juguetes tuviesen...", generoP3, 96);

	vector<string> *generoP4 = new vector<string>;
	generoP4->push_back("Aventuras");
	generoP4->push_back("Comedia");
	generoP4->push_back("Romantica");
	Pelicula *primos = new Pelicula("Primos", "Lo dejan plantado en el altar y sus primos...", generoP4, 98);

	/*
	Series:
		- Una serie se debe crear de forma dinámica y al constructor hay que pasarle el nombre, la descripcion, el/los genero/s y las temporadas
		- Nombre: String
		- Descripcion: String
		- Genero/s: Puntero a vector de strings
		- Temporada/s: Mapa cuya clave es un string que coincide con el nombre de la temporada y cuyo valor es un puntero a un vector de punteros de tipo Capitulos

		Capítulos:
			- Un capítulo se debe crear de forma dinámica y al constructor hay que pasarle el nombre y la duracion
			- Nombre: String
			- Duración: Integer
	*/

	//Creamos un puntero a un vector de Capítulos que más tarde será la temporada 1
	vector<Capitulos*> *s1t1 = new vector<Capitulos*>;
	//Creamos tres punteros a Capítulos que formaran la temporada 1
	Capitulos *s1t11 = new Capitulos("1x01", 102);
	Capitulos *s1t12 = new Capitulos("1x02", 100);
	Capitulos *s1t13 = new Capitulos("1x03", 104);
	//Añadimos los capítulos al vector
	s1t1->push_back(s1t11);
	s1t1->push_back(s1t12);
	s1t1->push_back(s1t13);

	//Creamos un puntero a un vector de Capítulos que más tarde será la temporada 2
	vector<Capitulos*> *s1t2 = new vector<Capitulos*>;
	//Creamos cinco punteros a Capítulos que formaran la temporada 2
	Capitulos *s1t21 = new Capitulos("2x01", 60);
	Capitulos *s1t22 = new Capitulos("2x02", 58);
	Capitulos *s1t23 = new Capitulos("2x03", 59);
	Capitulos *s1t24 = new Capitulos("2x04", 60);
	Capitulos *s1t25 = new Capitulos("2x05", 63);
	//Añadimos los capítulos al vector
	s1t2->push_back(s1t21);
	s1t2->push_back(s1t22);
	s1t2->push_back(s1t23);
	s1t2->push_back(s1t24);
	s1t2->push_back(s1t25);

	//Creamos el puntero al mapa que formara las temporadas de la serie
	map<string, vector<Capitulos*>* > *temporadasS1 = new map<string, vector<Capitulos*>* >;
	//Añadimos los dos arrays creados al mapa con su nombre
	temporadasS1->insert(pair<string,vector<Capitulos*> *>("T1", s1t1));
	temporadasS1->insert(pair<string,vector<Capitulos*> *>("T2", s1t2));

	//Creamos el puntero al vector que tendrá los generos de la serie
	vector<string> *generoS1 = new vector<string>;
	generoS1->push_back("Comedia");
	generoS1->push_back("Romantica");

	Serie *himym = new Serie("HIMYM", "Ted relata a sus hijos como conocio a su...", generoS1, temporadasS1);

	//Creamos un puntero a un vector de Capítulos que más tarde será la temporada 1
	vector<Capitulos*> *s2t1 = new vector<Capitulos*>;
	//Creamos tres punteros a Capítulos que formaran la temporada 1
	Capitulos *s2t11 = new Capitulos("1x01", 22);
	Capitulos *s2t12 = new Capitulos("1x02", 23);
	Capitulos *s2t13 = new Capitulos("1x03", 21);
	Capitulos *s2t14 = new Capitulos("1x04", 22);
	Capitulos *s2t15 = new Capitulos("1x05", 21);
	Capitulos *s2t16 = new Capitulos("1x06", 20);
	//Añadimos los capítulos al vector
	s2t1->push_back(s2t11);
	s2t1->push_back(s2t12);
	s2t1->push_back(s2t13);
	s2t1->push_back(s2t14);
	s2t1->push_back(s2t15);
	s2t1->push_back(s2t16);

	//Creamos un puntero a un vector de Capítulos que más tarde será la temporada 2
	vector<Capitulos*> *s2t2 = new vector<Capitulos*>;
	//Creamos cinco punteros a Capítulos que formaran la temporada 2
	Capitulos *s2t21 = new Capitulos("2x01", 23);
	Capitulos *s2t22 = new Capitulos("2x02", 22);
	Capitulos *s2t23 = new Capitulos("2x03", 22);
	Capitulos *s2t24 = new Capitulos("2x04", 20);
	Capitulos *s2t25 = new Capitulos("2x05", 21);
	Capitulos *s2t26 = new Capitulos("2x06", 21);
	//Añadimos los capítulos al vector
	s2t2->push_back(s2t21);
	s2t2->push_back(s2t22);
	s2t2->push_back(s2t23);
	s2t2->push_back(s2t24);
	s2t2->push_back(s2t25);
	s2t2->push_back(s2t26);

	//Creamos el puntero al mapa que formara las temporadas de la serie
	map<string, vector<Capitulos*>* > *temporadasS2 = new map<string, vector<Capitulos*>* >;
	//Añadimos los dos arrays creados al mapa con su nombre
	temporadasS2->insert(pair<string,vector<Capitulos*> *>("T1", s2t1));
	temporadasS2->insert(pair<string,vector<Capitulos*> *>("T2", s2t2));

	//Creamos el puntero al vector que tendrá los generos de la serie
	vector<string> *generoS2 = new vector<string>;
	generoS2->push_back("Comedia");
	generoS2->push_back("Romantica");
	generoS2->push_back("Aventuras");

	Serie *friends = new Serie("Friends", "Amor, risas, aventuras, pero sobre todo amistad...", generoS2, temporadasS2);

	/*
	Documentales:
		- Un documental se debe crear de forma dinámica y al constructor hay que pasarle el nombre, la descripcion, el/los genero/s y los episodios
		- Nombre: String
		- Descripcion: String
		- Genero/s: Puntero a vector de strings
		- Temporada/s: Puntero a vector de punteros de tipo Capitulos

		Capítulos:
			- Un capítulo se debe crear de forma dinámica y al constructor hay que pasarle el nombre y la duracion
			- Nombre: String
			- Duración: Integer
	*/

	//Creamos un puntero a un vector de Capítulos que seran los episodios del documental
	vector<Capitulos*> *capitulosD1 = new vector<Capitulos*>;

	//Creamos cinco punteros a Capítulos que formaran los episodios del documental
	Capitulos *d1e1 = new Capitulos("01", 40);
	Capitulos *d1e2 = new Capitulos("02", 40);
	Capitulos *d1e3 = new Capitulos("03", 41);
	Capitulos *d1e4 = new Capitulos("04", 41);
	Capitulos *d1e5 = new Capitulos("05", 40);

	//Añadimos los capítulos al vector
	capitulosD1->push_back(d1e1);
	capitulosD1->push_back(d1e2);
	capitulosD1->push_back(d1e3);
	capitulosD1->push_back(d1e4);
	capitulosD1->push_back(d1e5);

	//Creamos el puntero al vector que tendrá los generos de la serie
	vector<string> *generoD1 = new vector<string>;
	generoD1->push_back("Biografia");
	Documental *tiob = new Documental("The Internet's own boy", "Aaron Swartz, gracias por hacer de Internet un lugar mejor", generoD1, capitulosD1);

	//Creamos un puntero a un vector de Capítulos que seran los episodios del documental
	vector<Capitulos*> *capitulosD2 = new vector<Capitulos*>;

	//Creamos cinco punteros a Capítulos que formaran los episodios del documental
	Capitulos *d2e1 = new Capitulos("01", 22);
	Capitulos *d2e2 = new Capitulos("02", 24);

	//Añadimos los capítulos al vector
	capitulosD2->push_back(d2e1);
	capitulosD2->push_back(d2e2);

	//Creamos el puntero al vector que tendrá los generos de la serie
	vector<string> *generoD2 = new vector<string>;
	generoD2->push_back("Ciencia");
	Documental *lsdu = new Documental("Los secretos del universo", "Todo lo que nos rodea...", generoD2, capitulosD2);

	/*
	Gestor:
		- El gestor se debe crear de forma dinámica y al constructor no hay que pasarle nada
	*/
	Gestor *netflix = new Gestor();

	/*
	Insertar contenido:
		- Película: hay que pasarle el puntero de la película
		- Serie: hay que pasarle el puntero de la serie
		- Documental: hay que pasarle el puntero del documental
		- Temporada: hay que pasarle el nombre de la serie, el nombre de la temporada y un puntero a un vector de punteros de Capítulos
		- Capitulo:
			- Serie: hay que pasarle el nombre de la serie, el nombre de la temporada y el puntero al capitulo
			- Documental: hay que pasarle el nombre del documental y el puntero al capitulo
	*/

	//Insertando las peliculas
	netflix->insert(jobs);
	netflix->insert(hp);
	netflix->insert(ts);
	netflix->insert(primos);

	//Mostramos las peliculas
	cout << "- Peliculas del gestor -" << endl;
	netflix->mostrarPeliculas();
	cout << endl;

	//Insertando las series
	netflix->insert(himym);
	netflix->insert(friends);

	//Mostramos las series
	cout << "- Series del gestor -" << endl;
	netflix->mostrarSeries();
	cout << endl;

	//Insertando los documentales
	netflix->insert(tiob);
	netflix->insert(lsdu);

	//Mostramos los dcoumentales
	cout << "- Documentales del gestor -" << endl;
	netflix->mostrarDocumentales();
	cout << endl;

	//Insertando temporadas en series
	vector<Capitulos*> *s2t3 = new vector<Capitulos*>;
	Capitulos *s2t31 = new Capitulos("3x01", 20);
	s2t3->push_back(s2t31);
	netflix->insert("Friends", "T3", s2t3);

	//Mostramos la serie para comprobar que se ha añadido la temporada
	cout << "- Series a la que hemos añadido una temporada mas -" << endl;
	netflix->show(friends);
	cout << endl;

	//Insertando episodios en series
	Capitulos *s2t32 = new Capitulos("3x02", 22);
	netflix->insert(friends, "T3", s2t32);

	//Mostramos la serie para comprobar que se ha añadido un capitulo
	cout << "- Series a la que hemos añadido un capitulo mas -" << endl;
	netflix->show(friends);
	cout << endl;

	//Insertando episodios en documentales
	Capitulos *d1e6 = new Capitulos("06", 41);
	netflix->insert(tiob, d1e6);

	//Mostramos el documental al que hemos añadido un capitulo
	cout << "- Documental al que hemos añadido un capitulo mas -" << endl;
	netflix->show(tiob);
	cout << endl;

	/*
	Eliminar contenido:
		- Pelicula: hay que pasarle el puntero de la película
		- Serie: hay que pasarle el puntero de la serie
		- Documental: hay que pasarle el puntero del documental
		- Temporada: hay que pasarle el puntero de la serie y un string con el nombre de la temporada
		- Capitulo: hay que pasarle el puntero de la serie, un string con el nombre la temporada y un string con el nombre del capítulo
		- Episodio: hay que pasarle el puntero del documental y un string con el nombre del capitulo
	*/

	//Eliminando una película
	netflix->remove(primos);

	//Mostramos las peliculas una vez borrado una
	cout << "- Peliculas del gestor cuando hemos borrado una -" << endl;
	netflix->mostrarPeliculas();
	cout << endl;

	//Eliminando una serie
	netflix->remove(himym);

	//Mostramos las series una vez borrado una
	cout << "- Series del gestor cuando hemos borrado una -" << endl;
	netflix->mostrarSeries();
	cout << endl;

	//Eliminando un documental
	netflix->remove(lsdu);

	//Mostramos los documentales una vez borrado uno
	cout << "- Documentales del gestor cuando hemos borrado uno-" << endl;
	netflix->mostrarDocumentales();
	cout << endl;

	//Eliminando una temporada
	netflix->remove(friends, "T3");

	//Mostramos la serie una vez borrada la temporada
	cout << "- Serie con una temporada borrada -" << endl;
	netflix->show(friends);
	cout << endl;

	//Eliminando un capitulo de una serie
	netflix->remove(friends, "T2", "2x06");

	//Mostramos la serie una vez borrado el capitulo
	cout << "- Serie con un capitulo borrado -" << endl;
	netflix->show(friends);
	cout << endl;

	//Eliminando un capitulo de un documental
	netflix->remove(tiob, "06");

	//Mostramos el documental una vez borrado el capitulo
	cout << "- Documental con un capitulo borrado -" << endl;
	netflix->show(tiob);
	cout << endl;

	/*
	Copia de seguridad:
		- Hay que pasarle un string con el nombre del fichero en que queramos que guarde la copia de seguridad
	*/
	netflix->backup("backup.txt");

	/*
	Consultar contenido:
		- Película: hay que pasarle el puntero de la película
		- Serie: hay que pasarle el puntero de la serie
		- Documental: hay que pasarle el puntero del documental
		- Capitulo: hay que pasarle el puntero de la serie, un string con el nombre la temporada y un string con el nombre del capítulo
		- Episodio: hay que pasarle el puntero del documental y un string con el nombre del capitulo
	*/

	//Mostrar una película
	cout << "-- Mostramos una pelicula --" << endl;
	netflix->show(ts);
	cout << endl;

	//Mostrar una serie
	cout << "-- Mostramos una serie --" << endl;
	netflix->show(friends);
	cout << endl;

	//Mostrar un documental
	cout << "-- Mostramos un documental --" << endl;
	netflix->show(tiob);
	cout << endl;

	//Mostrar un capítulo de una serie
	cout << "-- Mostramos un capitulo de una serie --" << endl;
	netflix->show(friends, "T1", "1x04");
	cout << endl;

	//Mostrar un episodio de un documental
	cout << "-- Mostramos un episodio de un documental --" << endl;
	netflix->show(tiob, "05");
	cout << endl;

	/*
	Mostrar por géneros:
		- Hay que pasarle un puntero a un vector de strings que contenga todos los generos que se quieran mostrar
	*/
	vector<string> *generos1 = new vector<string>;
	generos1->push_back("Aventuras");
	generos1->push_back("Comedia");
	cout << "-- Mostramos el contenido que tenga entre sus generos 'Aventuras' y 'Comedia' --" << endl;
	netflix->showForGenders(generos1);
	cout << endl;

	vector<string> *generos2 = new vector<string>;
	generos2->push_back("Biografia");
	cout << "-- Mostramos el contenido que tenga entre sus generos 'Biografia' --" << endl;
	netflix->showForGenders(generos2);
	cout << endl;

	//Destruimos lo creado
	delete generoP1;
	delete jobs;
	delete generoP2;
	delete hp;
	delete generoP3;
	delete ts;
	delete generoP4;
	delete primos;
	delete s1t1;
	delete s1t11;
	delete s1t12;
	delete s1t13;
	delete s1t2;
	delete s1t21;
	delete s1t22;
	delete s1t23;
	delete s1t24;
	delete s1t25;
	delete temporadasS1;
	delete generoS1;
	delete himym;
	delete s2t1;
	delete s2t11;
	delete s2t12;
	delete s2t13;
	delete s2t14;
	delete s2t15;
	delete s2t16;
	delete s2t2;
	delete s2t21;
	delete s2t22;
	delete s2t23;
	delete s2t24;
	delete s2t25;
	delete s2t26;
	delete temporadasS2;
	delete generoS2;
	delete friends;
	delete capitulosD1;
	delete d1e1;
	delete d1e2;
	delete d1e3;
	delete d1e4;
	delete d1e5;
	delete generoD1;
	delete tiob;
	delete capitulosD2;
	delete d2e1;
	delete d2e2;
	delete generoD2;
	delete lsdu;
	delete netflix;
	delete s2t3;
	delete s2t31;
	delete s2t32;
	delete d1e6;
	delete generos1;
	delete generos2;
	return 0;
}
