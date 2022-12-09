#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "User.h"
#include "Manager.h"
#include "Record.h"
#include "FineRecord.h"
#include "OperationRecord_Book.h"
#include "OperationRecord_User.h"
#define MAX 100005
using namespace std;
int id_a[10000] = { 0 };
int cnt_a = 0;
int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool check(int date)//�ж��Ƿ�������
{
	int year = date / 10000;
	int month = date % 10000 / 100;
	int day = date % 100;

	if (!month || month > 13 || !day) return false;
	if (month != 2 && day > months[month]) return false;
	if (month == 2)
	{
		bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
		if (day > months[2] + leap) return false;
	}
	return true;

}

Manager::Manager(char newName[20], char newPassword[20]) {
	strcpy_s(name, newName);
	strcpy_s(password, newPassword);
}

void Manager::set_name(string _name) {
	for (int i = 0; i < _name.length(); i++)
		name[i] = _name[i];
}

char* Manager::get_name() {
	return name;
}

void Manager::set_password(string _passwd) {
	for (int i = 0; i < _passwd.length(); i++)
		password[i] = _passwd[i];
}

void Manager::show_menu() {
	string choice;
	while (true) {
		system("cls");
		/*
		std::cout << " 0 : �˳�" << std::endl;
		std::cout << " 1 : ����鼮" << std::endl;
		std::cout << " 2 : ɾ���鼮" << std::endl;
		std::cout << " 3 : �༭�鼮" << std::endl;
		std::cout << " 4 : ��ѯ�鼮" << std::endl;
		std::cout << " 5 : ����û�" << std::endl;
		std::cout << " 6 : ɾ���û�" << std::endl;
		std::cout << " 7 : �����û�" << std::endl;
		std::cout << " 8 : �޸��û�����" << std::endl;
		std::cout << " 9 : չʾ���ļ�¼" << std::endl;
		std::cout << " 10 : չʾ����Ա������¼" << std::endl;
		std::cout << "��ѡ��:";
		*/
		std::cout << " ********************************************************" << std::endl;
		std::cout << " *          ��ӭ��¼����Աϵͳ��                        *" << std::endl;
		std::cout << " *      ������������ֽ��о������                      *" << std::endl;
		std::cout << " *                                                      *" << std::endl;
		std::cout << " *           1 : ����鼮                               *" << std::endl;
		std::cout << " *           2 : ɾ���鼮                               *" << std::endl;
		std::cout << " *           3 : �༭�鼮                               *" << std::endl;
		std::cout << " *           4 : ��ѯ�鼮                               *" << std::endl;
		std::cout << " *           5 : ����û�                               *" << std::endl;
		std::cout << " *           6 : ɾ���û�                               *" << std::endl;
		std::cout << " *           7 : �����û�                               *" << std::endl;
		std::cout << " *           8 : �޸��û�����                           *" << std::endl;
		std::cout << " *           9 : չʾ���ļ�¼                           *" << std::endl;
		std::cout << " *           10 : չʾ����Ա������¼                    *" << std::endl;
		std::cout << " *           11 : ����Ƿ���¼                          *" << std::endl;
		std::cout << " *           12 : �鿴������                            *" << std::endl;
		std::cout << " *           13 : ��������鼮                          *" << std::endl;
		std::cout << " *           0���˳�����                                *" << std::endl;
		std::cout << " *                                                      *" << std::endl;
		std::cout << " ********************************************************" << std::endl;
		std::cin >> choice;
		if (choice == "0") {
			return;
		}
		else if (choice == "1") {
			add_book();
			system("pause");
		}
		else if (choice == "2") {
			delete_book();
			system("pause");
		}
		else if (choice == "3") {
			edit_book();
			system("pause");
		}
		else if (choice == "4") {
			search_book();
			system("pause");
		}
		else if (choice == "5") {
			add_user();
			//system("pause");
		}
		else if (choice == "6") {
			delete_user();
			system("pause");
		}
		else if (choice == "7") {
			search_user();
			system("pause");
		}
		else if (choice == "8") {
			edit_user_password();
			system("pause");
		}
		else if (choice == "9") {
			show_record();
			system("pause");
		}
		else if (choice == "10") {
			show_operation_record_book();
			show_operation_record_user();
			system("pause");
		}
		else if (choice == "11") {
			deal_fine_record();
			system("pause");
		}
		else if (choice == "12") {
			search_black_list();
			system("pause");
		}
		else if (choice == "13") {
			add_old_book();
			system("pause");
		}
		else {
			cout << "�����������������룡" << endl;
			system("pause");
			continue;
		}
	}
}

// �����û�
User Manager::register_user()
{
	User user;
	int id;
	char name[11] = { '\0'};
	char passwd[21] = { '\0'};
	char gender[10] = { '\0'};
	//char major[20] = { '\0' };
	int grade;
	char choice = {};
	string new_name;
	string new_passwd;
	int new_gender;
	int new_major;
	int new_grade;
	int new_status;

	while (true)
	{
		id = 0;
		//char name[11] = { '\0' };
		//passwd[21] = { '\0' };
		//gender[10] = { '0' };
		//char major[20] = { '\0' };
		grade = 0;
		choice = '\0';
		new_name = "";
		new_passwd = "";
		new_gender = 0;
		new_major = 0;
		new_grade = 0;
		new_status = 0;

		fstream ofs("User.dat", ios::binary | ios::in);
		if (!ofs)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			break;
		}

		//��ȡ���һ��ID
		User temp_user;
		int size = (int)sizeof(temp_user);

		ofs.seekg(-size, ios::end);
		//ofs.read((char*)&temp_user, sizeof(temp_user));

		if (ofs.read((char*)&temp_user, sizeof(temp_user)) && temp_user.get_id() >= 0)
			id = temp_user.get_id() + 1;
		else
			id = 2022101;
		ofs.close();


		while (true) {
			cout << "�����������û�������������10λ��:" << endl;
			while (!(cin >> new_name) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����������������������:" << endl;
			}
			if (new_name.length() > 10)
				cout << "�������ֹ��������������룡" << endl;
			else
				break;
		}

		memset(name, 0, sizeof(name));
		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];

		//if (strcmp(name, "0") == 0)return;

		/*while (true) {
			cout << "�����������û�����(������10λ):" << endl;
			cin >> new_passwd;
			if (new_passwd.length() > 10)
				cout << "����������������������룡" << endl;
			else
				break;
		}

		for (int i = 0; i < new_passwd.length(); i++)
			passwd[i] = new_passwd[i];*/

		while (true) {
			cout << "��ѡ�������û��Ա�:" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - Ů" << endl;
			//cout << "0 - �˳�" << endl;

			while (!(cin >> new_gender) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ������������룺" << endl;
			}

			//if (new_gender == 0)return;

			memset(gender, 0, sizeof(gender));
			if (new_gender == 1) {
				strcpy_s(gender, strlen("��") + 1, "��");
				break;
			}
			else if (new_gender == 2) {
				strcpy_s(gender, strlen("Ů") + 1, "Ů");
				break;
			}
			else {
				cout << "������� ���������룡" << endl;
			}
		}

		while (true) {
			cout << "�����������û��꼶( ������������� ��2020��" << endl;
			while (!(cin >> new_grade) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ������������룺" << endl;
			}

			//if (new_grade == 0)return;

			int count = 0;	// ���������꼶�Ƿ�Ϊ4λ
			int _grade = new_grade;
			while (_grade)
			{
				count++;
				_grade = _grade / 10;
			}
			if (count != 4 || (new_grade <= 2010 || new_grade > 2022))
				cout << "��������ȷ��ݣ�" << endl;
			else
				break;
		}
		grade = new_grade;


		while (true) {
			cout << "��ѡ�������û�Ժϵ:" << endl;
			cout << "1 - ���������ѧԺ" << endl;
			cout << "2 - ��Ϣ��ѧ�빤��ѧ��" << endl;
			cout << "3 - ��ѧ����ѧԺ" << endl;
			cout << "4 - ��������ѧѧԺ" << endl;
			cout << "5 - ��������ѧԺ" << endl;
			cout << "6 - ʳƷ��ѧ�빤��ѧԺ" << endl;
			cout << "7 - ҽҩѧԺ" << endl;
			cout << "8 - ����ѧԺ" << endl;
			cout << "9 - ������ѧ�빤��ѧԺ" << endl;
			cout << "10 - ����ѧԺ" << endl;
			cout << "11 - ����ѧԺ" << endl;
			cout << "12 - �����ѧԺ" << endl;
			cout << "13 - ��ѧ�����Ŵ���ѧԺ" << endl;
			cout << "14 - ��ѧԺ" << endl;
			cout << "15 - ���������빫������ѧԺ" << endl;
			cout << "16 - ��ѧ��ѧѧԺ" << endl;
			cout << "17 - ���Ͽ�ѧ�빤��ѧԺ" << endl;
			cout << "18 - ���˼����ѧԺ" << endl;
			cout << "19 - �籾ѧԺ" << endl;
			cout << "20 - ����ѧԺ" << endl;
			//cout << "0 - �˳�" << endl;

			//cin >> new_major;

			while (!(cin >> new_major) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�������ʹ���,���������룡" << endl;
			}

			//if (new_major == 0)return;

			if (new_major < 1 || new_major > 20) {
				cout << "ѡ�����������ѡ��" << endl;
			}
			else
				break;
		}

		cout << "�������û���ݣ�1-������ 2-�о�����" << endl;
		while (1)
		{
			while (!(cin >> new_status) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}

			//if (new_status == 0)return;

			if (new_status == 1 || new_status == 2)
				break;
			else
				cout << "��������������������" << endl;
		}

		cout << "ȷ�������û���Ϣ��" << endl;
		cout << "ID:" << id << endl;
		cout << "������" << name << endl;
		//cout << "����:" << passwd << endl;
		cout << "�꼶:" << grade << endl;
		cout << "�Ա�:" << gender << endl;
		cout << "Ժϵ:" << user.get_major(new_major) << endl;
		cout << "���:";
		if (new_status == 1)
			cout << "������" << endl;
		else
			cout << "�о���" << endl;
		cout << "�Ƿ�������" << endl;
		cout << "1 - ȷ�������û�" << endl;
		cout << "2 - ���������Ϣ�������󷵻��޸�" << endl;
		//cout << "0 - �˳�" << endl;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ݴ���,����������:" << endl;
		}

		//if (choice == '0')return;

		if (choice == '1')
			break;
		else
			system("cls");
			cout << "����������!" << endl;
	}

	if (choice == '1')
		// ѡ�������û�
	{
		fstream ofs("User.dat", ios::app | ios::binary);
		if (!ofs)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
		}

		//_itoa_s(id, passwd, 10);
		User new_user(id, name, gender, grade, new_major, 0, 0, 1, new_status);
		//new_user.get_id();
		//new_user.set_id(temp_user.get_id() + 1);
		//new_user.set_name(name);
		//new_user.set_gender(gender);
		//new_user.set_password(passwd);
		//new_user.set_borrow_num(0);
		//new_user.set_history_borrow_num(0);
		//new_user.set_user_state(1);
		//ofs.seekp(0, ios::end);
		ofs.write((char*)&new_user, sizeof(User));

		cout << "ע�����û��ɹ���" << endl;// ---------------1003�޸�
		//system("pause");
		system("pause");
		return new_user;
	}
}

