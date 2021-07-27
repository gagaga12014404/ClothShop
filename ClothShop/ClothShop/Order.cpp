#include "Order.h"

Order::Order(Shop* shop)
{
    _shop = shop;
}

Shop* Order::getShop()
{
    return _shop;
}

void Order::addCloth(Cloth* clothToAdd)
{
    _orderedClothes.push_back(clothToAdd);
}

double Order::getTotalPrice()
{
    double total = 0;
    int j = 0;

    for (auto i : _orderedClothes)
    {
        total += (i->getPrice() * _number[j]);
        j++;
    }

    return total;
}

void Order::addNumber(int number)
{
    _number.push_back(number);
}

vector<int> Order::getNumber()
{
    return _number;
}

vector<Cloth*> Order::getClothes()
{
    return _orderedClothes;
}
