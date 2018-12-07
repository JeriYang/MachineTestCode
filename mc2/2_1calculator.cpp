/*
练习题
时间限制：1s  内存限制：32M
（2006年浙江大学机试）
题目描述：
    读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
输入：
    测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。
样例输入：
1 + 2
4 + 2 * 5 - 7 / 11
0
样例输出：
3.00
13.36


传统方法：两个栈，一个保存运算符，一个保存数字
本题：由于不考虑括号，可取巧，仅使用一个栈（书上代码太多了。）
思路：
一个栈：
①若遇到加号把数字入栈；
②若遇到减号则将数字转换为负数后入栈；
③若遇到乘除则就近直接计算后，再把数值入栈；
④最后求和栈内的数字。按格式输出


@author:JeriYang
@time:2018
*/

#include <stdio.h>
#include <stack>
using namespace std;
stack<double> Snum; //定义栈

int main(){
    int num1;   //第一个输入数字
    int num2;   //之后的输入数字
    char c1,c2;  //用来保存前后空格以及运算符
    double res;  //结果

    while( scanf("%d%c",&num1,&c2)!=EOF ){
        if( num1==0 && c2=='\n') break;  //输入0时结束
		//初始化结果为0
        res = 0;
        Snum.push(1.0*num1); //转换为浮点数入栈
        //ans[++tail] = 1.0*temp1;  
        while(scanf("%c %d%c",&c1,&num2,&c2) != EOF){  //c1此时为运算符，c2为空格
            if( c1=='+'){                //如果是加号直接入栈
            	Snum.push(1.0*num2);
            }
            else if( c1=='-'){           //如果是负号转换为负数再入栈
            	Snum.push(-1.0*num2);   
            }
            else if( c1=='*'){           //如果是乘号则出栈更新数字后入栈
            	double mid1 = Snum.top();
            	Snum.pop();
            	Snum.push(mid1 * num2);
            }
            else if( c1=='/' && num2!=0){ //如果是除号(非0)则出栈更新数字后入栈
            	double mid2 = Snum.top();
            	Snum.pop();
            	Snum.push(num2 / mid2);  
            }
            else break;
            if( c2!=' ') break;  //如果最后一个字符不是空格则输入结束
        }
        while(!Snum.empty()){  //求和栈
        	double topNum = Snum.top();
        	Snum.pop();
        	res = res + topNum;
        }
        printf("%.2lf\n",res);
    }
    return 0;
}