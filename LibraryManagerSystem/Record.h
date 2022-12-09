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
	void recording();//����
	int get_id();//��ȡ�鼮id
	char* get_book_name();//��ȡ�鼮����
	int get_user_id();//��ȡ�û�id
	char* get_user_name();//��ȡ�û���

	int get_book_state();//��ȡ�鼮״̬
	int get_record_state();//��ȡ��¼״̬
	
	void set_book_state(int new_state);//�����鼮״̬
	void set_record_state(int new_state);//���ü�¼״̬

	void show_record();//չʾ��¼

	void set_return_tmp();//���ù黹ʱ��
	char* get_return_tmp();//��ȡ�黹ʱ��

	char* get_tmp();//��ȡʱ��
	void set_tmp(string tmp);//���ý���ʱ��

	void set_user_name(char _username[]);

private:
	int id_book; // �鼮���
	char name_book[20]; // ������������20���ַ���һ�����ֵ���2���ַ�
	int id_user;//ѧ��
	char name_user[20];//����
	int book_state;//���״̬
	int record_state;//��¼��״̬ 0Ϊ��������¼ 1Ϊ������¼
	char tmp[256];//ʱ��
	char return_tmp[256];//�黹ʱ��
};
