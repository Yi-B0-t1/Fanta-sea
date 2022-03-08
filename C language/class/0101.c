#include <stdio.h>
int main()
{
    float x, y;
    int a, b;
    x = a = 7.873;
    printf("%f\t%d\t\n", x, a);
    a = x = 7.873;
    printf("%f\t%d\t\n", x, a);
    x = a = y = 7.873;
    printf("%f\t%f\t%d\t\n", x, y, a);
    b = x = (a = 25, 15 / 2.);
    printf("%f\t%d\t%d\t\n", x, a, b);
    return 0;
}