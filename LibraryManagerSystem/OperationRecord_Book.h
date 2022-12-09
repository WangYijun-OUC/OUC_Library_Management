#pragma once
class OR_B
{
public:
	OR_B(int book_id1,char *book_name1,int state1);
	OR_B(){}
	int get_book_id();//获取书籍id
	char* get_book_name();//获取书籍名
	char* get_time();////获取书籍时间
	char* get_manager_name();//获取管理员名字
	int get_state();//获取操作类型
	void set_book_id(int _book_id);//设置书籍id
private:
	int book_id;//书籍id
	char book_name[20];//书籍名称
	char tmp[256];//时间
	char manager_name[20];//操作人id
	int state;//操作类型
};
