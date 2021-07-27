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
    void Floor1();//第一層內容
    void Floor2();//第二層內容
    void Floor3(string name);//第三層內容
    int Floor1Input();//第一層輸入，每層輸入的防呆皆不同，故每層輸入都寫一次
    int Floor2Input();//第二層輸入
    int Floor3Input();//第三層輸入
    void Floor3Order(int floor3Order, vector<Customer*> customer, int floor1Order, int floor2Order, int& number);
    void Floor3Order1(Mall mall);//新增衣服
    void Floor3Order2(vector<Cloth*> clothes);//查看所有衣服
    void Floor3Order3();//建立新訂單
    void Floor3Order4(int& number);//購買衣服
    void Floor3Order5();//結束訂單
    void Floor3Order6(vector<Customer*> customer, int floor2Order);//查看剩餘點數
    void Floor3Order7(vector<Customer*> customer, int floor1Order);//查看歷史紀錄

};
#endif // !MALLUI_H