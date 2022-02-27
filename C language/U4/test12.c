//作业，探究float与double的不同
#include <stdio.h>
#include <float.h>
int main()
{
    double dou = 1.0 / 3.0;
    float flo = 1.0 / 3.0;
    printf("%.6f  %.6f\n", flo, dou);
    printf("%.12f  %.12f\n", flo, dou); //可以看到，在7位小数之后float开始失去精度
    printf("%.16f  %.32f\n", flo, dou);
    printf("%d  %d\n", FLT_DIG, DBL_DIG); //这两个值分别对应小数点后精度确定的位数
    return 0;
}
