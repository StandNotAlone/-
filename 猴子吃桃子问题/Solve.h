void solve1()//使用顺序表求解猴子吃桃问题的solve函数
{
    cout<<"使用递推的方式反推回至第一天的桃子个数=";
    List L;
    L.start[0].data=1;
    REP(i,10) L.start[i].data=(L.start[i-1].data+1)<<1;
    cout<<L.start[10].data<<endl;
    L.print(10);
    cout<<endl;
}

void solve2()//使用链表求解猴子吃桃问题的solve函数
{
    cout<<"使用递推的方式反推回至第一天的桃子个数=";
    LinkList L;
    L.Insert(1,1);  //压入第一天的桃子个数
    rep(i,10) L.Insert(1,(L.start->next->data+1)<<1);
    cout<<L.start->next->data<<endl;
    L.print();
    cout<<endl;
}

void solve3(ll n,ll num)//利用递归求解猴子吃桃问题,n代表天数,num代表桃子个数
{
	num=(num+1)<<1;
	cout<<n<<"天前的桃子个数为"<<num<<"个"<<endl;
	if(n==10)
	{
		cout<<endl;
		return;
	}
	solve3(++n,num);
}

bool check(ll n)		//二分答案算法所需的check函数
{
	ll day=0;
	while(day<10&&n)
	{
		n=(n>>1)-1;
		day++;
	}
	if(day==10&&n>=1) return 1;
	else return 0;
}

void solve4()	//利用二分答案算法求解猴子吃桃问题
{
	ll low=0,high=10000;//设定初始的左右边界为0个和10000个桃子
	cout<<"由于对于答案的桃子个数x来说，如果假定的桃子个数>x则10天后剩余的桃子个数会多与一个,"<<endl;
	cout<<"而对于假定的桃子个数<x则十天后剩余的桃子个数会少于一个或者不足以支持吃到第十天。"<<endl;
	cout<<"会发现对于答案的情况来说，>x和<x的情况是不同的，满足了二分答案算法的基本要求。"<<endl;
	while(low<high)
	{
		cout<<"当前check函数的左右边界分别为"<<low<<' '<<high<<endl;
		ll mid=(low+high)>>1;
		check(mid)?high=mid:low=mid+1;
	}
	cout<<"求解出的答案为:"<<low<<"个桃子"<<endl<<endl;
}

void solve5()	//利用二进制数位分解得到结论，直接求得答案
{
	cout<<"由于这里的操作方式只有吃一半和多一个这样的操作类型"<<endl;
	cout<<"对于二进制分解后的数来说这样的操作其实就相当于移位操作和在末尾+1"<<endl;
	cout<<"因此其实对二进制分解后的数来说其实这个答案是有规律的"<<endl;
	cout<<"初始的桃子个数对应的二进制为:1"<<endl;
	cout<<"一天前的桃子个数对应的二进制为:100"<<endl;
	cout<<"两天前的桃子个数对应的二进制为1010"<<endl;
	cout<<"三天前的桃子个数对应的二进制为10110"<<endl;
	cout<<"四天前的桃子个数对应的二进制为101110"<<endl;
	cout<<"........"<<endl;
	cout<<"由此可以得出结论:"<<endl;
	cout<<"第n天前的桃子个数对应的二进制为\"10\"+(n-1)个\"1\"+\"0\""<<endl;
	cout<<"由此直接得到十天前的桃子个数对应的二进制为101111111110"<<endl;
	cout<<"该值=3*(10000000000表示的二进制数)-2"<<endl;
	cout<<"或者可以表述为一个更通用的求解公式，第n天前的桃子个数为1向作移位n位后乘以3减去2"<<endl;
	cout<<"由此算出十天前的桃子个数="<<((ll)1<<10)*3-2<<"个"<<endl<<endl;
}
