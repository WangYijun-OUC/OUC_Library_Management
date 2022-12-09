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
	int id;//用户id
	char name[20];//用户名
	int category;//罚款类型 0-图书丢失 1-超时归还
	double money;//罚款金额
};
