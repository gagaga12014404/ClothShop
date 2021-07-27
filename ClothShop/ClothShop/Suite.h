#pragma once
#ifndef SUITE_H
#define SUITE_H

#include <iostream>
#include <string>
#include <vector>
#include "Cloth.h"
using namespace std;
class Suite :public Cloth
{
public:
	Suite(string name, string description, double price, int id) : Cloth(name, description, price, id) {}
	void add(Cloth* clothes)
	{
		_Clothes.push_back(clothes);
	}
	double getPrice()
	{
		double total = 0;
		for (auto i : _Clothes)
		{
			total += i->getPrice();
		}
		return total * 0.9;
	}
private:
	vector<Cloth*>_Clothes;
};

#endif // !SUITE_H