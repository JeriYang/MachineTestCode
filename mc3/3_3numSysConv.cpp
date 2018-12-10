/*
例题：
数制转换
时间限制：1秒  空间限制：65536K
求任意两个不同进制非负整数的转换（2进制～16进制），所给整数在long所能表达的范围之内。     
不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。 
输入描述:
    输入只有一行，包含三个整数a，n，b。
    a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，2 =< a，b <= 16。
    数据可能存在包含前导零的情况。

输出描述:
    可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）。
示例1
输入
15 Aab3 7
输出
210306

思路：
转10进制->转其他进制

@author:JeriYang
@time:2018
*/

#include<stdio.h>
#include<string.h>
int main() {
    int a, b;
    char str[40];
    	//1.多组数据输入
    while (scanf("%d%s%d", &a, str, &b) != EOF) {
        long temp = 0;          //保存十进制结果
        int size = strlen(str); //保存长度
        int c = 1;              //初始化权重
        //1.转10进制，数位拆解的转化
        for (int i = size-1; i >= 0; i--) {
        	int x;
            if (str[i] <= 'f' && str[i] >= 'a') { //小写字母处理
                x = (str[i] - 'a') + 10;
            }
            else if (str[i] <= 'F'&&str[i] >= 'A') { //大写字母处理
                x = (str[i] - 'A') + 10;
            }
            else x = (str[i]-'0'); //数字处理
            temp = temp + x*c;
            c = c*a;  //下一个数的权重
        }
        //2.转对应的进制
        char str2[40]; int p = 0; //用str2保存b进制的各个数位的数字
         do{
            if (temp%b >= 10) { //大于10时
                str2[p] = temp % b - 10 + 'A'; //转换为字符并保存
                p++;
            }
            else{
            	str2[p] = temp % b + '0'; //转换为字符并保存
            	p++;
            }
            temp /= b;
         } while (temp);
        for (int i = --p; i >= 0; i--) {
            printf("%c", str2[i]);
        }
        printf("\n");
    }
    return 0;
}