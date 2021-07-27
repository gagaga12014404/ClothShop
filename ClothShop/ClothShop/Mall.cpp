#include "Mall.h"
Mall::Mall()//建立3個商店
{
	_shops.push_back(new Shop("UNIQLO"));
	_shops.push_back(new Shop("H&M"));
	_shops.push_back(new Shop("ZARA"));
	_customers.push_back(new Customer("Amber"));
	_customers.push_back(new Customer("Tim"));
	_customers.push_back(new Customer("Marry"));
	_shopIndex = 0;//選擇商店用
	_customerIndex = 0;//選擇客戶用
}
void Mall::creatNewCloth(string name, string description, double price)
{
	_shops[_shopIndex]->addNewCloth(name, description, price, _shops[_shopIndex]->getClothesSize() + 1);
}
/*void Mall::selectShop(int shopIndex)
{
	_shopIndex = shopIndex - 1;//vector從0開始，但輸入是123
}*/
vector<Cloth*>* Mall::getClothes()
{
	return _shops[_shopIndex]->getClothes();
}
vector<Shop*>* Mall::getShops()
{
	return &_shops;
}

vector<Customer*>* Mall::getCustomers()
{
	return &_customers;
}

void Mall::makeNewOrder()
{
	_customers[_customerIndex]->makeNewOrder(_shops[_shopIndex]);
}

void Mall::addClothToOrder(int id, int number)
{
	_customers[_customerIndex]->addClothToOrder(_shops[_shopIndex]->findCloth((id - 1)), number);
}

void Mall::selectCustomerAndShop(int customerIndex, int shopIndex)
{
	_customerIndex = customerIndex - 1;//vector從0開始，但輸入是123
	_shopIndex = shopIndex - 1;
}

bool Mall::isPointEnough()
{
	return _customers[_customerIndex]->isPointEnough();
}

void Mall::reducePointFromOrder()
{
	_customers[_customerIndex]->reducePoingFromOrder();
}

void Mall::cancelOrder()
{
	_customers[_customerIndex]->cancelOrder();
}

Order* Mall::getCurrentOrder()
{
	return _customers[_customerIndex]->getCurrentOrder();
}

bool Mall::isOrder()
{
	return _customers[_customerIndex]->isOrder();
}
