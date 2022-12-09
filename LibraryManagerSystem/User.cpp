#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstring>
#include"User.h"
#include"Record.h"
#include "FineRecord.h"
#define MAX 100005

using namespace std;

User::User(int new_id, char new_name[], char new_gender[], int new_grade, int new_major, int new_borrow_num, int new_history_borrow_num, int new_state, int new_status) {
	id = new_id;
	strcpy_s(name, strlen(new_name) + 1, new_name);
	strcpy_s(gender, strlen(new_gender) + 1, new_gender);
	grade = new_grade;
	majorID = new_major;
	//char char_id = id;
	//_itoa_s(id, password, 10);//��ʼ������Ϊѧ��
	snprintf(password, sizeof(password), "%d", id);
	borrow_num = new_borrow_num;
	user_state = new_state;
	status = new_status;
}

int User::get_status()
{
	return status;
}

int User::get_id() {
	return id;
}

void User::set_id(int _id) {
	this->id = _id;
}

char* User::get_name() {
	return name;
}

void User::set_name(char _name[20]) {
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

char* User::get_gender() {
	return gender;
}

void User::set_gender(char _gender[10]) {
	strcpy_s(this->gender, strlen(_gender) + 1, _gender);
}

int User::get_grade() {
	return grade;
}

void User::set_grade(int _grade) {
	this->grade = _grade;
}

string User::get_major(int _majorID) {
	//����ӳ���ϵ
	map<int, string> id_major;
	id_major[1] = "���������ѧԺ";
	id_major[2] = "��Ϣ��ѧ�빤��ѧ��";
	id_major[201] = "�������ѧ�뼼��ѧԺ";
	id_major[202] = "������Ϣ����ѧԺ";
	id_major[203] = "����ѧ�빤��ѧԺ";
	id_major[204] = "�����뺣��ѧԺ";
	id_major[3] = "��ѧ����ѧԺ";
	id_major[4] = "��������ѧѧԺ";
	id_major[5] = "��������ѧԺ";
	id_major[6] = "ʳƷ��ѧ�빤��ѧԺ";
	id_major[7] = "ҽҩѧԺ";
	id_major[8] = "����ѧԺ";
	id_major[9] = "������ѧ�빤��ѧԺ";
	id_major[10] = "����ѧԺ";
	id_major[11] = "����ѧԺ";
	id_major[12] = "�����ѧԺ";
	id_major[13] = "��ѧ�����Ŵ���ѧԺ";
	id_major[14] = "��ѧԺ";
	id_major[15] = "���������빫������ѧԺ";
	id_major[16] = "��ѧ��ѧѧԺ";
	id_major[17] = "���Ͽ�ѧ�빤��ѧԺ";
	id_major[18] = "���˼����ѧԺ";
	id_major[19] = "�籾ѧԺ";
	id_major[20] = "����ѧԺ";

	return id_major[_majorID];
}

int User::get_majorID() {
	return this->majorID;
}

void User::set_major(string major) {
	map<int, string> id_major;
	id_major[1] = "���������ѧԺ";
	id_major[2] = "��Ϣ��ѧ�빤��ѧ��";
	id_major[201] = "�������ѧ�뼼��ѧԺ";
	id_major[202] = "������Ϣ����ѧԺ";
	id_major[203] = "����ѧ�빤��ѧԺ";
	id_major[204] = "�����뺣��ѧԺ";
	id_major[3] = "��ѧ����ѧԺ";
	id_major[4] = "��������ѧѧԺ";
	id_major[5] = "��������ѧԺ";
	id_major[6] = "ʳƷ��ѧ�빤��ѧԺ";
	id_major[7] = "ҽҩѧԺ";
	id_major[8] = "����ѧԺ";
	id_major[9] = "������ѧ�빤��ѧԺ";
	id_major[10] = "����ѧԺ";
	id_major[11] = "����ѧԺ";
	id_major[12] = "�����ѧԺ";
	id_major[13] = "��ѧ�����Ŵ���ѧԺ";
	id_major[14] = "��ѧԺ";
	id_major[15] = "���������빫������ѧԺ";
	id_major[16] = "��ѧ��ѧѧԺ";
	id_major[17] = "���Ͽ�ѧ�빤��ѧԺ";
	id_major[18] = "���˼����ѧԺ";
	id_major[19] = "�籾ѧԺ";
	id_major[20] = "����ѧԺ";

	map<int, string>::iterator iter;
	//string major = "�籾ѧԺ";

	iter = std::find_if(id_major.begin(), id_major.end(), [major](const map<int, string>::value_type& item) {
		return item.second == major;
	});
	int n = 0;
	if (iter != id_major.end())
		this->majorID = iter->first;
}

void User::set_majorID(int major) {
	this->majorID = major;
}

int User::get_borrow_num() {
	int count = 0;
	Record record;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && record.get_book_state() == 0) {
			count++;
		}
	}
	fp.close();
	return count;
}

void User::set_borrow_num(int _num) {
	this->borrow_num = _num;
}

