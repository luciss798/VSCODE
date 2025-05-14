//��װ������ʾ�ý���  �� void showmenu()
//��main�����е��÷�װ�õĺ���
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//�����ϵ�˽ṹ��
struct person {
	//����
	string m_name;
	//�Ա� 1 �� 2 Ů 
	int m_sex;
	//����
	int m_age;
	//�绰
	string m_phone;
	//סַ
	string m_addr;

};
//���ͨѶ¼�ṹ��
struct addressbooks {
	//ͨѶ¼�б������ϵ������
	struct person presonarray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_size;
};
//�˵�����
void showmenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
void addperson(addressbooks* abs) {

	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		cout << "����������:" << endl;
		string name;
		cin >> name;
		abs->presonarray[abs->m_size].m_name = name;

		cout << "�������Ա�:" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "����������:" << endl;
		int age;
		cin >> age;
		abs->presonarray[abs->m_size].m_age = age;

		cout << "������绰:" << endl;
		string phonenumber;
		cin >> phonenumber;
		abs->presonarray[abs->m_size].m_phone = phonenumber;

		cout << "������סַ:" << endl;
		string address;
		cin >> address;
		abs->presonarray[abs->m_size].m_addr = address;
		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks *abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "����:" << abs->presonarray[i].m_name << "\t";
			cout << "�Ա�:" << (abs->presonarray[i].m_sex==1?"��":"Ů") << "\t";
			cout << "����:" << abs->presonarray[i].m_age << "\t";
			cout << "�绰:" << abs->presonarray[i].m_phone << "\t";
			cout << "סַ:" << abs->presonarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//���Һ����������ҵ���������ϵ�˵�λ�ã����򣬷���-1
int isexist(addressbooks* abs, string name) {
	int i;
	for (i = 0; i < abs->m_size; i++) {
		if (name == abs->presonarray[i].m_name) {
			return i;
		}
	}
	return -1;
}
void deleteperson(addressbooks* abs) {
	string name;
	cout << "������Ҫɾ����ϵ�˵�����:";
	cin >> name;
	//��ʱ��abs����Ϊ��ַ�������ģ�����Ҫ��ȡ��ַ
	int num = isexist(abs, name);
	if (num != -1) {
		for (int i = num; i < abs->m_size - 1; i++) {
			abs->presonarray[i] = abs->presonarray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��:" << endl;
	string name;
	cin >> name;
	int i = isexist(abs, name);
	if (i != -1) {
		cout << "����:" << abs->presonarray[i].m_name << "\t";
		cout << "�Ա�:" << (abs->presonarray[i].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs->presonarray[i].m_age << "\t";
		cout << "�绰:" << abs->presonarray[i].m_phone << "\t";
		cout << "סַ:" << abs->presonarray[i].m_addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��:" << endl;
	string name;
	cin >> name;
	int i = isexist(abs, name);
	if (i != -1) {
		cout << "����������:" << endl;
		string name;
		cin >> name;
		abs->presonarray[i].m_name = name;

		cout << "�������Ա�:" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[i].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "����������:" << endl;
		int age;
		cin >> age;
		abs->presonarray[i].m_age = age;

		cout << "������绰:" << endl;
		string phonenumber;
		cin >> phonenumber;
		abs->presonarray[i].m_phone = phonenumber;

		cout << "������סַ:" << endl;
		string address;
		cin >> address;
		abs->presonarray[i].m_addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs) {
	abs->m_size = 0;
	cout << "������" << endl;
	system("pause");
	system("cls");
}
int main() {
	int select = 0;//�����û�ѡ������ı�����

	//����ͨѶ¼
	addressbooks abs;
	abs.m_size = 0;

	//�˵�����
	showmenu();
	cin >> select;
	while (1) {
		switch (select) {
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://���ͨѶ¼
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
		showmenu();
		cin >> select;
	}
	return 0;

}