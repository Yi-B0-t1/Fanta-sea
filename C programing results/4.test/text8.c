#include <stdio.h>
#include <string.h>
int main()
{
    char name[20] = "Amy Louis";
    float cash = 43.72;
    printf("The %s family just may be $%.2fricher!\n", name, cash);
    return 0;
}