char* User::get_password() {
	return password;
}

void User::set_password(char _password[20]) {
	strcpy_s(this->password, strlen(_password) + 1, _password);
}

int User::get_history_borrow_num() {
	int count = 0;
	Record record;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && (record.get_book_state() == 1 || record.get_book_state() == 2)) {
			count++;
		}
	}
	fp.close();
	return count;
}

void User::set_history_borrow_num(int _num) {
	this->history_borrow_num = _num;
}

int User::get_user_state() {
	return user_state;
}

void User::set_user_state(int state) {
	this->user_state = state;
}

void User::set_status(int _status)
{
	status = _status;
}

void User::show_user() {
	cout << "ѧ�ţ�" << this->get_id() << setw(12) << "������" << this->get_name() << setw(12) << "�Ա�" << this->get_gender() << setw(12) << "�꼶��" << this->get_grade() << setw(12) << "��ݣ�";
	if (this->get_status() == 1)
		cout << "������";
	else if (this->get_status() == 2)
		cout << "�о���";
	cout << setw(12) << "רҵ��" << this->get_major(this->get_majorID()) << setw(20) << "��ǰ����������" << this->get_borrow_num() << endl;
	//cout << "ѧ�ţ�" << this->get_id() << endl;
	////cout << "���룺" << this->get_password() << endl;
	//cout << "������" << this->get_name() << endl;
	//cout << "�Ա�" << this->get_gender() << endl;
	//cout << "�꼶��" << this->get_grade() << endl;
	//cout << "רҵ��" << this->get_major() << endl;
	//cout << "��ǰ����������" << this->get_borrow_num() << endl;
}

void User::show_menu() {
	int choice;

	this->set_black_list();
	while (true) {
	
		if (this->get_user_state() == 1) {

			system("cls");
			std::cout << " ********************************************************" << std::endl;
			std::cout << " *               ��ӭ��½�û�ϵͳ��                     *" << std::endl;
			std::cout << " *�û�ID��" << this->get_id() << "                                       *" << std::endl;
			std::cout << " *��ݣ�";
			if (this->get_status() == 1)
				cout << "������" << "                                          *" << std::endl;
			if (this->get_status() == 2)
				cout << "�о���" << "                                          *" << std::endl;
			std::cout << " *               ������������ֽ��в���                 *" << std::endl;
			std::cout << " *               1 : ����                               *" << std::endl;
			std::cout << " *               2 : ����                               *" << std::endl;
			std::cout << " *               3 : ��ѯ��ʷ�����¼                   *" << std::endl;
			std::cout << " *               4 : ��ѯ��ǰ�������Ϣ                 *" << std::endl;
			std::cout << " *               5 : �޸ĸ�������                       *" << std::endl;
			std::cout << " *               6 : ����                               *" << std::endl;
			std::cout << " *               7 : �鼮��ʧ�걨                       *" << std::endl;
			std::cout << " *               0 : ����                               *" << std::endl;
			std::cout << " ********************************************************" << std::endl;



			while (!(cin >> choice) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}
			if (choice == 0) {
				return;
			}
			else if (choice == 1) {
				this->borrow_book();
				system("pause");
			}
			else if (choice == 2) {
				this->return_book();
			}
			else if (choice == 3) {
				this->inquire_history();
			}
			else if (choice == 4) {
				this->inquire_now();
			}
			else if (choice == 5) {
				this->change_info();
			}
			else if (choice == 6) {
				this->renew();
				system("pause");
			}
			else if (choice == 7) {
				this->declare();
				system("pause");
			}
			else {
				return;
			}
		}
		else if (this->get_user_state() == 0) {

			system("cls");
			std::cout << " �û�ID��" << this->get_id() << "" << std::endl;
			std::cout << " ��ݣ�";
			if (this->get_status() == 1)
				cout << "������" << "                                          *" << std::endl;
			if (this->get_status() == 2)
				cout << "�о���" << "                                          *" << std::endl;
			std::cout << "**************************************************" << endl;
			std::cout << "*                                                *" << endl;
			std::cout << "*  ���ѱ�����ͼ��ݺ������������뾡�컹�飡����  *" << endl;
			std::cout << "*                                                *" << endl;
			std::cout << "**************************************************" << endl;
			std::cout << " 1 : �鿴����δ���鼮" << std::endl;
			std::cout << " 2 : ����" << std::endl;
			std::cout << " 3 : ��ѯ��ʷ�����¼" << std::endl;
			std::cout << " 4 : ��ѯ��ǰ�������Ϣ" << std::endl;
			std::cout << " 5 : �޸ĸ�������" << std::endl;
			std::cout << " 6 : ����" << std::endl;
			std::cout << " 7 : �鼮��ʧ�걨" << std::endl;
			std::cout << " 0 : �˳�" << std::endl;
			std::cout << "��ѡ��:";

			std::cin >> choice;
			if (choice == 0) {
				return;
			}
			else if (choice == 1) {
				this->show_delay_book();
			}
			else if (choice == 2) {
				this->return_book();
				this->set_black_list();
			}
			else if (choice == 3) {
				this->inquire_history();
			}
			else if (choice == 4) {
				this->inquire_now();
			}
			else if (choice == 5) {
				this->change_info();
			}
			else if (choice == 6) {
				this->renew();
				this->set_black_list();
				system("pause");
			}
			else if (choice == 7) {
				this->declare();
				this->set_black_list();
				system("pause");
			}
			else {
				return;
			}

		}
	}
}

