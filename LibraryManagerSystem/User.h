#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
#include <map>
#include "Book.h"
#include "Record.h"
#include "FineRecord.h"
#include "Manager.h"
extern int id_a[10000];
extern int cnt_a;

class User {
public:
	User() {};
	User(int new_id, char new_name[], char new_gender[], int new_grade, int new_major, int new_borrow_num, int new_history_borrow_num, int new_state,int new_status);
	~User() {};
	void show_user();					//չʾѧ����Ϣ
	void show_menu();					//չʾ�û��˵�������Ϊ�����û��ͺ������û���
	int get_id();						//��ȡ�û�id
	char* get_name();					//��ȡ�û���
	char* get_gender();					//��ȡ�û��Ա�
	int get_grade();					//��ȡ�û��꼶
	string get_major(int _majorID);		//��ȡ�û�רҵ
	int get_majorID();					//��ȡ�û�רҵID
	int get_borrow_num();				//��ȡ��������
	int get_history_borrow_num();		//��ȡ��ʷ��������
	char* get_password();				//��ȡ�û�����

	void set_id(int _id);				//�����û�id
	void set_name(char _name[]);		//�����û���
	void set_gender(char gender[]);		//�����û��Ա�
	void set_grade(int _grade);			//�����û��꼶
	void set_major(string major);		//�����û�רҵ
	void set_majorID(int major);		//�����û�רҵID
	void set_password(char _passwd[]);	//�����û�����
	void set_borrow_num(int _num);		//�����û���������
	void set_history_borrow_num(int _num);//������ʷ��������

	int get_user_state();				//��ȡ�û�״̬
	void set_user_state(int state);		//�û�״̬��0Ϊ��������1Ϊ����
	void set_black_list();				//���������
	void show_delay_book();				//չʾ����δ���鼮

	void borrow_book();					//����
	void return_book();					//����
	void inquire_history();				//��ѯ��ʷ�����¼
	void inquire_now();					//��ѯ��ǰ�������Ϣ
	bool save_user_info();				//���������Ϣ
	//void change_password();			//�޸����루���滻Ϊ�޸���Ϣ��
	void change_info();					//�޸ĸ�����Ϣ
	void renew();						//�����鼮
	void declare();						//ͼ�鶪ʧ�걨
	int get_status();					//��ȡ���
	bool get_fine_record_id(int search_id);//�鿴���û��Ƿ���Ƿ����Ϣ
	void set_status(int _status);		//���ñ����������о���
	
private:
	int id;					//ѧ��
	char name[11];			//����
	char gender[10];		//�Ա�
	int grade;				//�꼶
	int majorID;			//רҵ��
	char password[21];		//����
	int borrow_num;			//��ǰ��������
	int history_borrow_num;	//��ʷ��������
	int user_state;			//�û�״̬��0Ϊ�����ڣ�1Ϊ���ڣ�2Ϊɾ��
	int status;				//�û����0Ϊ��������1Ϊ�о���
};
#endif // !USER_H
