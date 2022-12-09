#include <bits/stdc++.h>
using namespace std;

class Record
{
public:
	Record(){};
	Record(int new_id_book, char new_name_book[20], int new_id_user, char new_name_user[20], int new_state, int record_state);
	~Record() {};
	void recording();//����
	int get_id();//��ȡ�鼮id
	char* get_book_name();//��ȡ�鼮����
	int get_user_id();//��ȡ�û�id
	char* get_user_name();//��ȡ�û���

	int get_book_state();//��ȡ�鼮״̬
	int get_record_state();//��ȡ��¼״̬
	
	void set_book_state(int new_state);//�����鼮״̬
	void set_record_state(int new_state);//���ü�¼״̬

	void show_record();//չʾ��¼

	void set_return_tmp();//���ù黹ʱ��
	char* get_return_tmp();//��ȡ�黹ʱ��

	char* get_tmp();//��ȡʱ��
	void set_tmp(string tmp);//���ý���ʱ��

private:
	int id_book; // �鼮���
	char name_book[20]; // ������������20���ַ���һ�����ֵ���2���ַ�
	int id_user;//ѧ��
	char name_user[20];//����
	int book_state;//���״̬
	int record_state;//��¼��״̬ 0Ϊ��������¼ 1Ϊ������¼
	char tmp[256];//ʱ��
	char return_tmp[256];//�黹ʱ��
};

Record::Record(int new_id_book, char new_name_book[20], int new_id_user, char new_name_user[20], int new_book_state, int new_record_state) {
	id_book = new_id_book;
	strcpy_s(name_book, new_name_book);
	id_user = new_id_user;
	for (int i = 0; i < 20; i++) {
		name_user[i] = new_name_user[i];
	}
	book_state = new_book_state;
	record_state = new_record_state;

	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);

	time_t timep;//���ʱ��
	time(&timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &now_time);
	strcpy_s(return_tmp, "XXXX-XX-XX XX:XX:XX");
}
int Record::get_id()
{
	return id_book;
}
char* Record::get_book_name()
{
	return name_book;
}
int Record::get_user_id()
{
	return id_user;
}
char* Record::get_user_name()
{
	return name_user;
}
int Record::get_book_state()
{
	return book_state;
}
int Record::get_record_state()
{
	return record_state;
}
char* Record::get_tmp()
{
	return tmp;
}

void Record::set_return_tmp() {
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);

	time_t timep;//���ʱ�� 
	time(&timep);
	strftime(return_tmp, sizeof(return_tmp), "%Y-%m-%d %H:%M:%S", &now_time);
}

void Record::set_book_state(int new_state) {
	this->book_state = new_state;
}

void Record::set_record_state(int new_state) {
	this->record_state = new_state;
}

char* Record::get_return_tmp() {
	return return_tmp;
}

void Record::set_tmp(string _tmp)
{
	for (int i = 0; i < _tmp.length(); i++)
		tmp[i] = _tmp[i];
}

void Record::show_record() {
	if (this->get_id() != 3)
	{
		cout << "----------------------------------------------------------------" << endl;
		cout << "�鼮��ţ�" << this->get_id() << "\t������" << this->get_book_name() <<"\t�û�id:"<<this->get_user_id()<< "\t����ʱ�䣺" << this->get_tmp() << "\t����ʱ�䣺" << this->get_return_tmp() << "\t״̬��";
		if (book_state == 0)
			cout << "δ�黹";
		if (book_state == 1)
			cout << "�ѹ黹";
		if (book_state == 2)
			cout << "�鼮��ʧ";
		cout << endl;
	}
}

int main() {
    Record record;
    fstream fp("recording.dat", ios::binary | ios::in | ios::out);
	if (!fp) {
		cerr << "�ļ���ʧ��" << endl;
		exit(0);
	}

    while (fp.read((char*)&record, sizeof(Record))) {
		cout << "id_book" << " " << record.get_id() << endl;
        cout << "book_name" << " " << record.get_book_name() << endl;
        cout << "����ʱ��" << " " << record.get_tmp() << endl;
        cout << "����ʱ��" << " " << record.get_return_tmp() << endl;
        cout << "ʹ���û�" << " " << record.get_user_id() << endl;
        cout << "ʹ���û�" << " " << record.get_user_name() << endl;
		cout << "�鼮״̬" << " " << record.get_book_state() << endl;
		cout << "��¼״̬" << " " << record.get_record_state() << endl;
		cout << endl;
        //record.set_tmp("2022-01-09 19:14:27");

		// Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state(), 1);
		// record1.set_tmp("2022-08-24 00:31:45");
		// //record1.set_record_state(0);

		// if(record.get_id() == 8) {
		// 	//�ҵ���¼λ��
		// 	int size = sizeof(record);
		// 	fp.seekg(-size, ios::cur);
		// 	fp.write((char*)&record1, sizeof(record1));
		// }

			
	}
    // fp.close();

    // Record record1 = Record(record.get_id(), record.get_book_name(), record.get_user_id(), record.get_user_name(), record.get_book_state());
    // record1.set_tmp("2022-01-09 19:14:27");

    // fstream file("recording1.dat", ios::in | ios::binary | ios::out);
	// if (!file) {
	// 	cerr << "�ļ���ʧ��" << endl;
	// 	return 0;
	// }
	// file.write((char*)&record1, sizeof(record1));
	// file.close();


    return 0;
}