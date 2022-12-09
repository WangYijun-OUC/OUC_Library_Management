#include "Book.h"
#include <string.h>
#include <iostream>
using namespace std;

Book::Book()
{
    id = 0;
    for (int i = 0; i < 20; ++i)
    {
        name[i] = ' ';
        writer[i] = ' ';
        press[i] = ' ';
        category[i] = ' ';
    }
    state = 0;
    publication_date = 0;
    price = 0.0;
    //num = 0;
    isbn = 0;
}

Book::Book(int _id, char* _name, char* _writer, int _state, char* _press, int _publication_date, double _price, char* _category, long long _isbn, int _renew_time)
{
    this->id = _id;
    strcpy_s(this->name, _name);
    strcpy_s(this->writer, _writer);
    this->state = _state;
    strcpy_s(this->press, _press);
    this->publication_date = _publication_date;
    strcpy_s(this->category, _category);
    //this->num = _num;
    this->isbn = _isbn;
    this->price = _price;
    this->renew_time = _renew_time;
}

int Book::get_id() // ��ȡ�鼮id
{
    return id;
}

char* Book::get_name() // ��ȡ�鼮����
{
    return name;
}
char* Book::get_writer()
{
    return writer;
}
int Book::get_state()
{
    return state;
}

char* Book::get_press()
{
    return press;
}
char* Book::get_category()
{
    return category;
}
int Book::get_publication_date()
{
    return publication_date;
}
/*int Book::get_num()
{
    return num;
}*/
long long Book::get_isbn()
{
    return isbn;
}
double Book::get_price()
{
    return price;
}
void Book::show_book()
{
    cout << "ID��" << id << "\t������" << name << "\t���ߣ�" << writer << "\t�۸�" << price << "\t�����磺" << press << "\t�������ڣ�" << publication_date << "\t���" << category << "\tISBN��" << isbn << "\t״̬��";
    if (state == 0)
        cout << "�ѽ��" << endl;
    if (state == 1)
        cout << "�ɽ���" << endl;
    if (state == 2)
        cout << "�鼮��ʧ" << endl;
}

void Book::set_state(int _state) {
    this->state = _state;
}
void Book::set_id(int _id)
{
    id = _id;
}

int Book::get_renew_time() {
    return renew_time;
}

void Book::reset_renew_time() {
    this->renew_time = 0;
}

void Book::set_renew_time() {
    this->renew_time = this->renew_time + 1;
}
