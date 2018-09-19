#pragma once
#include "VectorDin.h"
#include "Linked.h"
#include <iostream>
using namespace std;
class Spatiu
{
private:
	Multime<int> multime;
	VectorDinamic familie;
	Multime<int> trouble;
public:
	Spatiu(Multime<int> multime, VectorDinamic familie);
	int check();
	bool ax1();
	bool ax2();
	bool ax3();
	Multime<int> intersectie(Multime<int> m1, Multime<int> m2);
	Multime<int> reuniune(Multime<int> m1, Multime<int> m2);
	Multime<int> getTrouble();
	~Spatiu();
};

