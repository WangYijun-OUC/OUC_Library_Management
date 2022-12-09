#include <bits/stdc++.h>
using namespace std;

class User {
public:
	User() {};
	User(int new_id, char new_name[], char new_gender[], int new_grade, int new_major, int new_borrow_num, int new_history_borrow_num, int new_state,int new_status);
	~User() {};
	void show_user();					//չʾѧ����Ϣ
	void show_menu();					//չʾ�û��˵�������Ϊ�����û��ͺ������û���
	int get_id();						//��ȡ�û�id
	char* get_name();					//��ȡ�û���
	char* get_gender();					//��ȡ�û��Ա�
	int get_grade();					//��ȡ�û��꼶
	string get_major(int _majorID);		//��ȡ�û�רҵ
	int get_majorID();					//��ȡ�û�רҵID
	int get_borrow_num();				//��ȡ��������
	int get_history_borrow_num();		//��ȡ��ʷ��������
	char* get_password();				//��ȡ�û�����

	void set_id(int _id);				//�����û�id
	void set_name(char _name[]);		//�����û���
	void set_gender(char gender[]);		//�����û��Ա�
	void set_grade(int _grade);			//�����û��꼶
	void set_major(string major);		//�����û�רҵ
	void set_majorID(int major);		//�����û�רҵID
	void set_password(char _passwd[]);	//�����û�����
	void set_borrow_num(int _num);		//�����û���������
	void set_history_borrow_num(int _num);//������ʷ��������

	int get_user_state();				//��ȡ�û�״̬
	void set_user_state(int state);		//�û�״̬��0Ϊ��������1Ϊ����
	void set_black_list();				//���������
	void show_delay_book();				//չʾ����δ���鼮

	void borrow_book();					//����
	void return_book();					//����
	void inquire_history();				//��ѯ��ʷ�����¼
	void inquire_now();					//��ѯ��ǰ�������Ϣ
	bool save_user_info();				//���������Ϣ
	//void change_password();			//�޸����루���滻Ϊ�޸���Ϣ��
	void change_info();					//�޸ĸ�����Ϣ
	void renew();						//�����鼮
	void declare();						//ͼ�鶪ʧ�걨
	int get_status();					//��ȡ���
	bool get_fine_record_id(int search_id);//�鿴���û��Ƿ���Ƿ����Ϣ
	void set_status(int _status);		//���ñ����������о���
	
private:
	int id;					//ѧ��
	char name[11];			//����
	char gender[10];		//�Ա�
	int grade;				//�꼶
	int majorID;			//רҵ��
	char password[21];		//����
	int borrow_num;			//��ǰ��������
	int history_borrow_num;	//��ʷ��������
	int user_state;			//�û�״̬��0Ϊ�����ڣ�1Ϊ���ڣ�2Ϊɾ��
	int status;				//�û����0Ϊ��������1Ϊ�о���
};

int User::get_id() {
	return id;
}

char* User::get_name() {
	return name;
}

char* User::get_gender() {
	return gender;
}

int User::get_grade() {
	return grade;
}


string User::get_major(int _majorID) {
	//����ӳ���ϵ
	map<int, string> id_major;
	id_major[1] = "���������ѧԺ";
	id_major[2] = "��Ϣ��ѧ�빤��ѧ��";
	id_major[201] = "�������ѧ�뼼��ѧԺ";
	id_major[202] = "������Ϣ����ѧԺ";
	id_major[203] = "����ѧ�빤��ѧԺ";
	id_major[204] = "�����뺣��ѧԺ";
	id_major[3] = "��ѧ����ѧԺ"; 
	id_major[4] = "��������ѧѧԺ";
	id_major[5] = "��������ѧԺ";
	id_major[6] = "ʳƷ��ѧ�빤��ѧԺ";
	id_major[7] = "ҽҩѧԺ";
	id_major[8] = "����ѧԺ";
	id_major[9] = "������ѧ�빤��ѧԺ";
	id_major[10] = "����ѧԺ";
	id_major[11] = "����ѧԺ";
	id_major[12] = "�����ѧԺ";
	id_major[13] = "��ѧ�����Ŵ���ѧԺ";
	id_major[14] = "��ѧԺ";
	id_major[15] = "���������빫������ѧԺ";
	id_major[16] = "��ѧ��ѧѧԺ";
	id_major[17] = "���Ͽ�ѧ�빤��ѧԺ";
	id_major[18] = "���˼����ѧԺ";
	id_major[19] = "�籾ѧԺ";
	id_major[20] = "����ѧԺ";

	return id_major[_majorID];
}

int User::get_majorID() {
	return this->majorID;
}

void User::set_major(string major) {
	map<int, string> id_major;
	id_major[1] = "���������ѧԺ";
	id_major[2] = "��Ϣ��ѧ�빤��ѧ��";
	id_major[201] = "�������ѧ�뼼��ѧԺ";
	id_major[202] = "������Ϣ����ѧԺ";
	id_major[203] = "����ѧ�빤��ѧԺ";
	id_major[204] = "�����뺣��ѧԺ";
	id_major[3] = "��ѧ����ѧԺ";
	id_major[4] = "��������ѧѧԺ";
	id_major[5] = "��������ѧԺ";
	id_major[6] = "ʳƷ��ѧ�빤��ѧԺ";
	id_major[7] = "ҽҩѧԺ";
	id_major[8] = "����ѧԺ";
	id_major[9] = "������ѧ�빤��ѧԺ";
	id_major[10] = "����ѧԺ";
	id_major[11] = "����ѧԺ";
	id_major[12] = "�����ѧԺ";
	id_major[13] = "��ѧ�����Ŵ���ѧԺ";
	id_major[14] = "��ѧԺ";
	id_major[15] = "���������빫������ѧԺ";
	id_major[16] = "��ѧ��ѧѧԺ";
	id_major[17] = "���Ͽ�ѧ�빤��ѧԺ";
	id_major[18] = "���˼����ѧԺ";
	id_major[19] = "�籾ѧԺ";
	id_major[20] = "����ѧԺ";

	map<int, string>::iterator iter;
	//string major = "�籾ѧԺ";

	iter = std::find_if(id_major.begin(), id_major.end(), [major](const map<int, string>::value_type& item) {
		return item.second == major;
	});
	int n = 0;
	if (iter != id_major.end())
		this->majorID = iter->first;
}

void User::set_majorID(int major) {
	this->majorID = major;
}


int User::get_borrow_num() {
	return borrow_num;
}

char* User::get_password() {
	return password;
}

int User::get_history_borrow_num() {
	return this->history_borrow_num;
}

int User::get_user_state() {
	return user_state;
}

int main() {
    //int id = 2;
    User tmp_usr;
    ifstream userfile("User.dat", ios::in | ios::binary);
	
	while (userfile.read((char*)&tmp_usr, sizeof(User))) {
        cout << "id:" << tmp_usr.get_id() << endl;
		cout << "name:" << tmp_usr.get_name() << endl;
		cout << "password:" << tmp_usr.get_password() << endl;
		cout << "age:" << tmp_usr.get_grade() << endl;
		cout << "state:" << tmp_usr.get_user_state() << endl;
		cout << "gender:" << tmp_usr.get_gender() << endl;
		cout << "major:" << tmp_usr.get_majorID() << endl;
		cout << "major:" << tmp_usr.get_major(tmp_usr.get_majorID()) << endl;
		cout << endl;

	}

	userfile.close();
}
