#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    int id;                 // 书籍编号
    char name[20];          // 书名，不超过19个字符，一个汉字等于2个字符
    char writer[20];        // 作者，不超过19个字符，一个汉字等于2个字符
    int state;              // 1可借，0不可借被借阅，2丢失
    char press[20];         //出版社
    int publication_date;   //出版日期
    char category[20];      //类别
    //int num;              //数量
    long long isbn;         // ISBN
    double price;           // 书籍价格，1000以内
    int renew_time;         //续借次数

public:
    // 三个构造函数
    Book();
    Book(int _id, char* _name, char* _writer, int _state, char* _press, int _publication_date, double _price, char* _category, long long _isbn, int _renew_time);
    int get_id(); // 获取书籍id
    char* get_name(); // 获取书名
    char* get_writer(); // 获取作者
    int get_state(); // 获取书籍状态
    char* get_press();//获取出版社
    char* get_category();//获取分类
    int get_publication_date();//获取出版日期
    //int get_num();
    long long get_isbn();//获取isbn
    double get_price(); // 获取书籍价格
    int get_renew_time();//获取续借次数
    void set_renew_time();//设置续借次数(续借加1，天数加30)
    void reset_renew_time();//重置续借次数为0
    void set_state(int _state);// 设置状态
    void show_book();//展示书籍信息
    void set_id(int _id);//设置id
};

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

int Book::get_id() // 获取书籍id
{
    return id;
}

char* Book::get_name() // 获取书籍名字
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
    cout << "ID：" << id << "\t书名：" << name << "\t作者：" << writer << "\t价格：" << price << "\t出版社：" << press << "\t出版日期：" << publication_date << "\t类别：" << category << "\tISBN：" << isbn << "\t状态：";
    if (state == 0)
        cout << "已借出" << endl;
    if (state == 1)
        cout << "可借阅" << endl;
    if (state == 2)
        cout << "书籍丢失" << endl;
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

int main() {
    Book book;
    fstream fp("Book.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "文件打开失败" << endl;
		exit(0);
	}

    while (fp.read((char*)&book, sizeof(Book))) {
		cout << "id_book:" << " " << book.get_id() << endl;
        cout << "name_book:" << " " << book.get_name() << endl;
        cout << "book_state:" << " " << book.get_state() << endl;
        cout << endl;
		// Book book1 = Book(book.get_id(), book.get_name(), book.get_writer(), book.get_state(), book.get_press(), book.get_publication_date(), book.get_price(), book.get_category(), book.get_isbn(), book.get_renew_time());
        // book1.set_state(1);

		// if(book.get_id() == 1) {
		// 	//找到记录位置
		// 	int size = sizeof(book);
		// 	fp.seekg(-size, ios::cur);
		// 	fp.write((char*)&book1, sizeof(book1));
		// }
    }
    fp.close();
}