/*
贪心算法：可拆分类型，选性价比最高的
贪心入门题，

时间限制：1秒
**内存限制：32兆  **
特殊判题：否

题目描述：
	FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
	The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. 
	FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food.
	Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
输入：
	The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. 
	Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. 
	All integers are not greater than 1000.
输出：
	For each test case, print in a single line a real number accurate up to 3 decimal places, 
	which is the maximum amount of JavaBeans that FatMouse can obtain.

个人觉得这句话难理解：he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food：这样表达可以购买几分之几的。
题目大意：
	有m元钱，n种物品；每种物品有j磅，总价值f元，可以使用0到f的任意价格购买相应磅的物品，
	例如使用0.3f元，可以购买0.3j磅物品。要求输出用m元钱最多能买到多少磅物品。
	多组数据输入，输入-1,-1结束

样例输入：
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1

样例输出：
13.333
31.500

@author:JeriYang
@time:2018
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
struct goods{
	double j; //重量
	double f; //价格
	double s; //1单位价格能买的重量(性价比)
}buf[1000];  //题目说数量最大不超过1000

//比较函数，降序
bool cmp(goods A, goods B){
	return A.s > B.s;
}

int main(){
	double m; //有m元钱
	int n;    //n个物品
	while(scanf("%lf%d",&m,&n) != EOF){
		if(m == -1 && n == -1) break;  //停止输入
		//input
		for(int i = 0; i<n; i++){
			scanf("%lf%lf",&buf[i].j,&buf[i].f);
			buf[i].s=buf[i].j/buf[i].f;
		}
		sort(buf, buf+n, cmp); //按性价比降序排序

		//output
		int index = 0;   //商品索引
		double res = 0;  //总重量
		while(m > 0 && index < n){ //有钱，且有商品
			if(m > buf[index].f){
				res = res + buf[index].j; //买的物品重量
				m = m - buf[index].f; //剩下的钱
				index++; //下一件商品
			}
			else{
				res = res + buf[index].s * m;
				m = 0;
			} 
		}
		printf("%.3lf\n",res); //保留三位小数(按格式输出)
	}
return 0;
}

