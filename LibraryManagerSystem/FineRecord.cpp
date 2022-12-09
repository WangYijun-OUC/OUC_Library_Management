#include "FineRecord.h"
#include <string.h>
#include <iostream>
using namespace std;
FR::FR(int _id, char* _name, int _category, double _money)
{
	this->id = _id;
	strcpy_s(this->name, _name);
	this->money = _money;
	this->category = _category;
	
}
int FR::get_id()
{
	return id;
}
char* FR::get_name()
{
	return name;
}
void FR::show()
{
	cout << "\t用户ID：" << this->id << "\t用户名：" << this->name << "\t类别：";
	if (this->category == 0)
		cout << "图书遗失";
	else
		cout << "超时还书";
	cout << "\t罚款金额：" << money << endl;
}
void FR::set_name(char _name[20])
{
	strcpy_s(name, _name);
}
