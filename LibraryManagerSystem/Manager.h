#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <CString>
#include "User.h"
#include "Book.h"
using namespace std;

class User;
class Manager
{
	public:
		Manager() {};
		Manager(char newName[20], char newPassword[20]);
		~Manager() {};
		void set_name(string name);			// 设置管理员用户名（Library.cpp)
		void set_password(string password);	// 设置管理员密码  （Library.cpp)
		char* get_name();					// 获取管理员用户名（OperationRecord_User.cpp)
		void show_menu();     		// 显示菜单栏   ---------------1003实现函数
		void add_book();			// 添加书籍        
		void delete_book();			// 删除书籍        
		void edit_book(); 			// 编辑书籍
		void search_book();			// 查询书籍       
		User register_user();		// 注册
		void add_user();			// 添加用户
		void delete_user();			// 删除用户
		//User *FindUserLocate(int id);		// 定位用户
		void search_user();			// 搜索用户         
		bool check_user(User& user);          //检查用户是否已注册并返回-------1003新添加
		void edit_user_password();     // 修改用户密码
		void show_record();     // 展示记录
		bool save_password(int id, char password[]);		// 保存密码
		// Record / int search_record();     // 查询记录
		void exit();              // 注销
		void show_operation_record_book();//展示图书操作记录
		void show_operation_record_user();//展示用户操作记录
		void deal_fine_record();
		void search_black_list();		//查询所有黑名单人员
		void add_black_list();			//加入黑名单
		void remove_black_list();		//移除黑名单
		void add_old_book();//增加已有书籍
	private:
		char name[20];				// 管理员名称
		static char password[20];	//管理员密码
};
#endif // !MANAGER_H