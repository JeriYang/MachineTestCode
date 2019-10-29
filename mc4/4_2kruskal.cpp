/*
时间限制：1秒 空间限制：65536K 热度指数：2988

题目描述
    某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
    当N为0时，输入结束，该用例不被处理。
输出描述:
    对每个测试用例，在1行里输出最小的公路总长度。
示例1
输入：
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
输出
3
5

思路：
按格式输入->最小生成树->按格式输出（根数量-1）

最小生成树（kruskal算法）：https://blog.csdn.net/qq_41754350/article/details/81460643

@author:JeriYang
@time:2019
*/

#include <stdio.h>
#include <stdlib.h>
int Tree[100]; //用来保存每个节点的最上层的父亲节点，起始的根节点的父亲节点为-1
int findRoot(int x){
    if(Tree[x]==-1) return x; //说明该点的父亲节点是自己，相当于是根节点
    else{
        int tmp=findRoot(Tree[x]);//递归寻找最早的父亲节点
        Tree[x]=tmp;
        return tmp;
    }
}
struct Edge{
    int a;
    int b;
    int cost;
}edge[6000];
typedef struct Edge Edge;
int cmp(const void *x,const void *y){
    return (*(Edge*)x).cost-(*(Edge*)y).cost; //复写cmp
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i=1;i<=n*(n-1)/2;i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        qsort(edge+1,n*(n-1)/2,sizeof(Edge),cmp);//将路径按距离排序 每次优先取最短的路径
        for(int i=1;i<=n;i++){
            Tree[i]=-1;
        }
        int ans=0;
        for(int i=1;i<=n*(n-1)/2;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){ //如果该边的两个端点的根节点相同，说明形成了环，那么这条边舍弃
                Tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}