//Ŀ��:����һ����ʹ���߽��棬�OӋһ��ُ�����ģ��܉�����̵꣬�����·����鿴�·��ĳ�ʽ��
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