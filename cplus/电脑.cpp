#include<iostream>
#include<string>
using namespace std;

//案例需求：
//电脑主要组成部件：CPU，显卡，内存条

//抽象基类
//抽象CPU类
class  CPU {
public:
	//抽象的计算函数
	virtual void calculator() = 0;
};
//抽象显卡类
class  VideoCard {
public:
	//抽象的显示函数
	virtual void dispaly() = 0;
};
//抽象内存条类
class  Memory {
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

//电脑类
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
	//析构函数
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
		cout << "Intel的CPU开始计算了" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Intel的显卡开始显示了" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel的内存条开始储存了" << endl;
	}
};
class LegionCPU :public CPU {
public:
	virtual void calculator() {
		cout << "Legion的CPU开始计算了" << endl;
	}
};
class LegionVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Legion的显卡开始显示了" << endl;
	}
};
class LegionMemory :public Memory {
public:
	virtual void storage() {
		cout << "Legion的内存条开始储存了" << endl;
	}
};




void test01() {
	//第一台电脑组装
	CPU* i = new IntelCPU;
	VideoCard* v = new IntelVideoCard;
	Memory* m = new IntelMemory;
	cout << "第一台电脑开始工作：" << endl;
	computer *computer1=new computer(i,v,m);
	computer1->work();
	delete computer1;
	cout << "-----------------------" << endl;
}
void test02() {
	computer* computer2 = new computer(new IntelCPU, new LegionVideoCard, new IntelMemory);
	cout << "第二台电脑开始工作：" << endl;
	computer2->work();
	delete computer2;
	cout << "-----------------------" << endl;
}

// void test04() {
// 	computer c = computer(new IntelCPU, new LegionVideoCard, new IntelMemory);
// 	computer &c4= c;
// 	cout << "第四台电脑开始工作：" << endl;
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