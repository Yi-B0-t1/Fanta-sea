#include <stdio.h>
int main()
{
    int a = 1;
    int b = (3 > 5);
    int x = 1, y = 2;
    double z = -.3;
    int c = 7, d = -2;
    char ch = NULL;
    printf("result_____%d_____\n", a + 'a');
    printf("result_____%d_____\n", sizeof(short int));
    printf("%c and %%\n", ch);
    printf("test ''a number:___%d__%d__", a, 5 % -2);
    return 0;
}
/*
#include <stdio.h>
int main()
{
    int i, j, k;
    i = 3;
    j = 4;
    k = 5;
    printf("%d", !(i + j) + k - 1 && j + k / 2);
    return 0;
}*/