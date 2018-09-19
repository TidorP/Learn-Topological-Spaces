#pragma once
#pragma once
#include <vector>
#include <iostream>

template<typename ElementType>
class IteratorMultime;

template<typename ElementType>
class Multime
{
private:
	int* urm;
	int* prec;
	ElementType* lista;
	int start;
	int ultim;
	int len;
	int cap;
	int primLiber;
public:
	Multime() = default;
	Multime(const Multime& multime)
	{
		int i;
		this->len = multime.len;
		this->lista = new ElementType[multime.cap];
		this->urm = new int[multime.cap];
		this->prec = new int[multime.cap];
		for (i = 0; i < this->len; i++)
		{
			this->lista[i] = multime.lista[i];
		}

		//this->prec = multime.prec;
		this->primLiber = multime.primLiber;
		this->start = multime.start;
		this->ultim = multime.ultim;
		//this->urm = multime.urm;
		this->cap = multime.cap;
		for (i = 0; i < this->cap; i++)
		{
			this->urm[i] = multime.urm[i];
			this->prec[i] = multime.prec[i];
		}
	}
	Multime(const Multime&& multime)
	{
		this->len = multime.len;
		int i;
		this->lista = new ElementType[multime.cap];
		this->urm = new int[multime.cap];
		this->prec = new int[multime.cap];
		for (i = 0; i < this->len; i++)
		{
			this->lista[i] = multime.lista[i];

		}
		//this->prec = multime.prec;
		this->primLiber = multime.primLiber;
		this->start = multime.start;
		this->ultim = multime.ultim;
		//this->urm = multime.urm;
		this->cap = multime.cap;
		for (i = 0; i < this->cap; i++)
		{
			this->urm[i] = multime.urm[i];
			this->prec[i] = multime.prec[i];
		}
	}
	Multime(int cap) noexcept : start{ -1 }, len{ 0 }, cap{ cap }, primLiber{ 0 }, ultim{ -1 }
	{
		lista = new ElementType[cap];
		urm = new int[cap];
		prec = new int[cap];
		for (int i = 0; i < cap - 1; i++)
		{
			urm[i] = i + 1;
		}
		urm[cap - 1] = -1;
		for (int i = 1; i < cap; i++)
		{
			prec[i] = i - 1;
		}
		prec[0] = -1;
	}
	template<typename ElementType>
	friend class IteratorMultime;
	~Multime() {

		//delete[] lista;
		//delete[] urm;
		//delete[] prec;
		//start = -1;
		//ultim = -1;
		//primLiber = -1;
		//cap = 0;
		//len = 0;

	}
	void add(ElementType NextData)
	{
		if (find(NextData) == false)
		{
			if (primLiber != -1)
			{
				if (len == 0)
					start = primLiber;
				lista[primLiber] = NextData;
				prec[primLiber] = ultim;
				urm[ultim] = primLiber;
				ultim = primLiber;
				primLiber = urm[primLiber];
				len++;

			}
		}
	}
	void del(ElementType Data)
	{
		for (int i = 0; i < cap; i++)
		{
			if (lista[i] == Data)
			{
				if (i == start && i == ultim)
				{
					start = -1;
					ultim = -1;
					primLiber = 0;
					lista[i] = -1;
					len--;
					return;
				}
				if (i == ultim)
				{
					ultim = prec[i];
					primLiber = i;
					lista[i] = -1;
					len--;
					return;
				}
				if (i == start)
				{
					start = urm[i];
					prec[urm[i]] = -1;
					urm[i] = primLiber;
					prec[primLiber] = i;
					primLiber = i;
					lista[i] = -1;
					urm[ultim] = primLiber;
					len--;
					return;
				}

				//int copie = primLiber;
				prec[primLiber] = i;
				urm[prec[i]] = urm[i];
				prec[urm[i]] = prec[i];
				urm[i] = primLiber;
				primLiber = i;
				lista[i] = -1;
				urm[ultim] = primLiber;
				len--;
			}
		}
	}
	bool empty()
	{
		return len == 0;
	}
	bool isSubSet(Multime ot)
	{
		if (len < ot.len) return false;
		if (ot.len == 0) return true;
		int i = ot.start;
		while (i != -1 && i != ot.primLiber)
		{

			if (find(ot.lista[i]) == false)
				return false;
			i = ot.urm[i];
		}
		return true;
	}

	//Multime<ElementType> expresie2(Multime<ElementType>& B)
	//{
	//	//face intersectia
	//	Multime<ElementType> C;
	//	int i = start;
	//	while (i != -1 && i != primLiber)
	//	{
	//		if (B.find(lista[i]) == true)
	//			C.add(lista[i]);

	//	}
	//	return C;
	//}
	//void expresie1(Multime<ElementType>& B)
	//{
	//	Multime<ElementType> D;
	//	Multime<ElementType> rezultat;
	//	D = expresie2(B);//intersectia
	//	int i = start;
	//	while (i != -1 && i != primLiber)
	//	{
	//		if (B.find(lista[i]) == false)
	//			B.add(lista[i]);

	//	}
	//	int i = B.start;
	//	while (i != -1 && i != B.primLiber)
	//	{
	//		if (D.find(lista[i]) == false)
	//			rezultat.add(lista[i]);

	//	}
	//	B = rezultat;

	//}
	bool find(ElementType Data)
	{
		int i = start;
		while (i != -1 && i != primLiber)
		{

			if (lista[i] == Data)
				return true;
			i = urm[i];

		}
		return false;

		/*for (int i = 0; i < len; i++)
		{
		if (lista[i] == Data)
		return true;
		}
		return false;*/
	}
	void printList()
	{
		int i = start;
		while (i != -1 && i != primLiber)
		{

			cout << "Element este: " << lista[i];
			cout << "Precedent este: " << prec[i] << "\nUrmator este: " << urm[i] << "\n";
			i = urm[i];

		}

	}
	bool operator==(Multime ot)
	{
		int ok = 1;
		if (len != ot.len)
			ok = 0;
		int i = start;
		while (i != -1 && i != primLiber)
		{
			if (ot.find(lista[i]) == false)
				ok = 0;
			i = urm[i];

		}
		if (ok == 1) return true;
		else
			return false;
	}
	int element(int poz)
	{
		int i = start;
		int contor = 0;
		while (i != -1 && i != primLiber)
		{
			if (contor == poz)
				return lista[i];
			contor++;
			i = urm[i];
		}
		return -1;
	}
	int dim()
	{
		return len;
	}
	Multime& operator=(const Multime& ot)
	{
		int i;
		this->len = ot.len;
		this->lista = new ElementType[ot.cap];
		for (i = 0; i<this->len; i++)
			this->lista[i] = ot.lista[i];
		this->prec = ot.prec;
		this->primLiber = ot.primLiber;
		this->start = ot.start;
		this->ultim = ot.ultim;
		this->urm = ot.urm;
		this->cap = ot.cap;
		return *this;
	}
	IteratorMultime<ElementType> iterator() {

		//returnam un iterator pe multime

		return IteratorMultime<ElementType>(*this);

	}


};


template<typename ElementType>
class IteratorMultime {

private:


	Multime<ElementType>& mul;


	int curent;


public:

	//constructor

	IteratorMultime(Multime<ElementType>& multime) :mul{ multime }, curent{ mul.start } {}



	//operatii pe iterator

	void prim()
	{
		curent = mul.start;
	}



	void urmator()
	{
		if (valid())
			curent = mul.urm[curent];
	}



	ElementType element() const
	{
		return mul.element(curent);
	}



	bool valid() const
	{
		return curent < mul.dim();
	}

};



