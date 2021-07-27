#include "Shop.h"
Shop::Shop(string name)//建構子，初始化商店名字
{
	_name = name;
	ReadFile();
}
string Shop::getName()
{
	return _name;
}
void Shop::addNewCloth(string name, string description, double price, int id)//新建衣服
{
	_clothes.push_back(new Cloth(name, description, price, id));
}

vector<Cloth*>* Shop::getClothes()
{
	return &_clothes;
}
int Shop::getClothesSize()
{
	return _clothes.size();
}
Cloth* Shop::findCloth(int id)
{
	return _clothes[id];
}

void Shop::ReadFile()
{

	ifstream file("Cloth.txt");
	string line;
	int count = 0;
	string whichShop = "Shop " + getName() + ':';
	if (whichShop == "Shop UNIQLO:")
	{
		while (getline(file, line)) {
			if (count >= 1 && count <= 2)
			{
				string word;
				vector<string> cloth;

				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				addNewCloth(cloth[1], cloth[2], stod(cloth[3]), stod(cloth[0]));
			}
			if (count >= 3 && count <= 4)
			{
				string word;
				vector<string> cloth;
				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				Suite* s = new Suite(cloth[1], cloth[2], 0, stod(cloth[0]));
				s->add(_clothes[0]);
				_clothes.push_back(s);
			}
			count += 1;

		}
	}
	if (whichShop == "Shop ZARA:")
	{
		while (getline(file, line)) {
			if (count >= 6 && count <= 9)
			{
				string word;
				vector<string> cloth;

				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				addNewCloth(cloth[1], cloth[2], stod(cloth[3]), stod(cloth[0]));
			}
			if (count >= 10 && count <= 11)
			{
				string word;
				vector<string> cloth;
				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				Suite* s = new Suite(cloth[1], cloth[2], 0, stod(cloth[0]));
				s->add(_clothes[0]);
				s->add(_clothes[1]);
				_clothes.push_back(s);
			}
			count += 1;

		}
	}
	if (whichShop == "Shop H&M:")
	{
		while (getline(file, line)) {
			if (count >= 13 && count <= 16)
			{
				string word;
				vector<string> cloth;

				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				addNewCloth(cloth[1], cloth[2], stod(cloth[3]), stod(cloth[0]));
			}
			if (count >= 17 && count <= 17)
			{
				string word;
				vector<string> cloth;
				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				Suite* s = new Suite(cloth[1], cloth[2], 0, stod(cloth[0]));
				s->add(_clothes[0]);
				s->add(_clothes[1]);
				s->add(_clothes[2]);
				_clothes.push_back(s);
			}
			count += 1;

		}
	}

}


/*void Shop::ReadFile() {
	ifstream file("Cloth.txt");
	string line;
	int count = 0;
	string whichShop= "Shop " + getName() + ':';
	if (whichShop == "Shop UNIQLO:")
	{
		while (getline(file, line)) {
			if (count >= 1 && count <= 4)
			{
				string word;
				vector<string> cloth;

				for (unsigned int i = 0; i < line.size(); i++) {//id,name,des,price
					if (line[i] == ',') {
						cloth.push_back(word);
						word = "";
						continue;
					}

					word += line[i];

					if (i == line.size() - 1)
						cloth.push_back(word);
				}
				if (count >= 3 && count <= 4)
				{//name,des,price,id
					Suite s(cloth[1], cloth[2], 0, stod(cloth[0]));
					s.add(_clothes[0]);
					//addNewCloth(s.getName(),s.getDescription(),s.getPrice(),s.getId());
				}
				addNewCloth(cloth[1], cloth[2], stod(cloth[3]), stod(cloth[0]));
			}
			count += 1;
		}
	}

}*/