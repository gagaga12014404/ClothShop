#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include "Order.h"
#include "Cloth.h"
#include "Shop.h"
#include <string>
using namespace std;
class Customer
{
public:
    Customer(string name);
    string getName();
    double getPoint();//得到點數
    void makeNewOrder(Shop* shop);//建立新訂單
    void addClothToOrder(Cloth* cloth, int number);//把衣服加入order，數量也加入
    double getOrderTotalPrice();//總金額
    bool isPointEnough();//剩餘點數是否足夠
    void reducePoingFromOrder();//扣款
    void cancelOrder();
    Order* getCurrentOrder();
    bool isOrder();
    vector<Order*>* getPurchaseHistoryFrom();
    vector<Cloth*> orderedClothes;
    vector<int> number2;
private:
    string _name;
    double _point;
    Order* _order;
    bool _isOrder;//是否有建立訂單
    vector<Order*> _orders;

};
#endif // !CUSTOMER_H