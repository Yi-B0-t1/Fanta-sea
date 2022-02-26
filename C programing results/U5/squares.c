/* squares.c -- 计算1～20的平方 */
#include <stdio.h>
#include <math.h>
int main(void)
{
    int num = 1;
    while (num < 21)
    {
        printf("%4d %6d\n", num, pow(num, 2));
        num = num + 1;
    }
    return 0;
}