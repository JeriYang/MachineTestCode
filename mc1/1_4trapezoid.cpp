/*
例题：
时间限制：1秒          内存限制：32兆
题目描述：
输入一个高度h，输出一个高为h，上底边为h的梯形。

输入：
一个整数h(1<=h<=1000)。

输出：
h所对应的梯形。

样例输入：
4

样例输出：
      ****
    ******
  ********
**********

@author:JeriYang
@time:2018
*/

#include<stdio.h>
int main () {
	int h;
	//input
	while (scanf("%d",&h)!= EOF){
		int maxLine = h + (h - 1) * 2; //计算最后一行包含的星号个数
		//output
		for (int i = 1;i <= h;i ++) {
			for (int j = 1;j <= maxLine;j ++) { //依次输出每行当中的空格或星号         
				if (j < maxLine - h - (i - 1) * 2 + 1)
				//空格
				printf(" ");	           
				else
				//星号           
				printf("*");
			}
			printf("\n");
		}    
	}
	return 0;
}
