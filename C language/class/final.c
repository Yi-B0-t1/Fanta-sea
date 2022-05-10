#include "prepare.h"  //函数原型声明与数据结构原型
#include "funtions.h" //函数定义
#include <stdio.h>

int TOTAL = 10;
int main(void)
{
    /*用于数据存储的数组*/
    Student stu_list[TOTAL];
    Course course_list[TOTAL];
    Select select_list[TOTAL];
    Score grade_list[TOTAL];
    FILE *file_stu, *file_course, *file_select; //输入的三个文件的指针
    /*主要功能*/
    while (1) //七个主功能，7*3个子功能
    {
        switch (menu_select()) //主菜单
        {
        case 1:
            system("cls"); /* 清屏 */
            /*从文件导入初始数据*/
            puts("NOW you are in: Initialize from 3 files\n");
            // inputfile(FILE * file_stu, FILE * file_course, FILE * file_select);
            {
                char filename[30];
                puts("Enter the name of the \"STUDENT\" file to be processed:\n");
                scanf("%30s", filename);
                if ((file_stu = fopen(filename, "rb")) == NULL)
                { /* 只读模式　 */
                    printf("can't open %s,be well prepared next time!\n", filename);
                    puts("file name such as \"name.txt\"");
                    system("pause");
                    break;
                }
                else
                    puts("\n\"STUDENT\" file loaded.");
                clearline();
                puts("Enter the name of the \"COURSE\" file to be processed:\n");
                scanf("%30s", filename);
                if ((file_course = fopen(filename, "rb")) == NULL)
                { /* 只读模式　 */
                    printf("can't open %s,be well prepared next time!\n", filename);
                    puts("file name such as \"name.txt\"");
                    system("pause");
                    break;
                }
                puts("\n\"COURSE\" file loaded.");
                clearline();
                puts("Enter the name of the \"SELECT\" file to be processed:\n");
                scanf("%30s", filename);
                if ((file_select = fopen(filename, "rb")) == NULL)
                { /* 只读模式　 */
                    printf("can't open %s,be well prepared next time!\n", filename);
                    puts("file name such as \"name.txt\"");
                    system("pause");
                    break;
                }
                puts("\nALL files loaded.");
            }
            //文件输入
            //现在的任务是确定文件的输入形式
            system("pause");
            break;
        case 2:
            /*显示所有数据*/
            system("pause");
            break;
        case 3:
            /*键入与修改数据*/
            system("pause");
            break;
        case 4:
            /*根据输入删除对应数据*/
            system("pause");
            break;
        case 5:
            /*根据输入查询信息*/
            system("pause");
            break;
        case 6:
            //导出所有数据
            system("pause");
            break;
        case 0: //退出程序
            puts("Goodbye!\n");
            system("pause");
            exit(0);
        }
        clearline();
    }
    return 0;
}