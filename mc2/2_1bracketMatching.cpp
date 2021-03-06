/*
例题：
题目描述：
    在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。
    写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

输入：
    输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100。

输出：
    对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"","?"和空格组成，""和"?"表示与之对应的左括号和右括号不能匹配。

样例输入：
)(rttyy())sss)(
样例输出：
)(rttyy())sss)(
?            ?$

@author: JeriYang
@time: 2018
*/

#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

stack<int> S;      //定义一个堆栈
char str[110]={0}; //定义输入字符串，并输出化为0
char ans[110];     //定义输出字符串

int main(){
	while(scanf("%s",&str) != EOF){  //多组输入
		for(int i=0; str[i]!=0; i++){ //遍历字符
			if(str[i] == '('){         //1.遇到左括号 
				S.push(i);             //左括号索引入栈
				ans[i] = '$';          //保存未匹配字符'$'
			}
			else if(str[i]==')'){        //2.遇到右括号，弹栈
				if(S.empty() == false){  //有左括号，则成功弹栈，并将
					int tmp = S.top();   //取之前未匹配字符'$'的索引
					S.pop();
					ans[tmp]=' '; //将原左括号对应的'$'置为' '
					ans[i]=' ';
				}
				else{
					ans[i]='?'; //没有匹配的，则置为'?'
				}
			}
			else{
				ans[i]=' '; //其他字符对应' '
			}
		}
		printf("%s\n",str);
		printf("%s",ans);
	}
	return 0;
}