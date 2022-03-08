#include <stdio.h>
int main()
{
    int a;
    float f1 = 123456789.123456789;
    double f12 = 123456789.123456789;
    long double f13 = 123456789.123456789;
    float f2 = 2.1;
    char c = 250;                               // I input
    float f = f1 + f2;                          // P process
    printf("the number is __%.20llf__\n", f1);  // O output
    printf("the number is __%.20f__\n", f13);   // O output
    printf("the number is __%.20llf__\n", f12); // O output
    printf("the number is __%.20Ld_\n\n", f13); // O output

    printf("the number is __%.20Ld__\n", f1);    // O output
    printf("the number is __%.20ld__\n", f1);    // O output
    printf("the number is __%.20lf__\n", f12);   // O output
    printf("the number is __%.20lf__\n\n", f13); // O output

    printf("the number is __%.20lf__\n", f1);  // O output
    printf("the number is __%.20f__\n", f1);   // O output
    printf("the number is __%.20f__\n", f1);   // O output
    printf("the number is __%.20f__\n\n", f1); // O output

    printf("the number is __%d__\n", sizeof(float));
    printf("the number is __%d\t%d__\n", 123456789, 123456789);
    return 0;
}