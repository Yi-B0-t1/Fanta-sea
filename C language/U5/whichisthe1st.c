#include <stdio.h>
int main()
{
    int a = 4 % 3 * 9;
    int b = (3 > 5);
    char ch;
    ch = '%';
    printf("%c and %%\n", ch);
    printf("test ''a number:___%d__%d__", a, b);
    return 0;
}