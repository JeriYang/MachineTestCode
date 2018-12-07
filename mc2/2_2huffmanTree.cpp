/*

例题：
时间限制：1秒  空间限制：65536K
哈夫曼树，第一行输入一个数n，表示叶结点的个数。
需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有结点的值与权值的乘积之和。 
输入描述:
	输入有多组数据。
	每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。

输出描述:
	输出权值。

示例1
输入
5  
1 2 2 5 9
输出
37

@author:JeriYang
@time:2018
*/

#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >Q;  //建立小顶堆Q

int main(){
	int n;
	int input;
	while(scanf("%d",&n) != EOF){  //多组输入
		while(Q.empty()==false) Q.pop();
		for(int i = 0; i < n; i++){
			scanf("%d",&input);
			Q.push(input);
		}
		//初始化乘积和为0
		int sum = 0;

		//计算值与权重值的乘积和
		if(n == 1){
			sum += 0;
		}
		else{
			while(Q.size()>1){
				int left = Q.top();  //选取最小的
				Q.pop();
				int rig = Q.top();   //选取第二小的
				Q.pop();
				sum += left+rig;
				Q.push(left+rig);    //重构小顶堆
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}