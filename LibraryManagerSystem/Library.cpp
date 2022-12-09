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
		std::cout << " 0 : �˳�" << std::endl;
		std::cout << " 1 : ע��" << std::endl;
		std::cout << " 2 : ��¼" << std::endl;
		std::cout << " 3 : ����Ա��¼" << std::endl;
		std::cout << "��ѡ��:";
		*/
		std::cout << endl << endl << endl << endl << endl << endl;
		std::cout << "\t\t\t\t ********************************************************" << std::endl;
		std::cout << " \t\t\t\t*                                                      *" << std::endl;
		std::cout << " \t\t\t\t*           ��ӭ����ͼ�����ϵͳ����ѡ����ع���       *" << std::endl;
		std::cout << " \t\t\t\t*                                                      *" << std::endl;
		std::cout << " \t\t\t\t*                   1. ���û�ע��                      *" << std::endl;
		std::cout << " \t\t\t\t*                   2. �����˻���¼                    *" << std::endl;
		std::cout << " \t\t\t\t*                   3. ����Ա��¼                      *" << std::endl;
		std::cout << " \t\t\t\t*                   0. �˳�����                        *" << std::endl;
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
		std::cout << "���������Ա�û�����";
		std::cin >> name;
		if (name != std::string(_name)) {
			std::cout << "�û��������㻹��" << i << "�λ���" << std::endl;
			continue;
		}
		_manager.set_name(name);
		std::cout << "���������Ա���룺";
		for (int j = 5; j >= 0; j--) {
			std::cin >> password;
			if (password != std::string(_password)) {
				std::cout << "��������㻹��" << j << "�λ���" << std::endl;
				continue;
			}
			break;
		}
		_manager.set_password(password);
		std::cout << "��¼�ɹ�" << std::endl;
		system("pause");
		return true;
	}
	return false;
}