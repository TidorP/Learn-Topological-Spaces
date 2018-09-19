#pragma once
#include "GenerateSubSets.h"

void testAll()
{
	int cap = 5;
	std::vector<int> arr;
	for (int i = 1; i <= cap; i++)
	{
		arr.push_back(i);
	}
	GenerateSubSets g{ arr };
	for (auto el : g.print())
	{
		QDebug debug = qDebug();
		for (auto e : el)
		{
			if (e != null)
			{
				debug <<e;
			}
		}
	}
	g.clear();
	for (auto el : g.print_for_size(3))
	{
		QDebug debug = qDebug();
		for (auto e : el)
		{
			if (e != null)
			{
				debug << e;
			}
		}
	}
}