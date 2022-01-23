#include<stdio.h>
int b();
int c();
int main()
{
    b();printf(",");c();printf("\n");
    c();printf(",\n");
    b();
    return 0;
}
int b()
{
    printf("Brzail, Russia");
}
int c()
{
    printf("India, China");
}