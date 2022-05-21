#include <stdio.h>
int main()
{
    union
    {
        unsigned char c;
        unsigned int i;
        /* data */
    } u1;
    char *s = "ASDUU";
    int a[3] = {0, 2, 3}, o = 0;
    int *i = a;
    typedef struct data
    {
        int a;
        float b; /* data */
    } rename;
    struct data a;
    rename a;
    while (*i++)
    {
        printf("AAA");
        break;
    }
    printf("%d\n", o++);
    printf("%d", *i);
    return 0;
}