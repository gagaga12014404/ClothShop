#include "MallUI.h"
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
}
int MallUI::start() {
    vector<Shop*> shop = *_mall->getShops();
    vector<Customer*> customer = *_mall->getCustomers();
    int number;//���ټ��·�

    while (true) {
        Floor1();//��һ���x��͑�
        int floor1Order = Floor1Input();//��һ��ݔ���Ă��͑�

        if (floor1Order == 4)//4.�x�_
            return 0;

        Floor2();//�ڶ���
        int floor2Order = Floor2Input();//�ڶ����x���̵�
        _mall->selectCustomerAndShop(floor1Order, floor2Order);//�x��͑����̵�

        while (true) {
            cout << "\n�H�۵��: " << customer[floor1Order - 1]->getName() << "������!" << endl;
            Floor3(shop[floor2Order - 1]->getName());
            int floor3Order = Floor3Input();//������ݔ��
            Floor3Order(floor3Order, customer, floor1Order, floor2Order, number);

            if (floor3Order == 8)
                break;
        }
    }
}
void MallUI::Floor1()//��һ�Ӄ���
{
    cout << "1.Amber\n"
        << "2.Tim\n"
        << "3.Marry\n"
        << "4.�x�_\n"
        << "select customer: ";
}
void MallUI::Floor2()//�ڶ��Ӄ���
{
    cout << "1.UNIQLO\n"
        << "2.H&M\n"
        << "3.ZARA\n"
        << "Select Shop: ";
}
void MallUI::Floor3(string name)//�����Ӄ���
{
    cout << "(" << name << ")" << "1.�����·�" << endl;
    cout << "(" << name << ")" << "2.�鿴�����·�" << endl;
    cout << "(" << name << ")" << "3.������ӆ��" << endl;
    cout << "(" << name << ")" << "4.ُ�I�·�" << endl;
    cout << "(" << name << ")" << "5.�Y��ӆ��" << endl;
    cout << "(" << name << ")" << "6.�鿴ʣ�N�c��" << endl;
    cout << "(" << name << ")" << "7.�鿴�vʷ�o�" << endl;
    cout << "(" << name << ")" << "8.�x�_" << endl;
    cout << "Ոݔ���x��: ";
}
int MallUI::Floor1Input()//��һ��ݔ��
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>4)//ֻ���x1-4
    {
        cin.clear();
        getline(cin, str);
        cout << "Ո�x�����ϵĿ͑�: \nSelect customer:";
    }

    return order;
}
int MallUI::Floor2Input()//�ڶ���ݔ��
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>3)//ֻ���x1-3
    {
        cin.clear();
        getline(cin, str);
        cout << "Ո�x�����ϵĵ��: \nSelect Shop:";
    }

    return order;
}
int MallUI::Floor3Input()//������ݔ��
{
    int order;
    string str;

    while (!(cin >> order) || order < 1 || order>8)//ֻ���x1-8
    {
        cin.clear();
        getline(cin, str);
        cout << "Ոݔ�����_�x�: ";
    }

    return order;
}
void MallUI::Floor3Order(int floor3Order, vector<Customer*> customer, int floor1Order, int floor2Order, int& number)
{
    if (floor3Order == 1)//�����·�
        Floor3Order1(*_mall);
    else if (floor3Order == 2)//�鿴�����·�
        Floor3Order2(*_mall->getClothes());
    else if (floor3Order == 3)//����ӆ��
        Floor3Order3();
    else if (floor3Order == 4)//ُ�I�·�
        Floor3Order4(number);
    else if (floor3Order == 5)//�Y��ӆ��
        Floor3Order5();
    else if (floor3Order == 6)//�鿴ʣ�N�c��
        Floor3Order6(customer, floor1Order);
    else if (floor3Order == 7)
        Floor3Order7(customer, floor1Order);
}
void MallUI::Floor3Order1(Mall mall)
{
    string name, description;
    double price;
    string str;
    cout << "Ոݔ���·����Q: ";
    cin >> name;
    cout << "Ոݔ���·�����: ";
    cin >> description;
    cout << "Ոݔ��r��: ";

    while (!(cin >> price) || price <= 0)        //����
    {
        cin.clear();
        getline(cin, str);
        cout << "�·��r����С춵���㣬Ո����ݔ��\nՈݔ��r��: ";
    }

    mall.creatNewCloth(name, description, price);
}
void MallUI::Floor3Order2(vector<Cloth*> clothes)
{
    cout << setfill(' ') << setw(5) << left << "NO.";
    cout << setfill(' ') << setw(40) << left << "�·����Q";
    cout << setfill(' ') << setw(10) << left << "�r��";
    cout << setfill(' ') << setw(20) << left << "����" << endl;

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
    cout << "�ɹ�����ӆ��!!!" << endl;
}
void MallUI::Floor3Order4(int& number)
{
    if (!_mall->isOrder())
    {
        cout << "Ո�Ƚ���ӆ�Σ�����ُ�I�·�!" << endl;
    }
    else
    {
        Floor3Order2(*_mall->getClothes());//�@ʾ�������·�

        while (true)
        {
            cout << "Ոݔ���·�ID, �x�_Ոݔ��-1:";
            int order;
            cin >> order;

            if (order == -1)
                break;

            cout << "Ոݔ���·�����:";
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
        cout << "Ո�Ƚ���ӆ�Σ�����ُ�I�·�!" << endl;
    }
    else if (_mall->isPointEnough())
    {
        cout << "ӆ�νY���ɹ�!" << endl;
        _mall->reducePointFromOrder();
        _mall->cancelOrder();
    }
    else
    {
        cout << "ʣ�N�c�����㣬�o���M��ُ�I!" << endl;
        _mall->cancelOrder();
    }
}
void MallUI::Floor3Order6(vector<Customer*> customer, int floor1Order)
{
    cout << "��ʣ�N���c��ʣ��:" << customer[floor1Order - 1]->getPoint() << endl;
}
void MallUI::Floor3Order7(vector<Customer*> customer, int floor1Order)
{
    cout << customer[floor1Order - 1]->getName() << "�Ěvʷ�o�:" << endl;
    cout << setfill(' ') << setw(40) << left << "���Q";
    cout << setfill(' ') << setw(10) << left << "����";
    cout << setfill(' ') << setw(10) << left << "�΃r";
    cout << setfill(' ') << setw(10) << left << "���r" << endl;
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
    cout << "�����~:" << total << endl;
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
