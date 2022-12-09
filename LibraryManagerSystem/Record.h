#pragma once
#include <stdio.h>
#include <string>
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

	void set_user_name(char _username[]);

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
