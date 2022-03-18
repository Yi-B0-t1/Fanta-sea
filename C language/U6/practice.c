#include <stdio.h>
#include <math.h>
int main() /*
 {
     char a = 'a', ABCarray[26];
     int i;
     for (i = 0; i < 26; i++, a++)
     {
         ABCarray[i] = a;
         printf("%c ", ABCarray[i]);
     }
     return 0;
 }*/
{
    int i;
    double a, sum1 = 1.0, sum2 = 1.0;
    printf("please enter the number:");
    scanf("%d", &i);
    for (a = 2.0; (double)(i + 1) != a; a++)
    {
        sum1 += (1.0 / a) * pow((-1), ((int)a % 2 + 1));
        sum2 += (1.0 / a);
    }
    printf("\nsum is__%f__", sum1 + sum2);
    printf("\nsum is__%f__", sum1);
    printf("\nsum is__%f__", sum2);
    return 0;
}