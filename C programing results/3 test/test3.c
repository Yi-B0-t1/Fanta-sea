/* showf_pt.c -- 以两种方式显示float类型的值 */
#include<stdio.h>
int main(){
    float aboat=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;
    printf("%f　can　be　written　%e\n",aboat,aboat);
    // 下一行要求编译器支持C99或其中的相关特性
    printf("And it's %a in hexadecimal, powers of 2　notation\n",aboat);
    printf("%f　can　be　written　%e\n",abet,abet);
    printf("%Lf　can　be　written　%Le\n",dip,dip);
    float toosmall= 0.4E-88*1/100.0f;
    printf("%e\n", toosmall);
    long double a,b;
    b=2.0e20+1.0;
    a=b-2.0e20;
    printf("%lle　\n",a);
    return 0;
}