User* find_user_locate(int id)
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

		if (tmp_usr.get_id() == id && tmp_usr.get_user_state() == 1)
		{
			user = new User(tmp_usr.get_id(), tmp_usr.get_name(), tmp_usr.get_gender(), tmp_usr.get_grade(), tmp_usr.get_majorID(), tmp_usr.get_borrow_num(), tmp_usr.get_history_borrow_num(), tmp_usr.get_user_state(), tmp_usr.get_status());
			user->set_password(tmp_usr.get_password());
			// load_record(user1.get_id());			// ��ȡ�û����ļ�¼����δʵ�ָú�����
			userfile.close();
			return user;							//�����û���Ϣ
		}
	}
}

bool User::save_user_info()
// ���ļ��б����û�����
{
	fstream UserFile("User.dat", ios::in | ios::binary | ios::out);
	if (!UserFile) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return false;
	}

	User usr;
	//cout << get_id();
	User new_usr(get_id(), get_name(), get_gender(), get_grade(), get_majorID(), get_borrow_num(), get_history_borrow_num(), get_user_state(), get_status());
	new_usr.set_password(this->get_password());

	while (UserFile.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == this->get_id()) {
			//�ҵ�������ͬ���û�λ��
			int size = sizeof(usr);
			UserFile.seekg(-size, ios::cur);
			UserFile.write((char*)&new_usr, sizeof(new_usr));
			UserFile.close();
			return true;
		}
	}
	return false;
}

/*void User::change_password() {
	string old_password;
	string new_password;
	char password[10] = {};
	cout << "������ԭʼ���룺";
	cin >> old_password;
	int t = 1;
	while (true) {
		//cout << get_password();
		if (old_password == this->get_password()) {
			while (true) {
				cout << "�����������루���Ȳ��ɳ���10λ ͬʱ���ܵ���5λ����" << endl;
				//string key1;
				cin >> new_password;
				if (new_password.length() > 10 || new_password.length() < 5)
					cout << "�������벻����Ҫ�����������룡" << endl;
				else break;
			}

			cout << "ȷ�������룺" << endl;
			string confim_passwd;
			cin >> confim_passwd;
			if (new_password == confim_passwd)//������������һ��
			{
				for (int i = 0; i < new_password.length(); i++)
					password[i] = new_password[i];

				if (save_user_info()) {
					cout << "�޸ĳɹ���" << endl;
					system("pause");
					return;
				}
				else {
					cout << "�޸�ʧ�ܣ�" << endl;
					//system("pause");
					return;
				}
			}
			else {
				cout << "�������벻һ�£����������룡" << endl;
				//system("pause");
			}
		}
		else {
			cout << "ԭʼ��������������������룺";
			cin >> old_password;
		}
	}
}*/

int include_chinese(char* str)
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

