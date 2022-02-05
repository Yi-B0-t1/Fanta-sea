/* pizza.c -- 在比萨饼程序中使用已定义的常量 */
#include <stdio.h>
int main()
{
    int x = -002;
    char charr = '4';
    float flo = 2.303;
    printf("***int=%04.2d***,char=%0c,***float=%010f***\n", x, charr, flo);
    char char1 = '9';
    char char2 = 6;
    printf("char1=%c,char1hh=%hhc,char2=%c,char2=%hhc\n", char1, char1, char2, char2);
    printf("你的狗屎有%d块", 1000);
    return 0;
}