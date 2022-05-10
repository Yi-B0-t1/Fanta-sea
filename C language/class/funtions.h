#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void clearline(void)
{
    while (getchar() != '\n')
        continue;
}
//菜单函数
int menu_select()
{
    char c;
    system("cls"); /* 清屏 */
    puts(
        "enter number 0to6 to choose function:\n"
        "0. exit\n"
        "1. initialize from 3 files\n"
        "2. show all data\n"
        "3. renew\n"
        "4. delete\n"
        "5. find\n"
        "6. output all data\n"
        "enter your number:");
    while (EOF != (c = getchar()))
    {
        if ('0' <= c && c <= '6')
            break;
        else
        {
            clearline();
            puts("\nerror\nyou must enter NUMBER from 0, 1, 2, 3, 4, 5, 6\nplease enter again:");
        }
    }
    clearline();
    return (c - '0');
}

//初始化数据
// void init(Student stu_list[], int *stu_total, Course course_list[], int *course_total, Score select_list[], int *select_total)
//打开三个文件
// void inputfile(FILE *file_stu, FILE *file_course, FILE *file_select)
