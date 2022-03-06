#include <stdio.h>
double cube(double(x));
void main(void)
{
    double num;
    printf("please enter a number and we will return its cube\n");
    scanf("%lf", &num);
    cube(num);
    printf("test a function's value:__%d__,__%.2f__",
           printf("123456789\n"), cube(num));
    /*注意每次调用函数的时候（将函数的返回值当作常量计算），
    实际上是运行了一遍函数，因此函数的所有“副作用"：如显示特定值
    改变函数内（重点）变量值都会依次发生，所以会将平方数打印两遍，
    第二遍就是在printf函数中被调用而又执行一遍的结果*/
}
double cube(double(x))
{
    x = x * x * x;
    printf("%f\n", x);
    return x;
}