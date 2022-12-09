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
		void set_name(string name);			// ���ù���Ա�û�����Library.cpp)
		void set_password(string password);	// ���ù���Ա����  ��Library.cpp)
		char* get_name();					// ��ȡ����Ա�û�����OperationRecord_User.cpp)
		void show_menu();     		// ��ʾ�˵���   ---------------1003ʵ�ֺ���
		void add_book();			// ����鼮        
		void delete_book();			// ɾ���鼮        
		void edit_book(); 			// �༭�鼮
		void search_book();			// ��ѯ�鼮       
		User register_user();		// ע��
		void add_user();			// ����û�
		void delete_user();			// ɾ���û�
		//User *FindUserLocate(int id);		// ��λ�û�
		void search_user();			// �����û�         
		bool check_user(User& user);          //����û��Ƿ���ע�Ტ����-------1003�����
		void edit_user_password();     // �޸��û�����
		void show_record();     // չʾ��¼
		bool save_password(int id, char password[]);		// ��������
		// Record / int search_record();     // ��ѯ��¼
		void exit();              // ע��
		void show_operation_record_book();//չʾͼ�������¼
		void show_operation_record_user();//չʾ�û�������¼
		void deal_fine_record();
		void search_black_list();		//��ѯ���к�������Ա
		void add_black_list();			//���������
		void remove_black_list();		//�Ƴ�������
		void add_old_book();//���������鼮
	private:
		char name[20];				// ����Ա����
		static char password[20];	//����Ա����
};
#endif // !MANAGER_H