void User::change_info() {

	cout << "��ѡ������Ҫ�޸ĵ���Ϣ" << endl;
	cout << "1���û���" << endl;
	cout << "2������" << endl;
	cout << "3���Ա�" << endl;
	cout << "4��Ժϵ" << endl;
	cout << "0������" << endl;
	int choice;
	while (true)
	{
		while (!(cin >> choice) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}

		if (choice < 0 || choice > 4) {
			cout << "�����������������" << endl;
		}
		else
			break;
	}

	string new_name;
	char name[10] = {};

	string old_password;
	string new_password;
	char password[10] = {};

	int new_gender;
	char gender[10];
	int flag;

	int new_major;
	char a[50] = { 0 };
	switch (choice) {
	case 1:
		cout << "��ǰ�û���Ϊ��" << this->get_name() << endl;
		cout << "�޸��û���Ϊ�����Ȳ��ɳ���10λ ����0�˳�����" << endl;
		while (true)
		{
			while (!(cin >> new_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}
			for (int i = 0; i < new_name.length(); i++) {
				a[i] = new_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (new_name.length() > 10 || !new_name.length())
				cout << "�����û���������Ҫ�� ���������룡" << endl;
			else
				break;
		}

		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];
		this->set_name(name);
		if (save_user_info()) {

			//�޸ļ�¼�û���
			fstream fp_fr("FineRecord.dat", ios::in | ios::binary);
			if (!fp_fr)
			{
				cerr << "�ļ���ʧ�ܣ�" << endl;
				return;
			}
			FR fr4;
			int size = sizeof(FR);
			while (fp_fr.read((char*)&fr4, sizeof(fr4)))
			{
				if (fr4.get_id() == this->id)
				{
					fr4.set_name(name);
					fp_fr.seekp(-size, ios::cur);
					fp_fr.write((char*)&fr4, sizeof(fr4));
				}
			}

			// �޸�record��Ϣ
			/*fstream file1("recording.dat", ios::in | ios::binary);
			if (!file1) {
				cout << "�ļ���ʧ�ܣ�" << endl;
				return;
			}
			Record record;

			while (file1.read((char*)&record, sizeof(record)))
			{
				if (record.get_user_id() == this->get_id()) {
					//�ҵ�������ͬ���û�λ��
					int size = sizeof(record);
					file1.seekg(-size, ios::cur);
					record.set_user_name(name);
					file1.write((char*)&record, sizeof(record));
					//file1.close();
				}
				if (record.get_id() == 0)
					break;
			}

			
			file1.close(); */
			fp_fr.close();
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			return;
		}
		else {
			cout << "�޸�ʧ�ܣ�" << endl;
			system("pause");
			return;
		}
		break;
	case 2:
		cout << "������ԭʼ���룺(����0�˳�)";
		while (!(cin >> old_password) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		for (int i = 0; i < old_password.length(); i++) {
			a[i] = old_password[i];
		}
		if (strcmp(a, "0") == 0)return;
		while (true) {
			//cout << get_password();
			if (old_password == this->get_password()) {
				while (true) {
					cout << "�����������루���Ȳ��ɳ���10λ ͬʱ���ܵ���5λ ����0�˳�����" << endl;
					//string key1;
					//cin >> new_password;
					while (!(cin >> new_password) || cin.peek() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�������ʹ���,���������룡" << endl;
					}
					char b[50] = { 0 };
					for (int i = 0; i < new_password.length(); i++) {
						b[i] = new_password[i];
					}
					int flag = 0;
					if (new_password == "0")return;
					flag = include_chinese(b);
					if (new_password.length() > 10 || new_password.length() < 5 || flag)
						cout << "�������벻����Ҫ�����������룡" << endl;
					else break;
				}

				cout << "ȷ�������룺" << endl;
				string confim_passwd;
				while (!(cin >> confim_passwd) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�������,���������룡" << endl;
				}
				if (new_password == confim_passwd)//������������һ��
				{
					for (int i = 0; i < new_password.length(); i++)
						password[i] = new_password[i];

					this->set_password(password);
					if (save_user_info()) {
						cout << "�޸ĳɹ���" << endl;
						system("pause");
						return;
					}
					else {
						cout << "�޸�ʧ�ܣ�" << endl;
						system("pause");
						return;
					}
				}
				else {
					cout << "�������벻һ�£����������룡" << endl;
					//system("pause");
				}
			}
			else {
				cout << "ԭʼ��������������������룺";
				cin >> old_password;
			}
		}
		break;
	case 3:
		cout << "��ǰѡ���Ա�Ϊ��" << this->get_gender() << endl;
		if (!strcmp(this->get_gender(), "��")) {
			strcpy_s(gender, strlen("Ů") + 1, "Ů");
			flag = 0;
		}
		else {
			strcpy_s(gender, strlen("��") + 1, "��");
			flag = 1;
		}

		cout << "1�������Ա�Ϊ��";
		if (!flag)
			cout << "Ů" << endl;
		else
			cout << "��" << endl;
		cout << "2��ȡ���޸�" << endl;

		while (true) {
			while (!(cin >> new_gender) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����ѡ�����,���������룡" << endl;
			}

			if (new_gender == 1) {
				this->set_gender(gender);
				if (save_user_info()) {
					cout << "�޸ĳɹ���" << endl;
					system("pause");
					return;
				}
				else {
					cout << "�޸�ʧ�ܣ�" << endl;
					system("pause");
					return;
				}
			}
			else if (new_gender == 2)
				return;
			else
				cout << "������� ���������룡" << endl;
		}

		break;
	case 4:
		cout << "��ǰԺϵΪ:" << this->get_major(this->get_majorID()) << endl;
		cout << "��Ҫ�޸�Ϊ��" << endl;
		while (true) {
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
			if (new_major == 0)return;
			if (new_major < 1 && new_major > 20) {
				cout << "ѡ�����������ѡ��" << endl;
			}
			else
				break;
		}

		this->set_majorID(new_major);
		if (save_user_info()) {
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			return;
		}
		else {
			cout << "�޸�ʧ�ܣ�" << endl;
			system("pause");
			return;
		}
		break;
	case 0:
		return;
	}
}

void User::borrow_book() {//����
	Record record;
	int count = 0;
	fstream flegal("recording.dat", ios::binary | ios::in);
	if (!flegal) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (flegal.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && (record.get_book_state() == 0) ) {
			count++;
		}
	}
	flegal.close();
	if ((this->get_status() == 1 && count > 4) || (this->get_status() == 2 && count > 7)) {//�жϵ�ǰ�������Ƿ񳬹����ֵ������������5�����о�������8��
		cout << "��ǰ���������Ѵ����ֵ�����ɽ��飡" << endl;
		return;
	}
	int find1 = 0;
	Manager manager1;
	manager1.search_book();
	if (cnt_a == 0)
		return;
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
		cout << "������Ҫ���ĵ��鼮id ����0�˳�" << endl;
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
		{
			for (int i = 0; i < 10000; i++)
			{
				if (search_id == id_a[i])
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
	while (file.read((char*)&book1, sizeof(book1)))//Ѱ�ҽ��ĵ��鼮
	{
		if (book1.get_id() == search_id)
		{
			find = 1;
			cout << "�ҵ����鼮��Ϣ����:" << endl;
			book1.show_book();
			break;
		}
	}
	if (book1.get_state() == 1)
	{
		int state;
		state = book1.get_state();
		int choice = 0;
		cout << "��ȷ��Ҫ���Ȿ����" << endl
			<< "1.��" << endl
			<< "2.��" << endl;
		while (true) {
			while (!(cin >> choice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�����������ʹ���,����������:" << endl;
			}
			if (choice <= 0 || choice > 2) {
				cout << "�����������������" << endl;
			}
			else
				break;
		}
		if (choice == 1) {
			book1.set_state(0);
			Record record1(book1.get_id(), book1.get_name(), this->get_id(), this->get_name(), book1.get_state(), 1);
			record1.recording();
			fstream fp("book.dat", ios::binary | ios::out | ios::in);
			if (!fp) {
				cerr << "�ļ���ʧ�ܣ�" << endl;
				exit(0);
			}
			Book bookfor_id;
			while (fp.read((char*)&bookfor_id, sizeof(Book))) {
				if (bookfor_id.get_id() == book1.get_id()) {
					break;
				}
			}
			int size = sizeof(Book);
			fp.seekp(-size, ios::cur);
			fp.write((char*)&book1, sizeof(Book));
			fp.close();
			cout << "���ĳɹ���" << endl;
		}
		else
			return;
	}
	else if (book1.get_state() == 0)
	{
		cout << "�ѱ�������ɽ��ģ�" << endl;
		return;
	}
	else if (book1.get_state() == 2)
	{
		cout << "�Ѷ�ʧ���ɽ��ģ�" << endl;
		return;
	}
}

int calculate_day(char return_tmp[256], char tmp[256]) {
	int date1[3], date2[3];
	date1[0] = (return_tmp[0] - '0') * 1000 + (return_tmp[1] - '0') * 100 + (return_tmp[2] - '0') * 10 + (return_tmp[3] - '0');
	date1[1] = (return_tmp[5] - '0') * 10 + (return_tmp[6] - '0');
	date1[2] = (return_tmp[8] - '0') * 10 + (return_tmp[9] - '0');
	date2[0] = (tmp[0] - '0') * 1000 + (tmp[1] - '0') * 100 + (tmp[2] - '0') * 10 + (tmp[3] - '0');
	date2[1] = (tmp[5] - '0') * 10 + (tmp[6] - '0');
	date2[2] = (tmp[8] - '0') * 10 + (tmp[9] - '0');
	int i = date1[0], j = date2[0];  //������date1[0]�ĸı�����ɵ����ݴ���
	int day = 0, z1 = 0, z2 = 0;//z1��z2�ֱ�date1[1]��date2[1]�����·�����
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	day = (date2[0] - date1[0]) * 365;
	for (; date2[0] > date1[0]; date1[0]++)
		if (date1[0] % 400 == 0 || (date1[0] % 4 == 0 && date1[0] % 100 != 0))//�ж��Ƿ�Ϊ����
			day++;
	for (int m = 1; m <= 12; m++)
	{
		if (m <= date1[1])
			z1 += a[m];
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))//�ж�date1[0]�Ƿ�Ϊ����
			z1++;
	}
	for (int m = 1; m <= 12; m++)
	{
		if (m <= date2[1])
			z2 += a[m];
		if (j % 400 == 0 || (j % 4 == 0 && j % 100 != 0))//�ж�date2[0]�Ƿ�Ϊ����
			z2++;
	}
	day += abs((z2 + date2[2]) - (z1 + date1[2]));//abs��ʾȡ�����ľ���ֵ
	return day;
}

void User::set_black_list() {
	int day;	// ����������������
	Record record;

	////�Ѿ��ں������� ֱ�ӷ���
	//if (this->get_user_state() == 0)
	//	return;

	fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}

	Book book;
	fstream fp_book("Book.dat", ios::binary | ios::in | ios::out);
	if (!fp_book) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}

	while (fp.read((char*)&record, sizeof(Record))) {
		if (record.get_record_state() == 0 && record.get_user_id() == this->get_id())
			return;

		if (record.get_user_id() == this->get_id() && record.get_book_state() == 0) {
			while (fp_book.read((char*)&book, sizeof(Book))) {
				if (book.get_id() == record.get_id())
					break;
			}
			fp_book.close();
			//��ȡ��ǰʱ��
			char return_tmp[256];

			time_t time_seconds = time(0);
			struct tm now_time;
			localtime_s(&now_time, &time_seconds);

			time_t timep;//���ʱ�� 
			time(&timep);
			strftime(return_tmp, sizeof(return_tmp), "%Y-%m-%d %H:%M:%S", &now_time);

			day = calculate_day(return_tmp, record.get_tmp());
			int deadline = day;
			if (book.get_renew_time() == 0)
				deadline = 30;
			else if (book.get_renew_time() == 1)
				deadline = 60;

			if (day > deadline) {
				this->set_user_state(0);	// ���������
				User new_usr(this->get_id(), this->get_name(), this->get_gender(), this->get_grade(), this->get_majorID(), this->get_borrow_num(), this->get_history_borrow_num(), 0, this->get_status());
				new_usr.set_password(this->get_password());

				// ��User.dat�ļ��޸�state = 0
				fstream ofs("User.dat", ios::in | ios::binary | ios::out);
				if (!ofs) {
					cout << "�ļ���ʧ�ܣ�" << endl;
					return;
				}
				User usr;
				while (ofs.read((char*)&usr, sizeof(usr)))
				{
					if (usr.get_id() == this->get_id()) {
						//�ҵ�������ͬ���û�λ��
						int size = sizeof(usr);
						ofs.seekg(-size, ios::cur);
						ofs.write((char*)&new_usr, sizeof(new_usr));
						ofs.close();
						break;
					}
				}

				//�ڼ�¼���ļ������ø�����¼��record_state = 0
				Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state(), 0);
				record1.set_tmp(record.get_tmp());
				record1.set_record_state(0);
				//�ҵ���¼λ��
				int size = sizeof(record);
				fp.seekg(-size, ios::cur);
				fp.write((char*)&record1, sizeof(record1));
				fp.close();

				return;
			}
		}
	}

	this->set_user_state(1);
	User new_usr(this->get_id(), this->get_name(), this->get_gender(), this->get_grade(), this->get_majorID(), this->get_borrow_num(), this->get_history_borrow_num(), this->get_user_state(), this->get_status());
	new_usr.set_password(this->get_password());

	fp.close();
	fp_book.close();

	// ��User.dat�ļ��޸�state = 1
	fstream ofs("User.dat", ios::in | ios::binary | ios::out);
	if (!ofs) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	User usr;
	while (ofs.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == this->get_id()) {
			//�ҵ�������ͬ���û�λ��
			int size = sizeof(usr);
			ofs.seekg(-size, ios::cur);
			ofs.write((char*)&new_usr, sizeof(new_usr));
			ofs.close();
			break;
		}
	}
	return;
}

