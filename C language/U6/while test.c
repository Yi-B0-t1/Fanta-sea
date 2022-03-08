#include <stdio.h>
#include <inttypes.h>
int main(void) /*标准规定main返回值类型就是int，
 这种类型便于操作，因此方便各种编译器进行编译
 （C的特点就是可移植性，因此最好按标准来）*/
{
    int n = 'A' + 7;
    int a = 'A';
    intmax_t max = 1234567890987654321;
    printf("%zd\n", max);
    while (n++ < 3)
        ;
    printf("n is %d\n", n);
    printf("That's all\n");
    return 0; // return 0 表示程序正常退出 这是给编译器说的
}