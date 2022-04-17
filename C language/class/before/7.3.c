/*算术模板*/
#include <stdio.h>
#define result gcd(num1, num2)
#define print printf("please enter the number with the form\"num1,num2\"\npress q to quit:")

int gcd(int num1, int num2);
int main()
{
    int num1, num2;
    for (print; 2 == scanf("%d,%d", &num1, &num2); print)
    {
        /*if (num1 <= num2)
        {
            printf("\nshould num1>num2\n");
            continue;
        }*/
        printf("\nthe result is %d\n", result);
    }
    return 0;
}
int gcd(int num1, int num2)
{
    int a, b, temp;
    if (num1 < num2) /*交换两个数，使大数放在 num1 上*/
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    a = num1;
    b = num2;
    while (b != 0) /*利用辗除法，直到 b 为 0 为止*/
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}