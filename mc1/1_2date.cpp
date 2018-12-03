/*
时间限制：1秒    空间限制：65536K
例题：
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天（0<年数<5000）
输入描述:
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出描述:
每组数据输出一行，即日期差值
示例：
输入
20110412
20110422

输出
11

@author:JeriYang
@time:2018
*/

#include<stdio.h>
//判断是否是闰年
int IsYeap(int x){
	if(x%100!=0 && x%4==0 || x%400==0){
		return 1;//yes
	}
	else{
		return 0;//no
	}
}
//返回绝对值
int Abs(int x){
    if(x<0){
		return -x;
	}
	else{
		return x;
	}
}
//平年和闰年
int dayofMonth[2][13]={
	0,31,28,31,30,31,30,31,31,30,31,30,31,
	0,31,29,31,30,31,30,31,31,30,31,30,31,
};

//日期的结构体
struct Date{
	int Year;
	int Month;
	int Day;//0 1 32
    void nextDay(){
        Day++;
        if(Day>dayofMonth[IsYeap(Year)][Month]){
            Day=1; //0 1 1
            Month++;//0 2 1->0 13 1
            if(Month>12){
                Month=1;//0 1 1
                Year++;//1 1 1
            }
         }
      }
};

int buf[5001][13][32];

int main(){
	//三维数组赋值
	Date tmp;
    int cnt=0;  //天数计数
    tmp.Year=0;
	tmp.Month=1;
	tmp.Day=1;
    while(tmp.Year!=5001){
        buf[tmp.Year][tmp.Month][tmp.Day]=cnt; 
        tmp.nextDay();//计算下一天日期
        cnt++;
    }

	int y1,m1,d1;
	int y2,m2,d2;
	//yyyy= (y1-'0')*1000
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",Abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
	}
	return 0;
}