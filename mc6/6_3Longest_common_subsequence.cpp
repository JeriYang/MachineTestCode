/*
LCS
题目描述
给定两个字符串str1和str2，输出连个字符串的最长公共子序列。如过最长公共子序列为空，则输出-1。

输入描述:
输出包括两行，第一行代表字符串str1，第二行代表str2。\left( 1\leq length(str1),length(str2) \leq 5000\right)(1≤length(str1),length(str2)≤5000)
输出描述:
输出一行，代表他们最长公共子序列。如果公共子序列的长度为空，则输出-1。

示例1
输入
1A2C3D4B56
B1D23CA45B6A

输出
123456
说明
"123456"和“12C4B6”都是最长公共子序列，任意输出一个。

备注:
时间复杂度O(n*m)O(n∗m)，空间复杂度O(n*m)O(n∗m)。(n,m分别表示两个字符串长度)

思路：
按格式输入->找DP方程->按格式输出

@author:JeriYang
@time:2019

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=0;i<s1.size()+1;i++)
    {
        for(int j=0;j<s2.size()+1;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[s1.size()][s2.size()]<<endl;
    return 0;
}