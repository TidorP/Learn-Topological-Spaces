#pragma once
#include <iostream>
#include <vector>
#include <qdebug.h>
#define null -999
class GenerateSubSets
{
private:
	std::vector<int> lista;
	std::vector<std::vector<int> > out;
public:
	GenerateSubSets(std::vector<int>& lista);
	void helper(std::vector<int> l, std::vector<int> sub,int i);
	void helper_for_size(std::vector<int> l, std::vector<int> sub, int i,int k);
	std::vector<std::vector<int> > print();
	std::vector<std::vector<int> > print_for_size(int size);
	int getSize(std::vector<int> vect);
	void clear();
};

