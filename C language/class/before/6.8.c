#include <stdio.h>
#include <math.h>
int main()
{
    double sum, j = 1, i; // counter
    for (i = 1, sum = 0; fabs(j) > 1e-6; i++)
    {
        j = (pow(-1, i + 1)) * (1.0 / (2.0 * i - 1.0));
        sum += j;
    }
    printf("pi=%f", 4 * sum);
    return 0;
}