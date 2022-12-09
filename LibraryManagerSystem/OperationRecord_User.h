#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class OR_U
{
public:
	OR_U(int _user_id, char _user_name[], int _grade, int _major, int _state, int _user_state, char _manager_name[]);
	OR_U() {}
	int get_id();							//获取用户id
	char* get_name();						//获取用户名
	char* get_time();						//获取时间
	int get_grade();						//获取年级
	string get_major();						//获取用户专业
	char* get_ori_password();				//获取修改前密码
	void set_ori_password(char passwd[20]);	//设置用户修改前密码
	void set_now_password(char passwd[20]);	//设置用户修改后密码
	char* get_now_password();				//获取用户现在密码
	char* get_manager_name();				//获取管理员名字
	int get_state();						//获取操作类型
	int get_user_state();					//获取用户状态
private:
	int id;									//学号
	char name[10];							//姓名
	int grade;								//年级
	int majorID;							//专业号
	char ori_password[20];					//修改前密码
	char now_password[20];					//修改后密码
	char tmp[256];							//操作时间
	char manager_name[20];					//操作人id
	int user_state;							//用户状态
	int state;								//操作类型
};