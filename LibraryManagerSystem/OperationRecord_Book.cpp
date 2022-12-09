#include <iostream>
#include "OperationRecord_Book.h"
#include <string>
using namespace std;
OR_B::OR_B(int book_id1, char* book_name1, int state1)
{
	book_id = book_id1;
	strcpy_s(book_name, book_name1);
	strcpy_s(manager_name, "Manager");
	state = state1;
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);
	time_t timep;//获得时间 
	time(&timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &now_time);
}
int OR_B::get_book_id()
{
	return book_id;
}
char* OR_B::get_book_name()
{
	return book_name;
}
char* OR_B::get_time()
{
	return tmp;
}
char* OR_B::get_manager_name()
{
	return manager_name;
}
int OR_B::get_state()
{
	return state;
}void OR_B::set_book_id(int _book_id)
{
	book_id = _book_id;
}