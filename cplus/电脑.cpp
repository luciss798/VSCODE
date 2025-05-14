#include<iostream>
#include<string>
using namespace std;

//��������
//������Ҫ��ɲ�����CPU���Կ����ڴ���

//�������
//����CPU��
class  CPU {
public:
	//����ļ��㺯��
	virtual void calculator() = 0;
};
//�����Կ���
class  VideoCard {
public:
	//�������ʾ����
	virtual void dispaly() = 0;
};
//�����ڴ�����
class  Memory {
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

//������
class computer {
public:
	computer(CPU *cpu, VideoCard *vc, Memory *menm) {
		m_cpu = cpu;
		m_vc = vc;
		m_menm = menm;
	}
	void work() {
		m_cpu->calculator();
		m_vc->dispaly();
		m_menm->storage();
	}
	//��������
	~computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc= NULL;
		}
		if (m_menm != NULL) {
			delete m_menm;
			m_menm = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_menm;
};
class IntelCPU :public CPU {
public:
	virtual void calculator() {
		cout << "Intel��CPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel���ڴ�����ʼ������" << endl;
	}
};
class LegionCPU :public CPU {
public:
	virtual void calculator() {
		cout << "Legion��CPU��ʼ������" << endl;
	}
};
class LegionVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Legion���Կ���ʼ��ʾ��" << endl;
	}
};
class LegionMemory :public Memory {
public:
	virtual void storage() {
		cout << "Legion���ڴ�����ʼ������" << endl;
	}
};




void test01() {
	//��һ̨������װ
	CPU* i = new IntelCPU;
	VideoCard* v = new IntelVideoCard;
	Memory* m = new IntelMemory;
	cout << "��һ̨���Կ�ʼ������" << endl;
	computer *computer1=new computer(i,v,m);
	computer1->work();
	delete computer1;
	cout << "-----------------------" << endl;
}
void test02() {
	computer* computer2 = new computer(new IntelCPU, new LegionVideoCard, new IntelMemory);
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	computer2->work();
	delete computer2;
	cout << "-----------------------" << endl;
}

// void test04() {
// 	computer c = computer(new IntelCPU, new LegionVideoCard, new IntelMemory);
// 	computer &c4= c;
// 	cout << "����̨���Կ�ʼ������" << endl;
// 	c4.work();
// 	//delete &c4;
// 	cout << "-----------------------" << endl;
// }
int main() {
	//test01();
	//test02();
	//test04();
	return 0;
}