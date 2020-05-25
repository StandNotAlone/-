#include"head.h"
#include"manu.h"
#include"Solve.h"


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	bool flag=0;
	while(1)
	{
		print_manu();
		ll temp;
		cin>>temp;
		switch(temp)
		{
			case 0:cout<<endl;
				   creat();
				   flag=1;
				   break;
			case 1:cout<<endl;
				   if(!flag)
				   {
					   cout<<"尚未建立迷宫!请先建立迷宫!"<<endl;
					   break;
				   }
				   solve1();
				   break;
			case 2:cout<<endl;
				   if(!flag)
				   {
					   cout<<"尚未建立迷宫!请先建立迷宫!"<<endl;
					   break;
				   }
				   solve2();
				   break;
			case 3:cout<<endl;
				   if(!flag)
				   {
					   cout<<"尚未建立迷宫!请先建立迷宫!"<<endl;
					   break;
				   }
				   change();
				   break;
			case 4:cout<<endl<<"感谢使用"<<endl;
				   exit(1);
			default:cout<<endl<<"非法的操作数字!请重试输入!"<<endl;
		}
	}
}
