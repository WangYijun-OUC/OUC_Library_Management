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
bool check(int date)//判断是否是日期
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
		std::cout << " 0 : 退出" << std::endl;
		std::cout << " 1 : 添加书籍" << std::endl;
		std::cout << " 2 : 删除书籍" << std::endl;
		std::cout << " 3 : 编辑书籍" << std::endl;
		std::cout << " 4 : 查询书籍" << std::endl;
		std::cout << " 5 : 添加用户" << std::endl;
		std::cout << " 6 : 删除用户" << std::endl;
		std::cout << " 7 : 搜索用户" << std::endl;
		std::cout << " 8 : 修改用户密码" << std::endl;
		std::cout << " 9 : 展示借阅记录" << std::endl;
		std::cout << " 10 : 展示管理员操作记录" << std::endl;
		std::cout << "请选择:";
		*/
		std::cout << " ********************************************************" << std::endl;
		std::cout << " *          欢迎登录管理员系统！                        *" << std::endl;
		std::cout << " *      请输入相关数字进行具体操作                      *" << std::endl;
		std::cout << " *                                                      *" << std::endl;
		std::cout << " *           1 : 添加书籍                               *" << std::endl;
		std::cout << " *           2 : 删除书籍                               *" << std::endl;
		std::cout << " *           3 : 编辑书籍                               *" << std::endl;
		std::cout << " *           4 : 查询书籍                               *" << std::endl;
		std::cout << " *           5 : 添加用户                               *" << std::endl;
		std::cout << " *           6 : 删除用户                               *" << std::endl;
		std::cout << " *           7 : 搜索用户                               *" << std::endl;
		std::cout << " *           8 : 修改用户密码                           *" << std::endl;
		std::cout << " *           9 : 展示借阅记录                           *" << std::endl;
		std::cout << " *           10 : 展示管理员操作记录                    *" << std::endl;
		std::cout << " *           11 : 处理欠款记录                          *" << std::endl;
		std::cout << " *           12 : 查看黑名单                            *" << std::endl;
		std::cout << " *           13 : 添加已有书籍                          *" << std::endl;
		std::cout << " *           0：退出操作                                *" << std::endl;
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
			cout << "输入有误请重新输入！" << endl;
			system("pause");
			continue;
		}
	}
}

