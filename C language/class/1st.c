#include <stdio.h>
int main()
{
    double s = 1, a, b;
    for (a = 1, b = 2; a < 10.0, b < 1025; a++, b *= 2)
    {
        s *= 1 / a;
    }
    printf("the sum is__%.20lf__\n", s);
    printf("the sum is__%e__\n", b);
    printf("the number is__%.20lf__", 1.0 / 3.0);
    return 0;
}