void Manager::add_user()
{
	User user;
	int id;
	char name[11] = { '\0' };
	char passwd[21] = { '\0' };
	char gender[10] = { '\0' };
	//char major[20] = { '\0' };
	int grade;
	char choice = {};
	string new_name;
	string new_passwd;
	int new_gender;
	int new_major;
	int new_grade;
	int new_status = 0;

	while (true)
	{
		id = 0;
		//char name[11] = { '\0' };
		//passwd[21] = { '\0' };
		//gender[10] = { '0' };
		//char major[20] = { '\0' };
		grade = 0;
		choice = '\0';
		new_name = "";
		new_passwd = "";
		new_gender = 0;
		new_major = 0;
		new_grade = 0;
		new_status = 0;

		fstream ofs("User.dat", ios::binary | ios::in);
		if (!ofs)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			break;
		}

		//��ȡ���һ��ID
		User temp_user;
		int size = (int)sizeof(temp_user);

		ofs.seekg(-size, ios::end);
		//ofs.read((char*)&temp_user, sizeof(temp_user));

		if (ofs.read((char*)&temp_user, sizeof(temp_user)) && temp_user.get_id() >= 0)
			id = temp_user.get_id() + 1;
		else
			id = 2022101;
		ofs.close();


		while (true) {
			cout << "�����������û�������������10λ������0�˳���:" << endl;
			while (!(cin >> new_name) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����������������������:" << endl;
			}
			if (new_name.length() > 10)
				cout << "�������ֹ��������������룡" << endl;
			else
				break;
		}

		memset(name, 0, sizeof(name));
		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];

		if (strcmp(name, "0") == 0)return;

		/*while (true) {
			cout << "�����������û�����(������10λ):" << endl;
			cin >> new_passwd;
			if (new_passwd.length() > 10)
				cout << "����������������������룡" << endl;
			else
				break;
		}

		for (int i = 0; i < new_passwd.length(); i++)
			passwd[i] = new_passwd[i];*/

		while (true) {
			cout << "��ѡ�������û��Ա�:" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - Ů" << endl;
			cout << "0 - �˳�" << endl;

			while (!(cin >> new_gender) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ������������룺" << endl;
			}

			if (new_gender == 0)return;

			memset(gender, 0, sizeof(gender));
			if (new_gender == 1) {
				strcpy_s(gender, strlen("��") + 1, "��");
				break;
			}
			else if (new_gender == 2) {
				strcpy_s(gender, strlen("Ů") + 1, "Ů");
				break;
			}
			else {
				cout << "������� ���������룡" << endl;
			}
		}

		while (true) {
			cout << "�����������û��꼶( ������������� ��2020 ����0�˳���" << endl;
			while (!(cin >> new_grade) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ������������룺" << endl;
			}

			if (new_grade == 0)return;

			int count = 0;	// ���������꼶�Ƿ�Ϊ4λ
			int _grade = new_grade;
			while (_grade)
			{
				count++;
				_grade = _grade / 10;
			}
			if (count != 4 || (new_grade <= 2010 || new_grade > 2022))
				cout << "��������ȷ��ݣ�" << endl;
			else
				break;
		}
		grade = new_grade;
		while (true) {
			cout << "��ѡ�������û�Ժϵ:" << endl;
			cout << "1 - ���������ѧԺ" << endl;
			cout << "2 - ��Ϣ��ѧ�빤��ѧ��" << endl;
			cout << "3 - ��ѧ����ѧԺ" << endl;
			cout << "4 - ��������ѧѧԺ" << endl;
			cout << "5 - ��������ѧԺ" << endl;
			cout << "6 - ʳƷ��ѧ�빤��ѧԺ" << endl;
			cout << "7 - ҽҩѧԺ" << endl;
			cout << "8 - ����ѧԺ" << endl;
			cout << "9 - ������ѧ�빤��ѧԺ" << endl;
			cout << "10 - ����ѧԺ" << endl;
			cout << "11 - ����ѧԺ" << endl;
			cout << "12 - �����ѧԺ" << endl;
			cout << "13 - ��ѧ�����Ŵ���ѧԺ" << endl;
			cout << "14 - ��ѧԺ" << endl;
			cout << "15 - ���������빫������ѧԺ" << endl;
			cout << "16 - ��ѧ��ѧѧԺ" << endl;
			cout << "17 - ���Ͽ�ѧ�빤��ѧԺ" << endl;
			cout << "18 - ���˼����ѧԺ" << endl;
			cout << "19 - �籾ѧԺ" << endl;
			cout << "20 - ����ѧԺ" << endl;
			cout << "0 - �˳�" << endl;

			//cin >> new_major;

			while (!(cin >> new_major) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����ѡ�����,���������룡" << endl;
			}

			if (new_major == 0)return;

			if (new_major < 1 || new_major > 20) {
				cout << "ѡ�����������ѡ��" << endl;
			}
			else
				break;
		}

		cout << "�������û���ݣ�1-������ 2-�о��� 0-�˳���" << endl;
		while (1)
		{
			while (!(cin >> new_status) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}

			if (new_status == 0)return;

			if (new_status == 1 || new_status == 2)
				break;
			else
				cout << "��������������������" << endl;
		}

		cout << "ȷ�������û���Ϣ��" << endl;
		cout << "ID:" << id << endl;
		cout << "������" << name << endl;
		//cout << "����:" << passwd << endl;
		cout << "�꼶:" << grade << endl;
		cout << "�Ա�:" << gender << endl;
		cout << "Ժϵ:" << user.get_major(new_major) << endl;
		cout << "���:";
		if (new_status == 1)
			cout << "������" << endl;
		else
			cout << "�о���" << endl;
		cout << "�Ƿ�������" << endl;
		cout << "1 - ȷ�������û�" << endl;
		cout << "2 - ���������Ϣ�������󷵻��޸�" << endl;
		cout << "0 - �˳�" << endl;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ݴ���,����������:" << endl;
		}

		if (choice == '0')return;

		if (choice == '1')
			break;
		else
			system("cls");
			cout << "����������!" << endl;
	}

	if (choice == '1')
		// ѡ�������û�
	{
		fstream ofs("User.dat", ios::app | ios::binary);
		if (!ofs)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
		}

		//_itoa_s(id, passwd, 10);
		User new_user(id, name, gender, grade, new_major, 0, 0, 1, new_status);
		//new_user.get_id();
		//new_user.set_id(temp_user.get_id() + 1);
		//new_user.set_name(name);
		//new_user.set_gender(gender);
		//new_user.set_password(passwd);
		//new_user.set_borrow_num(0);
		//new_user.set_history_borrow_num(0);
		//new_user.set_user_state(1);
		//ofs.seekp(0, ios::end);
		ofs.write((char*)&new_user, sizeof(User));

		cout << "ע�����û��ɹ���" << endl;// ---------------1003�޸�

		// ��������û���¼������Ա������¼��
		fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
		if (!file)
		{
			cerr << "�ļ���ʧ��!" << endl;
		}

		OR_U or_u(new_user.get_id(), new_user.get_name(), new_user.get_grade(), new_user.get_majorID(), 0, new_user.get_user_state(), this->get_name());
		file.write((char*)&or_u, sizeof(or_u));

		ofs.close();
		file.close();
		system("pause");
		return;
	}
}

User* FindUserLocate(int id)
{
	User* user;
	User tmp_usr;
	int i = 0;
	ifstream userfile("User.dat", ios::in | ios::binary);
	string temp;

	for (i = 0; i <= MAX; i++)
	{
		// ���α�����ȡuser��Ϣ
		userfile.read((char*)&tmp_usr, sizeof(tmp_usr));

		if (tmp_usr.get_id() == id)
		{
			user = new User(tmp_usr.get_id(), tmp_usr.get_name(), tmp_usr.get_gender(), tmp_usr.get_grade(), tmp_usr.get_majorID(), tmp_usr.get_borrow_num(), tmp_usr.get_history_borrow_num(), tmp_usr.get_user_state(), tmp_usr.get_status());
			user->set_password(tmp_usr.get_password());
			// load_record(user1.get_id());			// ��ȡ�û����ļ�¼����δʵ�ָú�����
			userfile.close();
			return user;							//�����û���Ϣ
		}
	}
}

