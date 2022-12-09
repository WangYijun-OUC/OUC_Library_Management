#include <bits/stdc++.h>
using namespace std;

class Record
{
public:
	Record(){};
	Record(int new_id_book, char new_name_book[20], int new_id_user, char new_name_user[20], int new_state, int record_state);
	~Record() {};
	void recording();//保存
	int get_id();//获取书籍id
	char* get_book_name();//获取书籍名字
	int get_user_id();//获取用户id
	char* get_user_name();//获取用户名

	int get_book_state();//获取书籍状态
	int get_record_state();//获取记录状态
	
	void set_book_state(int new_state);//设置书籍状态
	void set_record_state(int new_state);//设置记录状态

	void show_record();//展示记录

	void set_return_tmp();//设置归还时间
	char* get_return_tmp();//获取归还时间

	char* get_tmp();//获取时间
	void set_tmp(string tmp);//设置借书时间

private:
	int id_book; // 书籍编号
	char name_book[20]; // 书名，不超过20个字符，一个汉字等于2个字符
	int id_user;//学号
	char name_user[20];//姓名
	int book_state;//书的状态
	int record_state;//记录的状态 0为黑名单记录 1为正常记录
	char tmp[256];//时间
	char return_tmp[256];//归还时间
};

Record::Record(int new_id_book, char new_name_book[20], int new_id_user, char new_name_user[20], int new_book_state, int new_record_state) {
	id_book = new_id_book;
	strcpy_s(name_book, new_name_book);
	id_user = new_id_user;
	for (int i = 0; i < 20; i++) {
		name_user[i] = new_name_user[i];
	}
	book_state = new_book_state;
	record_state = new_record_state;

	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);

	time_t timep;//获得时间
	time(&timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &now_time);
	strcpy_s(return_tmp, "XXXX-XX-XX XX:XX:XX");
}
int Record::get_id()
{
	return id_book;
}
char* Record::get_book_name()
{
	return name_book;
}
int Record::get_user_id()
{
	return id_user;
}
char* Record::get_user_name()
{
	return name_user;
}
int Record::get_book_state()
{
	return book_state;
}
int Record::get_record_state()
{
	return record_state;
}
char* Record::get_tmp()
{
	return tmp;
}

void Record::set_return_tmp() {
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);

	time_t timep;//获得时间 
	time(&timep);
	strftime(return_tmp, sizeof(return_tmp), "%Y-%m-%d %H:%M:%S", &now_time);
}

void Record::set_book_state(int new_state) {
	this->book_state = new_state;
}

void Record::set_record_state(int new_state) {
	this->record_state = new_state;
}

char* Record::get_return_tmp() {
	return return_tmp;
}

void Record::set_tmp(string _tmp)
{
	for (int i = 0; i < _tmp.length(); i++)
		tmp[i] = _tmp[i];
}

void Record::show_record() {
	if (this->get_id() != 3)
	{
		cout << "----------------------------------------------------------------" << endl;
		cout << "书籍编号：" << this->get_id() << "\t书名：" << this->get_book_name() <<"\t用户id:"<<this->get_user_id()<< "\t借书时间：" << this->get_tmp() << "\t还书时间：" << this->get_return_tmp() << "\t状态：";
		if (book_state == 0)
			cout << "未归还";
		if (book_state == 1)
			cout << "已归还";
		if (book_state == 2)
			cout << "书籍丢失";
		cout << endl;
	}
}

int main() {
    Record record;
    fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "文件打开失败" << endl;
		exit(0);
	}

    while (fp.read((char*)&record, sizeof(Record))) {
		cout << "id_book" << " " << record.get_id() << endl;
        cout << "book_name" << " " << record.get_book_name() << endl;
        cout << "借书时间" << " " << record.get_tmp() << endl;
        cout << "还书时间" << " " << record.get_return_tmp() << endl;
        cout << "使用用户" << " " << record.get_user_id() << endl;
        cout << "使用用户" << " " << record.get_user_name() << endl;
		cout << "书籍状态" << " " << record.get_book_state() << endl;
		cout << "记录状态" << " " << record.get_record_state() << endl;
		cout << endl;
        //record.set_tmp("2022-01-09 19:14:27");

		// Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state(), 1);
		// record1.set_tmp("2022-08-24 00:31:45");
		// //record1.set_record_state(0);

		// if(record.get_id() == 8) {
		// 	//找到记录位置
		// 	int size = sizeof(record);
		// 	fp.seekg(-size, ios::cur);
		// 	fp.write((char*)&record1, sizeof(record1));
		// }

			
	}
    // fp.close();

    // Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state());
    // record1.set_tmp("2022-01-09 19:14:27");

    // fstream file("recording1.dat", ios::in | ios::binary | ios::out);
	// if (!file) {
	// 	cerr << "文件打开失败" << endl;
	// 	return 0;
	// }
	// file.write((char*)&record1, sizeof(record1));
	// file.close();


    return 0;
}