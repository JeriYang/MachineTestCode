/*
最小公倍数

题目描述：
	求两个自然数的最小公倍数

输入说明：
	输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数

输出说明：
	对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。

输入样例：
2 4
输出样例：
4

思路:最小公倍数 = 两数乘积/最大公约数

@author:JeriYang
@time:2018
*/
 
#include <stdio.h>
//求最大公约数
int gcd(int a,int b){
	if(b==0) return a;//关键:默认b!=0，因为取模的时候b不能为0
	else return gcd(b,a%b);//其他情况用递归
}
 
int main(){
	int a,b;
	//1.多组数据输入
	while(scanf("%d %d",&a,&b) != EOF){
		int gcd = gcd(a,b);  //2.求最大公约数
		printf("%d\n",a*b/gcd);//3.最小公倍数 = 两数乘积/最大公约数
	}
	return 0;
}