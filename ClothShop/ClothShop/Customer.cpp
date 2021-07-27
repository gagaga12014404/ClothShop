#include "Customer.h"

Customer::Customer(string name)
{
    _name = name;
    _point = 2000.000000;//üc”µ³õÊ¼žé2000
    _isOrder = false;
}

string Customer::getName()
{
    return _name;
}

double Customer::getPoint()
{
    return _point;
}

void Customer::makeNewOrder(Shop* shop)
{
    _order = new Order(shop);
    _isOrder = true;
}

void Customer::addClothToOrder(Cloth* cloth, int number)
{
    _order->addCloth(cloth);
    _order->addNumber(number);
    orderedClothes.push_back(cloth);
    number2.push_back(number);
}

double Customer::getOrderTotalPrice()
{
    return _order->getTotalPrice();
}

bool Customer::isPointEnough()
{
    if (_point >= getOrderTotalPrice())
        return true;

    return false;
}

void Customer::reducePoingFromOrder()
{
    _point -= getOrderTotalPrice();
}

void Customer::cancelOrder()
{

    delete(_order);
    _isOrder = false;
}

Order* Customer::getCurrentOrder()
{
    return _order;
}

bool Customer::isOrder()
{
    return _isOrder;
}

vector<Order*>* Customer::getPurchaseHistoryFrom()
{
    return &_orders;
}
