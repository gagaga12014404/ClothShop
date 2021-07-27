#ifndef MALLUI_H
#define MALLUI_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Cloth.h"
#include "Suite.h"
#include "Shop.h"
#include "Mall.h"
using namespace std;
class MallUI
{
public:
    MallUI(Mall* mall);
    int start();
private:
    Mall* _mall;
    void Floor1();//��һ�Ӄ���
    void Floor2();//�ڶ��Ӄ���
    void Floor3(string name);//�����Ӄ���
    int Floor1Input();//��һ��ݔ�룬ÿ��ݔ��ķ����Բ�ͬ����ÿ��ݔ�붼��һ��
    int Floor2Input();//�ڶ���ݔ��
    int Floor3Input();//������ݔ��
    void Floor3Order(int floor3Order, vector<Customer*> customer, int floor1Order, int floor2Order, int& number);
    void Floor3Order1(Mall mall);//�����·�
    void Floor3Order2(vector<Cloth*> clothes);//�鿴�����·�
    void Floor3Order3();//������ӆ��
    void Floor3Order4(int& number);//ُ�I�·�
    void Floor3Order5();//�Y��ӆ��
    void Floor3Order6(vector<Customer*> customer, int floor2Order);//�鿴ʣ�N�c��
    void Floor3Order7(vector<Customer*> customer, int floor1Order);//�鿴�vʷ�o�

};
#endif // !MALLUI_H