#include <bits/stdc++.h>
using namespace std;

class User {
public:
	User() {};
	User(int new_id, char new_name[], char new_gender[], int new_grade, int new_major, int new_borrow_num, int new_history_borrow_num, int new_state,int new_status);
	~User() {};
	void show_user();					//展示学生信息
	void show_menu();					//展示用户菜单栏（分为正常用户和黑名单用户）
	int get_id();						//获取用户id
	char* get_name();					//获取用户名
	char* get_gender();					//获取用户性别
	int get_grade();					//获取用户年级
	string get_major(int _majorID);		//获取用户专业
	int get_majorID();					//获取用户专业ID
	int get_borrow_num();				//获取借书数量
	int get_history_borrow_num();		//获取历史借书数量
	char* get_password();				//获取用户密码

	void set_id(int _id);				//设置用户id
	void set_name(char _name[]);		//设置用户名
	void set_gender(char gender[]);		//设置用户性别
	void set_grade(int _grade);			//设置用户年级
	void set_major(string major);		//设置用户专业
	void set_majorID(int major);		//设置用户专业ID
	void set_password(char _passwd[]);	//设置用户密码
	void set_borrow_num(int _num);		//设置用户借书数量
	void set_history_borrow_num(int _num);//设置历史借书数量

	int get_user_state();				//获取用户状态
	void set_user_state(int state);		//用户状态，0为黑名单，1为存在
	void set_black_list();				//拉入黑名单
	void show_delay_book();				//展示逾期未还书籍

	void borrow_book();					//借书
	void return_book();					//还书
	void inquire_history();				//查询历史借书记录
	void inquire_now();					//查询当前借书的信息
	bool save_user_info();				//保存个人信息
	//void change_password();			//修改密码（已替换为修改信息）
	void change_info();					//修改个人信息
	void renew();						//续借书籍
	void declare();						//图书丢失申报
	int get_status();					//获取身份
	bool get_fine_record_id(int search_id);//查看该用户是否有欠款信息
	void set_status(int _status);		//设置本科生还是研究生
	
private:
	int id;					//学号
	char name[11];			//姓名
	char gender[10];		//性别
	int grade;				//年级
	int majorID;			//专业号
	char password[21];		//密码
	int borrow_num;			//当前借书数量
	int history_borrow_num;	//历史借书数量
	int user_state;			//用户状态，0为被拉黑，1为存在，2为删除
	int status;				//用户身份0为本科生，1为研究生
};

int User::get_id() {
	return id;
}

char* User::get_name() {
	return name;
}

char* User::get_gender() {
	return gender;
}

int User::get_grade() {
	return grade;
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
	return borrow_num;
}

char* User::get_password() {
	return password;
}

int User::get_history_borrow_num() {
	return this->history_borrow_num;
}

int User::get_user_state() {
	return user_state;
}

int main() {
    //int id = 2;
    User tmp_usr;
    ifstream userfile("User.dat", ios::in | ios::binary);
	
	while (userfile.read((char*)&tmp_usr, sizeof(User))) {
        cout << "id:" << tmp_usr.get_id() << endl;
		cout << "name:" << tmp_usr.get_name() << endl;
		cout << "password:" << tmp_usr.get_password() << endl;
		cout << "age:" << tmp_usr.get_grade() << endl;
		cout << "state:" << tmp_usr.get_user_state() << endl;
		cout << "gender:" << tmp_usr.get_gender() << endl;
		cout << "major:" << tmp_usr.get_majorID() << endl;
		cout << "major:" << tmp_usr.get_major(tmp_usr.get_majorID()) << endl;
		cout << endl;

	}

	userfile.close();
}