void User::show_delay_book() {
	Record record;
	Book book;
	fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}

	while (fp.read((char*)&record, sizeof(Record))) {
		if (record.get_user_id() == this->get_id() && record.get_record_state() == 0) {
			// ��ȡ��ǰ�鼮��Ϣ
			int book_id = record.get_id();

			fstream file("book.dat", ios::binary | ios::in | ios::out);
			if (!fp) {
				cerr << "�ļ���ʧ�ܣ�" << endl;
				exit(0);
			}


			while (file.read((char*)&book, sizeof(Book)))
				if (book_id == book.get_id()) {
					book.show_book();
				}
			file.close();
		}
	}
	fp.close();
	system("pause");
}

void User::return_book() {
	Record record;
	int count = 0;
	fstream fbook_now_number("recording.dat", ios::binary | ios::in);
	if (!fbook_now_number) {
		cerr << ("�ļ���ʧ�ܣ�") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "��ǰδ�����鼮��" << endl;
		system("pause");
		return;
	}

	cout << "��ǰ������Ϣ���£�" << endl;
	fstream fshowbook("recording.dat", ios::binary | ios::in);
	if (!fshowbook) {
		cerr << ("�ļ���ʧ�ܣ�") << endl;
		exit(0);
	}
	while (fshowbook.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			record.show_record();
		}
	}
	fshowbook.close();

	int day;
	Book last_book;
	Book book_for_search;
	fstream fp("book.dat", ios::in | ios::binary);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	int size = sizeof(Book);
	fp.seekg(-size, ios::end);
	fp.read((char*)&last_book, size);
	fp.close();
	int id = 0;
	cout << "��������Ҫ�������id��(����0�˳�)" << endl;
	while (!(cin >> id) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�����������ʹ���,����������:" << endl;
	}
	if (id == 0)return;
	while (1)
	{
		if (id < 1 || id > last_book.get_id()) {
			cout << "�����������������룡" << endl;
			cin >> id;
		}
		else
			break;
	}
	fstream fsearch_id("book.dat", ios::binary | ios::in);
	if (!fsearch_id) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	while (fsearch_id.read((char*)&book_for_search, sizeof(Book))) {
		if (book_for_search.get_id() == id) {
			book_for_search.show_book();
			break;
		}
	}
	fsearch_id.close();
	if (book_for_search.get_state() == 1) {
		cout << "����δ�������" << endl;
		system("pause");
		return;
	}
	if (book_for_search.get_state() == 2) {
		cout << "�����Ѷ�ʧ��" << endl;
		system("pause");
		return;
	}
	int choice = 0;
	cout << "��ȷ��Ҫ���Ȿ����" << endl
		<< "1.��" << endl
		<< "2.��" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "�����������������" << endl;
		}
		else
			break;
	}
	if (choice == 1) {
		Record record;
		fstream fp("recording.dat", ios::binary | ios::in | ios::out);
		if (!fp) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fp.read((char*)&record, sizeof(Record))) {
			if (record.get_user_id() == this->get_id() && record.get_id() == id && record.get_book_state() == 0) {
				record.set_return_tmp();
				day = calculate_day(record.get_return_tmp(), record.get_tmp());
				if (day > 30 + book_for_search.get_renew_time() * 30) {//�������������30
					cout << "����ʱ���ѳ�ʱ���뵽ǰ̨���ɷ���" << endl;
					int d = 0;
					double money = 0;
					d = day - 13 + book_for_search.get_renew_time() * 30;
					money = d * 0.3;
					if (money > 30) {
						money = 30;
					}
					fstream fpfine("FineRecord.dat", ios::binary | ios::app);//д�뷣���¼
					if (!fpfine) {
						cerr << "�ļ���ʧ�ܣ�" << endl;
						exit(0);
					}
					FR fr1(this->id, this->name, 1, money);
					fpfine.write((char*)&fr1, sizeof(FR));
					fpfine.close();
					cout << "������Ϊ��" << money << endl;
					system("pause");
				}
				int size;
				size = sizeof(Record);
				record.set_book_state(1);
				record.set_record_state(1);
				fp.seekp(-size, ios::cur);
				fp.write((char*)&record, sizeof(Record));
				break;
			}
		}
		fp.close();
		fstream freturn("book.dat", ios::binary | ios::out | ios::in);
		if (!freturn) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		Book bookfor_id;
		while (freturn.read((char*)&bookfor_id, sizeof(Book))) {
			if (bookfor_id.get_id() == book_for_search.get_id()) {
				break;
			}
		}
		int size = sizeof(Book);
		freturn.seekp(-size, ios::cur);
		book_for_search.set_state(1);
		book_for_search.reset_renew_time();//���ý������Ϊ0
		freturn.write((char*)&book_for_search, sizeof(Book));
		freturn.close();
		cout << "����ɹ���" << endl;
		system("pause");
	}
	else if (choice == 2) {
		return;
	}
}