// 增加用户
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
			cerr << "文件打开失败！" << endl;
			break;
		}

		//获取最后一个ID
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
			cout << "请输入新增用户姓名（不超过10位）:" << endl;
			while (!(cin >> new_name) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入类型有误请重新输入:" << endl;
			}
			if (new_name.length() > 10)
				cout << "输入名字过长，请重新输入！" << endl;
			else
				break;
		}

		memset(name, 0, sizeof(name));
		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];

		//if (strcmp(name, "0") == 0)return;

		/*while (true) {
			cout << "请输入新增用户密码(不超过10位):" << endl;
			cin >> new_passwd;
			if (new_passwd.length() > 10)
				cout << "输入密码过长，请重新输入！" << endl;
			else
				break;
		}

		for (int i = 0; i < new_passwd.length(); i++)
			passwd[i] = new_passwd[i];*/

		while (true) {
			cout << "请选择新增用户性别:" << endl;
			cout << "1 - 男" << endl;
			cout << "2 - 女" << endl;
			//cout << "0 - 退出" << endl;

			while (!(cin >> new_gender) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误，请重新输入：" << endl;
			}

			//if (new_gender == 0)return;

			memset(gender, 0, sizeof(gender));
			if (new_gender == 1) {
				strcpy_s(gender, strlen("男") + 1, "男");
				break;
			}
			else if (new_gender == 2) {
				strcpy_s(gender, strlen("女") + 1, "女");
				break;
			}
			else {
				cout << "输入错误 请重新输入！" << endl;
			}
		}

		while (true) {
			cout << "请输入新增用户年级( 请输入完整年份 如2020）" << endl;
			while (!(cin >> new_grade) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误，请重新输入：" << endl;
			}

			//if (new_grade == 0)return;

			int count = 0;	// 计算输入年级是否为4位
			int _grade = new_grade;
			while (_grade)
			{
				count++;
				_grade = _grade / 10;
			}
			if (count != 4 || (new_grade <= 2010 || new_grade > 2022))
				cout << "请输入正确年份！" << endl;
			else
				break;
		}
		grade = new_grade;


		while (true) {
			cout << "请选择新增用户院系:" << endl;
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
			//cout << "0 - 退出" << endl;

			//cin >> new_major;

			while (!(cin >> new_major) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入类型错误,请重新输入！" << endl;
			}

			//if (new_major == 0)return;

			if (new_major < 1 || new_major > 20) {
				cout << "选择错误，请重新选择！" << endl;
			}
			else
				break;
		}

		cout << "请输入用户身份（1-本科生 2-研究生）" << endl;
		while (1)
		{
			while (!(cin >> new_status) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}

			//if (new_status == 0)return;

			if (new_status == 1 || new_status == 2)
				break;
			else
				cout << "身份输入错误，请重新输入" << endl;
		}

		cout << "确认新增用户信息：" << endl;
		cout << "ID:" << id << endl;
		cout << "姓名：" << name << endl;
		//cout << "密码:" << passwd << endl;
		cout << "年级:" << grade << endl;
		cout << "性别:" << gender << endl;
		cout << "院系:" << user.get_major(new_major) << endl;
		cout << "身份:";
		if (new_status == 1)
			cout << "本科生" << endl;
		else
			cout << "研究生" << endl;
		cout << "是否新增？" << endl;
		cout << "1 - 确认新增用户" << endl;
		cout << "2 - 我输入的信息有误，请求返回修改" << endl;
		//cout << "0 - 退出" << endl;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据错误,请重新输入:" << endl;
		}

		//if (choice == '0')return;

		if (choice == '1')
			break;
		else
			system("cls");
			cout << "请重新输入!" << endl;
	}

	if (choice == '1')
		// 选择新增用户
	{
		fstream ofs("User.dat", ios::app | ios::binary);
		if (!ofs)
		{
			cerr << "文件打开失败！" << endl;
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

		cout << "注册新用户成功！" << endl;// ---------------1003修改
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
			cerr << "文件打开失败！" << endl;
			break;
		}

		//获取最后一个ID
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
			cout << "请输入新增用户姓名（不超过10位，输入0退出）:" << endl;
			while (!(cin >> new_name) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入类型有误请重新输入:" << endl;
			}
			if (new_name.length() > 10)
				cout << "输入名字过长，请重新输入！" << endl;
			else
				break;
		}

		memset(name, 0, sizeof(name));
		for (int i = 0; i < new_name.length(); i++)
			name[i] = new_name[i];

		if (strcmp(name, "0") == 0)return;

		/*while (true) {
			cout << "请输入新增用户密码(不超过10位):" << endl;
			cin >> new_passwd;
			if (new_passwd.length() > 10)
				cout << "输入密码过长，请重新输入！" << endl;
			else
				break;
		}

		for (int i = 0; i < new_passwd.length(); i++)
			passwd[i] = new_passwd[i];*/

		while (true) {
			cout << "请选择新增用户性别:" << endl;
			cout << "1 - 男" << endl;
			cout << "2 - 女" << endl;
			cout << "0 - 退出" << endl;

			while (!(cin >> new_gender) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误，请重新输入：" << endl;
			}

			if (new_gender == 0)return;

			memset(gender, 0, sizeof(gender));
			if (new_gender == 1) {
				strcpy_s(gender, strlen("男") + 1, "男");
				break;
			}
			else if (new_gender == 2) {
				strcpy_s(gender, strlen("女") + 1, "女");
				break;
			}
			else {
				cout << "输入错误 请重新输入！" << endl;
			}
		}

		while (true) {
			cout << "请输入新增用户年级( 请输入完整年份 如2020 输入0退出）" << endl;
			while (!(cin >> new_grade) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误，请重新输入：" << endl;
			}

			if (new_grade == 0)return;

			int count = 0;	// 计算输入年级是否为4位
			int _grade = new_grade;
			while (_grade)
			{
				count++;
				_grade = _grade / 10;
			}
			if (count != 4 || (new_grade <= 2010 || new_grade > 2022))
				cout << "请输入正确年份！" << endl;
			else
				break;
		}
		grade = new_grade;
		while (true) {
			cout << "请选择新增用户院系:" << endl;
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

			//cin >> new_major;

			while (!(cin >> new_major) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入选项错误,请重新输入！" << endl;
			}

			if (new_major == 0)return;

			if (new_major < 1 || new_major > 20) {
				cout << "选择错误，请重新选择！" << endl;
			}
			else
				break;
		}

		cout << "请输入用户身份（1-本科生 2-研究生 0-退出）" << endl;
		while (1)
		{
			while (!(cin >> new_status) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}

			if (new_status == 0)return;

			if (new_status == 1 || new_status == 2)
				break;
			else
				cout << "身份输入错误，请重新输入" << endl;
		}

		cout << "确认新增用户信息：" << endl;
		cout << "ID:" << id << endl;
		cout << "姓名：" << name << endl;
		//cout << "密码:" << passwd << endl;
		cout << "年级:" << grade << endl;
		cout << "性别:" << gender << endl;
		cout << "院系:" << user.get_major(new_major) << endl;
		cout << "身份:";
		if (new_status == 1)
			cout << "本科生" << endl;
		else
			cout << "研究生" << endl;
		cout << "是否新增？" << endl;
		cout << "1 - 确认新增用户" << endl;
		cout << "2 - 我输入的信息有误，请求返回修改" << endl;
		cout << "0 - 退出" << endl;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据错误,请重新输入:" << endl;
		}

		if (choice == '0')return;

		if (choice == '1')
			break;
		else
			system("cls");
			cout << "请重新输入!" << endl;
	}

	if (choice == '1')
		// 选择新增用户
	{
		fstream ofs("User.dat", ios::app | ios::binary);
		if (!ofs)
		{
			cerr << "文件打开失败！" << endl;
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

		cout << "注册新用户成功！" << endl;// ---------------1003修改

		// 添加新增用户记录到管理员操作记录类
		fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
		if (!file)
		{
			cerr << "文件打开失败!" << endl;
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
		// 依次遍历读取user信息
		userfile.read((char*)&tmp_usr, sizeof(tmp_usr));

		if (tmp_usr.get_id() == id)
		{
			user = new User(tmp_usr.get_id(), tmp_usr.get_name(), tmp_usr.get_gender(), tmp_usr.get_grade(), tmp_usr.get_majorID(), tmp_usr.get_borrow_num(), tmp_usr.get_history_borrow_num(), tmp_usr.get_user_state(), tmp_usr.get_status());
			user->set_password(tmp_usr.get_password());
			// load_record(user1.get_id());			// 读取用户借阅记录（暂未实现该函数）
			userfile.close();
			return user;							//返回用户信息
		}
	}
}

void Manager::delete_user()
//删除用户
{
	int delete_id;	//要删除的id
	User* user, usr;
	while (true)
	{
		cout << "请输入需要删除用户的ID (长度小于10，输入0退出)：" << endl;

		while (!(cin >> delete_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据错误,请重新输入:" << endl;
		}
		//cin >> delete_id;

		if (delete_id == 0)return;

		if (delete_id != 0)
		{
			user = FindUserLocate(delete_id);
			if (user->get_id() == delete_id && user->get_user_state() != 2)
				// 找到且该用户不是已删除状态
			{
				user->show_user();
				if (user->get_borrow_num()) {//还有未还书籍
					cout << "该用户还有书籍未归还，不可删除！" << endl;
					return;
				}
				else if (user->get_fine_record_id(delete_id)) {
					cout << "该用户还有罚款未结清，不可删除！" << endl;
					return;
				}
				else
				{
					cout << "是否删除该用户?" << endl;
					cout << "1 - 是" << endl;
					cout << "2 - 否" << endl;
					int choice;
					//cin >> choice;
					while (!(cin >> choice) || cin.peek() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "输入数据错误,请重新输入:" << endl;
					}

					if (choice == 1) {
						user->set_user_state(2);

						fstream file1("User.dat", ios::in | ios::binary | ios::out);
						if (!file1)
						{
							cerr << "文件打开失败！" << endl;
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
						// 从User.dat文件中删除
						/*fstream file1("Temp.dat", ios::out | ios::binary);	//打开一个用于保存删除后记录的文件
						if (!file1)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						fstream file2("User.dat", ios::in | ios::binary);
						if (!file2)
						{
							cerr << "文件打开失败！" << endl;
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

						fstream file3("User.dat", ios::out | ios::binary);		//用于将temp.dat中的内容复制过来
						if (!file3)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						fstream file4("Temp.dat", ios::in | ios::binary);		//用于将内容赋值给book.dat
						if (!file4)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						User usr1;
						while (file4.read((char*)&usr1, sizeof(usr1)))//复制temp.dat中的数据给book.dat
						{
							file3.write((char*)&usr1, sizeof(usr1));
						}
						file3.close();
						file4.close();


						// 从recording.dat文件中删除
						Record record;
						fstream file5("Temp.dat", ios::out | ios::binary);	//打开一个用于保存删除后记录的文件
						if (!file5)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						fstream file6("recording.dat", ios::in | ios::binary);
						if (!file6)
						{
							cerr << "文件打开失败！" << endl;
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

						fstream file7("User.dat", ios::out | ios::binary);		//用于将temp.dat中的内容复制过来
						if (!file7)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						fstream file8("Temp.dat", ios::in | ios::binary);		//用于将内容赋值给book.dat
						if (!file8)
						{
							cerr << "文件打开失败！" << endl;
							return;
						}

						Record record1;
						while (file7.read((char*)&record1, sizeof(record1)))//复制temp.dat中的数据给book.dat
						{
							file8.write((char*)&record1, sizeof(record1));
						}
						file7.close();
						file8.close();
						*/

						// 添加删除用户记录到管理员操作记录类
						fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
						if (!file)
						{
							cerr << "文件打开失败!" << endl;
						}
						OR_U or_u(user->get_id(), user->get_name(), user->get_grade(), user->get_majorID(), 1, user->get_user_state(), this->get_name());
						file.write((char*)&or_u, sizeof(or_u));
						file.close();

						cout << "删除成功！" << endl;
						//system("pause");
						/*
						FILE* pfd = NULL;
						errno_t err = fopen_s(&pfd, "Temp.dat", "w+");
						if (!err)
						{
							//printf("已清空文件！\n");
							fclose(pfd);
						}
						*/


						return;
					}
					else if (choice == 2) {
						cout << "已取消删除" << endl;
						system("pause");
						break;
					}
					else {
						cout << "选择错误，请重新选择！" << endl;
						system("pause");
						break;
					}
				}
			}
			else {
				cout << "该ID不存在！" << endl;
				system("pause");
				return;
			}

		}
		else
			cout << "输入ID值为有误 请重新输入！" << endl;
	}
	// 删除成功
}

bool Manager::save_password(int id, char password[])
// 在文件中保存用户密码
{
	fstream ofs("User.dat", ios::in | ios::binary | ios::out);
	if (!ofs) {
		cout << "文件打开失败！" << endl;
		return false;
	}

	User* user, usr;
	user = FindUserLocate(id);

	// 记录用户原始密码
	char ori_password[21];
	strcpy_s(ori_password, strlen(user->get_password()) + 1, user->get_password());

	User new_usr(id, user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), user->get_user_state(), user->get_status());
	new_usr.set_password(password);

	while (ofs.read((char*)&usr, sizeof(usr)))
	{
		if (usr.get_id() == id) {
			//找到名字相同的用户位置
			int size = sizeof(usr);
			ofs.seekg(-size, ios::cur);
			ofs.write((char*)&new_usr, sizeof(new_usr));
			ofs.close();

			// 添加修改用户记录到管理员操作记录类
			fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
			if (!file)
			{
				cerr << "文件打开失败!" << endl;
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
		if (c == 0) break;  //如果到字符串尾则说明该字符串没有中文字符
		if (c & 0x80)        //如果字符高位为1且下一字符高位也是1则有中文字符
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
			cout << "输入数据错误,请重新输入:" << endl;
		}
		search_id = _search_id;
		if (_search_id == 0)return 1;
		else if (_search_id < 2022100) {
			cout << "输入有误请重新输入！" << endl;
			system("pause");
		}
		else {
			fstream fp("User.dat", ios::binary | ios::in);
			if (!fp) {
				cerr << "文件打开失败！" << endl;
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
				cout << "查无此人请重新输入！" << endl;
				//system("pause");
			}
			else
				break;
		}
	}
	return 0;
}

void Manager::edit_user_password()
//修改密码
{
	int search_id = 0;				// 要修改的id
	char password[10] = {};			// 修改的密码
	cout << "请输入修改用户的ID(输入0退出)" << endl;
	if (check_id(search_id)) {
		return;
	}
	User user;						// 
	while (true)
	{
		string passwd;
		while (true) {
			cout << "请输入新密码（长度不可超过10位 同时不能低于5位 输入0退出）：" << endl;
			//string key1;
			while (!(cin >> passwd) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入类型错误,请重新输入！" << endl;
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
				cout << "输入密码不符合要求，请重新输入！" << endl;
			else break;
		}

		cout << "确认新密码：" << endl;
		string confim_passwd;
		cin >> confim_passwd;
		if (passwd == confim_passwd)//两次密码输入一致
		{
			char c[10] = {};

			for (int i = 0; i < passwd.length(); i++)
				password[i] = passwd[i];

			if (save_password(search_id, password)) {
				cout << "修改成功！" << endl;
				break;
			}
			else {
				cout << "修改失败！" << endl;
				//system("pause");
			}
		}
		else {
			cout << "两次输入不一致，请重新输入！" << endl;
			//system("pause");
		}

	}
}

bool Manager::check_user(User& _user) {
	User* user;
	cout << "请输入用户ID：" << endl;
	int id;
	while (!(cin >> id) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入id错误,请重新输入:" << endl;
	}

	//if (id == 0)return;

	user = FindUserLocate(id);

	//cout << user->get_id() << " " << user->get_password();
	// 赋值（_user与user不同类）
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

	//_user.set_black_list();		// 登录时设置黑名单
	if (user->get_id() == id && user->get_user_state() != 2)//找到
	{
		string password;
		for (int i = 3; i >= 0; i--) {
			cout << "请输入密码：" << endl;
			cin >> password;
			if (password == string(user->get_password()))
				return true;
			cout << "密码错误，你还有" << i << "次机会" << endl;
		}
		return false;
	}
	else {
		cout << "查无此人！" << endl;
		system("pause");
		user = nullptr;
		return false;
	}
}

void Manager::search_user()
// 查找用户
{
	char a[50] = { 0 };
	while (true)
	{
		cout << "请选择查询信息：" << endl;
		cout << "1、用户姓名" << endl;
		cout << "2、用户ID" << endl;
		cout << "3、用户年级" << endl;
		cout << "4、用户院系" << endl;
		cout << "0、取消" << endl;

		char choice;

		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误,请重新输入！" << endl;
		}


		int num = 0;
		// 找到的同名用户数量
		string name;
		char tmp_major[20];
		// Book book;
		User* user, usr;

		ifstream ifs("User.dat", ios::in | ios::binary);
		if (!ifs)
			cout << "文件打开失败！" << endl;

		switch (choice)
		{
		case '1'://按姓名
			cout << "请输入用户姓名：(输入0退出)" << endl;
			while (!(cin >> name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<< "数据类型错误, 请重新输入！" << endl;
			}
			for (int i = 0; i < name.length(); i++) {
				a[i] = name[i];
			}

			if (strcmp(a, "0") == 0)return;

			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_name() == name && usr.get_user_state() != 2)
				// 找到名字且未被删除
				{
					user = FindUserLocate(usr.get_id());
					num++;
					cout << "已找到该用户 信息如下：" << endl;
					user->show_user();
					//cout << "该用户信息：" << endl;
					//user->show();
					////cout << "正在借书信息：" << endl;
					//show_now_record();
					////cout << "历史借书记录：" << endl;
					//show_past_record();

				}
			}

			if (num == 0)//未找到
			{
				cout << "查无此人！" << endl;
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
		case '2'://按用户ID
			cout << "请输入用户ID：(输入0退出)" << endl;
			int id;
			while (!(cin >> id) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入id错误,请重新输入:" << endl;
			}
			//cin >> id;

			if (id == 0)return;

			user = FindUserLocate(id);
			if (user->get_id() == id && user->get_user_state() != 2)//找到
			{
				cout << "已找到该用户 信息如下：" << endl;
				user->show_user();
				//user->show();
				////cout << "正在借书信息：" << endl;
				//show_now_record();
				////cout << "历史借书记录：" << endl;
				//show_past_record();

				ifs.close();
				//system("pause");
				return;
			}
			else {
				cout << "查无此人！" << endl;
				ifs.close();
				system("pause");
				break;

			}

			break;
		case '3'://按年级
			cout << "请输入用户所在年级（输入完整年份 输入0退出）" << endl;
			int grade;
			while (true) {
				while (!(cin >> grade) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入年级错误,请重新输入:" << endl;
				}

				if (grade == 0)return;

				int count = 0;	// 计算输入年级是否为4位
				int _grade = grade;
				while (_grade)
				{
					count++;
					_grade = _grade / 10;
				}
				if (count != 4)
					cout << "请输入完整年份！" << endl;
				else
					break;
			}

			{int num = 0;	// 统计学生数量
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_grade() == grade && usr.get_user_state() != 2) {	//判断年级是否相同
					num++;
					cout << "找到所有" << grade << "级学生的图书馆信息" << endl;
					cout << "第" << num << "个学生：" << endl;
					usr.show_user();
					cout << endl;

				}
			}

			if (num == 0)//未找到
			{
				cout << "查找不到任何信息！" << endl;
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
		case '4':// 按用户院系 ·······这个我想后期加上模糊查找 所以先按精准查找写
			int new_major;
			while (true) {
				cout << "请选择查找用户院系:" << endl;
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

				if (choice == 0)return;

				if (new_major <= 1 && new_major >= 20) {
					cout << "选择错误，请重新选择！" << endl;
				}
				else
					break;
			}

			//if (new_major >= 1 && new_major <= 10)
			//	break;


			{int num = 0;	// 统计学生数量
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_majorID() == new_major && usr.get_user_state() != 2) {	//判断年级是否相同
					num++;
					cout << "找到所有" << usr.get_major(new_major) << "学生的图书馆信息" << endl;
					cout << "第" << num << "个学生：" << endl;
					usr.show_user();
					cout << endl;

				}
			}

			if (num == 0)//未找到
			{
				cout << "查找不到任何信息！" << endl;
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
			cout << "输入有误！" << endl;
			system("pause");
			break;
		}
		}
		ifs.close();
	}
}

void Manager::search_black_list() {
	cout << "所有在黑名单里的用户" << endl;
	User user;
	int choice;
	fstream fp("User.dat", ios::binary | ios::in);
	if (!fp) {
		cerr << "文件打开失败！" << endl;
		return;
	}

	int num = 0;
	while (fp.read((char*)&user, sizeof(User))) {
		if (user.get_user_state() == 0) {
			user.show_user();
			num++;
		}
	}

	
	cout << "请选择操作：" << endl;
	if(num)
		cout << "1 - 删除黑名单用户" << endl;
	cout << "0 - 返回" << endl;
	//cin >> choice;
	while (!(cin >> choice) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "数据类型错误,请重新输入！" << endl;
	}

	while (true) {
		if (choice == 1) {
			remove_black_list();
			break;
		}
		else if (choice == 0)
			return;
		else
			cout << "输入错误 请重新输入！" << endl;
	}

}

/*
void Manager::add_black_list() {
	cout << "请输入添加用户的学号或姓名" << endl;
	cout << "1 - 姓名" << endl;
	cout << "2 - 学号" << endl;
	cout << "0 - 退出" << endl;
	int choice;
	char a[50] = { 0 };
	while (1)
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入!" << endl;
		}

		if (choice == 0)return;

		if (choice == 1 || choice == 2)
			break;
		else
			cout << "输入错误，请重新输入!" << endl;
	}

	int num = 0;
	// 找到的同名用户数量
	int id;
	string name;
	char tmp_major[20];
	// Book book;
	User* user, usr;
	int choice1;

	fstream ifs("User.dat", ios::in | ios::binary | ios::out);
	if (!ifs)
		cout << "文件打开失败！" << endl;

	Record record;
	fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "文件打开失败！" << endl;
		return;
	}

	int flag = 0;

	switch (choice)
	{
	case 1://按姓名
		flag = 0;
		cout << "请输入用户姓名：(输入0退出)" << endl;
		while (!(cin >> name) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}
		for (int i = 0; i < name.length(); i++) {
			a[i] = name[i];
		}

		if (strcmp(a, "0") == 0)return;

		while (ifs.read((char*)&usr, sizeof(usr)))
		{
			if (usr.get_name() == name && usr.get_user_state() != 2)
			// 找到名字且未被删除
			{
				if (num == 0)
					cout << "找到如下用户：" << endl;
				user = FindUserLocate(usr.get_id());
				num++;
				user->show_user();
			}
		}
		ifs.close();

		if (num == 0)//未找到
		{
			cout << "查无此人！" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//system("pause");
			break;
		}
		else
		{
			cout << "请输入对应学号 将该用户加入黑名单：(输入0退出)" << endl;
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
				cout << "该用户不存在满足黑名单的记录！" << endl;
				return;
			}

			cout << "是否将该用户加入黑名单？" << endl;
			cout << "1 - 是" << endl;
			cout << "2 - 否" << endl;
			cin >> choice1;

			if (choice1 == 2) {
				cout << "已取消添加！" << endl;
				return;
			}
			else if (choice1 == 1 && user->get_user_state() == 0) {
				cout << "该用户已经在黑名单中，请勿重复添加！" << endl;
				break;
			}

			fstream ifs("User.dat", ios::in | ios::binary | ios::out);
			if (!ifs)
				cout << "文件打开失败！" << endl;
			//找到记录位置
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_name() == name && usr.get_id() == id && usr.get_user_state() != 2)
					// 找到名字
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "添加黑名单成功！" << endl;

					// 添加新增用户记录到管理员操作记录类
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
					if (!file)
					{
						cerr << "文件打开失败!" << endl;
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
	case 2://按用户ID
		cout << "请输入用户学号：(输入0退出)" << endl;
		int id;
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入id错误,请重新输入:" << endl;
		}
		//cin >> id;

		if (id == 0)return;

		user = FindUserLocate(id);

		if (user->get_id() == id && user->get_user_state() != 2)//找到
		{
			cout << "已找到该用户 信息如下：" << endl;
			user->show_user();

			while (fp.read((char*)&record, sizeof(Record))) {
				if (record.get_user_id() == user->get_id() && record.get_record_state() == 0) {
					flag++;
				}
			}
			fp.close();
			if (!flag) {
				cout << "该用户不存在满足黑名单的记录！" << endl;
				return;
			}

			cout << "是否将该用户加入黑名单？" << endl;
			cout << "1 - 是" << endl;
			cout << "2 - 否" << endl;
			cin >> choice1;
			if (choice1 == 2) {
				cout << "已取消添加！" << endl;
				return;
			}
			else if (choice1 == 1 && user->get_user_state() == 0) {
				cout << "该用户已经在黑名单中，请勿重复添加！" << endl;
				system("pause");
				break;
			}

			User new_user(user->get_id(), user->get_name(), user->get_gender(), user->get_grade(), user->get_majorID(), user->get_borrow_num(), user->get_history_borrow_num(), 0, user->get_status());
			new_user.set_password(user->get_password());

			//找到记录位置
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_id() == id)
					// 找到名字
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "添加黑名单成功！" << endl;

					// 添加新增用户记录到管理员操作记录类
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
					if (!file)
					{
						cerr << "文件打开失败!" << endl;
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
			cout << "查无此人！" << endl;
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
	cout << "请输入删除用户的学号(输入0退出)" << endl;

	int num = 0;
	// 找到的同名用户数量
	User* user, usr;
	int choice1;

	fstream ifs("User.dat", ios::in | ios::binary | ios::out);
	if (!ifs)
		cout << "文件打开失败！" << endl;

	while (true) {
		//按用户ID
		int id;
		while (!(cin >> id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入id错误,请重新输入:" << endl;
		}
		//cin >> id;

		if (id == 0)return;

		user = FindUserLocate(id);
		if (user->get_id() == id && user->get_user_state() == 0)//找到
		{
			cout << "已找到该用户 信息如下：" << endl;
			user->show_user();

			cout << "是否将该用户移除黑名单？" << endl;
			cout << "1 - 是" << endl;
			cout << "2 - 否" << endl;
			cin >> choice1;
			if (choice1 == 2) {
				cout << "已取消删除！" << endl;
				return;
			}

			Record record;
			fstream fp("recording.dat", ios::binary | ios::in | ios::out);
			if (!fp) {
				cerr << "文件打开失败！" << endl;
				return;
			}

			while (fp.read((char*)&record, sizeof(Record))) {
				if (record.get_user_id() == user->get_id() && record.get_record_state() == 0 && record.get_book_state() == 0) {
					cout << "该用户还有逾期未归还的书籍 无法移除黑名单！" << endl;
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

			//找到记录位置
			while (ifs.read((char*)&usr, sizeof(usr)))
			{
				if (usr.get_id() == id)
					// 找到名字
				{
					int size = sizeof(usr);
					ifs.seekg(-size, ios::cur);
					ifs.write((char*)&new_user, sizeof(new_user));
					cout << "移除黑名单成功！" << endl;

					// 添加新增用户记录到管理员操作记录类
					fstream file("OperationRecord_User.dat", ios::binary | ios::app);//保存操作记录
					if (!file)
					{
						cerr << "文件打开失败!" << endl;
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
			cout << "输入ID错误，请重新输入！" << endl;
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

char Manager::password[20] = "aa123123";//管理员密码初始化

void Manager::add_book()//添加书籍
{
	fstream file10("book.dat", ios::binary | ios::in);//找出最后一个id
	if (!file10)
	{
		cerr << "文件打开失败！" << endl;
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
	int book_state = 1;//可借
	char press[20] = { 0 };
	string press1;
	int publication_date;
	double price;
	char category[20] = { 0 };
	string category1;
	//int num;
	long long isbn;
	while (1)//书名容错
	{
		cout << "请输入要添加的书籍名称(字符长度不超过19 输入0退出)" << endl;
		while (!(cin >> name1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < name1.length(); i++) {
			a[i] = name1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (name1.length() > 19)
			cout << "长度非法，请重新输入" << endl;
		else
			break;
	}
	while (1)//作者名容错
	{
		cout << "请输入作者名(字符长度小于19 输入0退出)" << endl;
		while (!(cin >> writer1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < writer1.length(); i++) {
			a[i] = writer1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (writer1.length() > 19)
			cout << "长度非法请重新输入！" << endl;
		else
			break;
	}
	while (1)//出版社容错
	{
		cout << "请输入出版社(字符长度小于19 输入0退出)" << endl;
		while (!(cin >> press1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < press1.length(); i++) {
			a[i] = press1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (press1.length() > 19)
			cout << "长度非法请重新输入！" << endl;
		else
			break;
	}
	while (1)//出版日期容错
	{
		cout << "请输入出版日期（例如20020908 输入0退出）" << endl;
		while (!(cin >> publication_date) || cin.peek() != '\n')//确保输入的数据类型正确，以下作用相同
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (publication_date == 0)return;

		if (get_length(publication_date) != 8)
			cout << "格式非法请重新输入！" << endl;
		else
		{
			if (check(publication_date))
			{
				if (publication_date / 10000 > 1900 && publication_date / 10000 < 2022)
					break;
				else
					cout << "出版年份不合法！" << endl;
			}
			else
				cout << "输入不是日期格式！请重新输入！" << endl;
		}
	}

	while (1)//价格容错
	{
		cout << "请输入价格 输入0退出" << endl;
		while (!(cin >> price) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (price == 0)return;

		int count = 0;	// 计算输入金额是否合理
		double _price = price;
			
		if (price <= 0)
			cout << "价格非法请重新输入！" << endl;
		else
			break;
	}
	int cchoice;
	cout << "请选择书籍类别:" << endl;
	cout << "1-马列主义" << endl;
	cout << "2-哲学、宗教" << endl;
	cout << "3-社会科学总论" << endl;
	cout << "4-政治、法律" << endl;
	cout << "5-军事" << endl;
	cout << "6-经济" << endl;
	cout << "7-文化、教育、体育" << endl;
	cout << "8-自然科学总论" << endl;
	cout << "9-其他" << endl;
	cout << "0 - 退出" << endl;
	while (1)//choice容错
	{
		while (!(cin >> cchoice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非数字,请重新输入:" << endl;
		}
		if (cchoice == 0)
			return;
		if (cchoice < 0 || cchoice > 9)
			cout << "输入不在范围内，请重新输入！" << endl;
		else
			break;
	}
	if (cchoice == 1)
		strcpy_s(category, "马列主义");
	else if (cchoice == 2)
		strcpy_s(category, "哲学、宗教");
	else if (cchoice == 3)
		strcpy_s(category, "社会科学总论");
	else if (cchoice == 4)
		strcpy_s(category, "政治、法律");
	else if (cchoice == 5)
		strcpy_s(category, "军事");
	else if (cchoice == 6)
		strcpy_s(category, "经济");
	else if (cchoice == 7)
		strcpy_s(category, "文化、教育、体育");
	else if (cchoice == 8)
		strcpy_s(category, "自然科学总论");
	else if (cchoice == 9)
		strcpy_s(category, "其他");

	/*while (1)//数量容错
	{
		cout << "请输入这本书的添加数量" << endl;
		while (!(cin >> num) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非数字,请重新输入:" << endl;
		}
		if (price <= 0)
			cout << "数量非法请重新输入！" << endl;
		else
			break;
	}
	*/
	while (1)//isbn容错
	{
		cout << "请输入该书的isbn号(要求为13位 输入0退出)" << endl;
		while (!(cin >> isbn) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (isbn == 0)return;

		if (get_length(isbn) != 13)
			cout << "长度非法请重新输入！" << endl;
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
	while (1)//num容错
	{
		cout << "请输入该书籍的数量 输入0退出" << endl;
		while (!(cin >> num1) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (num1 == 0)return;

		int count = 0;	// 计算输入数量是否合理
		int _num = num1;
		while (_num)
		{
			count++;
			_num = _num / 10;
		}
		if (count >= 5) {
			cout << "请输入正确的数量！" << endl;
			continue;
		}

		if (num1 < 0)
			cout << "数量非法请重新输入！" << endl;
		else
			break;
	}
	int j;
	fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);//保存操作记录
	if (!fp11)
	{
		cerr << "文件打开失败" << endl;
		return;
	}
	fstream file("book.dat", ios::binary | ios::app);
	if (!file)
	{
		cerr << "文件打开失败" << endl;
		return;
	}
	OR_B or1(book1.get_id(), book1.get_name(), 0);
	for (j = 0; j < num1; j++)//批量添加书籍和管理员操作记录
	{
		file.write((char*)&book1, sizeof(book1));
		fp11.write((char*)&or1, sizeof(or1));
		id++;
		or1.set_book_id(id);
		book1.set_id(id);
	}
	file.close();
	cout << "书籍添加成功！" << endl;
	fp11.close();
}

void Manager::search_book()
{
	id_a[10000] = { 0 };
	cnt_a = 0;
	Book book1;
	int choice;
	cout << "请选择查询的方式，1.按id查询  2.按作者查询  3.类别查询  4.按书名查询  0.退出" << endl;
	while (1)//choice容错
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (choice == 0)return;
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
			break;
		else
			cout << "输入不在选项内" << endl;
	}
	if (choice == 1)
	{
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
			cout << "请输入要查询的书籍id(输入0退出)" << endl;
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
		while (1)//作者名容错
		{
			cout << "请输入作者名(字符长度小于19，输入0退出)" << endl;
			while (!(cin >> search_writer) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入类型有误请重新输入:" << endl;
			}
			if (search_writer.length() > 19)
				cout << "长度非法请重新输入！" << endl;
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
			if (strcmp(book1.get_writer(), writer1) == 0 && book1.get_state() != 3)//判断作者名是否相等
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
		cout << "请选择书籍类别:" << endl;
		cout << "1-马列主义" << endl;
		cout << "2-哲学、宗教" << endl;
		cout << "3-社会科学总论" << endl;
		cout << "4-政治、法律" << endl;
		cout << "5-军事" << endl;
		cout << "6-经济" << endl;
		cout << "7-文化、教育、体育" << endl;
		cout << "8-自然科学总论" << endl;
		cout << "9-其他" << endl;
		cout << "0-退出" << endl;
		while (1)//choice容错
		{
			while (!(cin >> cchoice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入非数字,请重新输入:" << endl;
			}
			if (cchoice == 0)
				return;
			if (cchoice <= 0 || cchoice > 9)
				cout << "数量非法请重新输入！" << endl;
			else
				break;
		}
		if (choice == 0)return;
		if (cchoice == 1)
			strcpy_s(category1, "马列主义");
		else if (cchoice == 2)
			strcpy_s(category1, "哲学、宗教");
		else if (cchoice == 3)
			strcpy_s(category1, "社会科学总论");
		else if (cchoice == 4)
			strcpy_s(category1, "政治、法律");
		else if (cchoice == 5)
			strcpy_s(category1, "军事");
		else if (cchoice == 6)
			strcpy_s(category1, "经济");
		else if (cchoice == 7)
			strcpy_s(category1, "文化、教育、体育");
		else if (cchoice == 8)
			strcpy_s(category1, "自然科学总论");
		else if (cchoice == 9)
			strcpy_s(category1, "其他");
		fstream file1("book.dat", ios::in | ios::binary);
		int p2 = 0;
		while (file1.read((char*)&book1, sizeof(book1)))
		{
			if (strcmp(book1.get_category(), category1) == 0 && book1.get_state() != 3)//判断分类名是否相等
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
		while (1)//书名容错
		{
			cout << "请输入书名(字符长度小于19 输入0退出)" << endl;
			while (!(cin >> search_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "数据类型错误, 请重新输入！" << endl;
			}

			char a[50] = { 0 };
			for (int i = 0; i < search_name.length(); i++) {
				a[i] = search_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (search_name.length() > 19)
				cout << "长度非法请重新输入！" << endl;
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
			if (strcmp(book1.get_name(), name1) == 0 && book1.get_state() != 3)//判断书名是否相等
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
		cout << "不存在该书籍！" << endl;

}

void Manager::delete_book()
{
	int find1 = 0;
	search_book();
	if (cnt_a == 0)
		return;
	int delete_id;
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
		cout << "请输入要删除的书籍id 输入0退出" << endl;
		while (!(cin >> delete_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (delete_id == 0)return;

		if (delete_id < 0 || delete_id > book11.get_id())
			cout << "输入id不存在，请重新输入" << endl;
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
	while (file.read((char*)&book1, sizeof(book1)))//寻找删除的书籍并进行删除操作
	{
		if (book1.get_id() == delete_id)
		{
			find = 1;
			cout << "找到的书籍信息如下:" << endl;
			book1.show_book();
			break;
		}
	}
	if (find == 1)//找到
	{
		if (book1.get_state() == 0)//已经借出
		{
			cout << "该书已借出，不可删除！" << endl;
			return;
		}
		int choice;
		cout << endl;
		cout << "是否删除该书籍？1-删除 2-取消";
		while (1)//choice容错
		{
			while (!(cin >> choice) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}
			if (choice == 1 || choice == 2)
				break;
		}
		if (choice == 1)//删除
		{
			int size;
			size = sizeof(Book);
			file.seekp(-size, ios::cur);
			book1.set_state(3);
			file.write((char*)&book1, sizeof(Book));
			file.close();
			cout << "删除成功！" << endl;
			fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);
			if (!fp11)
			{
				cerr << "文件打开失败" << endl;
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
	else//未找到
	{
		cout << "未找到该书籍！" << endl;
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
		cout << "请输入要修改的书籍id 输入0退出" << endl;
		while (!(cin >> edit_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (edit_id == 0)return;
		if (edit_id < 0 || edit_id > book11.get_id())
			cout << "输入id不存在，请重新输入" << endl;
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
				cout << "输入id不在查询结果中,请重新输入！" << endl;
		}
	}
	fstream file66("book.dat", ios::binary | ios::in | ios::out);
	if (!file66)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	Book book66;
	while (file66.read((char*)&book66, sizeof(book66)))//寻找删除的书籍并进行删除操作
	{
		if (book66.get_id() == edit_id && book66.get_state() == 0)
		{
			cout << "该书已借出，不可修改！";
			return;
		}
	}
	file66.close();
	int id = edit_id;
	cout << "请输入修改后的书籍信息" << endl;
	char name[20] = { 0 };
	string name1;
	char writer[20] = { 0 };
	string writer1;
	int book_state;//可借
	char press[20] = { 0 };
	string press1;
	int publication_date;
	double price;
	char category[20] = { 0 };
	long long isbn;
	while (1)//书名容错
	{
		cout << "请输入要添加的书籍名称(字符长度不超过19 输入0退出)" << endl;
		while (!(cin >> name1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < name1.length(); i++) {
			a[i] = name1[i];
		}

		if (strcmp(a, "0") == 0)return;
		if (name1.length() > 19)
			cout << "长度非法，请重新输入" << endl;
		else
			break;
	}
	while (1)//作者名容错
	{
		cout << "请输入作者名(字符长度小于19 输入0退出)" << endl;
		while (!(cin >> writer1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < writer1.length(); i++) {
			a[i] = writer1[i];
		}

		if (strcmp(a, "0") == 0)return;
		if (writer1.length() > 19)
			cout << "长度非法请重新输入！" << endl;
		else
			break;
	}
	while (1)//出版社容错
	{
		cout << "请输入出版社(字符长度小于19 输入0退出)" << endl;
		while (!(cin >> press1) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "数据类型错误, 请重新输入！" << endl;
		}

		char a[50] = { 0 };
		for (int i = 0; i < press1.length(); i++) {
			a[i] = press1[i];
		}

		if (strcmp(a, "0") == 0)return;

		if (writer1.length() > 19)
			cout << "长度非法请重新输入！" << endl;
		else
			break;
	}
	while (1)//出版日期容错
	{
		cout << "请输入出版日期（例如20020908 输入0退出）" << endl;
		while (!(cin >> publication_date) || cin.peek() != '\n')//确保输入的数据类型正确，以下作用相同
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (publication_date == 0)return;

		if (get_length(publication_date) != 8)
			cout << "格式非法请重新输入！" << endl;
		else
		{
			if (check(publication_date))
			{
				if (publication_date / 10000 > 1900 && publication_date / 10000 < 2022)
					break;
				else
					cout << "出版年份不合法！" << endl;
			}
			else
				cout << "输入不是日期格式！请重新输入！" << endl;
		}
	}

	while (1)//价格容错
	{
		cout << "请输入价格（输入0退出）" << endl;
		while (!(cin >> price) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (press == 0)return;

		if (price < 0)
			cout << "价格非法请重新输入！" << endl;
		else
			break;
	}
	int cchoice;
	cout << "请选择书籍类别:" << endl;
	cout << "1-马列主义" << endl;
	cout << "2-哲学、宗教" << endl;
	cout << "3-社会科学总论" << endl;
	cout << "4-政治、法律" << endl;
	cout << "5-军事" << endl;
	cout << "6-经济" << endl;
	cout << "7-文化、教育、体育" << endl;
	cout << "8-自然科学总论" << endl;
	cout << "9-其他" << endl;
	cout << "0-退出" << endl;
	while (1)//cchoice容错
	{
		while (!(cin >> cchoice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非数字,请重新输入:" << endl;
		}

		if (cchoice == 0)return;

		if (cchoice < 0 || cchoice > 9)
			cout << "数量非法请重新输入！" << endl;
		else
			break;
	}
	if (cchoice == 1)
		strcpy_s(category, "马列主义");
	else if (cchoice == 2)
		strcpy_s(category, "哲学、宗教");
	else if (cchoice == 3)
		strcpy_s(category, "社会科学总论");
	else if (cchoice == 4)
		strcpy_s(category, "政治、法律");
	else if (cchoice == 5)
		strcpy_s(category, "军事");
	else if (cchoice == 6)
		strcpy_s(category, "经济");
	else if (cchoice == 7)
		strcpy_s(category, "文化、教育、体育");
	else if (cchoice == 8)
		strcpy_s(category, "自然科学总论");
	else if (cchoice == 9)
		strcpy_s(category, "其他");

	/*while (1)//数量容错
	{
		cout << "请输入这本书的添加数量" << endl;
		while (!(cin >> num) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非数字,请重新输入:" << endl;
		}
		if (price <= 0)
			cout << "数量非法请重新输入！" << endl;
		else
			break;
	}
	*/
	while (1)//isbn容错
	{
		cout << "请输入该书的isbn号(要求为13位 输入0退出)" << endl;
		while (!(cin >> isbn) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (isbn == 0)return;

		if (get_length(isbn) != 13)
			cout << "长度非法请重新输入！" << endl;
		else
			break;
	}
	while (1)//状态容错
	{
		cout << "请输入修改后的书籍状态(0-已借出 1-可借阅 2-丢失 3-退出)" << endl;
		while (!(cin >> book_state) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (book_state == 3)return;
		if (book_state == 0 || book_state == 1 || book_state == 2)
			break;
		else
			cout << "状态非法请重新输入！" << endl;
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
		cerr << "文件打开失败！" << endl;
		return;
	}
	while (file2.read((char*)&book2, sizeof(book2))) //确定要修改的书籍在文件中的位置，用i记录
	{
		i++;
		if (book2.get_id() == book3.get_id())
		{
			break;
		}
	}
	Book edit_book(book3.get_id(), book3.get_name(), book3.get_writer(), book3.get_state(), book3.get_press(), book3.get_publication_date(), book3.get_price(), book3.get_category(), book3.get_isbn(), book3.get_renew_time());//修改后的书籍
	file2.seekg(sizeof(edit_book) * (i - 1), ios::beg);//更改指针位置
	file2.write((char*)&edit_book, sizeof(edit_book));//覆盖原来的信息
	cout << "书籍信息修改成功！" << endl;
	file2.close();
	fstream fp11("OperationRecord_Book.dat", ios::binary | ios::app);//保存操作记录
	if (!fp11)
	{
		cerr << "文件打开失败" << endl;
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
		cerr << "文件打开失败" << endl;
		return;
	}
	Record record1;
	cout << "书籍借阅信息如下：" << endl;
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
		cerr << "文件打开失败" << endl;
		return;
	}
	OR_B or1;
	cout << "书籍操作信息如下：" << endl;
	while (file.read((char*)&or1, sizeof(or1)))
	{
		cout << "书籍ID：" << or1.get_book_id() << "\t书名：" << or1.get_book_name() << "\t管理员名称：" << or1.get_manager_name() << "\t操作时间：" << or1.get_time() << "\t操作方式：";
		if (or1.get_state() == 0)
			cout << "添加书籍";
		if (or1.get_state() == 1)
			cout << "删除书籍";
		if (or1.get_state() == 2)
			cout << "修改书籍";
		cout << endl;
	}
}

void Manager::show_operation_record_user() {
	fstream file("OperationRecord_User.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "文件打开失败" << endl;
		return;
	}

	OR_U or_u;
	cout << "用户操作信息如下：" << endl;
	while (file.read((char*)&or_u, sizeof(or_u)))
	{
		if (or_u.get_user_state() == 1|| or_u.get_user_state() == 2) {
			if (or_u.get_state() == 0) {
				cout << "添加用户：    学号：" << or_u.get_id() << setw(12) << "姓名：" << or_u.get_name() << setw(12) << "年级：" << or_u.get_grade() << setw(12) << "专业：" << or_u.get_major() << setw(20) << "操作者：" << or_u.get_manager_name() << setw(12) << "操作时间：" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 1) {
				cout << "删除用户：    学号：" << or_u.get_id() << setw(12) << "姓名：" << or_u.get_name() << setw(12) << "年级：" << or_u.get_grade() << setw(12) << "专业：" << or_u.get_major() << setw(20) << "操作者：" << or_u.get_manager_name() << setw(12) << "操作时间：" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 2) {
				cout << "修改用户密码：学号：" << or_u.get_id() << setw(12) << "姓名：" << or_u.get_name() << setw(12) << "原始密码：" << or_u.get_ori_password() << setw(12) << "修改密码：" << or_u.get_now_password() << setw(20) << "操作者：" << or_u.get_manager_name() << setw(12) << "操作时间：" << or_u.get_time() << endl;
			}
		}
		else if (or_u.get_user_state() == 0) {
			if (or_u.get_state() == 0) {
				cout << "添加用户于黑名单：    学号：" << or_u.get_id() << setw(12) << "姓名：" << or_u.get_name() << setw(12) << "年级：" << or_u.get_grade() << setw(12) << "专业：" << or_u.get_major() << setw(20) << "操作者：" << or_u.get_manager_name() << setw(12) << "操作时间：" << or_u.get_time() << endl;
			}
			else if (or_u.get_state() == 1) {
				cout << "删除用户于黑名单：    学号：" << or_u.get_id() << setw(12) << "姓名：" << or_u.get_name() << setw(12) << "年级：" << or_u.get_grade() << setw(12) << "专业：" << or_u.get_major() << setw(20) << "操作者：" << or_u.get_manager_name() << setw(12) << "操作时间：" << or_u.get_time() << endl;
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
	cout << "请选择查询的方式，1.按用户id查询  2.按用户名查询  0.退出" << endl;
	int cnt = 0;
	int search_id;
	string search_name;
	char name1[20] = { 0 };
	while (1)//choice容错
	{
		while (!(cin >> choice) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}

		if (choice == 0)return;

		if (choice == 1 || choice == 2)
			break;
		else
			cout << "输入不在选项内" << endl;
	}

	if (choice == 1)
	{
		fstream file11("User.dat", ios::binary | ios::in);//找出最后一个id
		if (!file11)
		{
			cerr << "文件打开失败！" << endl;
			return;
		}
		User user11;
		int size = (int)sizeof(User);
		file11.seekg(-size, ios::end);
		file11.read((char*)&user11, sizeof(user11));
		file11.close();
		while (1)//id容错
		{
			cout << "请输入要查询用户id 输入0退出" << endl;
			while (!(cin >> search_id) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入数据类型错误,请重新输入:" << endl;
			}

			if (search_id == 0)return;

			if (search_id < 0 || search_id > user11.get_id())
				cout << "输入id不存在，请重新输入" << endl;
			else
				break;
		}
		fstream file1("FineRecord.dat", ios::in | ios::binary);
		if (!file1)
		{
			cerr << "文件打开失败！" << endl;
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
			cout << "该用户无欠款信息" << endl;
			return;
		}
		else
		{
			cout << endl;
			cout << "是否一次结清了所有欠款？（1-是  2-否  0-退出）" << endl;
			int choice1;
			while (1)//choice1容错
			{
				while (!(cin >> choice1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入数据类型错误,请重新输入:" << endl;
				}

				if (choice1 == 0)return;

				if (choice1 == 1 || choice1 == 2)
					break;
				else
					cout << "输入不在选项内" << endl;
			}
			if (choice1 == 2)
				return;
			else
			{
				FR fr2;
				fstream file1("temp.dat", ios::out | ios::binary);//打开一个用于保存删除后记录的文件
				if (!file1)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				fstream file2("FineRecord.dat", ios::in | ios::binary);
				if (!file2)
				{
					cerr << "文件打开失败！" << endl;
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
				fstream file3("FineRecord.dat", ios::out | ios::binary);//用于将temp.dat中的内容复制过来
				if (!file3)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				fstream file4("temp.dat", ios::in | ios::binary);//用于将内容赋值给FineRecord.dat
				if (!file4)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				FR fr3;
				while (file4.read((char*)&fr3, sizeof(fr3)))//复制temp.dat中的数据给FineReocrd.dat
				{
					file3.write((char*)&fr3, sizeof(fr3));
				}
				file3.close();
				file4.close();
				cout << "处理成功！" << endl;
			}
		}
	}
	if (choice == 2)
	{
		int id1;
		while (1)//用户名容错
		{
			cout << "请输入用户名(字符长度小于19 输入0退出)" << endl;
			while (!(cin >> search_name) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "数据类型错误, 请重新输入！" << endl;
			}

			char a[50] = { 0 };
			for (int i = 0; i < search_name.length(); i++) {
				a[i] = search_name[i];
			}

			if (strcmp(a, "0") == 0)return;

			if (search_name.length() > 19)
				cout << "长度非法请重新输入！" << endl;
			else
				break;
		}

		for (int i = 0; i < search_name.length(); i++)
			name1[i] = search_name[i];
		fstream file1("FineRecord.dat", ios::in | ios::binary);
		if (!file1)
		{
			cerr << "文件打开失败！" << endl;
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
			}//判断名字是否相等

		}
		file1.close();
		if (cnt == 0)
		{
			cout << "无欠款信息" << endl;
			return;
		}
		else
		{
			int find2 = 0;
			cout << "请输入要处理的用户id 输入0退出" << endl;
			while (1)//id1容错
			{
				while (!(cin >> id1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入数据类型错误,请重新输入:" << endl;
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
					cout << "输入id不在查询结果内，请重新输入！" << endl;
				else
					break;
			}
			cout << endl;
			cout << "是否一次结清了所有欠款？（1-是  2-否  0-退出）" << endl;
			int choice1;
			while (1)//choice1容错
			{
				while (!(cin >> choice1) || cin.peek() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入数据类型错误,请重新输入:" << endl;
				}

				if (choice1 == 0)return;

				if (choice1 == 1 || choice1 == 2)
					break;
				else
					cout << "输入不在选项内" << endl;
			}
			if (choice1 == 2)
				return;
			else
			{
				FR fr2;
				fstream file1("temp.dat", ios::out | ios::binary);//打开一个用于保存删除后记录的文件
				if (!file1)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				fstream file2("FineRecord.dat", ios::in | ios::binary);
				if (!file2)
				{
					cerr << "文件打开失败！" << endl;
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
				fstream file3("FineRecord.dat", ios::out | ios::binary);//用于将temp.dat中的内容复制过来
				if (!file3)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				fstream file4("temp.dat", ios::in | ios::binary);//用于将内容赋值给FineRecord.dat
				if (!file4)
				{
					cerr << "文件打开失败！" << endl;
					return;
				}
				FR fr3;
				while (file4.read((char*)&fr3, sizeof(fr3)))//复制temp.dat中的数据给FineReocrd.dat
				{
					file3.write((char*)&fr3, sizeof(fr3));
				}
				file3.close();
				file4.close();
				cout << "处理成功！" << endl;
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
		cout << "请输入要添加的书籍id 输入0退出" << endl;
		while (!(cin >> add_id) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入数据类型错误,请重新输入:" << endl;
		}
		if (add_id == 0)return;
		if (add_id < 0 || add_id > book11.get_id())
			cout << "输入id不存在，请重新输入" << endl;
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
				cout << "输入id不在查询结果中,请重新输入！" << endl;
		}
	}
	fstream file("book.dat", ios::binary | ios::in);
	if (!file)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	Book book1;
	int find = 0;
	while (file.read((char*)&book1, sizeof(book1)))//寻找要添加书籍的id
	{
		if (book1.get_id() == add_id)
		{
			find = 1;
			cout << "找到的书籍信息如下:" << endl;
			book1.show_book();
			break;
		}
	}
	file.close();
	if (find == 1)
	{
		cout << "请输入要添加的数量 输入0退出" << endl;
		int num3;
		while (1)//数量容错
		{
			while (!(cin >> num3) || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入非数字,请重新输入:" << endl;
			}

			if (num3 == 0)return;

			if (num3 < 0)
				cout << "数量非法请重新输入！" << endl;
			else
				break;
		}
		book1.set_id(book11.get_id() + 1);
		fstream file55("book.dat", ios::binary | ios::app);
		if (!file55)
		{
			cerr << "文件打开失败！" << endl;
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
		cout << "书籍添加成功!" << endl;
		file55.close();
	}
	else
	{
		cout << "未找到该书籍！" << endl;
		return;
	}
}


