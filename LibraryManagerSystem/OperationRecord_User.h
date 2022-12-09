#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class OR_U
{
public:
	OR_U(int _user_id, char _user_name[], int _grade, int _major, int _state, int _user_state, char _manager_name[]);
	OR_U() {}
	int get_id();							//��ȡ�û�id
	char* get_name();						//��ȡ�û���
	char* get_time();						//��ȡʱ��
	int get_grade();						//��ȡ�꼶
	string get_major();						//��ȡ�û�רҵ
	char* get_ori_password();				//��ȡ�޸�ǰ����
	void set_ori_password(char passwd[20]);	//�����û��޸�ǰ����
	void set_now_password(char passwd[20]);	//�����û��޸ĺ�����
	char* get_now_password();				//��ȡ�û���������
	char* get_manager_name();				//��ȡ����Ա����
	int get_state();						//��ȡ��������
	int get_user_state();					//��ȡ�û�״̬
private:
	int id;									//ѧ��
	char name[10];							//����
	int grade;								//�꼶
	int majorID;							//רҵ��
	char ori_password[20];					//�޸�ǰ����
	char now_password[20];					//�޸ĺ�����
	char tmp[256];							//����ʱ��
	char manager_name[20];					//������id
	int user_state;							//�û�״̬
	int state;								//��������
};