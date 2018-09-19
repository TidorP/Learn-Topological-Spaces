#include "VectorDin.h"
using namespace std;


void VectorDinamic::redim() {

	//alocam un spatiu de capacitate dubla

	TElem *eNou = new TElem[2 * cp];

	//copiem vechile valori in noua zona

	for (int i = 0; i < n; i++)

		eNou[i] = e[i];

	//dublam capacitatea

	cp = 2 * cp;

	//eliberam vechea zona

	delete[] e;

	//vectorul indica spre noua zona

	e = eNou;

}



VectorDinamic::VectorDinamic(int cp) {

	//setam capacitatea

	this->cp = cp;

	//alocam spatiu de memorare pentru vector

	e = new TElem[cp];

	//setam numarul de elemente

	this->n = 0;

}



VectorDinamic::~VectorDinamic() {

	//eliberam zona de memorare alocata vectorului

	//delete[] e;

}



int VectorDinamic::dim() const {

	return n;

}



TElem& VectorDinamic::element(int i) const {

	return e[i];

}



void VectorDinamic::adaugaSfarsit(TElem el) {

	//daca s-a atins capacitatea maxima, redimensionam

	if (n == cp)
		redim();

	//adaugam la sfarsit

	this->e[n++] = el;
	//this->e[n].printList();

}
void VectorDinamic::sterge(int poz)
{
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		if (i == poz)
		{
			for (j = i; j < n - 1; j++)
				e[j] = e[j + 1];
			n--;
		}
	}
}
bool VectorDinamic::find(TElem el)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (e[i] == el)
		{
			return true;
		}
	}
	return false;
}
VectorDinamic& VectorDinamic::operator=(const VectorDinamic& ot)
{
	this->n = ot.n;
	e = new TElem[ot.cp];
	int i;
	for (i = 0; i<this->n; i++)
		this->e[i] = ot.e[i];
	this->cp = ot.cp;
	return *this;
}

Iterator VectorDinamic::iterator() {

	//returnam un iterator pe vector

	return Iterator(*this);

}


Iterator::Iterator(const VectorDinamic& _v) :

	v(_v) {

	//seteaza iteratorul pe prima pozitie din vector

	curent = 0;

	//varianta 2

	//curent=v.e; //- pointer spre primul element din vector

}



void Iterator::prim() {

	//seteaza iteratorul pe prima pozitie din vector

	curent = 0;

	//varianta 2

	//curent=v.e; //- pointer spre primul element din vector

}



bool Iterator::valid() const {

	//verifica daca iteratorul indica spre un element al vectorului

	return curent < v.dim();

	//varianta 2

	//return curent-v.e<v.dim();

}



TElem Iterator::element() const {

	//elementul curent

	return v.e[curent];

	//varianta 2

	//return *curent;

}



void Iterator::urmator() {

	//pentru ambele variante

	curent++;

}
