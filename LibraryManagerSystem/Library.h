#pragma once

#include<memory>
#include"User.h"
#include"Manager.h"

class Library {
public:
	Library();
	void begin();//��ʼ

private:
	bool sign_up();//ע��
	bool sign_in();//��¼
	bool manager_sign_in();//����Ա��¼

private:
	User _user;
	Manager _manager;
	char _name[20] = "Manager";//����Ա�˺�
	char _password[20] = "123456";//����Ա����
};