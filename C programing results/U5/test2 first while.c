/* shoes2.c -- 计算多个不同鞋码对应的脚长 */
#include <stdio.h>
#include <math.h>
#define ADJUST 7.31 // 字符常量
int main(void)
{
    const double SCALE = 0.333; // const变量
    double shoe, foot;
    printf("Shoe　size　(men's)　　 foot　length\n");
    shoe = 3.0;
    while (shoe < 18.5)               /* while循环开始 */
    {                                 /* 块开始　*/
        foot = SCALE * shoe + ADJUST; //在循环块（block)中加断点能够暂停循环，或者依次进行循环
        printf("%10.1f　%15.2f　inches\n", shoe, foot);
        shoe = shoe + 1.0;
    } /* 块结束　　　 */
    printf("If　the　shoe　fits,　wear　it.\n");
    int new = pow(2, 6);
    printf("test new operater: 2^2: %d\a", new);
    return 0;
}
//注意检查和step by step run block的方法 再循环之中加断点