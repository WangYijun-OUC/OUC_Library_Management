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
	cout << "\t�û�ID��" << this->id << "\t�û�����" << this->name << "\t���";
	if (this->category == 0)
		cout << "ͼ����ʧ";
	else
		cout << "��ʱ����";
	cout << "\t�����" << money << endl;
}
void FR::set_name(char _name[20])
{
	strcpy_s(name, _name);
}
