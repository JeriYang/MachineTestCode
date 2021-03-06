/*
枚举
时间限制：1秒 空间限制：65536K 热度指数：4627

题目描述
    用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入描述:
    测试数据有多组，输入n。
输出描述:
    对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。

示例1
输入
40

输出
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99

思路：
按格式输入->依次枚举x,y,z(避免除法的精度消失)->按格式输出

@author:JeriYang
@time:2019
*/

#include <stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){ //输入
            for(int x=0;x<=100;x++){//枚举X的值
                for(int y=0;y<=100-x;y++){ //枚举y的值
                    int z=100-x-y;//计算z
                    if(15*x+9*y+1*z<=3*n){//重点！！！避免除法带来的精度损失，乘以3
                        printf("x=%d,y=%d,z=%d\n",x,y,z);
                    }
                }
            }
    }
} 