void User::inquire_history() {
	Record record;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << ("�ļ���ʧ�ܣ�") << endl;
		exit(0);
	}
	while (fp.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 1 || record.get_book_state() == 2)) {
			record.show_record();
		}
	}
	system("pause");
	fp.close();
}

void User::inquire_now() {
	Record record;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && record.get_book_state() == 0) {
			record.show_record();
		}
	}
	//cout << "1" ;
	system("pause");
	fp.close();
}

void User::renew()
{
	Record record;
	int count = 0;
	fstream fbook_now_number("recording.dat", ios::binary | ios::in);
	if (!fbook_now_number) {
		cerr << ("�ļ���ʧ�ܣ�") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "��ǰδ�����鼮���ɽ����鼮���裡" << endl;
		return;
	}

	cout << "��ǰ������Ϣ���£�" << endl;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}

	int ban_id = -1;
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && record.get_book_state() == 0) {
			record.show_record();
			if (record.get_record_state() == 0) {
				cout << "���������鼮����ʱ���ѳ���30�����ڼ�δ���裬�ѽ�ֹ���裡������" << endl;
				ban_id = record.get_id();
			}
		}
	}

	fp.close();
	int id;
	cout << "��������Ҫ��������id��(����0�˳�)" << endl;
	while (1)
	{
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (id == 0)return;
		if (id == ban_id) {
			cout << "���鼮����ʱ���ѳ���30�����ڼ�δ���裬�ѽ�ֹ���裡" << endl;
			cout << "��ǰ�����飡" << endl;
			return;
		}

		Record record1;
		fstream fp2("recording.dat", ios::binary | ios::in);
		if (!fp2) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		int flag = 0;//������Լ���ǰ�������Ƿ��ҵ���id
		while (fp2.read((char*)&record1, sizeof(Record)))
		{
			if (this->get_id() == record1.get_user_id() && record1.get_book_state() == 0 && id == record1.get_id())
			{
				flag = 1;
				fp2.close();
				break;
			}
		}
		if (flag == 1)
			break;
		if (flag == 0)
			cout << "��id����δ�������ģ����������룡" << endl;
	}
	int choice = 0;
	cout << "��ȷ��Ҫ�����Ȿ����" << endl
		<< "1.��" << endl
		<< "2.��" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "�����������������" << endl;
		}
		else
			break;
	}
	if (choice == 1)
	{
		Book book_for_search;
		/*Record record2;
		fstream fp3("recording.dat", ios::binary | ios::in|ios::out);
		if (!fp3) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fp3.read((char*)&record2, sizeof(Record)))
		{
			if (id == record2.get_id())
				break;
		}
		int size = sizeof(Record);
		fp3.seekp(-size, ios::cur);
		Record record3(record2.get_id(), record2.get_book_name(), record2.get_user_id(), record2.get_user_name(), record2.get_book_state());
		fp3.write((char*)&record3, sizeof(Record));
		fp3.close();*/
		fstream fprenew("book.dat", ios::in | ios::out | ios::binary);
		if (!fprenew) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fprenew.read((char*)&book_for_search, sizeof(Book))) {
			if (book_for_search.get_id() == id && book_for_search.get_renew_time() < 1) {//�������һ��
				book_for_search.set_renew_time();//���������һ
				int size = sizeof(Book);
				fprenew.seekp(-size, ios::cur);
				fprenew.write((char*)&book_for_search, sizeof(Book));
				cout << "����ɹ���" << endl;
				break;
			}
			else if (book_for_search.get_id() == id && book_for_search.get_renew_time() >= 1) {
				cout << "���������ѳ������������޷����裡" << endl;
				break;
			}
		}
		fprenew.close();
	}
	else
		return;
}

