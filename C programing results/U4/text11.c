/*这是第四单元的编程实验*/
// name程序
#include <stdio.h>
int main()
{
    char F[10];
    char L[10]; //应该把姓名放在一个array里的，充分说明编程序前先要构想程序，明确需求
    int length;
    printf("Please enter your first-name and last-name.\n");
    scanf("%s %s", F, L);
    length = printf("%s,%s\n", F, L);
    printf("\"%s %s\"\n", F, L);
    printf("\"%-10s%-10s\"\n", F, L);
    printf("\"%10s%10s\"\n", F, L);
    printf("\"%*s%*s   \"\n", length / 2, F, length / 2, L);
    return 0; //此程序作为一个失败范例提示我们先想后写
}