#include"Header.h"
//单链表的基本操作
struct Lnode//定义了一个链表的节点类型
{
    ll data;
    Lnode *next;
};

class LinkList//定义一个Lnode类型的单链表类LinkList
{
public:
    LinkList();//构造函数
    bool GetElem(ll i,ll &e);//从单链表中取序号为i的元素，通过e返回
    ll LocateElem(ll e);//在单链表中查找值为e的元素，返回该节点地址
    bool Insert(ll i,ll e);//在单链表中第i个位置插入值为e的新结点
    bool Delete(ll i);//在单链表中删除第i个位置的元素
    void Create_front(ll n);//逆序输入n个元素，用前插法建立带表头结点的单链表L
    void Create_back(ll n);//顺序输入n个元素，用后插法建立带头结点的单链表L
    void MergeSorted(LinkList &LB);//合并两个不严格递增的单链表LA和LB，不开辟新的内存空间
    void print();
    Lnode *start;
private:

    ll data;
};

//单链表的基本操作

LinkList::LinkList()//初始化单链表L
{
    start=new Lnode;
    start->next=NULL;
    start->data=-llINF;
}

bool LinkList::GetElem(ll i,ll &e)//在带头结点的单链表L中取序号i的元素，通过e返回
{
    Lnode* t=start->next;
    while(t&&--i)
        t=t->next;
    if(!t||i) return 0;
    e=t->data;
    return 1;
}

ll LinkList::LocateElem(ll e)//在带头节点的单链表L中查找值为e的元素，返回该节点地址
{
    ll num=1;
    Lnode* t=start->next;
    while(t&&t->data!=e)
    {
        num++;
        t=t->next;
    }
    return t&&t->data==e?num:0;
}

bool LinkList::Insert(ll i,ll e)//在带头结点的单链表L中第i个位置插入值为e的新结点
{
    Lnode* t=start;
    while(t&&--i)                //注意这里的判断顺序为短路的L和--i，并且这里采用了前置自减运算，L为插入点前一个位置的结点
        t=t->next;
    if(i) return 0;
    Lnode *T=new Lnode;
    T->data=e;
    T->next=t->next;
    t->next=T;
    return 1;
}

bool LinkList::Delete(ll i)//在带头节点的单链表L中删除第i个位置的元素
{
    Lnode* t=start;
    while(--i&&t)
        t=t->next;
    if(i<0||!t->next) return 0;
    Lnode* T=t->next;
    t->next=T->next;
    delete T;
    return 1;
}

void LinkList::Create_front(ll n)//逆序输入n个元素，用前插法建立带表头结点的单链表L
{
    while(n--)
    {
        Lnode *t=new Lnode;
        cin>>t->data;
        t->next=start->next;
        start->next=t;
    }
}

void LinkList::Create_back(ll n)//顺序输入n个元素，用后插法建立带头结点的单链表L
{
    Lnode *back=start;
    while(n--)
    {
        Lnode *t=new Lnode;
        cin>>t->data;
        t->next=back->next;
        back->next=t;
        back=t;
    }
}

void LinkList::print()
{
    Lnode *t=start;
    while(t->next)
    {
        t=t->next;
        cout<<t->data<<"->";
    }
    cout<<endl;
}
