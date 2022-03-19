#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch1;
    printf("请输入考核等级(A`E):");
    ch1 = getchar(), ch1 = tolower(ch1);
    if ('a' == ch1)
        printf("90`100");
    else if ('b' == ch1)
        printf("80`89");
    else if ('c' == ch1)
        printf("70`79");
    else if ('d' == ch1)
        printf("60`69");
    else if ('e' == ch1)
        printf("0`59");
    else
        printf("error");
    return 0;
}