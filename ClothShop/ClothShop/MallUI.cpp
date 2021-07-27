#include "MallUI.h"
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
}
int MallUI::start() {
    vector<Shop*> shop = *_mall->getShops();
    vector<Customer*> customer = *_mall->getCustomers();
    int number;//多少件衣服

    while (true) {
        Floor1();//第一層選擇客戶
        int floor1Order = Floor1Input();//第一層輸入哪個客戶

        if (floor1Order == 4)//4.離開
            return 0;

        Floor2();//第二層
        int floor2Order = Floor2Input();//第二層選擇商店
        _mall->selectCustomerAndShop(floor1Order, floor2Order);//選擇客戶和商店

        while (true) {
            cout << "\n親愛的顧客: " << customer[floor1Order - 1]->getName() << "，您好!" << endl;
            Floor3(shop[floor2Order - 1]->getName());
            int floor3Order = Floor3Input();//第三層輸入
            Floor3Order(floor3Order, customer, floor1Order, floor2Order, number);

            if (floor3Order == 8)
                break;
        }
    }
}
void MallUI::Floor1()//第一層內容
{
    cout << "1.Amber\n"
        << "2.Tim\n"
        << "3.Marry\n"
        << "4.離開\n"
        << "select customer: ";
}
void MallUI::Floor2()//第二層內容
{
    cout << "1.UNIQLO\n"
        << "2.H&M\n"
        << "3.ZARA\n"
        << "Select Shop: ";
}
void MallUI::Floor3(string name)//第三層內容
{
    cout << "(" << name << ")" << "1.新增衣服" << endl;
    cout << "(" << name << ")" << "2.查看所有衣服" << endl;
    cout << "(" << name << ")" << "3.建立新訂單" << endl;
    cout << "(" << name << ")" << "4.購買衣服" << endl;
    cout << "(" << name << ")" << "5.結束訂單" << endl;
    cout << "(" << name << ")" << "6.查看剩餘點數" << endl;
    cout << "(" << name << ")" << "7.查看歷史紀錄" << endl;
    cout << "(" << name << ")" << "8.離開" << endl;
    cout << "請輸入選擇: ";
}
int MallUI::Floor1Input()//第一層輸入
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>4)//只能選1-4
    {
        cin.clear();
        getline(cin, str);
        cout << "請選擇畫面上的客戶: \nSelect customer:";
    }

    return order;
}
int MallUI::Floor2Input()//第二層輸入
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>3)//只能選1-3
    {
        cin.clear();
        getline(cin, str);
        cout << "請選擇畫面上的店家: \nSelect Shop:";
    }

    return order;
}
int MallUI::Floor3Input()//第三層輸入
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>8)//只能選1-8
    {
        cin.clear();
        getline(cin, str);
        cout << "請輸入正確選項: ";
    }

    return order;
}
void MallUI::Floor3Order(int floor3Order, vector<Customer*> customer, int floor1Order, int floor2Order, int& number)
{
    if (floor3Order == 1)//新增衣服
        Floor3Order1(*_mall);
    else if (floor3Order == 2)//查看所有衣服
        Floor3Order2(*_mall->getClothes());
    else if (floor3Order == 3)//建立訂單
        Floor3Order3();
    else if (floor3Order == 4)//購買衣服
        Floor3Order4(number);
    else if (floor3Order == 5)//結束訂單
        Floor3Order5();
    else if (floor3Order == 6)//查看剩餘點數
        Floor3Order6(customer, floor1Order);
    else if (floor3Order == 7)
        Floor3Order7(customer, floor1Order);
}
void MallUI::Floor3Order1(Mall mall)
{
    string name, description;
    double price;
    string str;
    cout << "請輸入衣服名稱: ";
    cin >> name;
    cout << "請輸入衣服描述: ";
    cin >> description;
    cout << "請輸入價格: ";

    while (!(cin >> price) || price <= 0)        //防呆
    {
        cin.clear();
        getline(cin, str);
        cout << "衣服價格不能小於等於零，請重新輸入\n請輸入價格: ";
    }

    mall.creatNewCloth(name, description, price);
}
void MallUI::Floor3Order2(vector<Cloth*> clothes)
{
    cout << setfill(' ') << setw(5) << left << "NO.";
    cout << setfill(' ') << setw(40) << left << "衣服名稱";
    cout << setfill(' ') << setw(10) << left << "價格";
    cout << setfill(' ') << setw(20) << left << "描述" << endl;

    //cout << a[0]->getName() << endl;
    for (unsigned int i = 0; i < clothes.size(); i++)
    {
        cout << setfill(' ') << setw(5) << left << clothes[i]->getId();
        cout << setfill(' ') << setw(40) << left << clothes[i]->getName();
        cout << setfill(' ') << setw(9) << left << clothes[i]->getPrice();
        cout << setfill(' ') << setw(20) << left << clothes[i]->getDescription() << endl;
    }
    for (unsigned int i = 0; i < clothes.size(); i++)
    {
        cout << setfill(' ') << setw(5) << left << clothes[i]->getId();
        cout << setfill(' ') << setw(40) << left << clothes[i]->getName();
        cout << setfill(' ') << setw(9) << left << clothes[i]->getPrice();
        cout << setfill(' ') << setw(20) << left << clothes[i]->getDescription() << endl;
    }
    cout << endl;
}
void MallUI::Floor3Order3()
{
    _mall->makeNewOrder();
    cout << "成功建立訂單!!!" << endl;
}
void MallUI::Floor3Order4(int& number)
{
    if (!_mall->isOrder())
    {
        cout << "請先建立訂單，才能購買衣服!" << endl;
    }
    else
    {
        Floor3Order2(*_mall->getClothes());//顯示出所有衣服

        while (true)
        {
            cout << "請輸入衣服ID, 離開請輸入-1:";
            int order;
            cin >> order;

            if (order == -1)
                break;

            cout << "請輸入衣服數量:";
            int number;
            cin >> number;
            _mall->addClothToOrder(order, number);
        }
    }
}
void MallUI::Floor3Order5()
{
    if (!_mall->isOrder())
    {
        cout << "請先建立訂單，才能購買衣服!" << endl;
    }
    else if (_mall->isPointEnough())
    {
        cout << "訂單結束成功!" << endl;
        _mall->reducePointFromOrder();
        _mall->cancelOrder();
    }
    else
    {
        cout << "剩餘點數不足，無法進行購買!" << endl;
        _mall->cancelOrder();
    }
}
void MallUI::Floor3Order6(vector<Customer*> customer, int floor1Order)
{
    cout << "您剩餘的點數剩下:" << customer[floor1Order - 1]->getPoint() << endl;
}
void MallUI::Floor3Order7(vector<Customer*> customer, int floor1Order)
{
    cout << customer[floor1Order - 1]->getName() << "的歷史紀錄:" << endl;
    cout << setfill(' ') << setw(40) << left << "名稱";
    cout << setfill(' ') << setw(10) << left << "數量";
    cout << setfill(' ') << setw(10) << left << "單價";
    cout << setfill(' ') << setw(10) << left << "總價" << endl;
    vector<int> n = customer[floor1Order - 1]->number2;
    vector<Cloth*> c = customer[floor1Order - 1]->orderedClothes;
    int total = 0;
    for (int i = 0;i < n.size();i++)
    {
        cout << setfill(' ') << setw(40) << left << c[i]->getName();
        cout << setfill(' ') << setw(10) << left << n[i];
        cout << setfill(' ') << setw(10) << left << c[i]->getPrice();
        cout << setfill(' ') << setw(10) << left << n[i] * c[i]->getPrice() << endl;
        total += n[i] * c[i]->getPrice();
    }
    cout << "總金額:" << total << endl;
    /*vector<Order*> order = *customer[floor1Order - 1]->getPurchaseHistoryFrom();
    for (auto i : order)
    {
        vector<int> n = i->getNumber();
        vector<Cloth*> c = i->getClothes();
        for (auto k : c)
            cout << k;
        for (auto j : n)
            cout << j<<endl;
    }*/
}
