/*
例题
素数判定
时间限制：1秒		空间限制：65536K
给定一个数n，要求判断其是否为素数（0,1，负数都是非素数）。 
输入描述:
	测试数据有多组，每组输入一个数n。
输出描述:
	对于每组输入,若是素数则输出yes，否则输入no。

示例1
输入
13
输出
yes

思路：多组输入->判断2到sqrt(n)间是否有n的质数->按格式输出

@author:JeriYang
@time:2018
*/

#include<stdio.h>
#include<math.h>
bool judge(int n){         //判断素数函数
    if (n <= 1) return 0;
    else{
        int bound =  sqrt(n);   //不用取整加1，在下面用 i <= bound 一样的效果；
        for (int i = 2; i <= bound; i++) {  //依此枚举这些数能否整除x，若能则不为素数
            if (n%i == 0) return 0; //同 return false;
        }
        return 1;  //同return true
    }
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        if(judge(n)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

/*
练习题：

素数(北航2008机试)
时间限制：1秒    空间限制：65536K
输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。 
输入描述:
    输入有多组数据。
    每组一行，输入n。

输出描述:
    输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数(素数之间用空格隔开，最后一个素数后面没有空格)，如果没有则输出-1。
示例1
输入
100
输出
11 31 41 61 71
*/