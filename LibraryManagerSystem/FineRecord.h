#pragma once
class FR
{
public:
	FR(){}
	FR(int _id, char* _name, int _category, double _money );
	int get_id();
	char* get_name();
	void show();
	void set_name(char _name[20]);
private:
	int id;//�û�id
	char name[20];//�û���
	int category;//�������� 0-ͼ�鶪ʧ 1-��ʱ�黹
	double money;//������
};
