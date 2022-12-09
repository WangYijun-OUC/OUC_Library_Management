#pragma once
#include <stdio.h>
class Book
{
private:
    int id;                 // �鼮���
    char name[20];          // ������������19���ַ���һ�����ֵ���2���ַ�
    char writer[20];        // ���ߣ�������19���ַ���һ�����ֵ���2���ַ�
    int state;              // 1�ɽ裬0���ɽ豻���ģ�2��ʧ��3ɾ��
    char press[20];         //������
    int publication_date;   //��������
    char category[20];      //���
    //int num;              //����
    long long isbn;         // ISBN
    double price;           // �鼮�۸�1000����
    int renew_time;         //�������

public:
    // �������캯��
    Book();
    Book(int _id, char* _name, char* _writer, int _state, char* _press, int _publication_date, double _price, char* _category, long long _isbn, int _renew_time);
    int get_id(); // ��ȡ�鼮id
    char* get_name(); // ��ȡ����
    char* get_writer(); // ��ȡ����
    int get_state(); // ��ȡ�鼮״̬
    char* get_press();//��ȡ������
    char* get_category();//��ȡ����
    int get_publication_date();//��ȡ��������
    //int get_num();
    long long get_isbn();//��ȡisbn
    double get_price(); // ��ȡ�鼮�۸�
    int get_renew_time();//��ȡ�������
    void set_renew_time();//�����������(�����1��������30)
    void reset_renew_time();//�����������Ϊ0
    void set_state(int _state);// ����״̬
    void show_book();//չʾ�鼮��Ϣ
    void set_id(int _id);//����id
};
