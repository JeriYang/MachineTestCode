/*
例题：
N的阶乘（2006年清华计算机）
时间限制：1秒   空间限制：65536K

输入一个正整数N，输出N的阶乘。 
输入描述:
	正整数N(0<=N<=1000)

输出描述:
	输入可能包括多组数据，对于每一组输入数据，输出N的阶乘

示例1
输入
4
5
15

输出
24
120
1307674368000

思路：
输入小于1000，因此四位保存即可
多组数据输入->大数乘法(用将要乘的小乘数来乘高精度整数的每一位数并加上来自低位的进位即可)
->多组数据输出

@author:JeriYang
@time:2018
*/

#include<stdio.h>
#include<string.h>
struct bigInteger{
    int digit[1000]; //按四位一个单位来保存数值
    int size;        //用于保存大数有几个四位
    void init(){     //初始化大数全为0
        for(int i=0; i<1000; i++) digit[i]=0;
        size = 0;
    }
    void set(int x){  //用一个小于4位的整数，来设置高精度整数
        init();
        do{
            digit[size++] = x%10000;
            x/=10000;
        }while(x!=0);
    }
    bigInteger operator * (int x) const{   //高精度整数与普通整数的乘积（复写乘法）
        bigInteger ret;  //结果
        ret.init();      //初始化
        int carry=0;     //进位初始化
        for(int i=0;i<size;i++){  //2. 用将要乘的小乘数来乘高精度整数的每一位数并加上来自低位的进位
            int tmp=x*digit[i]+carry;
            carry = tmp/10000;      //更新进位
            tmp = tmp%10000;        //去除进位部分
            ret.digit[ret.size]=tmp;
            ret.size++;
        }
		while(carry!=0){  //处理最后一次进位
		    ret.digit[ret.size]=carry%10000;
		    ret.size++;
		    carry /= 10000;
		}        
         
        return ret;
    }
    void output(){    //3. 用于输出(区分首位即可)
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
        printf("\n");
    }    
}a;
int main(){
    int n;
    while(scanf("%d",&n) != EOF){ //1.多组数据输入
        a.init(); //初始化a
        a.set(1); //初始化a为1
        for(int i=1;i<=n;i++){
            a=a*i;  //2.依次乘以小乘数
        }
        a.output(); //3.输出
    }
    return 0;
}
