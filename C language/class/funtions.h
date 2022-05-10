#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void clearline(void)
{
    while (getchar() != '\n')
        continue;
}
//菜单函数
int menu_select(void)
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
void openfiles(FILE *file_stu, FILE *file_course, FILE *file_select)
{
    char filename[30];
    puts("Enter the name of the \"STUDENT\" file to be processed:\n");
    scanf("%30s", filename);
    if ((file_stu = fopen(filename, "r")) == NULL)
    { /* 只读模式　 */
        printf("can't open %s,be well prepared next time!\n", filename);
        puts("file name such as \"name.txt\"");
        system("pause");
        return;
    }
    else
        puts("\n\"STUDENT\" file loaded.");
    clearline();
    puts("Enter the name of the \"COURSE\" file to be processed:\n");
    scanf("%30s", filename);
    if ((file_course = fopen(filename, "r")) == NULL)
    { /* 只读模式　 */
        printf("can't open %s,be well prepared next time!\n", filename);
        puts("file name such as \"name.txt\"");
        system("pause");
        return;
    }
    puts("\n\"COURSE\" file loaded.");
    clearline();
    puts("Enter the name of the \"SELECT\" file to be processed:\n");
    scanf("%30s", filename);
    if ((file_select = fopen(filename, "r")) == NULL)
    { /* 只读模式　 */
        printf("can't open %s,be well prepared next time!\n", filename);
        puts("file name such as \"name.txt\"");
        system("pause");
        return;
    }
    puts("\nALL files loaded.");
    return;
}
//建表
void init(Student stu_list[], int *stu_total, Course course_list[], int *course_total, Select select_list[], int *select_total)
{
    int counter;
    for (counter = 0; EOF != fscanf(file_stu, "%s %s %s %d", &stu_list[counter].stu_ID, &stu_list[counter].stu_name, &stu_list[counter].sex, &stu_list[counter].age); counter++)
        continue;
    *stu_total = counter + 1;
    for (counter = 0; EOF != fscanf(file_course, "%s %s %f", &course_list[counter].course_ID, &course_list[counter].course_name, &course_list[counter].course_grade); counter++)
        continue;
    *course_total = counter + 1;
    for (counter = 0; EOF != fscanf(file_select, "%s %s %f", &select_list[counter].stu_ID, &select_list[counter].course_ID, &select_list[counter].stu_grade); counter++)
        continue;
    *select_total = counter + 1;
}
//学号，姓名，各科（按读入顺序）成绩，总分，加权平均分
void create_grade_list(Student stu_list[], int *stu_total, Course course_list[], int *course_total, Select select_list[], int *select_total, Score grade_list[])
{
    int counter;
    int average_part, average;
    for (counter = 0, average_part = 0, average = 0; counter < *stu_total; counter++)
    {
        grade_list[counter].stu_ID = stu_list[counter].stu_ID;
        grade_list[counter].stu_name = stu_list[counter].stu_name;
        int tempstu = counter;
        grade_list[tempstu].total_grade = 0;
        for (counter = 0; counter < *course_total; counter++)
            if (strcmp(stu_list[tempstu].stu_ID, select_list[counter].stu_ID))
            {
                int course_counter;
                for (course_counter = 0; course_counter < *course_total; course_counter++)
                    if (strcmp(select_list[counter].course_ID, course_list[course_counter].course_ID))
                    {
                        grade_list[tempstu].stu_grade = select_list[counter].stu_grade;
                        average_part = select_list[counter].stu_grade * course_list[course_counter].course_grade;
                        average += average_part;
                        grade_list[tempstu].total_grade += course_list[course_counter].course_grade;
                    }
            }
        grade_list[tempstu].average_grade = average / grade_list[tempstu].total_grade;
    }
}
void sort_slist(Student stu_list[], int *stu_total) //按照学号升序排序。
{
    int counter;
    for (counter = 1; counter < *stu_total; counter++)
    {
        if (strcmp(stu_list[counter].stu_ID, stu_list[counter - 1].stu_ID) < 0)
        { //各项拷贝即可
        }
    }
}
void sort_clist(Course course_list[], int *course_total); //按照课程号升序排序。
void sort_grade_list(Score grade_list[], int *stu_total); //按照平均成绩降序排序