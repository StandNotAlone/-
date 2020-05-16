#include"Header.h"
//顺序表的基本操作

struct Node//定义一个基本数据元素Node，包含一个整型数值data
{
    ll data;
};

class List//定义一个Node的顺序表类List
{
public:
    List();                //不指定初始长度，构造默认长度maxn的顺序表
    bool GetNode(ll x,Node &n);//从顺序表中取第x个元素赋值给n
    ll SearchNode(Node n);//在顺序表中查询元素n所在的位置
    bool change(ll x,ll data);//改变顺序表中第x个元素的值为data
    bool InsertNode(ll x,Node n);//在顺序表L的第x个元素的位置插入元素n
    bool DeleteNode(ll x);//在顺序表中删除第x个位置的元素
    void print(ll n);
    Node *start;
    ll len;
private:
};

//顺序表的基本操作
List::List()//按照默认长度maxn进行构造顺序表
{
    start=new Node[maxn];
    if(!start) exit(1);
    len=0;
}

bool List::GetNode(ll x,Node &n)//从顺序表L中获取第x个元素赋值给n
{
    if(x<1||x>len) return 0;
    n=start[x-1];
    return 1;
}

ll List::SearchNode(Node n)//在顺序表L中查询元素n所在的位置
{
    for(ll i=0;i<len;i++)
        if(start[i].data==n.data) return i+1;
    return 0;
}

bool List::change(ll x,ll data)//改变顺序表中第x个元素的值为data
{
    if(x<1||x>len) return 0;
    start[x-1].data=data;
    return 1;
}

bool List::InsertNode(ll x,Node n)//在顺序表L的第x个元素的位置插入元素n
{
    if(x<1||x>len+1||len==maxn) return 0;
    for(ll i=len;i>=x;i--)
        start[i]=start[i-1];
    start[x-1]=n;
    len++;
    return 1;
}

bool List::DeleteNode(ll x)//在顺序表中删除第x个位置的元素
{
    if(x<1||x>len) return 0;
    for(ll i=x;i<len;i++)
        start[i-1]=start[i];
    len--;
    return 1;
}

void List::print(ll n)
{
    cout<<"天数";
    REP(i,n) cout<<setw(8)<<i;
    cout<<endl<<"个数";
    REP(i,n) cout<<setw(8)<<start[i].data;
    cout<<endl;
}
