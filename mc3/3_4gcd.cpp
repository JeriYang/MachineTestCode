/*
例题：
最大公约数
时间限制：1秒  空间限制：65536K

输入两个正整数，求其最大公约数。 
输入描述:
	测试数据有多组，每组输入两个正整数。

输出描述:
	对于每组输入,请输出其最大公约数。

示例1
输入
49 14
输出
7

思路：
多组输入->欧几里得算法->输出

@author:JeriYang
@time:2018
*/

#include<stdio.h>
int gcd(int a, int b) {
    if (b == 0)return a + b;  //若b为0，则求得最大的公约数a
    else return gcd(b, a%b);  //否则，递归求b和a取余b的最大公约数
}
int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {  //1.多组数据输入
        printf("%d\n", gcd(a, b));          //求最大公约数
    }
    return 0;
}