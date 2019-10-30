/*
Problem Description
搬寝室是很累的,xhd深有体会.时间追述2006年7月9号,那天xhd迫于无奈要从27号楼搬到3号楼,
因为10号要封楼了.看着寝室里的n件物品,xhd开始发呆,因为n是一个小于2000的整数,实在是太多了,
于是xhd决定随便搬2*k件过去就行了.
但还是会很累,因为2*k也不小是一个不大于n的整数.
幸运的是xhd根据多年的搬东西的经验发现每搬一次的疲劳度是和左右手的物品的重量差的平方成正比(这里补充一句,xhd每次搬两件东西,左手一件右手一件).
例如xhd左手拿重量为3的物品,右手拿重量为6的物品,
则他搬完这次的疲劳度为(6-3)^2 = 9.
现在可怜的xhd希望知道搬完这2*k件物品后的最佳状态是怎样的(也就是最低的疲劳度),请告诉他吧.
 
Input
每组输入数据有两行,第一行有两个数n,k(2<=2*k<=n<2000).第二行有n个整数分别表示n件物品的重量(重量是一个小于2^15的正整数).
 
Output
对应每组输入数据,输出数据只有一个表示他的最少的疲劳度,每个一行.
 
 
Sample Input
2 1 1 3
 
Sample Output
4

思路：
按格式输入->找DP方程->按格式输出

@author:JeriYang
@time:2019

*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x7f7f7f7f
#define N 2010
int v[N];
int a[N];
int dp[N][N];
int main()
{
    int n , k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i= 0 ;i < n ; i++) scanf("%d",&v[i]);
        sort(v,v+n);
        for(int i = 1 ; i < n ; i++) a[i-1] = (v[i]-v[i-1])*(v[i]-v[i-1]);
        //memset(dp,0x7f,sizeof(dp));
        for(int i = 0 ; i < n ; i++)
            for(int j = i/2+1 ; j< n ;j++) dp[i][j] = INF;
        for(int j = 0 ; j < n ;j++) dp[j][0] = 0;
        dp[1][1] = a[0];
        for(int i =2 ;i < n ; i++) 
            for(int j = 1 ; 2*j <= i+1 ;j++)
                dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+a[i-1]);
        printf("%d\n",dp[n-1][k]);
    }
    return 0;
}