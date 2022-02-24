/* floatcnv.c -- 不匹配的浮点型转换 */
//未解之谜
#include <stdio.h>
int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld%ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4); //书上写这一行后面两个不能正确显示,不同的编译器寄存方式不一样吧
    double AA;
    scanf("%la", &AA); //书上没有写la是不是对应了double的p计数法输入，自己试了试，好像不是，但我也没搞懂p记法怎么正确输入
    printf("%a", AA);
    return 0;
}