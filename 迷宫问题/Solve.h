#include"head.h"
#include"Lstack.h"

bool field[(ll)maxn][(ll)maxn];			//field[i][j]用于记录坐标为(i,j)的点是否已经被走过

struct AMGraph	//建立一个由邻接矩阵表示的图
{
	ll arcs[(ll)maxn][(ll)maxn];	//邻接矩阵
	ll m,n;		//图的长度和宽度
	node start,end;
}G;

ll dir[4][2]=		//方向数组
{
	1,0,
	-1,0,
	0,1,
	0,-1
};

void creat()		//使用邻接表建立迷宫基本信息
{
	while(1)
	{
		cout<<"请输入图的长和宽:";
		cin>>G.m>>G.n;
		if(G.m>0&&G.m<maxn&&G.n>0&&G.n<maxn) break;
		else cout<<"不合法的输入数据!请重新输入!"<<endl;
	}
	srand((int)time(0));
	REP(i,G.m)
		REP(j,G.n)
			G.arcs[i][j]=rand()%3%2;//生成随机的迷宫地图，0代表该点为通路，1代表该点为障碍。先模3再模2使地图中的通路更多
	while(1)
	{
		cout<<"请输入起点的横纵坐标:";
		cin>>G.start.x>>G.start.y;
		if(G.start.x>0&&G.start.x<=G.m&&G.start.y>0&&G.start.y<=G.n) break;
		else cout<<"非法的坐标！请重新输入!"<<endl;
	}
	while(1)
	{
		cout<<"请输入终点的横纵坐标:";
		cin>>G.end.x>>G.end.y;
		if(G.end.x>0&&G.end.x<=G.m&&G.end.y>0&&G.end.y<=G.n) break;
		else cout<<"非法的坐标!请重新输入!"<<endl;
	}
	cout<<"创建出的随机迷宫地图为:"<<endl;
	cout<<setw(3)<<' ';
	REP(i,G.n) cout<<setw(3)<<i;
	cout<<endl;
	REP(i,G.m)
	{
		cout<<setw(3)<<i;
		REP(j,G.n)
			cout<<setw(3)<<G.arcs[i][j];
		cout<<endl;
	}
}

void change()		//改变图的起点和终点坐标
{
	while(1)
	{
		cout<<"请输入起点的横纵坐标:";
		cin>>G.start.x>>G.start.y;
		if(G.start.x>0&&G.start.x<=G.m&&G.start.y>0&&G.start.y<=G.n) break;
		else cout<<"非法的坐标！请重新输入!"<<endl;
	}
	while(1)
	{
		cout<<"请输入终点的横纵坐标:";
		cin>>G.end.x>>G.end.y;
		if(G.end.x>0&&G.end.x<=G.m&&G.end.y>0&&G.end.y<=G.n) break;
		else cout<<"非法的坐标!请重新输入!"<<endl;
	}
	cout<<"起终点坐标改变成功!"<<endl;
}

ll getdir(node a,node b)	//获得结点a到节点b的方向
{
	rep(i,4)
		if(a.x+dir[i][0]==b.x&&a.y+dir[i][1]==b.y) return i;
	return -1;
}

