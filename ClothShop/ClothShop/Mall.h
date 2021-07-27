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
    Mall();//建立3個商店，建立3個客戶
    void creatNewCloth(string name, string description, double price);
    //void selectShop(int shopIndex);//選擇商店
    vector<Cloth*>* getClothes();
    vector<Shop*>* getShops();
    vector<Customer*>* getCustomers();
    void makeNewOrder();//建立訂單，用customer來建立
    void addClothToOrder(int id, int number);//利用custormer建立衣服，和數量
    void selectCustomerAndShop(int customerIndex, int shopIndex);//選擇商店和客戶
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