#include<stdio.h>
int f();
int j();
int main()
{
    f();
    f();
    f();
    j();
    return 0;
}
int f()
{
    printf("For　he's　a　jolly　good　fellow!\n");
}
int j()
{
    printf("Which nobody can deny!");
}