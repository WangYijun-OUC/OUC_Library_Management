#pragma once
class OR_B
{
public:
	OR_B(int book_id1,char *book_name1,int state1);
	OR_B(){}
	int get_book_id();//��ȡ�鼮id
	char* get_book_name();//��ȡ�鼮��
	char* get_time();////��ȡ�鼮ʱ��
	char* get_manager_name();//��ȡ����Ա����
	int get_state();//��ȡ��������
	void set_book_id(int _book_id);//�����鼮id
private:
	int book_id;//�鼮id
	char book_name[20];//�鼮����
	char tmp[256];//ʱ��
	char manager_name[20];//������id
	int state;//��������
};
