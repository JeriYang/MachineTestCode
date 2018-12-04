/*
例题：
    时间限制：1秒   空间限制：65536K
    输入N个学生的信息，然后进行查询。 
输入描述:
    输入的第一行为N，即学生的个数(N<=1000)
    接下来的N行包括N个学生的信息，信息格式如下：
    01 李江 男 21
    02 刘唐 男 23
    03 张军 男 19
    04 王娜 女 19
    然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
    02
    03
    01
04

输出描述:
    输出M行，每行包括一个对应于查询的学生的信息。
    如果没有对应的学生信息，则输出“No Answer!”

示例1
输入
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03

输出
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19

@author:JeriYang
@time:2018
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
 
struct Student{     //用于表示学生个体的结构体
    char no[100];   //学号
    char name[100]; //姓名
    int age;        //年龄
    char sex[5];    //性别
}buf[1000];

bool cmp(Student a, Student b){    //比较函数
    return strcmp(a.no, b.no) < 0;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        //input
        for(int i = 0; i < n; i ++){
            scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
        }
        sort(buf, buf + n, cmp);//对数组排序使其按照学号升序排列
        int m;
        scanf("%d", &m);        //有m组询问
        while (m-- != 0){       //while循环保证查询次数为m
            int ans = -1;       //目标元素下标,初始化为-1
            char x[30];
            scanf("%s",x);      //待查找学号
            int top = n - 1,base = 0;            //初试时，开始下标0,结束下标n-1,查找子集为整个数组
            while(top >= base){                  //当查找子集不为空集时重复二分查找
                int mid = (top + base) / 2;      //计算中间点下标
                int tmp = strcmp(buf[mid].no,x); //比较中间点学号与目标学号
                if (tmp == 0){
                ans = mid;
                break;                           //若相等,则查找完成跳出二分查找
                }
                else if(tmp > 0) top = mid - 1;  // 若大于,则结束下标变为中间点前一个点下标
                else base = mid + 1;             // 若小于,则开始点下标变为中间点后一个点坐标
            }
            if (ans == -1){ //若查找失败
                printf("No Answer!\n");
            }
            else printf("%s %s %s %d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age); //若查找成功
        }
    }
    return 0;
}