void Manager::delete_user()
//ɾ���û�
{
	int delete_id;	//Ҫɾ����id
	User* user, usr;
	while (true)
	{
		cout << "��������Ҫɾ���û���ID (����С��10������0�˳�)��" << endl;

		while (!(cin >> delete_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ݴ���,����������:" << endl;
		}
		//cin >> delete_id;

		if (delete_id == 0)return;

		if (delete_id != 0)
		{
			user = FindUserLocate(delete_id);
			if (user->get_id() == delete_id && user->get_user_state() != 2)
				// �ҵ��Ҹ��û�������ɾ��״̬
			{
				user->show_user();
				if (user->get_borrow_num()) {//����δ���鼮
					cout << "���û������鼮δ�黹������ɾ����" << endl;
					return;
				}
				else if (user->get_fine_record_id(delete_id)) {
					cout << "���û����з���δ���壬����ɾ����" << endl;
					return;
				}
				else
				{
					cout << "�Ƿ�ɾ�����û�?" << endl;
					cout << "1 - ��" << endl;
					cout << "2 - ��" << endl;
					int choice;
					//cin >> choice;
					while (!(cin >> choice) || cin.peek() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�������ݴ���,����������:" << endl;
					}

					if (choice == 1) {
						user->set_user_state(2);

						fstream file1("User.dat", ios::in | ios::binary | ios::out);
						if (!file1)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						User new_usr(user->get_id(), user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), user->get_user_state(), user->get_status());
						new_usr.set_password(password);

						while (file1.read((char*)&usr, sizeof(usr)))
						{
							if (usr.get_id() == delete_id)
							{
								
								int size = (int)sizeof(usr);
								file1.seekg(-size, ios::cur);
								file1.write((char*)&new_usr, sizeof(new_usr));
								file1.close();
								break;
							}
						}
						// ��User.dat�ļ���ɾ��
						/*fstream file1("Temp.dat", ios::out | ios::binary);	//��һ�����ڱ���ɾ�����¼���ļ�
						if (!file1)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						fstream file2("User.dat", ios::in | ios::binary);
						if (!file2)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						while (file2.read((char*)&usr, sizeof(usr)))
						{
							if (usr.get_id() != delete_id)
							{
								file1.write((char*)&usr, sizeof(usr));
							}
						}

						file1.close();
						file2.close();

						fstream file3("User.dat", ios::out | ios::binary);		//���ڽ�temp.dat�е����ݸ��ƹ���
						if (!file3)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						fstream file4("Temp.dat", ios::in | ios::binary);		//���ڽ����ݸ�ֵ��book.dat
						if (!file4)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						User usr1;
						while (file4.read((char*)&usr1, sizeof(usr1)))//����temp.dat�е����ݸ�book.dat
						{
							file3.write((char*)&usr1, sizeof(usr1));
						}
						file3.close();
						file4.close();


						// ��recording.dat�ļ���ɾ��
						Record record;
						fstream file5("Temp.dat", ios::out | ios::binary);	//��һ�����ڱ���ɾ�����¼���ļ�
						if (!file5)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						fstream file6("recording.dat", ios::in | ios::binary);
						if (!file6)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						while (file5.read((char*)&record, sizeof(record)))
						{
							if (record.get_user_id() != delete_id)
							{
								file1.write((char*)&record, sizeof(record));
							}
						}

						file5.close();
						file6.close();

						fstream file7("User.dat", ios::out | ios::binary);		//���ڽ�temp.dat�е����ݸ��ƹ���
						if (!file7)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						fstream file8("Temp.dat", ios::in | ios::binary);		//���ڽ����ݸ�ֵ��book.dat
						if (!file8)
						{
							cerr << "�ļ���ʧ�ܣ�" << endl;
							return;
						}

						Record record1;
						while (file7.read((char*)&record1, sizeof(record1)))//����temp.dat�е����ݸ�book.dat
						{
							file8.write((char*)&record1, sizeof(record1));
						}
						file7.close();
						file8.close();
						*/

						// ���ɾ���û���¼������Ա������¼��
						fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
						if (!file)
						{
							cerr << "�ļ���ʧ��!" << endl;
						}
						OR_U or_u(user->get_id(), user->get_name(), user->get_grade(), user->get_majorID(), 1, user->get_user_state(), this->get_name());
						file.write((char*)&or_u, sizeof(or_u));
						file.close();

						cout << "ɾ���ɹ���" << endl;
						//system("pause");
						/*
						FILE* pfd = NULL;
						errno_t err = fopen_s(&pfd, "Temp.dat", "w+");
						if (!err)
						{
							//printf("������ļ���\n");
							fclose(pfd);
						}
						*/


						return;
					}
					else if (choice == 2) {
						cout << "��ȡ��ɾ��" << endl;
						system("pause");
						break;
					}
					else {
						cout << "ѡ�����������ѡ��" << endl;
						system("pause");
						break;
					}
				}
			}
			else {
				cout << "��ID�����ڣ�" << endl;
				system("pause");
				return;
			}

		}
		else
			cout << "����IDֵΪ���� ���������룡" << endl;
	}
	// ɾ���ɹ�
}

bool Manager::save_password(int id, char password[])
// ���ļ��б����û�����
{
	fstream ofs("User.dat", ios::in | ios::binary | ios::out);
	if (!ofs) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return false;
	}

	User* user, usr;
	user = FindUserLocate(id);

	// ��¼�û�ԭʼ����
	char ori_password[21];
	strcpy_s(ori_password, strlen(user->get_password()) + 1, user->get_password());

	User new_usr(id, user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), user->get_user_state(), user->get_status());
	new_usr.set_password(password);

	while (ofs.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == id) {
			//�ҵ�������ͬ���û�λ��
			int size = sizeof(usr);
			ofs.seekg(-size, ios::cur);
			ofs.write((char*)&new_usr, sizeof(new_usr));
			ofs.close();

			// ����޸��û���¼������Ա������¼��
			fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
			if (!file)
			{
				cerr << "�ļ���ʧ��!" << endl;
			}
			OR_U or_u(new_usr.get_id(), new_usr.get_name(), new_usr.get_grade(), new_usr.get_majorID(), 2, new_usr.get_user_state(), this->get_name());
			or_u.set_ori_password(ori_password);
			or_u.set_now_password(password);
			file.write((char*)&or_u, sizeof(or_u));
			file.close();

			return true;
		}
	}
}

int IncludeChinese(char* str)
{
	char c;
	while (1)
	{
		c = *str++;
		if (c == 0) break;  //������ַ���β��˵�����ַ���û�������ַ�
		if (c & 0x80)        //����ַ���λΪ1����һ�ַ���λҲ��1���������ַ�
			if (*str & 0x80) return 1;
	}
	return 0;
}

