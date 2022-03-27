#include <stdio.h>
int main(void)
{
    int i = 0;
    while (i < 3)
    {
        switch (i++) //表明对含后缀++的表达式求值，其中i会在整个表达式求值结束后加一
        {            //注意switch语句的书写结构，switch后必须有大括号的
        case 0:
            printf("fat "); //注意没有break的跳转的连续执行
        case 1:             //标签之后要执行的语句最好缩进换行写
            printf("hat ");
        case 2:
            printf("cat ");
        default:
            printf("Oh no!");
        }
        putchar('\n');
    }
    return 0;
}