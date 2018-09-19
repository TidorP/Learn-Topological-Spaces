#include "GenerateSubSets.h"



GenerateSubSets::GenerateSubSets(std::vector<int>& lista) :lista{ lista }{}

std::vector<std::vector<int> > GenerateSubSets::print()
{
	std::vector<int> sub(lista.size(),null);
	helper(lista, sub, 0);
	return out;
}
std::vector<std::vector<int> > GenerateSubSets::print_for_size(int size)
{
	std::vector<int> sub(lista.size(), null);
	helper_for_size(lista, sub, 0,size);
	return out;
}
void  GenerateSubSets::helper(std::vector<int> l, std::vector<int> sub, int i)
{
	if (i == lista.size())
	{
		out.push_back(sub);
	}
	else
	{
		sub.at(i) = null;
		helper(l, sub, i + 1);
		sub.at(i) = l.at(i);
		helper(l, sub, i + 1);
	}
}
void GenerateSubSets::helper_for_size(std::vector<int> l, std::vector<int> sub, int i,int k)
{
	if (getSize(sub)== k)
	{
		out.push_back(sub);
	}
	else
	{
		if (i < lista.size())
		{
			sub.at(i) = null;
			helper_for_size(l, sub, i + 1,k);
			sub.at(i) = l.at(i);
			helper_for_size(l, sub, i + 1,k);
		}
		
	}
}
int GenerateSubSets::getSize(std::vector<int> vect)
{
	int count = 0;
	for (auto el : vect)
	{
		if (el != null)
			count++;
	}
	return count;
}
void GenerateSubSets::clear()
{
	out.clear();
}