int check_id(int &search_id) {
	int _search_id;
	while (1) {
		while (!(cin >> _search_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ݴ���,����������:" << endl;
		}
		search_id = _search_id;
		if (_search_id == 0)return 1;
		else if (_search_id < 2022100) {
			cout << "�����������������룡" << endl;
			system("pause");
		}
		else {
			fstream fp("User.dat", ios::binary | ios::in);
			if (!fp) {
				cerr << "�ļ���ʧ�ܣ�" << endl;
				exit(0);
			}
			User user1;
			int flag = 1;
			while (fp.read((char*)&user1, sizeof(User))) {
				if (user1.get_id() == _search_id && user1.get_user_state() != 2) {
					flag = 0;
					break;
				}
			}
			fp.close();
			if (flag) {
				cout << "���޴������������룡" << endl;
				//system("pause");
			}
			else
				break;
		}
	}
	return 0;
}

void Manager::edit_user_password()
//�޸�����
{
	int search_id = 0;				// Ҫ�޸ĵ�id
	char password[10] = {};			// �޸ĵ�����
	cout << "�������޸��û���ID(����0�˳�)" << endl;
	if (check_id(search_id)) {
		return;
	}
	User user;						// 
	while (true)
	{
		string passwd;
		while (true) {
			cout << "�����������루���Ȳ��ɳ���10λ ͬʱ���ܵ���5λ ����0�˳�����" << endl;
			//string key1;
			while (!(cin >> passwd) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�������ʹ���,���������룡" << endl;
			}
			char a[50] = {0};
			strcpy_s(a, passwd.c_str());
			for (int i = 0; i < passwd.length(); i++) {
				a[i] = passwd[i];
			}

			if (strcmp(a, "0") == 0)return;

			int flag = 0;
			flag = IncludeChinese(a);
			if (passwd.length() > 10 || passwd.length() < 5 || flag)
				cout << "�������벻����Ҫ�����������룡" << endl;
			else break;
		}

		cout << "ȷ�������룺" << endl;
		string confim_passwd;
		cin >> confim_passwd;
		if (passwd == confim_passwd)//������������һ��
		{
			char c[10] = {};

			for (int i = 0; i < passwd.length(); i++)
				password[i] = passwd[i];

			if (save_password(search_id, password)) {
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			else {
				cout << "�޸�ʧ�ܣ�" << endl;
				//system("pause");
			}
		}
		else {
			cout << "�������벻һ�£����������룡" << endl;
			//system("pause");
		}

	}
}

bool Manager::check_user(User& _user) {
	User* user;
	cout << "�������û�ID��" << endl;
	int id;
	while (!(cin >> id) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����id����,����������:" << endl;
	}

	//if (id == 0)return;

	user = FindUserLocate(id);

	//cout << user->get_id() << " " << user->get_password();
	// ��ֵ��_user��user��ͬ�ࣩ
	_user.set_id(user->get_id());
	_user.set_name(user->get_name());
	_user.set_grade(user->get_grade());
	_user.set_gender(user->get_gender());
	_user.set_majorID(user->get_majorID());
	_user.set_borrow_num(user->get_borrow_num());
	_user.set_history_borrow_num(user->get_history_borrow_num());
	_user.set_user_state(user->get_user_state());
	_user.set_password(user->get_password());
	_user.set_status(user->get_status());

	//_user.set_black_list();		// ��¼ʱ���ú�����
	if (user->get_id() == id && user->get_user_state() != 2)//�ҵ�
	{
		string password;
		for (int i = 3; i >= 0; i--) {
			cout << "���������룺" << endl;
			cin >> password;
			if (password == string(user->get_password()))
				return true;
			cout << "��������㻹��" << i << "�λ���" << endl;
		}
		return false;
	}
	else {
		cout << "���޴��ˣ�" << endl;
		system("pause");
		user = nullptr;
		return false;
	}
}

void Manager::search_user()
// �����û�
{
	char a[50] = { 0 };
	while (true)
	{
		cout << "��ѡ���ѯ��Ϣ��" << endl;
		cout << "1���û�����" << endl;
		cout << "2���û�ID" << endl;
		cout << "3���û��꼶" << endl;
		cout << "4���û�Ժϵ" << endl;
		cout << "0��ȡ��" << endl;

		char choice;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���,���������룡" << endl;
		}


		int num = 0;
		// �ҵ���ͬ���û�����
		string name;
		char tmp_major[20];
		// Book book;
		User* user, usr;

		ifstream ifs("User.dat", ios::in | ios::binary);
		if (!ifs)
			cout << "�ļ���ʧ�ܣ�" << endl;

		switch (choice)
		{
		case '1'://������
			cout << "�������û�������(����0�˳�)" << endl;
			while (!(cin >> name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<< "�������ʹ���, ���������룡" << endl;
			}
			for (int i = 0; i < name.length(); i++) {
				a[i] = name[i];
			}

			if (strcmp(a, "0") == 0)return;

			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_name() == name && usr.get_user_state() != 2)
				// �ҵ�������δ��ɾ��
				{
					user = FindUserLocate(usr.get_id());
					num++;
					cout << "���ҵ����û� ��Ϣ���£�" << endl;
					user->show_user();
					//cout << "���û���Ϣ��" << endl;
					//user->show();
					////cout << "���ڽ�����Ϣ��" << endl;
					//show_now_record();
					////cout << "��ʷ�����¼��" << endl;
					//show_past_record();

				}
			}

			if (num == 0)//δ�ҵ�
			{
				cout << "���޴��ˣ�" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				break;

			}
			else
			{
				//system("pause");
				ifs.close();
				return;
			}

			break;
		case '2'://���û�ID
			cout << "�������û�ID��(����0�˳�)" << endl;
			int id;
			while (!(cin >> id) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����id����,����������:" << endl;
			}
			//cin >> id;

			if (id == 0)return;

			user = FindUserLocate(id);
			if (user->get_id() == id && user->get_user_state() != 2)//�ҵ�
			{
				cout << "���ҵ����û� ��Ϣ���£�" << endl;
				user->show_user();
				//user->show();
				////cout << "���ڽ�����Ϣ��" << endl;
				//show_now_record();
				////cout << "��ʷ�����¼��" << endl;
				//show_past_record();

				ifs.close();
				//system("pause");
				return;
			}
			else {
				cout << "���޴��ˣ�" << endl;
				ifs.close();
				system("pause");
				break;

			}

			break;
		case '3'://���꼶
			cout << "�������û������꼶������������� ����0�˳���" << endl;
			int grade;
			while (true) {
				while (!(cin >> grade) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����꼶����,����������:" << endl;
				}

				if (grade == 0)return;

				int count = 0;	// ���������꼶�Ƿ�Ϊ4λ
				int _grade = grade;
				while (_grade)
				{
					count++;
					_grade = _grade / 10;
				}
				if (count != 4)
					cout << "������������ݣ�" << endl;
				else
					break;
			}

			{int num = 0;	// ͳ��ѧ������
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_grade() == grade && usr.get_user_state() != 2) {	//�ж��꼶�Ƿ���ͬ
					num++;
					cout << "�ҵ�����" << grade << "��ѧ����ͼ�����Ϣ" << endl;
					cout << "��" << num << "��ѧ����" << endl;
					usr.show_user();
					cout << endl;

				}
			}

			if (num == 0)//δ�ҵ�
			{
				cout << "���Ҳ����κ���Ϣ��" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				break;

			}
			else
			{
				//system("pause");
				ifs.close();
				return;
			}}

			break;
		case '4':// ���û�Ժϵ �����������������������ڼ���ģ������ �����Ȱ���׼����д
			int new_major;
			while (true) {
				cout << "��ѡ������û�Ժϵ:" << endl;
				cout << "1 - ���������ѧԺ" << endl;
				cout << "2 - ��Ϣ��ѧ�빤��ѧ��" << endl;
				cout << "3 - ��ѧ����ѧԺ" << endl;
				cout << "4 - ��������ѧѧԺ" << endl;
				cout << "5 - ��������ѧԺ" << endl;
				cout << "6 - ʳƷ��ѧ�빤��ѧԺ" << endl;
				cout << "7 - ҽҩѧԺ" << endl;
				cout << "8 - ����ѧԺ" << endl;
				cout << "9 - ������ѧ�빤��ѧԺ" << endl;
				cout << "10 - ����ѧԺ" << endl;
				cout << "11 - ����ѧԺ" << endl;
				cout << "12 - �����ѧԺ" << endl;
				cout << "13 - ��ѧ�����Ŵ���ѧԺ" << endl;
				cout << "14 - ��ѧԺ" << endl;
				cout << "15 - ���������빫������ѧԺ" << endl;
				cout << "16 - ��ѧ��ѧѧԺ" << endl;
				cout << "17 - ���Ͽ�ѧ�빤��ѧԺ" << endl;
				cout << "18 - ���˼����ѧԺ" << endl;
				cout << "19 - �籾ѧԺ" << endl;
				cout << "20 - ����ѧԺ" << endl;
				cout << "0 - �˳�" << endl;

				while (!(cin >> new_major) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "����ѡ�����,���������룡" << endl;
				}

				if (choice == 0)return;

				if (new_major <= 1 && new_major >= 20) {
					cout << "ѡ�����������ѡ��" << endl;
				}
				else
					break;
			}

			//if (new_major >= 1 && new_major <= 10)
			//	break;


			{int num = 0;	// ͳ��ѧ������
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_majorID() == new_major && usr.get_user_state() != 2) {	//�ж��꼶�Ƿ���ͬ
					num++;
					cout << "�ҵ�����" << usr.get_major(new_major) << "ѧ����ͼ�����Ϣ" << endl;
					cout << "��" << num << "��ѧ����" << endl;
					usr.show_user();
					cout << endl;

				}
			}

			if (num == 0)//δ�ҵ�
			{
				cout << "���Ҳ����κ���Ϣ��" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				break;
			}
			else
			{
				//system("pause");
				ifs.close();
				return;
			}}

			break;
		case '0':
			ifs.close();
			return;
			break;
		default: {
			cout << "��������" << endl;
			system("pause");
			break;
		}
		}
		ifs.close();
	}
}

