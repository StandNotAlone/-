#include"List.h"
#include"Header.h"
#include"Llist.h"
#include"Solve.h"
#include"manu.h"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(1)
    {
        print_manu();
        ll temp;
        cin>>temp;
        switch(temp)
        {
            case 1:cout<<endl<<"使用顺序表的求解过程为:"<<endl;
                   solve1();
                   break;
            case 2:cout<<endl<<"使用链表的求解过程为:"<<endl;
                   solve2();
                   break;
            case 3:cout<<endl<<"使用递归的求解过程为:"<<endl;
				   solve3(1,1);
                   break;
            case 4:cout<<endl<<"使用二分答案的求解过程为"<<endl;
				   solve4();
                   break;
            case 5:cout<<endl<<"使用数位分解结论的求解过程为"<<endl;
				   solve5();
				   break;
            case 6:cout<<endl<<"感谢使用"<<endl;
                   exit(1);
            default:cout<<endl<<"非法的操作数字!请重新输入!"<<endl;
        }
    }
}



