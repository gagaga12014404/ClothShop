#ifndef CLOTH_H
#define CLOTH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Cloth
{
public:
    Cloth(string name, string description, double price, int id);//������
    string getName();
    string getDescription();
    virtual double getPrice();
    int getId();
    string getInformation();//�]����??
protected:
    string _name;
    string _description;
    double _price;
    int _id;

};

#endif // !CLOTH_H