void solve1()
{
	cout<<"使用非递归算法求解过程为:"<<endl;
	LinkStack S;
	S.init();
	REP(i,G.m)
		REP(j,G.n)
			field[i][j]=0;	//对field数组初始化，所有位置在开始时均为被走过
	bool flag=0;			//标志是否已经找到了到终点的通路
	field[G.start.x][G.start.y]=1;	//将起点设置为被走过，并压入到栈中
	S.push(G.start);
	while(S.size())
	{
		node now;		//标志当前走到的位置坐标
		now=S.gettop();
		node temp;		//标志下一个位置的坐标
		bool cas=0;		//标志当前点位是否还存在可走路线
		rep(i,4)
		{
			temp.x=now.x+dir[i][0];
			temp.y=now.y+dir[i][1];
			if(temp.x>0&&temp.x<=G.m&&temp.y>0&&temp.y<=G.n&&!G.arcs[temp.x][temp.y]&&!field[temp.x][temp.y])
			{
				S.push(temp);
				field[temp.x][temp.y]=1;
				if(temp.x==G.end.x&&temp.y==G.end.y)	//如果已经走到终点则改变标记为已经找到通路并直接跳出循环
				{
					flag=1;
					break;
				}
				cas=1;
				break;
			}
		}
		if(flag) break;
		if(!cas) S.pop();
	}
	if(flag)
	{
		cout<<"该迷宫存在起点坐标到终点坐标的通路，通路如下图:"<<endl;
		ll Graph[(ll)maxn][(ll)maxn];		//记录最后的答案图像，用-1表示路径，输出时候用&符号表示
		REP(i,G.m)
			REP(j,G.n)
				Graph[i][j]=G.arcs[i][j];
		LinkStack S1;
		while(S.size())
		{
			node temp;
			temp=S.gettop();
			S1.push(temp);			//将栈S中的数据依次取出压入栈S1中，达到翻转的效果
			S.pop();
			Graph[temp.x][temp.y]=-1;
		}
		cout<<setw(3)<<' ';
		REP(i,G.n) cout<<setw(3)<<i;
		cout<<endl;
		REP(i,G.m)
		{
			cout<<setw(3)<<i;
			REP(j,G.n)
				if(Graph[i][j]==-1) cout<<setw(3)<<'&';
				else cout<<setw(3)<<Graph[i][j];
			cout<<endl;
		}
		cout<<"路径为{格式为(当前横坐标，当前纵坐标，方向值),方向值0代表向下，1代表向上，2代表向右，3代表向左)}:"<<endl;
		ll num=0;
		while(S1.size()>1)
		{
			if(num) cout<<',';
			if(num%5==0) cout<<endl;
			num++;
			node temp1=S1.gettop();
			S1.pop();
			node temp2=S1.gettop();
			cout<<'('<<temp1.x<<','<<temp1.y<<','<<getdir(temp1,temp2)<<')';
		}
		cout<<endl;
	}
	else cout<<"该迷宫不存在起点坐标到终点坐标的通路"<<endl;
	cout<<endl;
}

bool flag;	//记录是否已经找到了起点到终点的通路
ll Graph[(ll)maxn][(ll)maxn];		//记录最后的答案图像，用-1表示路径，输出时候用&符号表示
LinkStack S;						//

void dfs(node now)
{
	if(now.x==G.end.x&&now.y==G.end.y) flag=1;//到达终点将标志flag置为1
	if(flag)				//如果已经找到终点则直接记录当前的路径
	{
		S.push(now);
		Graph[now.x][now.y]=-1;
		return;
	}
	node temp;
	rep(i,4)				//向四个方向移动
	{
		temp.x=now.x+dir[i][0];
		temp.y=now.y+dir[i][1];
		if(temp.x>0&&temp.x<=G.m&&temp.y>0&&temp.y<=G.n&&!G.arcs[temp.x][temp.y]&&!field[temp.x][temp.y])
		{
			field[temp.x][temp.y]=1;
			dfs(temp);
			if(flag)				//如果已经找到终点则直接记录当前的路径
			{
				S.push(now);
				Graph[now.x][now.y]=-1;
				return;
			}
		}
	}
}

void solve2()
{
	S.clear();			//清空路径答案栈
	cout<<"使用递归算法求解的过程为"<<endl;
	REP(i,G.m)
	REP(j,G.n)
		field[i][j]=0;	//对field数组初始化，所有位置在开始时均为被走过
	field[G.start.x][G.start.y]=1;
	flag=0;
	REP(i,G.m)
		REP(j,G.n)
			Graph[i][j]=G.arcs[i][j];
	dfs(G.start);
	if(flag)
	{
		cout<<"该迷宫存在起点坐标到终点坐标的通路，通路如下图:"<<endl;
		cout<<setw(3)<<' ';
		REP(i,G.n) cout<<setw(3)<<i;
		cout<<endl;
		REP(i,G.m)
		{
			cout<<setw(3)<<i;
			REP(j,G.n)
				if(Graph[i][j]==-1) cout<<setw(3)<<'&';
				else cout<<setw(3)<<Graph[i][j];
			cout<<endl;
		}
		cout<<"路径为{格式为(当前横坐标，当前纵坐标，方向值),方向值0代表向下，1代表向上，2代表向右，3代表向左)}:"<<endl;
		ll num=0;
		while(S.size()>1)
		{
			if(num) cout<<',';
			if(num%5==0) cout<<endl;
			num++;
			node temp1=S.gettop();
			S.pop();
			node temp2=S.gettop();
			cout<<'('<<temp1.x<<','<<temp1.y<<','<<getdir(temp1,temp2)<<')';
		}
		cout<<endl;
	}
	else cout<<"该迷宫不存在起点坐标到终点坐标的通路"<<endl;
	cout<<endl;
}
