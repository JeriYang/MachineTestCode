/*
    对输入的n个数进行排序并输出。 
输入描述:
    输入的第一行包括一个整数n(1<=n<=100)。
    接下来的一行包括n个整数。


输出描述:
    可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
    每组测试数据的结果占一行。

示例1
输入
4
1 4 3 2

输出
4 3 2 1
*/


#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){ //降序
	return a>b;
}

//快速排序 
/*
void fastSort(int a[],int low,int high){
	if(low<high){
		int  i =low,j = high;
		int temp;
		temp = a[i];
		while(i<j){
			while(i<j&&a[j]>=temp) j--;
			if(i<j){
				a[i] = a[j];
				i++;
			}
			while(i<j&&a[i]<=temp) i++;
			if(i<j){
				a[j] = a[i];
				j--; 
			}   
		}
		a[i] = temp;
		fastSort(a,low,i-1);
		fastSort(a,i+1,high);
	}
}*/

int main(){
	int n; //输入个数
	int buf[100]; 
	while(scanf("%d", &n)!=EOF){
		//1. input
		for(int i = 0; i < n; i++){
			scanf("%d",&buf[i]);
		}
		//2. sort
		sort(buf,buf+n,cmp);

		//3. output
		for(i = 0; i < n; i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}