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
    double getPoint();//�õ��c��
    void makeNewOrder(Shop* shop);//������ӆ��
    void addClothToOrder(Cloth* cloth, int number);//���·�����order������Ҳ����
    double getOrderTotalPrice();//�����~
    bool isPointEnough();//ʣ�N�c���Ƿ����
    void reducePoingFromOrder();//�ۿ�
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
    bool _isOrder;//�Ƿ��н���ӆ��
    vector<Order*> _orders;

};
#endif // !CUSTOMER_H