#include "Cloth.h"
Cloth::Cloth(string name, string description, double price, int id)//½¨˜‹×Ó
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}
string Cloth::getName()
{
    return _name;
}
string Cloth::getDescription()
{
    return _description;
}
double Cloth::getPrice()
{
    return _price;
}
int Cloth::getId()
{
    return _id;
}