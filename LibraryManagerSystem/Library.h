#pragma once

#include<memory>
#include"User.h"
#include"Manager.h"

class Library {
public:
	Library();
	void begin();//开始

private:
	bool sign_up();//注册
	bool sign_in();//登录
	bool manager_sign_in();//管理员登录

private:
	User _user;
	Manager _manager;
	char _name[20] = "Manager";//管理员账号
	char _password[20] = "123456";//管理员密码
};