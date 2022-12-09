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
	time_t timep;//���ʱ�� 
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