void Manager::search_black_list() {
	cout << "�����ں���������û�" << endl;
	User user;
	int choice;
	fstream fp("User.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	int num = 0;
	while (fp.read((char*)&user, sizeof(User))) {
		if (user.get_user_state() == 0) {
			user.show_user();
			num++;
		}
	}

	
	cout << "��ѡ�������" << endl;
	if(num)
		cout << "1 - ɾ���������û�" << endl;
	cout << "0 - ����" << endl;
	//cin >> choice;
	while (!(cin >> choice) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�������ʹ���,���������룡" << endl;
	}

	while (true) {
		if (choice == 1) {
			remove_black_list();
			break;
		}
		else if (choice == 0)
			return;
		else
			cout << "������� ���������룡" << endl;
	}

}

/*
void Manager::add_black_list() {
	cout << "����������û���ѧ�Ż�����" << endl;
	cout << "1 - ����" << endl;
	cout << "2 - ѧ��" << endl;
	cout << "0 - �˳�" << endl;
	int choice;
	char a[50] = { 0 };
	while (1)
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������!" << endl;
		}

		if (choice == 0)return;

		if (choice == 1 || choice == 2)
			break;
		else
			cout << "�����������������!" << endl;
	}

	int num = 0;
	// �ҵ���ͬ���û�����
	int id;
	string name;
	char tmp_major[20];
	// Book book;
	User* user, usr;
	int choice1;

	fstream ifs("User.dat", ios::in | ios::binary | ios::out);
	if (!ifs)
		cout << "�ļ���ʧ�ܣ�" << endl;

	Record record;
	fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	int flag = 0;

	switch (choice)
	{
	case 1://������
		flag = 0;
		cout << "�������û�������(����0�˳�)" << endl;
		while (!(cin >> name) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}
		for (int i = 0; i < name.length(); i++) {
			a[i] = name[i];
		}

		if (strcmp(a, "0") == 0)return;

		while (ifs.read((char*)&usr, sizeof(usr)))
		{
			if (usr.get_name() == name && usr.get_user_state() != 2)
			// �ҵ�������δ��ɾ��
			{
				if (num == 0)
					cout << "�ҵ������û���" << endl;
				user = FindUserLocate(usr.get_id());
				num++;
				user->show_user();
			}
		}
		ifs.close();

		if (num == 0)//δ�ҵ�
		{
			cout << "���޴��ˣ�" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//system("pause");
			break;
		}
		else
		{
			cout << "�������Ӧѧ�� �����û������������(����0�˳�)" << endl;
			cin >> id;

			if (id == 0)return;

			user = FindUserLocate(id);
			User new_user(user->get_id(), user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), 0, user->get_status());
			new_user.set_password(user->get_password());

			while (fp.read((char*)&record, sizeof(Record))) {
				if (record.get_user_id() == user->get_id() && record.get_record_state() == 0) {
					flag++;
				}
			}
			fp.close();
			if (!flag) {
				cout << "���û�����������������ļ�¼��" << endl;
				return;
			}

			cout << "�Ƿ񽫸��û������������" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - ��" << endl;
			cin >> choice1;

			if (choice1 == 2) {
				cout << "��ȡ����ӣ�" << endl;
				return;
			}
			else if (choice1 == 1 && user->get_user_state() == 0) {
				cout << "���û��Ѿ��ں������У������ظ���ӣ�" << endl;
				break;
			}

			fstream ifs("User.dat", ios::in | ios::binary | ios::out);
			if (!ifs)
				cout << "�ļ���ʧ�ܣ�" << endl;
			//�ҵ���¼λ��
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_name() == name && usr.get_id() == id && usr.get_user_state() != 2)
					// �ҵ�����
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "��Ӻ������ɹ���" << endl;

					// ��������û���¼������Ա������¼��
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
					if (!file)
					{
						cerr << "�ļ���ʧ��!" << endl;
					}

					OR_U or_u(new_user.get_id(), new_user.get_name(), new_user.get_grade(), new_user.get_majorID(), 0, new_user.get_user_state(), this->get_name());
					file.write((char*)&or_u, sizeof(or_u));

					file.close();

					return;
				}
			}

			ifs.close();
			return;
		}

		break;
	case 2://���û�ID
		cout << "�������û�ѧ�ţ�(����0�˳�)" << endl;
		int id;
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����id����,����������:" << endl;
		}
		//cin >> id;

		if (id == 0)return;

		user = FindUserLocate(id);

		if (user->get_id() == id && user->get_user_state() != 2)//�ҵ�
		{
			cout << "���ҵ����û� ��Ϣ���£�" << endl;
			user->show_user();

			while (fp.read((char*)&record, sizeof(Record))) {
				if (record.get_user_id() == user->get_id() && record.get_record_state() == 0) {
					flag++;
				}
			}
			fp.close();
			if (!flag) {
				cout << "���û�����������������ļ�¼��" << endl;
				return;
			}

			cout << "�Ƿ񽫸��û������������" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - ��" << endl;
			cin >> choice1;
			if (choice1 == 2) {
				cout << "��ȡ����ӣ�" << endl;
				return;
			}
			else if (choice1 == 1 && user->get_user_state() == 0) {
				cout << "���û��Ѿ��ں������У������ظ���ӣ�" << endl;
				system("pause");
				break;
			}

			User new_user(user->get_id(), user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), 0, user->get_status());
			new_user.set_password(user->get_password());

			//�ҵ���¼λ��
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_id() == id)
					// �ҵ�����
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "��Ӻ������ɹ���" << endl;

					// ��������û���¼������Ա������¼��
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
					if (!file)
					{
						cerr << "�ļ���ʧ��!" << endl;
					}

					OR_U or_u(new_user.get_id(), new_user.get_name(), new_user.get_grade(), new_user.get_majorID(), 0, new_user.get_user_state(), this->get_name());
					file.write((char*)&or_u, sizeof(or_u));

					file.close();

					return;
				}
			}

			ifs.close();
			return;
		}
		else {
			cout << "���޴��ˣ�" << endl;
			ifs.close();
			//system("pause");
			break;
		}
		break;
	default:
		break;
	}
}
*/

void Manager::remove_black_list() {
	cout << "������ɾ���û���ѧ��(����0�˳�)" << endl;

	int num = 0;
	// �ҵ���ͬ���û�����
	User* user, usr;
	int choice1;

	fstream ifs("User.dat", ios::in | ios::binary | ios::out);
	if (!ifs)
		cout << "�ļ���ʧ�ܣ�" << endl;

	while (true) {
		//���û�ID
		int id;
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����id����,����������:" << endl;
		}
		//cin >> id;

		if (id == 0)return;

		user = FindUserLocate(id);
		if (user->get_id() == id && user->get_user_state() == 0)//�ҵ�
		{
			cout << "���ҵ����û� ��Ϣ���£�" << endl;
			user->show_user();

			cout << "�Ƿ񽫸��û��Ƴ���������" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - ��" << endl;
			cin >> choice1;
			if (choice1 == 2) {
				cout << "��ȡ��ɾ����" << endl;
				return;
			}

			Record record;
			fstream fp("recording.dat", ios::binary | ios::in | ios::out);
			if (!fp) {
				cerr << "�ļ���ʧ�ܣ�" << endl;
				return;
			}

			while (fp.read((char*)&record, sizeof(Record))) {
				if (record.get_user_id() == user->get_id() && record.get_record_state() == 0 && record.get_book_state() == 0) {
					cout << "���û���������δ�黹���鼮 �޷��Ƴ���������" << endl;
					fp.close();
					return;
				}
				else if (record.get_user_id() == user->get_id() && record.get_record_state() == 0 && record.get_book_state() == 2) {
					record.set_record_state(1);
					int size = sizeof(record);
					fp.seekg(-size, ios::cur);
					fp.write((char*)&record, sizeof(record));
					fp.close();
					break;
				}
			}

			User new_user(user->get_id(), user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), 1, user->get_status());
			new_user.set_password(user->get_password());

			//�ҵ���¼λ��
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_id() == id)
					// �ҵ�����
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "�Ƴ��������ɹ���" << endl;

					// ��������û���¼������Ա������¼��
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//���������¼
					if (!file)
					{
						cerr << "�ļ���ʧ��!" << endl;
					}

					OR_U or_u(new_user.get_id(), new_user.get_name(), new_user.get_grade(), new_user.get_majorID(), 1, 0, this->get_name());
					file.write((char*)&or_u, sizeof(or_u));

					file.close();

					return;
				}
			}

			ifs.close();
			return;
		}
		else {
			cout << "����ID�������������룡" << endl;
			ifs.close();

		}
	}


}

int get_length(long long x)
{
	int leng = 0;
	while (x)
	{
		x /= 10;
		leng++;
	}
	return leng;
}

char Manager::password[20] = "aa123123";//����Ա�����ʼ��

