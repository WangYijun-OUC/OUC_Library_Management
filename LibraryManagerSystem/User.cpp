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
	//_itoa_s(id, password, 10);//初始化密码为学号
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
	//建立映射关系
	map<int, string> id_major;
	id_major[1] = "海洋与大气学院";
	id_major[2] = "信息科学与工程学部";
	id_major[201] = "计算机科学与技术学院";
	id_major[202] = "电子信息工程学院";
	id_major[203] = "光电科学与工程学院";
	id_major[204] = "物理与海技学院";
	id_major[3] = "化学化工学院";
	id_major[4] = "海洋地球科学学院";
	id_major[5] = "海洋生命学院";
	id_major[6] = "食品科学与工程学院";
	id_major[7] = "医药学院";
	id_major[8] = "工程学院";
	id_major[9] = "环境科学与工程学院";
	id_major[10] = "管理学院";
	id_major[11] = "经济学院";
	id_major[12] = "外国语学院";
	id_major[13] = "文学与新闻传播学院";
	id_major[14] = "法学院";
	id_major[15] = "国际事务与公共管理学院";
	id_major[16] = "数学科学学院";
	id_major[17] = "材料科学与工程学院";
	id_major[18] = "马克思主义学院";
	id_major[19] = "崇本学院";
	id_major[20] = "海德学院";

	return id_major[_majorID];
}

int User::get_majorID() {
	return this->majorID;
}

void User::set_major(string major) {
	map<int, string> id_major;
	id_major[1] = "海洋与大气学院";
	id_major[2] = "信息科学与工程学部";
	id_major[201] = "计算机科学与技术学院";
	id_major[202] = "电子信息工程学院";
	id_major[203] = "光电科学与工程学院";
	id_major[204] = "物理与海技学院";
	id_major[3] = "化学化工学院";
	id_major[4] = "海洋地球科学学院";
	id_major[5] = "海洋生命学院";
	id_major[6] = "食品科学与工程学院";
	id_major[7] = "医药学院";
	id_major[8] = "工程学院";
	id_major[9] = "环境科学与工程学院";
	id_major[10] = "管理学院";
	id_major[11] = "经济学院";
	id_major[12] = "外国语学院";
	id_major[13] = "文学与新闻传播学院";
	id_major[14] = "法学院";
	id_major[15] = "国际事务与公共管理学院";
	id_major[16] = "数学科学学院";
	id_major[17] = "材料科学与工程学院";
	id_major[18] = "马克思主义学院";
	id_major[19] = "崇本学院";
	id_major[20] = "海德学院";

	map<int, string>::iterator iter;
	//string major = "崇本学院";

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
		cerr << "文件打开失败！" << endl;
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
		cerr << "文件打开失败！" << endl;
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
	cout << "学号：" << this->get_id() << setw(12) << "姓名：" << this->get_name() << setw(12) << "性别：" << this->get_gender() << setw(12) << "年级：" << this->get_grade() << setw(12) << "身份：";
	if (this->get_status() == 1)
		cout << "本科生";
	else if (this->get_status() == 2)
		cout << "研究生";
	cout << setw(12) << "专业：" << this->get_major(this->get_majorID()) << setw(20) << "当前借书数量：" << this->get_borrow_num() << endl;
	//cout << "学号：" << this->get_id() << endl;
	////cout << "密码：" << this->get_password() << endl;
	//cout << "姓名：" << this->get_name() << endl;
	//cout << "性别：" << this->get_gender() << endl;
	//cout << "年级：" << this->get_grade() << endl;
	//cout << "专业：" << this->get_major() << endl;
	//cout << "当前借书数量：" << this->get_borrow_num() << endl;
}

