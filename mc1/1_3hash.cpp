/*
题目描述：（时间限制1s，内存限制128M）
	给你n个整数，请从大到小的顺序输出其中前m大的数。
输入：
	每组测试数据有两行，第一行有两个数n, m(0<n,m<1000000)，
	第二行包含n个各不相同，且都处于[-500000，500000]的整数
输出：
	对每组测试数据按从大到小的顺序输出前m大的数

样例输入：
	5 3
	3 -35 92 213 -644
样例输出：
	213 92 3

@author: JeriYang
@time: 2018
*/
#include<stdio.h>
int Hash[1000001];

int main(){
	int OFFSET=500000;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		//init
		for(int i= -500000; i<=500000; i++){
			Hash[i+OFFSET] = 0;
		}
		//input
		for(i = 0; i <n; i++){
			int x;
			scanf("%d",&x);
			Hash[x+OFFSET]=1;
		}

		//output
		for(i = 500000; i>=-500000; i--){
			if(Hash[i+OFFSET]==1){
				printf("%d",i);
				m--;
				if(m != 0) printf(" ");
				else{
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}



