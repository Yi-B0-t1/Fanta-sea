/* rows1.c -- 使用嵌套循环 */
#include <stdio.h>
#define ROWS 6
#define CHARS 10
int main(void)
//{
//    int row;
//    char ch;
//    for (row = 0; row < ROWS; row++) /* 第10行 */
//    {
//        for (ch = 'A'; ch < ('A' + CHARS); ch++) /* 第12行 */
//            printf("%c", ch);
//        printf("\n");
//    }
//    return 0;
//}*/
{
    int x, y;
    int x1, y1;
    printf("please enter your x&y with the form\"x,y\":");
    scanf("%d,%d", &x1, &y1);
    for (y = 1; y <= y1; y++) //行递增
    {
        if (1 == y || y1 == y) //第一行和最后一行
        {
            for (x = 1; x <= x1; x++) //列递增
                printf("*");          //打满*号
        }
        else //其他行
        {
            for (x = 1; x <= x1; x++)                            //列递增
                (1 == x || x1 == x) ? printf("*") : printf(" "); //第一列和最后一列打印*，其他列打印空格
        }
        printf("\n"); //每递增一行换行
    }
    printf("if there is nothing,press your shift and check your intput form");
    return 0;
}
/*看来先设计再实现是非常正确的，先把逻辑搞清楚了，剩下的就只是翻译问题
重点是代码所表达的思想（处理方法）*/