#include <iostream>
#include <map>
#include <cstring>
#include "OperationRecord_User.h"
using namespace std;
OR_U::OR_U(int _user_id, char _name[], int _grade, int _major, int _state, int _user_state, char _manager_name[])
{
	id = _user_id;
	strcpy_s(this->name, strlen(_name) + 1, _name);
	grade = _grade;
	majorID = _major;
	state = _state;
	strcpy_s(this->manager_name, strlen(_manager_name) + 1, _manager_name);
	user_state = _user_state;

	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);
	time_t timep;//获得时间 
	time(&timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &now_time);
}

int OR_U::get_id() {
	return id;
}

char* OR_U::get_name()
{
	return name;
}

int OR_U::get_grade() {
	return grade;
}

char* OR_U::get_time()
{
	return tmp;
}

string OR_U::get_major() {
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

	return id_major[majorID];
}

char* OR_U::get_ori_password() {
	return ori_password;
}

void OR_U::set_ori_password(char passwd[20]) {
	strcpy_s(this->ori_password, strlen(passwd) + 1, passwd);
}

char* OR_U::get_now_password() {
	return now_password;
}

void OR_U::set_now_password(char passwd[20]) {
	strcpy_s(this->now_password, strlen(passwd) + 1, passwd);
}

char* OR_U::get_manager_name()
{
	return manager_name;
}

int OR_U::get_state()
{
	return state;
}

int OR_U::get_user_state() {
	return user_state;
}