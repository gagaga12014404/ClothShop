//目的:寫出一個有使用者介面，設計一個購物中心，能夠管理商店，新增衣服，查看衣服的程式。
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Cloth.h"
#include "Shop.h"
#include "Mall.h"
#include "MallUI.h"
using namespace std;


int main()
{
    Mall mall;
    MallUI ui(&mall);
    ui.start();
    system("pause");
}