void User::declare()
{
	Record record;
	int count = 0;
	fstream fbook_now_number("recording.dat", ios::binary | ios::in);
	if (!fbook_now_number) {
		cerr << ("�ļ���ʧ�ܣ�") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "��ǰδ�����鼮���ɽ����鼮��ʧ�걨��" << endl;
		return;
	}

	cout << "��ǰ������Ϣ���£�" << endl;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && record.get_book_state() == 0) {
			record.show_record();
		}
	}
	//cout << "1" ;
	fp.close();
	int id;
	cout << "��������Ҫ�걨��ʧ�����id��(����0�˳�)" << endl;
	while (1)
	{
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (id == 0)return;
		Record record1;
		fstream fp2("recording.dat", ios::binary | ios::in);
		if (!fp2) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		int flag = 0;//������Լ���ǰ�������Ƿ��ҵ���id
		while (fp2.read((char*)&record1, sizeof(Record)))
		{
			if (this->get_id() == record1.get_user_id() && id == record1.get_id() && record1.get_book_state() == 0)
			{
				flag = 1;
				fp2.close();
				break;
			}
		}
		if (flag == 1)
			break;
		if (flag == 0)
			cout << "��id����δ�������ģ����������룡" << endl;
	}
	int choice = 0;
	cout << "��ȷ��Ҫ���Ȿ���걨��ʧ��" << endl
		<< "1.��" << endl
		<< "2.��" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������ʹ���,����������:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "�����������������" << endl;
		}
		else
			break;
	}
	if (choice == 1)
	{
		Book book_for_search;//�޸��鼮״̬
		fstream fsearch_id("book.dat", ios::binary | ios::in);
		if (!fsearch_id) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		while (fsearch_id.read((char*)&book_for_search, sizeof(Book))) {
			if (book_for_search.get_id() == id)
			{
				break;
			}
		}
		fsearch_id.close();
		book_for_search.set_state(2);
		fstream fp5("book.dat", ios::binary | ios::out | ios::in);
		if (!fp5) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		Book bookfor_id;
		while (fp5.read((char*)&bookfor_id, sizeof(Book))) {
			if (bookfor_id.get_id() == book_for_search.get_id()) {
				break;
			}
		}
		int size = sizeof(Book);
		fp5.seekp(-size, ios::cur);
		fp5.write((char*)&book_for_search, sizeof(Book));
		fp5.close();

		//�޸ļ�¼�鼮״̬
		fstream fp51("recording.dat", ios::binary | ios::out | ios::in);
		if (!fp51) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		Record recordfor_id;
		while (fp51.read((char*)&recordfor_id, sizeof(Record))) {
			if ((recordfor_id.get_id() == id)&&(recordfor_id.get_book_state()==0)) {
				break;
			}
		}
		recordfor_id.set_book_state(2);
		//recordfor_id.set_record_state(1);
		int size1 = sizeof(Record);
		fp51.seekp(-size1, ios::cur);
		fp51.write((char*)&recordfor_id, sizeof(Record));
		fp51.close();
		cout << "�鼮��ʧ�걨�ɹ����뵽ǰ̨���ɷ��������Ϊ��" << book_for_search.get_price() << endl;
		fstream fp30("FineRecord.dat", ios::binary | ios::app);//д�뷣���¼
		if (!fp30) {
			cerr << "�ļ���ʧ�ܣ�" << endl;
			exit(0);
		}
		FR fr1(this->id, this->name, 0, book_for_search.get_price());
		fp30.write((char*)&fr1, sizeof(FR));
		fp30.close();
	}
	else
		return;

}

bool User::get_fine_record_id(int search_id) {
	FR fr1;
	fstream file1("FineRecord.dat", ios::in | ios::binary);
	if (!file1)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return 0;
	}

	while (file1.read((char*)&fr1, sizeof(fr1)))
	{
		if (fr1.get_id() == search_id)
			return true;
	}
	return false;
}