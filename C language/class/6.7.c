#include <stdio.h>
int isprime(int x);
int main()
{
    int n, x;
    for (n = 90; n <= 100; n += 2)
        for (x = 3; x < n / 2; x += 2)
            if (isprime(x) && isprime(n - x))
                printf("n=%d=%d+%d\n", n, x, n - x);
    return 0;
}
int isprime(int x)
{
    int i;
    for (i = 2; x % i != 0; i++)
        continue;
    return ((i == x) ? 1 : 0);
}
