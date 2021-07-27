#pragma once
#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Cloth.h"
#include "Suite.h"
using namespace std;
class Shop
{
public:
    Shop(string name);//建構子，初始化商店名字
    string getName();
    void addNewCloth(string name, string description, double price, int id);//新建衣服
    vector<Cloth*>* getClothes();
    int getClothesSize();
    Cloth* findCloth(int id);
private:
    vector<Cloth*> _clothes;
    string _name;
    void ReadFile();//讀檔
};

#endif // !SHOP_H




