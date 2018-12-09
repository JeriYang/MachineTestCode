/*
例题：(06年清华大学机试题)
题目描述：
二叉树的前序、中序、后序遍历的定义：
前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树；
中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树；
后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。
给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。

输入：
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。

输出：
输入样例可能有多组，对于每组测试样例，
输出一行，为后序遍历的字符串。

样例输入：
ABC
BAC
FDXEAG
XDEFAG

样例输出：
BCA
XEDGAF

思路：还原树->后序遍历树
重点内容，遍历
前序：根，左，右
中序：左，根，右
后序：左，右，根

@author:JeriYang
@time:2018
*/
#include<stdio.h>
#include<string.h>

struct Node{     //树节点结构体
    Node *lchild;//左子树
    Node *rchild;//右子树
    char c;      //节点信息
};

struct Node Tree[50];    //讲台内存分配数组
char str1[30],str2[30];  //放前序和中序
int loc;                 //静态数组中已分配的节点个数

Node *create(){          //申请一个结点空间，返回指向其的指针
    Tree[loc].lchild = Tree[loc].rchild = NULL;//初始化左右子树为空
    loc++; //loc累加，表示已经分配的个数
    return &Tree[loc-1]; //返回申请节点指针
}

//后序遍历树
void postOrder(Node *T){      
    if(T->lchild != NULL)
        postOrder(T->lchild);//递归遍历左子树
    if(T->rchild != NULL)
        postOrder(T->rchild);//递归遍历右子树
    printf("%c",T->c);       //遍历该节点，输出字符
}

//用于还原树
Node *build(int s1,int e1,int s2,int e2){
    //由字符串的前序遍和中序遍历还原树，并返回其根节点
    //s1和e1分别为前序遍历结果的头和尾下标，s2和e2分别为中序遍历结果的头和尾下标
    Node* ret = create(); //为根节点申请空间
    ret->c = str1[s1];    //该节点字符为前序遍历中第一个字符‘根’
    int rootIdex;
    //寻找根节点在中序遍历中的位置
    for(int i=s2; i<=e2; i++){
        if(str2[i] == str1[s1]){
            rootIdex = i;
            break;
        }
    }
    if(rootIdex != s2)//左子树不为空
        ret->lchild = build(s1+1,s1+rootIdex-s2,s2,rootIdex-1);//递归还原左子树

    if(rootIdex != e2)//右子树不为空
        ret->rchild = build(s1+rootIdex-s2+1,e1,rootIdex+1,e2);//递归还原右子树
    return ret;//返回根节点指针
}

int main()
{
    while(scanf("%s",str1) != EOF){        //1. 多组数据输入
        scanf("%s",str2);
        loc = 0;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        Node* T = build(0,len1-1,0,len2-1);//2. 还原树
        postOrder(T);                      //3. 后序遍历树
        printf("\n");
    }
    return 0;
}