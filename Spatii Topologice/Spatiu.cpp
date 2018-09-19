#include "Spatiu.h"



Spatiu::Spatiu(Multime<int> multime, VectorDinamic familie) : multime{ multime }, familie{ familie } {}

bool Spatiu::ax1()
{
	Multime<int> vida{ 2 };
	if (familie.find(multime) == false)
	{
		trouble = multime;
		return false;
	}
	if (familie.find(vida) == false)
	{
		trouble = vida;
		return false;
	}
	return true;
}
bool Spatiu::ax2()
{
	int i, j;
	for (i = 0; i < familie.dim()-1; i++)
		for (j = i + 1; j < familie.dim(); j++)
			if (familie.find(intersectie(familie.element(i), familie.element(j))) == false)
			{
				trouble = intersectie(familie.element(i), familie.element(j));
				return false;
			}
	return true;
}
bool Spatiu::ax3()
{
	int i, j;
	for (i = 0; i < familie.dim()-1; i++)
		for (j = i + 1; j < familie.dim(); j++)
			if (familie.find(reuniune(familie.element(i), familie.element(j))) == false)
			{
				trouble = reuniune(familie.element(i), familie.element(j));
				return false;
			}
	return true;
}
Multime<int> Spatiu::intersectie(Multime<int> m1, Multime<int> m2)
{
	Multime<int> mInter{ 100 };
	int i;
	for (i = 0; i < m1.dim(); i++)
	{
		if (m2.find(m1.element(i)) == true)
			mInter.add(m1.element(i));
	}
	return mInter;
}
Multime<int> Spatiu::reuniune(Multime<int> m1, Multime<int> m2)
{
	Multime<int> mReu{ 100 };
	int i;
	for (i = 0; i < m1.dim(); i++)
	{
		mReu.add(m1.element(i));
	}
	for (i = 0; i < m2.dim(); i++)
	{
		if (mReu.find(m2.element(i)) == false)
			mReu.add(m2.element(i));
	}
	return mReu;
}
int Spatiu::check()
{
	if (ax1() == false)
	{
		//cout << "Axioma 1 nu este verificata, nu este Spatiu Topologic \n";
		return 1;
	}
	if (ax2() == false)
	{
		//cout << "Axioma 2 nu este verificata, nu este Spatiu Topologic \n";
		return 2;
	}
	if (ax3() == false)
	{
		//cout << "Axioma 3 nu este verificata, nu este Spatiu Topologic \n";
		return 3;
	}
	//cout << "Congrats, este Spatiu Topologic \n";
	return 0;
}
Multime<int> Spatiu::getTrouble()
{
	return trouble;
}
Spatiu::~Spatiu()
{
}
