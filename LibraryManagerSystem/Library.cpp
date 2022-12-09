#include <iostream>
#include "Book.h"
#include "Manager.h"
#include "record.h"
#include "User.h"
#include "Library.h"

using namespace std;

Library::Library() {
	_manager = Manager(_name, _password);
}

void Library::begin() {
	std::string choice;
	while (true) {
		system("cls");
		/*
		std::cout << " 0 : 退出" << std::endl;
		std::cout << " 1 : 注册" << std::endl;
		std::cout << " 2 : 登录" << std::endl;
		std::cout << " 3 : 管理员登录" << std::endl;
		std::cout << "请选择:";
		*/
		std::cout << endl << endl << endl << endl << endl << endl;
		std::cout << "\t\t\t\t ********************************************************" << std::endl;
		std::cout << " \t\t\t\t*                                                      *" << std::endl;
		std::cout << " \t\t\t\t*           欢迎进入图书管理系统，请选择相关功能       *" << std::endl;
		std::cout << " \t\t\t\t*                                                      *" << std::endl;
		std::cout << " \t\t\t\t*                   1. 新用户注册                      *" << std::endl;
		std::cout << " \t\t\t\t*                   2. 已有账户登录                    *" << std::endl;
		std::cout << " \t\t\t\t*                   3. 管理员登录                      *" << std::endl;
		std::cout << " \t\t\t\t*                   0. 退出程序                        *" << std::endl;
		std::cout << " \t\t\t\t*                                                      *" << std::endl;
		std::cout << " \t\t\t\t********************************************************" << std::endl;
		std::cin >> choice;
		system("cls");
		if (choice == "0") {
			return;
		}
		else if (choice == "1") {
			if (!sign_up())
				continue;
			_user.show_menu();
		}
		else if (choice == "2") {
			if (!sign_in())
				continue;
			_user.show_menu();
		}
		else if (choice == "3") {
			if (!manager_sign_in())
				continue;
			_manager.show_menu();
		}
		else {
			continue;
		}
	}
}

bool Library::sign_up() {
	_user = _manager.register_user();
	return true;
}

bool Library::sign_in() {
	if (_manager.check_user(_user)) {
		//cout << _user.get_id() << endl;
		//system("pause");
		return true;
	}
	else
		return false;
}

bool Library::manager_sign_in() {
	std::string name;
	std::string password;
	for (int i = 5; i >= 0; i--) {
		std::cout << "请输入管理员用户名：";
		std::cin >> name;
		if (name != std::string(_name)) {
			std::cout << "用户名错误，你还有" << i << "次机会" << std::endl;
			continue;
		}
		_manager.set_name(name);
		std::cout << "请输入管理员密码：";
		for (int j = 5; j >= 0; j--) {
			std::cin >> password;
			if (password != std::string(_password)) {
				std::cout << "密码错误，你还有" << j << "次机会" << std::endl;
				continue;
			}
			break;
		}
		_manager.set_password(password);
		std::cout << "登录成功" << std::endl;
		system("pause");
		return true;
	}
	return false;
}