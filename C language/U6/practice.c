#include <stdio.h>
#include <math.h>
int main() /*
 {
     char a = 'a', ABCarray[26];
     int i;
     for (i = 0; i < 26; i++, a++)
     {
         ABCarray[i] = a;
         printf("%c ", ABCarray[i]);//正序打印字母表
     }
     return 0;
 }
{
    int i;
    double a, sum1 = 1.0, sum2 = 1.0;
    printf("please enter the number:");
    scanf("%d", &i);
    for (a = 2.0; (double)(i + 1) != a; a++)
    {
        sum1 += (1.0 / a) * pow((-1), ((int)a % 2 + 1));//用-1的幂函数控制符号
        sum2 += (1.0 / a);
    }
    printf("\nsum is__%f__", sum1 + sum2);
    printf("\nsum is__%f__", sum1);//收敛
    printf("\nsum is__%f__", sum2);//发散
    return 0;
}*/
{
    double first[8], sum[8];
    int i, s;

    printf("Enter 8 numbers please:\n");
    for (i = 0; i != 8; i++)
    {
        printf("No.%d number:", i + 1);
        s = scanf("%lf", &first[i]);
        if (1 != s)
            break;
        sum[i] = (0 == 1) ? first[0] : (sum[i - 1] + first[i]);
    }

    if (1 == s)
    {
        printf("first array:");
        for (i = 0; i != 8; i++)
            printf("%-6.3f ", first[i]);
        printf("\nsum array  :");
        for (i = 0; i != 8; i++)
            printf("%-6.3f ", sum[i]);
    }
    else
        printf("please check the form,you should enter the numbers!");

    return 0;
}