/*
例题：
时间限制：1秒  空间限制：32768K
题目描述
输入一系列整数，建立二叉排序树，并进行前序，中序，后序遍历。

输入描述:
输入第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。

输出描述:
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。
输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。

示例1
输入
5
1 6 5 9 8

输出
1 6 5 9 8 
1 5 6 8 9 
5 8 9 6 1 

思路：排序树->遍历树
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

struct Node Tree[110];   //静态内存分配数组
int loc;                 //静态数组中已分配的节点个数

Node *creat(){          //申请一个结点空间，返回指向其的指针
    Tree[loc].lchild = Tree[loc].rchild = NULL;//初始化左右子树为空
	loc++; //loc累加，表示已经分配的个数
    return &Tree[loc-1]; //返回申请节点指针
}

//前序遍历树
void preOrder(Node *T){   
	printf("%d ",T->c);       //遍历该节点，输出字符(根)
    if(T->lchild != NULL)
        preOrder(T->lchild);//递归遍历左子树
    if(T->rchild != NULL)
        preOrder(T->rchild);//递归遍历右子树
}

//中序遍历树
void inOrder(Node *T){      
    if(T->lchild != NULL)
       inOrder(T->lchild);//递归遍历左子树
	printf("%d ",T->c);       //遍历该节点，输出字符(根)
    if(T->rchild != NULL)
        inOrder(T->rchild);//递归遍历右子树
}

//后序遍历树
void postOrder(Node *T){      
    if(T->lchild != NULL)
        postOrder(T->lchild);//递归遍历左子树
    if(T->rchild != NULL)
        postOrder(T->rchild);//递归遍历右子树
    printf("%d ",T->c);       //遍历该节点，输出字符(根)
}

//用于生成排序树
Node *Insert(Node *T, int x){
    if(T == NULL){    //空树时
		T = creat();
		T->c = x;
		return T;
	}
	else if(x < T->c){ //非空树，且小于根节点的值时
		T->lchild = Insert(T->lchild, x); //递归插入左子树
	}
	else if(x > T->c){ //非空树，且大于根节点的值时
		T->rchild = Insert(T->rchild, x); //递归插入右子树
	}
	//等于时，根据题目意思，直接无视即可
    return T;//返回根节点指针
}

int main()
{
	int n; //节点数
		//1. 多组数据输入
    while(scanf("%d", &n) != EOF){        
		//2. 生成排序树
        loc = 0;        //初始化数组
		Node *T = NULL; //初始化二叉树根节点为空
		for(int i = 0; i < n; i++){ //依次输入节点的值
			int m;
			scanf("%d",&m);
			T = Insert(T,m); //插入排序树
		}
		//3.遍历（按格式输出）
		preOrder(T); //前序
		printf("\n");
		inOrder(T);  //中序
		printf("\n");
		postOrder(T);//后序
		printf("\n");
	}
    return 0;
}