void Manager::add_book()//����鼮
{
	fstream file10("book.dat", ios::binary | ios::in);//�ҳ����һ��id
	if (!file10)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book10;
	int size = (int)sizeof(Book);
	file10.seekg(-size, ios::end);
	file10.read((char*)&book10, sizeof(book10));
	file10.close();
	int id = book10.get_id() + 1;
	char name[20] = { 0 };
	string name1;
	char writer[20] = { 0 };
	string writer1;
	int book_state = 1;//�ɽ�
	char press[20] = { 0 };
	string press1;
	int publication_date;
	double price;
	char category[20] = { 0 };
	string category1;
	//int num;
	long long isbn;
	while (1)//�����ݴ�
	{
		cout << "������Ҫ��ӵ��鼮����(�ַ����Ȳ�����19 ����0�˳�)" << endl;
		while (!(cin >> name1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < name1.length(); i++) {
			a[i] = name1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (name1.length() > 19)
			cout << "���ȷǷ�������������" << endl;
		else
			break;
	}
	while (1)//�������ݴ�
	{
		cout << "������������(�ַ�����С��19 ����0�˳�)" << endl;
		while (!(cin >> writer1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < writer1.length(); i++) {
			a[i] = writer1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (writer1.length() > 19)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	while (1)//�������ݴ�
	{
		cout << "�����������(�ַ�����С��19 ����0�˳�)" << endl;
		while (!(cin >> press1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < press1.length(); i++) {
			a[i] = press1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (press1.length() > 19)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	while (1)//���������ݴ�
	{
		cout << "������������ڣ�����20020908 ����0�˳���" << endl;
		while (!(cin >> publication_date) || cin.peek() != '\n')//ȷ�����������������ȷ������������ͬ
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (publication_date == 0)return;

		if (get_length(publication_date) != 8)
			cout << "��ʽ�Ƿ����������룡" << endl;
		else
		{
			if (check(publication_date))
			{
				if (publication_date / 10000 > 1900 && publication_date / 10000 < 2022)
					break;
				else
					cout << "������ݲ��Ϸ���" << endl;
			}
			else
				cout << "���벻�����ڸ�ʽ�����������룡" << endl;
		}
	}

	while (1)//�۸��ݴ�
	{
		cout << "������۸� ����0�˳�" << endl;
		while (!(cin >> price) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (price == 0)return;

		int count = 0;	// �����������Ƿ����
		double _price = price;
			
		if (price <= 0)
			cout << "�۸�Ƿ����������룡" << endl;
		else
			break;
	}
	int cchoice;
	cout << "��ѡ���鼮���:" << endl;
	cout << "1-��������" << endl;
	cout << "2-��ѧ���ڽ�" << endl;
	cout << "3-����ѧ����" << endl;
	cout << "4-���Ρ�����" << endl;
	cout << "5-����" << endl;
	cout << "6-����" << endl;
	cout << "7-�Ļ�������������" << endl;
	cout << "8-��Ȼ��ѧ����" << endl;
	cout << "9-����" << endl;
	cout << "0 - �˳�" << endl;
	while (1)//choice�ݴ�
	{
		while (!(cin >> cchoice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���������,����������:" << endl;
		}
		if (cchoice == 0)
			return;
		if (cchoice < 0 || cchoice > 9)
			cout << "���벻�ڷ�Χ�ڣ����������룡" << endl;
		else
			break;
	}
	if (cchoice == 1)
		strcpy_s(category, "��������");
	else if (cchoice == 2)
		strcpy_s(category, "��ѧ���ڽ�");
	else if (cchoice == 3)
		strcpy_s(category, "����ѧ����");
	else if (cchoice == 4)
		strcpy_s(category, "���Ρ�����");
	else if (cchoice == 5)
		strcpy_s(category, "����");
	else if (cchoice == 6)
		strcpy_s(category, "����");
	else if (cchoice == 7)
		strcpy_s(category, "�Ļ�������������");
	else if (cchoice == 8)
		strcpy_s(category, "��Ȼ��ѧ����");
	else if (cchoice == 9)
		strcpy_s(category, "����");

	/*while (1)//�����ݴ�
	{
		cout << "�������Ȿ����������" << endl;
		while (!(cin >> num) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���������,����������:" << endl;
		}
		if (price <= 0)
			cout << "�����Ƿ����������룡" << endl;
		else
			break;
	}
	*/
	while (1)//isbn�ݴ�
	{
		cout << "����������isbn��(Ҫ��Ϊ13λ ����0�˳�)" << endl;
		while (!(cin >> isbn) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (isbn == 0)return;

		if (get_length(isbn) != 13)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	for (int i = 0; i < name1.length(); i++)
		name[i] = name1[i];
	for (int i = 0; i < writer1.length(); i++)
		writer[i] = writer1[i];
	for (int i = 0; i < press1.length(); i++)
		press[i] = press1[i];
	Book book1(id, name, writer, book_state, press, publication_date, price, category, isbn, 0);
	int num1;
	while (1)//num�ݴ�
	{
		cout << "��������鼮������ ����0�˳�" << endl;
		while (!(cin >> num1) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (num1 == 0)return;

		int count = 0;	// �������������Ƿ����
		int _num = num1;
		while (_num)
		{
			count++;
			_num = _num / 10;
		}
		if (count >= 5) {
			cout << "��������ȷ��������" << endl;
			continue;
		}

		if (num1 < 0)
			cout << "�����Ƿ����������룡" << endl;
		else
			break;
	}
	int j;
	fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);//���������¼
	if (!fp11)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}
	fstream file("book.dat", ios::binary | ios::app);
	if (!file)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}
	OR_B or1(book1.get_id(), book1.get_name(), 0);
	for (j = 0; j < num1; j++)//��������鼮�͹���Ա������¼
	{
		file.write((char*)&book1, sizeof(book1));
		fp11.write((char*)&or1, sizeof(or1));
		id++;
		or1.set_book_id(id);
		book1.set_id(id);
	}
	file.close();
	cout << "�鼮��ӳɹ���" << endl;
	fp11.close();
}

void Manager::search_book()
{
	id_a[10000] = { 0 };
	cnt_a = 0;
	Book book1;
	int choice;
	cout << "��ѡ���ѯ�ķ�ʽ��1.��id��ѯ  2.�����߲�ѯ  3.����ѯ  4.��������ѯ  0.�˳�" << endl;
	while (1)//choice�ݴ�
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (choice == 0)return;
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
			break;
		else
			cout << "���벻��ѡ����" << endl;
	}
	if (choice == 1)
	{
		int search_id;
		fstream file11("book.dat", ios::binary | ios::in);//�ҳ����һ��id
		if (!file11)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		Book book11;
		int size = (int)sizeof(Book);
		file11.seekg(-size, ios::end);
		file11.read((char*)&book11, sizeof(book11));
		file11.close();
		while (1)//id�ݴ�
		{
			cout << "������Ҫ��ѯ���鼮id(����0�˳�)" << endl;
			while (!(cin >> search_id) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}
			if (search_id == 0)return;
			if (search_id < 0 || search_id > book11.get_id())
				cout << "����id�����ڣ�����������" << endl;
			else
				break;
		}
		int p2 = 0;
		fstream file1("book.dat", ios::in | ios::binary);
		while (file1.read((char*)&book1, sizeof(book1)))
		{
			if (book1.get_id() == search_id && book1.get_state() != 3)
			{
				book1.show_book();
				cnt_a++;
				id_a[p2] = book1.get_id();
				p2++;
			}

		}
		file1.close();
		//system("pause");
	}
	if (choice == 2)
	{
		string search_writer;
		while (1)//�������ݴ�
		{
			cout << "������������(�ַ�����С��19������0�˳�)" << endl;
			while (!(cin >> search_writer) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����������������������:" << endl;
			}
			if (search_writer.length() > 19)
				cout << "���ȷǷ����������룡" << endl;
			else
				break;
		}
		char writer1[20] = { 0 };
		for (int i = 0; i < search_writer.length(); i++)
			writer1[i] = search_writer[i];
		if (strcmp(writer1, "0") == 0)return;
		int p2 = 0;
		fstream file1("book.dat", ios::in | ios::binary);
		while (file1.read((char*)&book1, sizeof(book1)))
		{
			if (strcmp(book1.get_writer(), writer1) == 0 && book1.get_state() != 3)//�ж��������Ƿ����
			{
				book1.show_book();
				cnt_a++;
				id_a[p2] = book1.get_id();
				p2++;
			}
		}
		file1.close();
	}
	if (choice == 3)
	{
		char category1[20] = { 0 };
		int cchoice;
		cout << "��ѡ���鼮���:" << endl;
		cout << "1-��������" << endl;
		cout << "2-��ѧ���ڽ�" << endl;
		cout << "3-����ѧ����" << endl;
		cout << "4-���Ρ�����" << endl;
		cout << "5-����" << endl;
		cout << "6-����" << endl;
		cout << "7-�Ļ�������������" << endl;
		cout << "8-��Ȼ��ѧ����" << endl;
		cout << "9-����" << endl;
		cout << "0-�˳�" << endl;
		while (1)//choice�ݴ�
		{
			while (!(cin >> cchoice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "���������,����������:" << endl;
			}
			if (cchoice == 0)
				return;
			if (cchoice <= 0 || cchoice > 9)
				cout << "�����Ƿ����������룡" << endl;
			else
				break;
		}
		if (choice == 0)return;
		if (cchoice == 1)
			strcpy_s(category1, "��������");
		else if (cchoice == 2)
			strcpy_s(category1, "��ѧ���ڽ�");
		else if (cchoice == 3)
			strcpy_s(category1, "����ѧ����");
		else if (cchoice == 4)
			strcpy_s(category1, "���Ρ�����");
		else if (cchoice == 5)
			strcpy_s(category1, "����");
		else if (cchoice == 6)
			strcpy_s(category1, "����");
		else if (cchoice == 7)
			strcpy_s(category1, "�Ļ�������������");
		else if (cchoice == 8)
			strcpy_s(category1, "��Ȼ��ѧ����");
		else if (cchoice == 9)
			strcpy_s(category1, "����");
		fstream file1("book.dat", ios::in | ios::binary);
		int p2 = 0;
		while (file1.read((char*)&book1, sizeof(book1)))
		{
			if (strcmp(book1.get_category(), category1) == 0 && book1.get_state() != 3)//�жϷ������Ƿ����
			{
				book1.show_book();
				cnt_a++;
				id_a[p2] = book1.get_id();
				p2++;
			}
		}
		file1.close();
	}
	if (choice == 4)
	{
		string search_name;
		while (1)//�����ݴ�
		{
			cout << "����������(�ַ�����С��19 ����0�˳�)" << endl;
			while (!(cin >> search_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�������ʹ���, ���������룡" << endl;
			}

			char a[50] = { 0 };
			for (int i = 0; i < search_name.length(); i++) {
				a[i] = search_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (search_name.length() > 19)
				cout << "���ȷǷ����������룡" << endl;
			else
				break;
		}
		char name1[20] = { 0 };
		for (int i = 0; i < search_name.length(); i++)
			name1[i] = search_name[i];
		fstream file1("book.dat", ios::in | ios::binary);
		int p2 = 0;
		while (file1.read((char*)&book1, sizeof(book1)))
		{
			if (strcmp(book1.get_name(), name1) == 0 && book1.get_state() != 3)//�ж������Ƿ����
			{
				book1.show_book();
				cnt_a++;
				id_a[p2] = book1.get_id();
				p2++;
			}

		}
		file1.close();
	}
	if (cnt_a == 0)
		cout << "�����ڸ��鼮��" << endl;

}

void Manager::delete_book()
{
	int find1 = 0;
	search_book();
	if (cnt_a == 0)
		return;
	int delete_id;
	fstream file11("book.dat", ios::binary | ios::in);//�ҳ����һ��id
	if (!file11)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book11;
	int size = (int)sizeof(Book);
	file11.seekg(-size, ios::end);
	file11.read((char*)&book11, sizeof(book11));
	file11.close();
	while (1)//id�ݴ�
	{
		cout << "������Ҫɾ�����鼮id ����0�˳�" << endl;
		while (!(cin >> delete_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (delete_id == 0)return;

		if (delete_id < 0 || delete_id > book11.get_id())
			cout << "����id�����ڣ�����������" << endl;
		else
		{
			for (int i = 0; i < 10000; i++)
			{
				if (delete_id == id_a[i])
				{
					find1 = 1;
					break;
				}
			}
			if (find1 == 1)
				break;
			else
				cout << "����id���ڲ�ѯ�����,���������룡" << endl;
		}
	}
	fstream file("book.dat", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book1;
	int find = 0;
	while (file.read((char*)&book1, sizeof(book1)))//Ѱ��ɾ�����鼮������ɾ������
	{
		if (book1.get_id() == delete_id)
		{
			find = 1;
			cout << "�ҵ����鼮��Ϣ����:" << endl;
			book1.show_book();
			break;
		}
	}
	if (find == 1)//�ҵ�
	{
		if (book1.get_state() == 0)//�Ѿ����
		{
			cout << "�����ѽ��������ɾ����" << endl;
			return;
		}
		int choice;
		cout << endl;
		cout << "�Ƿ�ɾ�����鼮��1-ɾ�� 2-ȡ��";
		while (1)//choice�ݴ�
		{
			while (!(cin >> choice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}
			if (choice == 1 || choice == 2)
				break;
		}
		if (choice == 1)//ɾ��
		{
			int size;
			size = sizeof(Book);
			file.seekp(-size, ios::cur);
			book1.set_state(3);
			file.write((char*)&book1, sizeof(Book));
			file.close();
			cout << "ɾ���ɹ���" << endl;
			fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);
			if (!fp11)
			{
				cerr << "�ļ���ʧ��" << endl;
				return;
			}
			OR_B or1(book1.get_id(), book1.get_name(), 1);
			fp11.write((char*)&or1, sizeof(or1));
			fp11.close();
			return;
		}
		else
		{
			file.close();
			return;
		}
	}
	else//δ�ҵ�
	{
		cout << "δ�ҵ����鼮��" << endl;
		file.close();
		return;
	}
}

void Manager::edit_book()
{
	int find1 = 0;
	search_book();
	if (cnt_a == 0)
		return;
	int edit_id;
	fstream file11("book.dat", ios::binary | ios::in);//�ҳ����һ��id
	if (!file11)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book11;
	int size = (int)sizeof(Book);
	file11.seekg(-size, ios::end);
	file11.read((char*)&book11, sizeof(book11));
	file11.close();
	while (1)//id�ݴ�
	{
		cout << "������Ҫ�޸ĵ��鼮id ����0�˳�" << endl;
		while (!(cin >> edit_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (edit_id == 0)return;
		if (edit_id < 0 || edit_id > book11.get_id())
			cout << "����id�����ڣ�����������" << endl;
		else
		{
			for (int i = 0; i < 10000; i++)
			{
				if (edit_id == id_a[i])
				{
					find1 = 1;
					break;
				}
			}
			if (find1 == 1)
				break;
			else
				cout << "����id���ڲ�ѯ�����,���������룡" << endl;
		}
	}
	fstream file66("book.dat", ios::binary | ios::in | ios::out);
	if (!file66)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book66;
	while (file66.read((char*)&book66, sizeof(book66)))//Ѱ��ɾ�����鼮������ɾ������
	{
		if (book66.get_id() == edit_id && book66.get_state() == 0)
		{
			cout << "�����ѽ���������޸ģ�";
			return;
		}
	}
	file66.close();
	int id = edit_id;
	cout << "�������޸ĺ���鼮��Ϣ" << endl;
	char name[20] = { 0 };
	string name1;
	char writer[20] = { 0 };
	string writer1;
	int book_state;//�ɽ�
	char press[20] = { 0 };
	string press1;
	int publication_date;
	double price;
	char category[20] = { 0 };
	long long isbn;
	while (1)//�����ݴ�
	{
		cout << "������Ҫ��ӵ��鼮����(�ַ����Ȳ�����19 ����0�˳�)" << endl;
		while (!(cin >> name1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < name1.length(); i++) {
			a[i] = name1[i];
		}

		if (strcmp(a, "0") == 0)return;
		if (name1.length() > 19)
			cout << "���ȷǷ�������������" << endl;
		else
			break;
	}
	while (1)//�������ݴ�
	{
		cout << "������������(�ַ�����С��19 ����0�˳�)" << endl;
		while (!(cin >> writer1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < writer1.length(); i++) {
			a[i] = writer1[i];
		}

		if (strcmp(a, "0") == 0)return;
		if (writer1.length() > 19)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	while (1)//�������ݴ�
	{
		cout << "�����������(�ַ�����С��19 ����0�˳�)" << endl;
		while (!(cin >> press1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������ʹ���, ���������룡" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < press1.length(); i++) {
			a[i] = press1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (writer1.length() > 19)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	while (1)//���������ݴ�
	{
		cout << "������������ڣ�����20020908 ����0�˳���" << endl;
		while (!(cin >> publication_date) || cin.peek() != '\n')//ȷ�����������������ȷ������������ͬ
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (publication_date == 0)return;

		if (get_length(publication_date) != 8)
			cout << "��ʽ�Ƿ����������룡" << endl;
		else
		{
			if (check(publication_date))
			{
				if (publication_date / 10000 > 1900 && publication_date / 10000 < 2022)
					break;
				else
					cout << "������ݲ��Ϸ���" << endl;
			}
			else
				cout << "���벻�����ڸ�ʽ�����������룡" << endl;
		}
	}

	while (1)//�۸��ݴ�
	{
		cout << "������۸�����0�˳���" << endl;
		while (!(cin >> price) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (press == 0)return;

		if (price < 0)
			cout << "�۸�Ƿ����������룡" << endl;
		else
			break;
	}
	int cchoice;
	cout << "��ѡ���鼮���:" << endl;
	cout << "1-��������" << endl;
	cout << "2-��ѧ���ڽ�" << endl;
	cout << "3-����ѧ����" << endl;
	cout << "4-���Ρ�����" << endl;
	cout << "5-����" << endl;
	cout << "6-����" << endl;
	cout << "7-�Ļ�������������" << endl;
	cout << "8-��Ȼ��ѧ����" << endl;
	cout << "9-����" << endl;
	cout << "0-�˳�" << endl;
	while (1)//cchoice�ݴ�
	{
		while (!(cin >> cchoice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���������,����������:" << endl;
		}

		if (cchoice == 0)return;

		if (cchoice < 0 || cchoice > 9)
			cout << "�����Ƿ����������룡" << endl;
		else
			break;
	}
	if (cchoice == 1)
		strcpy_s(category, "��������");
	else if (cchoice == 2)
		strcpy_s(category, "��ѧ���ڽ�");
	else if (cchoice == 3)
		strcpy_s(category, "����ѧ����");
	else if (cchoice == 4)
		strcpy_s(category, "���Ρ�����");
	else if (cchoice == 5)
		strcpy_s(category, "����");
	else if (cchoice == 6)
		strcpy_s(category, "����");
	else if (cchoice == 7)
		strcpy_s(category, "�Ļ�������������");
	else if (cchoice == 8)
		strcpy_s(category, "��Ȼ��ѧ����");
	else if (cchoice == 9)
		strcpy_s(category, "����");

	/*while (1)//�����ݴ�
	{
		cout << "�������Ȿ����������" << endl;
		while (!(cin >> num) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���������,����������:" << endl;
		}
		if (price <= 0)
			cout << "�����Ƿ����������룡" << endl;
		else
			break;
	}
	*/
	while (1)//isbn�ݴ�
	{
		cout << "����������isbn��(Ҫ��Ϊ13λ ����0�˳�)" << endl;
		while (!(cin >> isbn) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (isbn == 0)return;

		if (get_length(isbn) != 13)
			cout << "���ȷǷ����������룡" << endl;
		else
			break;
	}
	while (1)//״̬�ݴ�
	{
		cout << "�������޸ĺ���鼮״̬(0-�ѽ�� 1-�ɽ��� 2-��ʧ 3-�˳�)" << endl;
		while (!(cin >> book_state) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (book_state == 3)return;
		if (book_state == 0 || book_state == 1 || book_state == 2)
			break;
		else
			cout << "״̬�Ƿ����������룡" << endl;
	}
	for (int i = 0; i < name1.length(); i++)
		name[i] = name1[i];
	for (int i = 0; i < writer1.length(); i++)
		writer[i] = writer1[i];
	for (int i = 0; i < press1.length(); i++)
		press[i] = press1[i];
	Book book3(id, name, writer, book_state, press, publication_date, price, category, isbn, 0);
	int i = 0;
	Book book2;
	fstream file2("book.dat", ios::out | ios::in | ios::binary);
	if (!file2)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	while (file2.read((char*)&book2, sizeof(book2))) //ȷ��Ҫ�޸ĵ��鼮���ļ��е�λ�ã���i��¼
	{
		i++;
		if (book2.get_id() == book3.get_id())
		{
			break;
		}
	}
	Book edit_book(book3.get_id(), book3.get_name(), book3.get_writer(), book3.get_state(), book3.get_press(), book3.get_publication_date(), book3.get_price(), book3.get_category(), book3.get_isbn(), book3.get_renew_time());//�޸ĺ���鼮
	file2.seekg(sizeof(edit_book) * (i - 1), ios::beg);//����ָ��λ��
	file2.write((char*)&edit_book, sizeof(edit_book));//����ԭ������Ϣ
	cout << "�鼮��Ϣ�޸ĳɹ���" << endl;
	file2.close();
	fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);//���������¼
	if (!fp11)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}
	OR_B or1(book2.get_id(), book2.get_name(), 2);
	fp11.write((char*)&or1, sizeof(or1));
	fp11.close();
}

void Manager::show_record()
{
	fstream file("recording.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}
	Record record1;
	cout << "�鼮������Ϣ���£�" << endl;
	while (file.read((char*)&record1, sizeof(record1)))
	{
		record1.show_record();
		cout << endl;
	}
}

void Manager::show_operation_record_book()
{
	fstream file("OperationRecord_Book.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}
	OR_B or1;
	cout << "�鼮������Ϣ���£�" << endl;
	while (file.read((char*)&or1, sizeof(or1)))
	{
		cout << "�鼮ID��" << or1.get_book_id() << "\t������" << or1.get_book_name() << "\t����Ա���ƣ�" << or1.get_manager_name() << "\t����ʱ�䣺" << or1.get_time() << "\t������ʽ��";
		if (or1.get_state() == 0)
			cout << "����鼮";
		if (or1.get_state() == 1)
			cout << "ɾ���鼮";
		if (or1.get_state() == 2)
			cout << "�޸��鼮";
		cout << endl;
	}
}

void Manager::show_operation_record_user() {
	fstream file("OperationRecord_User.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}

	OR_U or_u;
	cout << "�û�������Ϣ���£�" << endl;
	while (file.read((char*)&or_u, sizeof(or_u)))
	{
		if (or_u.get_user_state() == 1|| or_u.get_user_state() == 2) {
			if (or_u.get_state() == 0) {
				cout << "����û���    ѧ�ţ�" << or_u.get_id() << setw(12) << "������" << or_u.get_name() << setw(12) << "�꼶��" << or_u.get_grade() << setw(12) << "רҵ��" << or_u.get_major() << setw(20) << "�����ߣ�" << or_u.get_manager_name() << setw(12) << "����ʱ�䣺" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 1) {
				cout << "ɾ���û���    ѧ�ţ�" << or_u.get_id() << setw(12) << "������" << or_u.get_name() << setw(12) << "�꼶��" << or_u.get_grade() << setw(12) << "רҵ��" << or_u.get_major() << setw(20) << "�����ߣ�" << or_u.get_manager_name() << setw(12) << "����ʱ�䣺" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 2) {
				cout << "�޸��û����룺ѧ�ţ�" << or_u.get_id() << setw(12) << "������" << or_u.get_name() << setw(12) << "ԭʼ���룺" << or_u.get_ori_password() << setw(12) << "�޸����룺" << or_u.get_now_password() << setw(20) << "�����ߣ�" << or_u.get_manager_name() << setw(12) << "����ʱ�䣺" << or_u.get_time() << endl;
			}
		}
		else if (or_u.get_user_state() == 0) {
			if (or_u.get_state() == 0) {
				cout << "����û��ں�������    ѧ�ţ�" << or_u.get_id() << setw(12) << "������" << or_u.get_name() << setw(12) << "�꼶��" << or_u.get_grade() << setw(12) << "רҵ��" << or_u.get_major() << setw(20) << "�����ߣ�" << or_u.get_manager_name() << setw(12) << "����ʱ�䣺" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 1) {
				cout << "ɾ���û��ں�������    ѧ�ţ�" << or_u.get_id() << setw(12) << "������" << or_u.get_name() << setw(12) << "�꼶��" << or_u.get_grade() << setw(12) << "רҵ��" << or_u.get_major() << setw(20) << "�����ߣ�" << or_u.get_manager_name() << setw(12) << "����ʱ�䣺" << or_u.get_time() << endl;
			}
		}


	}
}

void Manager::deal_fine_record()
{
	FR fr1;
	int id_1[1000] = { 0 };
	int j = 0;
	int choice;
	cout << "��ѡ���ѯ�ķ�ʽ��1.���û�id��ѯ  2.���û�����ѯ  0.�˳�" << endl;
	int cnt = 0;
	int search_id;
	string search_name;
	char name1[20] = { 0 };
	while (1)//choice�ݴ�
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (choice == 0)return;

		if (choice == 1 || choice == 2)
			break;
		else
			cout << "���벻��ѡ����" << endl;
	}

	if (choice == 1)
	{
		fstream file11("User.dat", ios::binary | ios::in);//�ҳ����һ��id
		if (!file11)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		User user11;
		int size = (int)sizeof(User);
		file11.seekg(-size, ios::end);
		file11.read((char*)&user11, sizeof(user11));
		file11.close();
		while (1)//id�ݴ�
		{
			cout << "������Ҫ��ѯ�û�id ����0�˳�" << endl;
			while (!(cin >> search_id) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}

			if (search_id == 0)return;

			if (search_id < 0 || search_id > user11.get_id())
				cout << "����id�����ڣ�����������" << endl;
			else
				break;
		}
		fstream file1("FineRecord.dat", ios::in | ios::binary);
		if (!file1)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		while (file1.read((char*)&fr1, sizeof(fr1)))
		{
			if (fr1.get_id() == search_id)
			{
				strcpy_s(name1, fr1.get_name());
				fr1.show();
				cnt++;
			}

		}
		file1.close();
		if (cnt == 0)
		{
			cout << "���û���Ƿ����Ϣ" << endl;
			return;
		}
		else
		{
			cout << endl;
			cout << "�Ƿ�һ�ν���������Ƿ���1-��  2-��  0-�˳���" << endl;
			int choice1;
			while (1)//choice1�ݴ�
			{
				while (!(cin >> choice1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������ʹ���,����������:" << endl;
				}

				if (choice1 == 0)return;

				if (choice1 == 1 || choice1 == 2)
					break;
				else
					cout << "���벻��ѡ����" << endl;
			}
			if (choice1 == 2)
				return;
			else
			{
				FR fr2;
				fstream file1("temp.dat", ios::out | ios::binary);//��һ�����ڱ���ɾ�����¼���ļ�
				if (!file1)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				fstream file2("FineRecord.dat", ios::in | ios::binary);
				if (!file2)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				while (file2.read((char*)&fr2, sizeof(fr2)))
				{
					if (fr2.get_id() != search_id)
					{
						file1.write((char*)&fr2, sizeof(fr2));
					}
				}
				file1.close();
				file2.close();
				fstream file3("FineRecord.dat", ios::out | ios::binary);//���ڽ�temp.dat�е����ݸ��ƹ���
				if (!file3)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				fstream file4("temp.dat", ios::in | ios::binary);//���ڽ����ݸ�ֵ��FineRecord.dat
				if (!file4)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				FR fr3;
				while (file4.read((char*)&fr3, sizeof(fr3)))//����temp.dat�е����ݸ�FineReocrd.dat
				{
					file3.write((char*)&fr3, sizeof(fr3));
				}
				file3.close();
				file4.close();
				cout << "����ɹ���" << endl;
			}
		}
	}
	if (choice == 2)
	{
		int id1;
		while (1)//�û����ݴ�
		{
			cout << "�������û���(�ַ�����С��19 ����0�˳�)" << endl;
			while (!(cin >> search_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�������ʹ���, ���������룡" << endl;
			}

			char a[50] = { 0 };
			for (int i = 0; i < search_name.length(); i++) {
				a[i] = search_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (search_name.length() > 19)
				cout << "���ȷǷ����������룡" << endl;
			else
				break;
		}

		for (int i = 0; i < search_name.length(); i++)
			name1[i] = search_name[i];
		fstream file1("FineRecord.dat", ios::in | ios::binary);
		if (!file1)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		while (file1.read((char*)&fr1, sizeof(fr1)))
		{
			if (strcmp(fr1.get_name(), name1) == 0)
			{
				id_1[j] = fr1.get_id();
				j++;
				search_id = fr1.get_id();
				fr1.show();
				cnt++;
			}//�ж������Ƿ����

		}
		file1.close();
		if (cnt == 0)
		{
			cout << "��Ƿ����Ϣ" << endl;
			return;
		}
		else
		{
			int find2 = 0;
			cout << "������Ҫ������û�id ����0�˳�" << endl;
			while (1)//id1�ݴ�
			{
				while (!(cin >> id1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������ʹ���,����������:" << endl;
				}

				if (id1 == 0)return;

				for (j = 0; j < 1000; j++)
				{
					if (id1 == id_1[j])
					{
						find2 = 1;
						break;
					}
				}
				if (find2 == 0)
					cout << "����id���ڲ�ѯ����ڣ����������룡" << endl;
				else
					break;
			}
			cout << endl;
			cout << "�Ƿ�һ�ν���������Ƿ���1-��  2-��  0-�˳���" << endl;
			int choice1;
			while (1)//choice1�ݴ�
			{
				while (!(cin >> choice1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������ʹ���,����������:" << endl;
				}

				if (choice1 == 0)return;

				if (choice1 == 1 || choice1 == 2)
					break;
				else
					cout << "���벻��ѡ����" << endl;
			}
			if (choice1 == 2)
				return;
			else
			{
				FR fr2;
				fstream file1("temp.dat", ios::out | ios::binary);//��һ�����ڱ���ɾ�����¼���ļ�
				if (!file1)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				fstream file2("FineRecord.dat", ios::in | ios::binary);
				if (!file2)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				while (file2.read((char*)&fr2, sizeof(fr2)))
				{
					if (fr2.get_id() != id1)
					{
						file1.write((char*)&fr2, sizeof(fr2));
					}
				}
				file1.close();
				file2.close();
				fstream file3("FineRecord.dat", ios::out | ios::binary);//���ڽ�temp.dat�е����ݸ��ƹ���
				if (!file3)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				fstream file4("temp.dat", ios::in | ios::binary);//���ڽ����ݸ�ֵ��FineRecord.dat
				if (!file4)
				{
					cerr << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				FR fr3;
				while (file4.read((char*)&fr3, sizeof(fr3)))//����temp.dat�е����ݸ�FineReocrd.dat
				{
					file3.write((char*)&fr3, sizeof(fr3));
				}
				file3.close();
				file4.close();
				cout << "����ɹ���" << endl;
			}
		}
	}
}

void Manager::add_old_book()
{
	int find1 = 0;
	search_book();
	if (cnt_a == 0)
		return;
	int add_id;
	fstream file11("book.dat", ios::binary | ios::in);//�ҳ����һ��id
	if (!file11)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book11;
	int size = (int)sizeof(Book);
	file11.seekg(-size, ios::end);
	file11.read((char*)&book11, sizeof(book11));
	file11.close();
	while (1)//id�ݴ�
	{
		cout << "������Ҫ��ӵ��鼮id ����0�˳�" << endl;
		while (!(cin >> add_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (add_id == 0)return;
		if (add_id < 0 || add_id > book11.get_id())
			cout << "����id�����ڣ�����������" << endl;
		else
		{
			for (int i = 0; i < 10000; i++)
			{
				if (add_id == id_a[i])
				{
					find1 = 1;
					break;
				}
			}
			if (find1 == 1)
				break;
			else
				cout << "����id���ڲ�ѯ�����,���������룡" << endl;
		}
	}
	fstream file("book.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Book book1;
	int find = 0;
	while (file.read((char*)&book1, sizeof(book1)))//Ѱ��Ҫ����鼮��id
	{
		if (book1.get_id() == add_id)
		{
			find = 1;
			cout << "�ҵ����鼮��Ϣ����:" << endl;
			book1.show_book();
			break;
		}
	}
	file.close();
	if (find == 1)
	{
		cout << "������Ҫ��ӵ����� ����0�˳�" << endl;
		int num3;
		while (1)//�����ݴ�
		{
			while (!(cin >> num3) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "���������,����������:" << endl;
			}

			if (num3 == 0)return;

			if (num3 < 0)
				cout << "�����Ƿ����������룡" << endl;
			else
				break;
		}
		book1.set_id(book11.get_id() + 1);
		fstream file55("book.dat", ios::binary | ios::app);
		if (!file55)
		{
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		int id3;
		book1.set_state(1);
		for (int i = 0; i < num3; i++)
		{
			file55.write((char*)&book1, sizeof(book1));
			id3 = book1.get_id();
			id3++;
			book1.set_id(id3);
		}
		cout << "�鼮��ӳɹ�!" << endl;
		file55.close();
	}
	else
	{
		cout << "δ�ҵ����鼮��" << endl;
		return;
	}
}


