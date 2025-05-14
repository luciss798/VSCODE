//封装函数显示该界面  如 void showmenu()
//在main函数中调用封装好的函数
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//设计联系人结构体
struct person {
	//姓名
	string m_name;
	//性别 1 男 2 女 
	int m_sex;
	//年龄
	int m_age;
	//电话
	string m_phone;
	//住址
	string m_addr;

};
//设计通讯录结构体
struct addressbooks {
	//通讯录中保存的联系人数组
	struct person presonarray[MAX];
	//通讯录中当前记录联系人的个数
	int m_size;
};
//菜单界面
void showmenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addperson(addressbooks* abs) {

	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		cout << "请输入姓名:" << endl;
		string name;
		cin >> name;
		abs->presonarray[abs->m_size].m_name = name;

		cout << "请输入性别:" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄:" << endl;
		int age;
		cin >> age;
		abs->presonarray[abs->m_size].m_age = age;

		cout << "请输入电话:" << endl;
		string phonenumber;
		cin >> phonenumber;
		abs->presonarray[abs->m_size].m_phone = phonenumber;

		cout << "请输入住址:" << endl;
		string address;
		cin >> address;
		abs->presonarray[abs->m_size].m_addr = address;
		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks *abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名:" << abs->presonarray[i].m_name << "\t";
			cout << "性别:" << (abs->presonarray[i].m_sex==1?"男":"女") << "\t";
			cout << "年龄:" << abs->presonarray[i].m_age << "\t";
			cout << "电话:" << abs->presonarray[i].m_phone << "\t";
			cout << "住址:" << abs->presonarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找函数，若查找到，返回联系人的位置，否则，返回-1
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
	cout << "请输入要删除联系人的名字:";
	cin >> name;
	//此时的abs是作为地址传进来的，不需要再取地址
	int num = isexist(abs, name);
	if (num != -1) {
		for (int i = num; i < abs->m_size - 1; i++) {
			abs->presonarray[i] = abs->presonarray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs) {
	cout << "请输入您要查找的联系人:" << endl;
	string name;
	cin >> name;
	int i = isexist(abs, name);
	if (i != -1) {
		cout << "姓名:" << abs->presonarray[i].m_name << "\t";
		cout << "性别:" << (abs->presonarray[i].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->presonarray[i].m_age << "\t";
		cout << "电话:" << abs->presonarray[i].m_phone << "\t";
		cout << "住址:" << abs->presonarray[i].m_addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs) {
	cout << "请输入您要修改的联系人:" << endl;
	string name;
	cin >> name;
	int i = isexist(abs, name);
	if (i != -1) {
		cout << "请输入姓名:" << endl;
		string name;
		cin >> name;
		abs->presonarray[i].m_name = name;

		cout << "请输入性别:" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[i].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄:" << endl;
		int age;
		cin >> age;
		abs->presonarray[i].m_age = age;

		cout << "请输入电话:" << endl;
		string phonenumber;
		cin >> phonenumber;
		abs->presonarray[i].m_phone = phonenumber;

		cout << "请输入住址:" << endl;
		string address;
		cin >> address;
		abs->presonarray[i].m_addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs) {
	abs->m_size = 0;
	cout << "清空完成" << endl;
	system("pause");
	system("cls");
}
int main() {
	int select = 0;//创建用户选择输入的变量；

	//创建通讯录
	addressbooks abs;
	abs.m_size = 0;

	//菜单调用
	showmenu();
	cin >> select;
	while (1) {
		switch (select) {
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空通讯录
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
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