void User::show_menu() {
	int choice;

	this->set_black_list();
	while (true) {
	
		if (this->get_user_state() == 1) {

			system("cls");
			std::cout << " ********************************************************" << std::endl;
			std::cout << " *               欢迎登陆用户系统！                     *" << std::endl;
			std::cout << " *用户ID：" << this->get_id() << "                                       *" << std::endl;
			std::cout << " *身份：";
			if (this->get_status() == 1)
				cout << "本科生" << "                                          *" << std::endl;
			if (this->get_status() == 2)
				cout << "研究生" << "                                          *" << std::endl;
			std::cout << " *               请输入相关数字进行操作                 *" << std::endl;
			std::cout << " *               1 : 借书                               *" << std::endl;
			std::cout << " *               2 : 还书                               *" << std::endl;
			std::cout << " *               3 : 查询历史借书记录                   *" << std::endl;
			std::cout << " *               4 : 查询当前借书的信息                 *" << std::endl;
			std::cout << " *               5 : 修改个人资料                       *" << std::endl;
			std::cout << " *               6 : 续借                               *" << std::endl;
			std::cout << " *               7 : 书籍丢失申报                       *" << std::endl;
			std::cout << " *               0 : 返回                               *" << std::endl;
			std::cout << " ********************************************************" << std::endl;



			while (!(cin >> choice) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
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
			std::cout << " 用户ID：" << this->get_id() << "" << std::endl;
			std::cout << " 身份：";
			if (this->get_status() == 1)
				cout << "本科生" << "                                          *" << std::endl;
			if (this->get_status() == 2)
				cout << "研究生" << "                                          *" << std::endl;
			std::cout << "**************************************************" << endl;
			std::cout << "*                                                *" << endl;
			std::cout << "*  您已被列入图书馆黑名单！！！请尽快还书！！！  *" << endl;
			std::cout << "*                                                *" << endl;
			std::cout << "**************************************************" << endl;
			std::cout << " 1 : 查看逾期未还书籍" << std::endl;
			std::cout << " 2 : 还书" << std::endl;
			std::cout << " 3 : 查询历史借书记录" << std::endl;
			std::cout << " 4 : 查询当前借书的信息" << std::endl;
			std::cout << " 5 : 修改个人资料" << std::endl;
			std::cout << " 6 : 续借" << std::endl;
			std::cout << " 7 : 书籍丢失申报" << std::endl;
			std::cout << " 0 : 退出" << std::endl;
			std::cout << "请选择:";

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
		// 依次遍历读取user信息
		userfile.read((char*)&tmp_usr, sizeof(tmp_usr));

		if (tmp_usr.get_id() == id && tmp_usr.get_user_state() == 1)
		{
			user = new User(tmp_usr.get_id(), tmp_usr.get_name(), tmp_usr.get_gender(), tmp_usr.get_grade(), tmp_usr.get_majorID(), tmp_usr.get_borrow_num(), tmp_usr.get_history_borrow_num(), tmp_usr.get_user_state(), tmp_usr.get_status());
			user->set_password(tmp_usr.get_password());
			// load_record(user1.get_id());			// 读取用户借阅记录（暂未实现该函数）
			userfile.close();
			return user;							//返回用户信息
		}
	}
}

bool User::save_user_info()
// 在文件中保存用户密码
{
	fstream UserFile("User.dat", ios::in | ios::binary | ios::out);
	if (!UserFile) {
		cout << "文件打开失败！" << endl;
		return false;
	}

	User usr;
	//cout << get_id();
	User new_usr(get_id(), get_name(), get_gender(), get_grade(), get_majorID(), get_borrow_num(), get_history_borrow_num(), get_user_state(), get_status());
	new_usr.set_password(this->get_password());

	while (UserFile.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == this->get_id()) {
			//找到名字相同的用户位置
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
	cout << "请输入原始密码：";
	cin >> old_password;
	int t = 1;
	while (true) {
		//cout << get_password();
		if (old_password == this->get_password()) {
			while (true) {
				cout << "请输入新密码（长度不可超过10位 同时不能低于5位）：" << endl;
				//string key1;
				cin >> new_password;
				if (new_password.length() > 10 || new_password.length() < 5)
					cout << "输入密码不符合要求，请重新输入！" << endl;
				else break;
			}

			cout << "确认新密码：" << endl;
			string confim_passwd;
			cin >> confim_passwd;
			if (new_password == confim_passwd)//两次密码输入一致
			{
				for (int i = 0; i < new_password.length(); i++)
					password[i] = new_password[i];

				if (save_user_info()) {
					cout << "修改成功！" << endl;
					system("pause");
					return;
				}
				else {
					cout << "修改失败！" << endl;
					//system("pause");
					return;
				}
			}
			else {
				cout << "两次输入不一致，请重新输入！" << endl;
				//system("pause");
			}
		}
		else {
			cout << "原始密码输入错误请重新输入：";
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
		if (c == 0) break;  //如果到字符串尾则说明该字符串没有中文字符
		if (c & 0x80)        //如果字符高位为1且下一字符高位也是1则有中文字符
			if (*str & 0x80) return 1;
	}
	return 0;
}

void User::change_info() {

	cout << "请选择您需要修改的信息" << endl;
	cout << "1、用户名" << endl;
	cout << "2、密码" << endl;
	cout << "3、性别" << endl;
	cout << "4、院系" << endl;
	cout << "0、返回" << endl;
	int choice;
	while (true)
	{
		while (!(cin >> choice) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (choice < 0 || choice > 4) {
			cout << "输入错误请重新输入" << endl;
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
		cout << "当前用户名为：" << this->get_name() << endl;
		cout << "修改用户名为（长度不可超过10位 输入0退出）：" << endl;
		while (true)
		{
			while (!(cin >> new_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}
			for (int i = 0; i < new_name.length(); i++) {
				a[i] = new_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (new_name.length() > 10 || !new_name.length())
				cout << "输入用户名不符合要求 请重新输入！" << endl;
			else
				break;
		}

		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];
		this->set_name(name);
		if (save_user_info()) {

			//修改记录用户名
			fstream fp_fr("FineRecord.dat", ios::in | ios::binary);
			if (!fp_fr)
			{
				cerr << "文件打开失败！" << endl;
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

			// 修改record信息
			/*fstream file1("recording.dat", ios::in | ios::binary);
			if (!file1) {
				cout << "文件打开失败！" << endl;
				return;
			}
			Record record;

			while (file1.read((char*)&record, sizeof(record)))
			{
				if (record.get_user_id() == this->get_id()) {
					//找到名字相同的用户位置
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
			cout << "修改成功！" << endl;
			system("pause");
			return;
		}
		else {
			cout << "修改失败！" << endl;
			system("pause");
			return;
		}
		break;
	case 2:
		cout << "请输入原始密码：(输入0退出)";
		while (!(cin >> old_password) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		for (int i = 0; i < old_password.length(); i++) {
			a[i] = old_password[i];
		}
		if (strcmp(a, "0") == 0)return;
		while (true) {
			//cout << get_password();
			if (old_password == this->get_password()) {
				while (true) {
					cout << "请输入新密码（长度不可超过10位 同时不能低于5位 输入0退出）：" << endl;
					//string key1;
					//cin >> new_password;
					while (!(cin >> new_password) || cin.peek() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "输入类型错误,请重新输入！" << endl;
					}
					char b[50] = { 0 };
					for (int i = 0; i < new_password.length(); i++) {
						b[i] = new_password[i];
					}
					int flag = 0;
					if (new_password == "0")return;
					flag = include_chinese(b);
					if (new_password.length() > 10 || new_password.length() < 5 || flag)
						cout << "输入密码不符合要求，请重新输入！" << endl;
					else break;
				}

				cout << "确认新密码：" << endl;
				string confim_passwd;
				while (!(cin >> confim_passwd) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入错误,请重新输入！" << endl;
				}
				if (new_password == confim_passwd)//两次密码输入一致
				{
					for (int i = 0; i < new_password.length(); i++)
						password[i] = new_password[i];

					this->set_password(password);
					if (save_user_info()) {
						cout << "修改成功！" << endl;
						system("pause");
						return;
					}
					else {
						cout << "修改失败！" << endl;
						system("pause");
						return;
					}
				}
				else {
					cout << "两次输入不一致，请重新输入！" << endl;
					//system("pause");
				}
			}
			else {
				cout << "原始密码输入错误请重新输入：";
				cin >> old_password;
			}
		}
		break;
	case 3:
		cout << "当前选择性别为：" << this->get_gender() << endl;
		if (!strcmp(this->get_gender(), "男")) {
			strcpy_s(gender, strlen("女") + 1, "女");
			flag = 0;
		}
		else {
			strcpy_s(gender, strlen("男") + 1, "男");
			flag = 1;
		}

		cout << "1、更改性别为：";
		if (!flag)
			cout << "女" << endl;
		else
			cout << "男" << endl;
		cout << "2、取消修改" << endl;

		while (true) {
			while (!(cin >> new_gender) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入选项错误,请重新输入！" << endl;
			}

			if (new_gender == 1) {
				this->set_gender(gender);
				if (save_user_info()) {
					cout << "修改成功！" << endl;
					system("pause");
					return;
				}
				else {
					cout << "修改失败！" << endl;
					system("pause");
					return;
				}
			}
			else if (new_gender == 2)
				return;
			else
				cout << "输入错误 请重新输入！" << endl;
		}

		break;
	case 4:
		cout << "当前院系为:" << this->get_major(this->get_majorID()) << endl;
		cout << "想要修改为：" << endl;
		while (true) {
			cout << "1 - 海洋与大气学院" << endl;
			cout << "2 - 信息科学与工程学部" << endl;
			cout << "3 - 化学化工学院" << endl;
			cout << "4 - 海洋地球科学学院" << endl;
			cout << "5 - 海洋生命学院" << endl;
			cout << "6 - 食品科学与工程学院" << endl;
			cout << "7 - 医药学院" << endl;
			cout << "8 - 工程学院" << endl;
			cout << "9 - 环境科学与工程学院" << endl;
			cout << "10 - 管理学院" << endl;
			cout << "11 - 经济学院" << endl;
			cout << "12 - 外国语学院" << endl;
			cout << "13 - 文学与新闻传播学院" << endl;
			cout << "14 - 法学院" << endl;
			cout << "15 - 国际事务与公共管理学院" << endl;
			cout << "16 - 数学科学学院" << endl;
			cout << "17 - 材料科学与工程学院" << endl;
			cout << "18 - 马克思主义学院" << endl;
			cout << "19 - 崇本学院" << endl;
			cout << "20 - 海德学院" << endl;
			cout << "0 - 退出" << endl;
			while (!(cin >> new_major) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入选项错误,请重新输入！" << endl;
			}
			if (new_major == 0)return;
			if (new_major < 1 && new_major > 20) {
				cout << "选择错误，请重新选择！" << endl;
			}
			else
				break;
		}

		this->set_majorID(new_major);
		if (save_user_info()) {
			cout << "修改成功！" << endl;
			system("pause");
			return;
		}
		else {
			cout << "修改失败！" << endl;
			system("pause");
			return;
		}
		break;
	case 0:
		return;
	}
}

void User::borrow_book() {//借书
	Record record;
	int count = 0;
	fstream flegal("recording.dat", ios::binary | ios::in);
	if (!flegal) {
		cerr << "文件打开失败！" << endl;
		exit(0);
	}
	while (flegal.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && (record.get_book_state() == 0) ) {
			count++;
		}
	}
	flegal.close();
	if ((this->get_status() == 1 && count > 4) || (this->get_status() == 2 && count > 7)) {//判断当前借书量是否超过最大值，本科生最多借5本，研究生最多借8本
		cout << "当前借书数量已达最大值，不可借书！" << endl;
		return;
	}
	int find1 = 0;
	Manager manager1;
	manager1.search_book();
	if (cnt_a == 0)
		return;
	int search_id;
	fstream file11("book.dat", ios::binary | ios::in);//找出最后一个id
	if (!file11)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	Book book11;
	int size = (int)sizeof(Book);
	file11.seekg(-size, ios::end);
	file11.read((char*)&book11, sizeof(book11));
	file11.close();

	while (1)//id容错
	{
		cout << "请输入要借阅的书籍id 输入0退出" << endl;
		while (!(cin >> search_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (search_id == 0)return;
		if (search_id < 0 || search_id > book11.get_id())
			cout << "输入id不存在，请重新输入" << endl;
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
				cout << "输入id不在查询结果中,请重新输入！" << endl;
		}
	}
	fstream file("book.dat", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	Book book1;
	int find = 0;
	while (file.read((char*)&book1, sizeof(book1)))//寻找借阅的书籍
	{
		if (book1.get_id() == search_id)
		{
			find = 1;
			cout << "找到的书籍信息如下:" << endl;
			book1.show_book();
			break;
		}
	}
	if (book1.get_state() == 1)
	{
		int state;
		state = book1.get_state();
		int choice = 0;
		cout << "您确定要借这本书吗？" << endl
			<< "1.是" << endl
			<< "2.否" << endl;
		while (true) {
			while (!(cin >> choice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}
			if (choice <= 0 || choice > 2) {
				cout << "输入错误请重新输入" << endl;
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
				cerr << "文件打开失败！" << endl;
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
			cout << "借阅成功！" << endl;
		}
		else
			return;
	}
	else if (book1.get_state() == 0)
	{
		cout << "已被借出不可借阅！" << endl;
		return;
	}
	else if (book1.get_state() == 2)
	{
		cout << "已丢失不可借阅！" << endl;
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
	int i = date1[0], j = date2[0];  //避免了date1[0]的改变所造成的数据错误
	int day = 0, z1 = 0, z2 = 0;//z1和z2分别date1[1]和date2[1]两个月份天数
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	day = (date2[0] - date1[0]) * 365;
	for (; date2[0] > date1[0]; date1[0]++)
		if (date1[0] % 400 == 0 || (date1[0] % 4 == 0 && date1[0] % 100 != 0))//判断是否为闰年
			day++;
	for (int m = 1; m <= 12; m++)
	{
		if (m <= date1[1])
			z1 += a[m];
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))//判断date1[0]是否为闰年
			z1++;
	}
	for (int m = 1; m <= 12; m++)
	{
		if (m <= date2[1])
			z2 += a[m];
		if (j % 400 == 0 || (j % 4 == 0 && j % 100 != 0))//判断date2[0]是否为闰年
			z2++;
	}
	day += abs((z2 + date2[2]) - (z1 + date1[2]));//abs表示取整数的绝对值
	return day;
}

void User::set_black_list() {
	int day;	// 超出还书的最大期限
	Record record;

	////已经在黑名单里 直接返回
	//if (this->get_user_state() == 0)
	//	return;

	fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "文件打开失败！" << endl;
		exit(0);
	}

	Book book;
	fstream fp_book("Book.dat", ios::binary | ios::in | ios::out);
	if (!fp_book) {
		cerr << "文件打开失败！" << endl;
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
			//获取当前时间
			char return_tmp[256];

			time_t time_seconds = time(0);
			struct tm now_time;
			localtime_s(&now_time, &time_seconds);

			time_t timep;//获得时间 
			time(&timep);
			strftime(return_tmp, sizeof(return_tmp), "%Y-%m-%d %H:%M:%S", &now_time);

			day = calculate_day(return_tmp, record.get_tmp());
			int deadline = day;
			if (book.get_renew_time() == 0)
				deadline = 30;
			else if (book.get_renew_time() == 1)
				deadline = 60;

			if (day > deadline) {
				this->set_user_state(0);	// 拉入黑名单
				User new_usr(this->get_id(), this->get_name(), this->get_gender(), this->get_grade(), this->get_majorID(), this->get_borrow_num(), this->get_history_borrow_num(), 0, this->get_status());
				new_usr.set_password(this->get_password());

				// 在User.dat文件修改state = 0
				fstream ofs("User.dat", ios::in | ios::binary | ios::out);
				if (!ofs) {
					cout << "文件打开失败！" << endl;
					return;
				}
				User usr;
				while (ofs.read((char*)&usr, sizeof(usr)))
				{
					if (usr.get_id() == this->get_id()) {
						//找到名字相同的用户位置
						int size = sizeof(usr);
						ofs.seekg(-size, ios::cur);
						ofs.write((char*)&new_usr, sizeof(new_usr));
						ofs.close();
						break;
					}
				}

				//在记录类文件中设置该条记录的record_state = 0
				Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state(), 0);
				record1.set_tmp(record.get_tmp());
				record1.set_record_state(0);
				//找到记录位置
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

	// 在User.dat文件修改state = 1
	fstream ofs("User.dat", ios::in | ios::binary | ios::out);
	if (!ofs) {
		cout << "文件打开失败！" << endl;
		return;
	}
	User usr;
	while (ofs.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == this->get_id()) {
			//找到名字相同的用户位置
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
		cerr << "文件打开失败！" << endl;
		exit(0);
	}

	while (fp.read((char*)&record, sizeof(Record))) {
		if (record.get_user_id() == this->get_id() && record.get_record_state() == 0) {
			// 获取当前书籍信息
			int book_id = record.get_id();

			fstream file("book.dat", ios::binary | ios::in | ios::out);
			if (!fp) {
				cerr << "文件打开失败！" << endl;
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
		cerr << ("文件打开失败！") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "当前未借阅书籍！" << endl;
		system("pause");
		return;
	}

	cout << "当前借阅信息如下：" << endl;
	fstream fshowbook("recording.dat", ios::binary | ios::in);
	if (!fshowbook) {
		cerr << ("文件打开失败！") << endl;
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
		cerr << "文件打开失败！" << endl;
		return;
	}
	int size = sizeof(Book);
	fp.seekg(-size, ios::end);
	fp.read((char*)&last_book, size);
	fp.close();
	int id = 0;
	cout << "请输入您要还的书的id：(输入0退出)" << endl;
	while (!(cin >> id) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入数据类型错误,请重新输入:" << endl;
	}
	if (id == 0)return;
	while (1)
	{
		if (id < 1 || id > last_book.get_id()) {
			cout << "输入有误请重新输入！" << endl;
			cin >> id;
		}
		else
			break;
	}
	fstream fsearch_id("book.dat", ios::binary | ios::in);
	if (!fsearch_id) {
		cerr << "文件打开失败！" << endl;
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
		cout << "该书未被借出！" << endl;
		system("pause");
		return;
	}
	if (book_for_search.get_state() == 2) {
		cout << "该书已丢失！" << endl;
		system("pause");
		return;
	}
	int choice = 0;
	cout << "您确定要还这本书吗：" << endl
		<< "1.是" << endl
		<< "2.否" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "输入错误请重新输入" << endl;
		}
		else
			break;
	}
	if (choice == 1) {
		Record record;
		fstream fp("recording.dat", ios::binary | ios::in | ios::out);
		if (!fp) {
			cerr << "文件打开失败！" << endl;
			exit(0);
		}
		while (fp.read((char*)&record, sizeof(Record))) {
			if (record.get_user_id() == this->get_id() && record.get_id() == id && record.get_book_state() == 0) {
				record.set_return_tmp();
				day = calculate_day(record.get_return_tmp(), record.get_tmp());
				if (day > 30 + book_for_search.get_renew_time() * 30) {//续借借书天数加30
					cout << "借书时间已超时，请到前台缴纳罚款" << endl;
					int d = 0;
					double money = 0;
					d = day - 13 + book_for_search.get_renew_time() * 30;
					money = d * 0.3;
					if (money > 30) {
						money = 30;
					}
					fstream fpfine("FineRecord.dat", ios::binary | ios::app);//写入罚款记录
					if (!fpfine) {
						cerr << "文件打开失败！" << endl;
						exit(0);
					}
					FR fr1(this->id, this->name, 1, money);
					fpfine.write((char*)&fr1, sizeof(FR));
					fpfine.close();
					cout << "罚款金额为：" << money << endl;
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
			cerr << "文件打开失败！" << endl;
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
		book_for_search.reset_renew_time();//重置借书次数为0
		freturn.write((char*)&book_for_search, sizeof(Book));
		freturn.close();
		cout << "还书成功！" << endl;
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
		cerr << ("文件打开失败！") << endl;
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
		cerr << "文件打开失败！" << endl;
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
		cerr << ("文件打开失败！") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "当前未借阅书籍不可进行书籍续借！" << endl;
		return;
	}

	cout << "当前借阅信息如下：" << endl;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "文件打开失败！" << endl;
		exit(0);
	}

	int ban_id = -1;
	while (fp.read((char*)&record, sizeof(Record))) {
		if (this->get_id() == record.get_user_id() && record.get_book_state() == 0) {
			record.show_record();
			if (record.get_record_state() == 0) {
				cout << "↑↑↑该书籍借阅时间已超过30天且期间未续借，已禁止续借！↑↑↑" << endl;
				ban_id = record.get_id();
			}
		}
	}

	fp.close();
	int id;
	cout << "请输入您要续借的书的id：(输入0退出)" << endl;
	while (1)
	{
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (id == 0)return;
		if (id == ban_id) {
			cout << "该书籍借阅时间已超过30天且期间未续借，已禁止续借！" << endl;
			cout << "请前往还书！" << endl;
			return;
		}

		Record record1;
		fstream fp2("recording.dat", ios::binary | ios::in);
		if (!fp2) {
			cerr << "文件打开失败！" << endl;
			exit(0);
		}
		int flag = 0;//标记在自己当前借书中是否找到该id
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
			cout << "该id的书未被您借阅！请重新输入！" << endl;
	}
	int choice = 0;
	cout << "您确定要续借这本书吗：" << endl
		<< "1.是" << endl
		<< "2.否" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "输入错误请重新输入" << endl;
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
			cerr << "文件打开失败！" << endl;
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
			cerr << "文件打开失败！" << endl;
			exit(0);
		}
		while (fprenew.read((char*)&book_for_search, sizeof(Book))) {
			if (book_for_search.get_id() == id && book_for_search.get_renew_time() < 1) {//最多续借一次
				book_for_search.set_renew_time();//续借次数加一
				int size = sizeof(Book);
				fprenew.seekp(-size, ios::cur);
				fprenew.write((char*)&book_for_search, sizeof(Book));
				cout << "续借成功！" << endl;
				break;
			}
			else if (book_for_search.get_id() == id && book_for_search.get_renew_time() >= 1) {
				cout << "该书续借已超过最大次数，无法续借！" << endl;
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
		cerr << ("文件打开失败！") << endl;
		exit(0);
	}
	while (fbook_now_number.read((char*)&record, sizeof(Record))) {
		if ((this->get_id() == record.get_user_id()) && (record.get_book_state() == 0)) {
			count++;
		}
	}
	fbook_now_number.close();
	if (count == 0) {
		cout << "当前未借阅书籍不可进行书籍丢失申报！" << endl;
		return;
	}

	cout << "当前借阅信息如下：" << endl;
	fstream fp("recording.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "文件打开失败！" << endl;
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
	cout << "请输入您要申报丢失的书的id：(输入0退出)" << endl;
	while (1)
	{
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (id == 0)return;
		Record record1;
		fstream fp2("recording.dat", ios::binary | ios::in);
		if (!fp2) {
			cerr << "文件打开失败！" << endl;
			exit(0);
		}
		int flag = 0;//标记在自己当前借书中是否找到该id
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
			cout << "该id的书未被您借阅！请重新输入！" << endl;
	}
	int choice = 0;
	cout << "您确定要对这本书申报丢失吗：" << endl
		<< "1.是" << endl
		<< "2.否" << endl;
	while (true) {
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (choice <= 0 || choice > 2) {
			cout << "输入错误请重新输入" << endl;
		}
		else
			break;
	}
	if (choice == 1)
	{
		Book book_for_search;//修改书籍状态
		fstream fsearch_id("book.dat", ios::binary | ios::in);
		if (!fsearch_id) {
			cerr << "文件打开失败！" << endl;
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
			cerr << "文件打开失败！" << endl;
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

		//修改记录书籍状态
		fstream fp51("recording.dat", ios::binary | ios::out | ios::in);
		if (!fp51) {
			cerr << "文件打开失败！" << endl;
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
		cout << "书籍丢失申报成功，请到前台缴纳罚款！罚款金额为：" << book_for_search.get_price() << endl;
		fstream fp30("FineRecord.dat", ios::binary | ios::app);//写入罚款记录
		if (!fp30) {
			cerr << "文件打开失败！" << endl;
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
		cerr << "文件打开失败！" << endl;
		return 0;
	}

	while (file1.read((char*)&fr1, sizeof(fr1)))
	{
		if (fr1.get_id() == search_id)
			return true;
	}
	return false;
}