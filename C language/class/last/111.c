#include <stdio.h>
int main()
{
    char s[] = "012xy\061\08s34f4w2";
    int i, n = 0;
    for (i = 0; s[i] != 0; i++)
        if (s[i] >= '0' && s[i] <= '9')
            n++;
    printf("%d\n", n);
    printf("\n the length %d", (sizeof s) / (sizeof(int)));
    return 0;
}