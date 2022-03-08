/* shoes1.c -- 把鞋码转换成英寸 */
#include <stdio.h>
#include <math.h>
#define ADJUST 7.31 //字符常量
int main(void)
{
    const double SCALE = 0.333; // const变量
    double shoe, foot;
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe　\fsize　(men's)　　 foot　length\n");
    printf("%10.1f　%15.2f　inches\n", shoe, foot);
    int new = pow(2, 6); //在man文档（manual)中查看库函数的归属头文件
    printf("test new operater: 2^2: %d\a", new);
    return 0;
}