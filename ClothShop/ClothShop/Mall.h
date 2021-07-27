#pragma once
#ifndef MALL_H
#define MALL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Cloth.h"
#include "Shop.h"
#include "Customer.h"
using namespace std;
class Mall
{
public:
    Mall();//����3���̵꣬����3���͑�
    void creatNewCloth(string name, string description, double price);
    //void selectShop(int shopIndex);//�x���̵�
    vector<Cloth*>* getClothes();
    vector<Shop*>* getShops();
    vector<Customer*>* getCustomers();
    void makeNewOrder();//����ӆ�Σ���customer����
    void addClothToOrder(int id, int number);//����custormer�����·����͔���
    void selectCustomerAndShop(int customerIndex, int shopIndex);//�x���̵�Ϳ͑�
    bool isPointEnough();
    void reducePointFromOrder();
    void cancelOrder();
    Order* getCurrentOrder();
    bool isOrder();
private:
    int _shopIndex;
    int _customerIndex;
    vector<Customer*> _customers;
    vector<Shop*> _shops;
};
#endif // !MALL_H