#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include<time.h>
#include "Record.h"
using namespace std;
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

void Record::recording() {
	Record record1 = Record(id_book, name_book, id_user, name_user, book_state, record_state);
	fstream file("recording.dat", ios::binary | ios::app);
	if (!file) {
		cerr << "文件打开失败" << endl;
		return;
	}
	file.write((char*)&record1, sizeof(record1));
	file.close();
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
	if (this->get_book_state() != 3)
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

void Record::set_user_name(char _username[]) {
	strcpy_s(this->name_user,strlen(_username) + 1,  _username);
}