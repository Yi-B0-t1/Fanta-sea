#include <stdio.h>
#define print printf("press q to quit\nenter the number:") //输入说明
int main()
{
    float sum;
    int n;                                   //阶乘上限
    int m;                                   //累加的中间变量
    int i;                                   //累乘的中间变量
    int j;                                   //每次累加的阶乘
    for (print; scanf("%d", &n) == 1; print) //输入阶乘上限为n
    {
        sum = 0;
        for (m = 1; m <= n; m++) //对于每一项求和从m到n
        {
            for (i = 1, j = 1; i <= m; i++) //第m项的阶乘为j
                j *= i;
            sum += j; //把第m项阶乘j加入总和sum
        }
        printf("sum=%.2f\n", sum);
    }
    return 0;
}