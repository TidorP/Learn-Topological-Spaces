#pragma once
#pragma once
#include "Linked.h"
typedef Multime<int> TElem;

class Iterator;

class VectorDinamic {

private:

	//capacitate

	int cp;

	//dimensiune

	int n;

	//elemente

	TElem *e;



	//pentru redimensionare

	void redim();



public:

	//pentru ca Iteratorul sa poata accesa reprezentarea vectorului

	friend class Iterator;



	//constructor
	VectorDinamic() = default;
	VectorDinamic(const VectorDinamic& vect)
	{
		this->n = vect.n;
		//this->dim = vect.dim;
		int i;
		e = new TElem[vect.cp];
		for (i = 0; i<this->n; i++)
			this->e[i] = vect.e[i];
		this->cp = vect.cp;
	}
	VectorDinamic(const VectorDinamic&& vect)
	{
		this->n = vect.n;
		int i;
		e = new TElem[vect.cp];
		for (i = 0; i<this->n; i++)
			this->e[i] = vect.e[i];
		this->cp = vect.cp;
	}
	VectorDinamic(int);



	//destructor

	~VectorDinamic();



	//dimensiunea vectorului (numar de elemente)

	int dim() const;



	//elementul al i-lea (1 <= i <= numar de elemente)

	TElem& element(int) const;



	//adaugare la sfarsit

	void adaugaSfarsit(TElem);


	void sterge(int poz);
	bool find(TElem el);
	VectorDinamic& operator=(const VectorDinamic& ot);
	//returneaza un iterator pe vector

	Iterator iterator();



	//alte operatii specifice

	//constructor copiere, operator atribuire...



};



class Iterator {

private:

	//iteratorul contine o referinta catre container

	const VectorDinamic& v;

	//pozitia curenta in iterator

	int curent;



	//varianta 2

	//TElem *curent; //pointer spre un element din vector

public:

	//constructor

	Iterator(const VectorDinamic&);



	//operatii pe iterator

	void prim();



	void urmator();



	TElem element() const;



	bool valid() const;

};
