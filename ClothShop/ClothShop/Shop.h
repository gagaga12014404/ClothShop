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
    Shop(string name);//�����ӣ���ʼ���̵�����
    string getName();
    void addNewCloth(string name, string description, double price, int id);//�½��·�
    vector<Cloth*>* getClothes();
    int getClothesSize();
    Cloth* findCloth(int id);
private:
    vector<Cloth*> _clothes;
    string _name;
    void ReadFile();//�x�n
};

#endif // !SHOP_H




