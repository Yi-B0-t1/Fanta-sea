#include <stdio.h>
#define result (num2 * (gcd(num1 - 1, num2))) - ((num1 - 1) * (gcd(num1 - 2, num2)))
#define print printf("please enter the number with the form\"num1,num2\"\npress q to quit:")
double gcd(int num1, double num2);
int main()
{
    int num1;
    double num2;
    for (print; 2 == scanf("%d,%lf", &num1, &num2); print)
    {
        if (num1 >= 0)
        {
            int i;
            printf("H(0, %.1f)=   1.00\n", num2);
            for (i = 1; i <= num1; i++)
                printf("H(%d, %.1f)=%7.2f\n", i, num2, gcd(i, num2));
        }
        else
            printf("n should >0");
    }
    return 0;
}
double gcd(int num1, double num2)
{
    double res;
    res = 2 * ((num1 >= 2) ? (result) : ((num1 == 1) ? num2 : 0.5));
    return res;
}