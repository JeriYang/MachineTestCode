/*
Floyd算法 and Dijkstra
时间限制：1秒 空间限制：32768K 热度指数：1532

题目描述
在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的t-shirt。但是每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是非常累的！所以现在他们想要寻找最短的从商店到赛场的路线，你可以帮助他们吗？

输入描述:
输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M则表示在成都有几条路。N=M=0表示输入结束。接下来M行，每行包括3个整数A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口A与路口B之间有一条路，我们的工作人员需要C分钟的时间走过这条路。
       
输入保证至少存在1条商店到赛场的路线。
       
输出描述:
对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间

示例1
输入：
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0

输出：
3
2

思路1：
按格式输入->Floyd算法

思路2：
按格式输入->Dijkstra

@author:JeriYang
@time:2019
*/

//Floyd算法
#include <stdio.h>
#define INF 0x7FFFFFFF
int dist[100][100];
int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        if (!N && !M)break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i!=j)dist[i][j] = INF;
                else dist[i][j] = 0;
            }
        }
        int a, b, cost;
        while (M--) {
            scanf("%d%d%d", &a, &b, &cost);
            dist[a-1][b-1] = dist[b-1][a-1] = cost;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if ((dist[i][k] == INF || dist[k][j] == INF)||(i==j))continue;
                    dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
                }
            }
        }
        printf("%d\n", dist[0][N - 1]);
    }
    return 0;
}

/*Dijkstra
#include <stdio.h>
#include <memory.h>
#define INF 0x7FFFFFFF
int dist[100][100];
bool flag[100];
int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        if (!N && !M)break;
        memset(flag, false, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i!=j)dist[i][j] = INF;
                else dist[i][j] = 0;
            }
        }
        int a, b, cost;
        while (M--) {
            scanf("%d%d%d", &a, &b, &cost);
            dist[a-1][b-1] = dist[b-1][a-1] = cost;
        }
        flag[0] = true;
        int min, tmp = 1;
        for (int i = 1; i < N; i++) {
            min = INF;
            for (int j = 1; j < N; j++) {
                if (flag[j])continue;
                if (dist[0][j] < min) {
                    min = dist[0][j];
                    tmp = j;
                }
            }
            flag[tmp] = true;
            if (tmp == N - 1)break;
            for (int j = 1; j < N; j++) {
                if (flag[j]||dist[tmp][j]==INF)continue;
                if (dist[0][tmp] + dist[tmp][j] < dist[0][j])dist[0][j] = dist[0][tmp] + dist[tmp][j];
            }
        }
        printf("%d\n", dist[0][N - 1]);
    }
    return 0;
}
*/