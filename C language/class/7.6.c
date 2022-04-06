#include <stdio.h>
#define introduction printf("please enter the number with the form\"num1\"\npress q to quit:")
void pr_rev(int num1);
int main()
{
    int num1;
    for (introduction; 1 == scanf("%d", &num1); introduction)
        pr_rev(num1), printf("  is the result\n");
    return 0;
}
void pr_rev(int num1)
{
    if (num1 < 10)
        printf("%d", num1);
    else
    {
        printf("%d", num1 % 10);
        pr_rev(num1 / 10);
    }
}