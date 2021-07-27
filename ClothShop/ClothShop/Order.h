#pragma once
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Shop.h"
#include "Cloth.h"
class Order
{
public:
    Order(Shop* shop);
    Shop* getShop();
    void addCloth(Cloth* clothToAdd);
    double getTotalPrice();
    void addNumber(int number);
    vector<int> getNumber();
    vector<Cloth*> getClothes();
private:
    vector<Cloth*> _orderedClothes;
    vector<int> _number;
    Shop* _shop;
};
#endif // !ORDER_H