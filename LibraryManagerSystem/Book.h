#pragma once
#include <stdio.h>
class Book
{
private:
    int id;                 // 书籍编号
    char name[20];          // 书名，不超过19个字符，一个汉字等于2个字符
    char writer[20];        // 作者，不超过19个字符，一个汉字等于2个字符
    int state;              // 1可借，0不可借被借阅，2丢失，3删除
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
