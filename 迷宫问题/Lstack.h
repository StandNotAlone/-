#include"head.h"

struct node		//建立一个二维坐标的结构体
{
	ll x,y;
};

//链栈的基本操作
struct Node//定义了一个链栈以及链队的基本结点
{
	node data;
	Node *next;
};

class LinkStack //定义了一个以Node为结点的链栈类
{
public:
	bool init();		//链栈的初始化
	bool push(node e);	//链栈的入栈
	bool pop();	//链栈的出栈
	node gettop();		//取栈顶元素
	void print();		//朴素法依次输出栈中所有元素
	Node* getstart() {return start;};
	ll size(){return num;};			//返回栈中保存的元素个数
	void clear();			//清空栈
private:
	Node *start;
	ll num;			//计数当前栈中保存了几个元素
};

//链栈类函数

bool LinkStack::init()//链栈的初始化
{
	start=NULL;
	num=0;
	return 1;
};

bool LinkStack::push(node e)//链栈的入栈
{
	Node *p=new Node;
	if(!p) return 0;
	p->data=e;
	p->next=start;
	start=p;
	num++;
	return 1;
};

bool LinkStack::pop()//链栈的出栈
{
	if(!start) return 0;
	Node *t=start;
	start=start->next;
	delete t;
	num--;
	return 1;
};

node LinkStack::gettop()//取链表栈顶元素
{
	if(!start) return {-1,-1};
	return start->data;
};

void LinkStack::print()//依次输出链栈所有元素
{
	cout<<"此时栈中的元素为(栈顶到栈底):";
	Node *t=start;
	while(t)
	{
		if(t!=start) cout<<' ';
		cout<<t->data.x<<' '<<t->data.y<<endl;
		t=t->next;
	}
	cout<<endl;
};

void LinkStack::clear()//清空栈
{
	while(num)
		this->pop();
};
