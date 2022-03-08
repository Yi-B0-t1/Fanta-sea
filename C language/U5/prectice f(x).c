#include <stdio.h>
double cube(double(x)); //函数声明：1.返回值类型是 double 2.名字叫 cube 3.参数有 一个 double 类型的值，形参名为x
void main(void)
{
    double num;
    printf("please enter a number and we will return its cube\n");
    scanf("%lf", &num);
    cube(num); /*调用函数的形式：函数名（参数）  一切都在声明中提前说明好了 要和声明的形式一致
    这时因为这条语句中调用了函数，打印了第一遍立方值*/
    printf("test a function's value:__%d__,__%.2f__",
           printf("123456789\n"), cube(num));
    /*注意每次调用函数的时候（将函数的返回值当作常量计算），
    实际上是运行了一遍函数，因此函数的所有“副作用"：如显示特定值
    改变函数内（重点）变量值等都会依次发生，所以会将立方数打印两遍，
    第二遍就是作为参数在printf函数中被调用而又运行一遍的结果*/
}
double cube(double(x))
{
    x = x * x * x;     //函数内变量值暂时（在这一次被调用中）改变
    printf("%f\n", x); //这时候打印出来的是上一条语句改变的x值
    x = 0;             //这个改变也是暂时的，下一次被调用时，x的值还是会重新被输入
    return x;          //函数的返回值永远是0，因为上一条语句每次（函数被调用）都会赋0给x
}