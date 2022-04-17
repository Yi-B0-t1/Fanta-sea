#include <stdio.h>

int main()

{
    int i, k;

    char a[4][80], b[4];

    for (i = 0; i < 4; i++)

        gets(a[i]);

    for (i = 0; i < 4; i++)

    {
        ________ = a[i][0];

        for (k = 1; a[i][k] != '\0'; k++)

            if (b[i] < ________)

                b[i] = a[i][k];
    }

    for (i = 0; i < 4; i++)

        printf("%d   %c\n", i, b[i]);

    return 0;
}