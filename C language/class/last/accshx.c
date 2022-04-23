#include <stdio.h>
#include <math.h>
double arcsh(double num);
int main(void)
{
    double num;
    scanf("%lf", &num);
    printf("%f", arcsh(num));
    return 0;
}
double everyone(int n, double num);
double arcsh(double num)
{
    double sum, every = 1.0;
    int n;
    for (sum = num, n = 1; fabs(every) >= 10e-7; n++)
        sum += (every = everyone(n, num));
    return sum;
}
double sum1(int n);
double sum2(int n);
double everyone(int n, double num)
{
    return (pow(-1, (double)n) * ((sum1(n) / sum2(n)) * (pow(num, (double)(2 * n + 1)) / (double)(2 * n + 1))));
}
double sum1(int n)
{
    int counter;
    double sum;
    for (sum = 1, counter = 1; counter <= n; counter++)
        sum *= 2 * counter - 1;
    return sum;
}
double sum2(int n)
{
    int counter;
    double sum;
    for (sum = 1, counter = 1; counter <= n; counter++)
        sum *= 2 * counter;
    return sum;
}