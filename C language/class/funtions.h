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
int openfiles(FILE *file_stu, FILE *file_course, FILE *file_select)
{
    char filename[30];
    int checker = 0;
    while (checker != 2)
    {
        if (checker == 0)
            puts("\"q\"\"enter\"\"q\"to quit.\"enter\"to continue");
        if (checker == 1)
            puts("\"qq\"to quit.\"enter\"to continue");
        clearline();
        if ((int)'q' == getchar())
            return 0;
        puts("Enter the name of the \"STUDENT\" file to be processed:\n");
        scanf("%30s", filename); //应该加一个退出功能的，算了吧
        if ((file_stu = fopen(filename, "rb")) == NULL)
        { /* 只读模式　 */
            printf("can't open %s,be well prepared next time!\n", filename);
            puts("file name such as \"name.txt\"");
            system("pause");
            checker = 1;
            continue;
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
            checker = 1;
            continue;
        }
        else
            puts("\n\"COURSE\" file loaded.");
        clearline();
        puts("Enter the name of the \"SELECT\" file to be processed:\n");
        scanf("%30s", filename);
        if ((file_select = fopen(filename, "rb")) == NULL)
        { /* 只读模式　 */
            printf("can't open %s,be well prepared next time!\n", filename);
            puts("file name such as \"name.txt\"");
            system("pause");
            checker = 1;
            continue;
        }
        else
        {
            checker = 2;
            puts("\nALL lists created.");
            system("pause");
            return 1;
        }
    }
}
//建表
void init(Student stu_list[], int *stu_total, Course course_list[], int *course_total, Select select_list[], int *select_total)
{
    int counter;
    for (counter = 0; EOF != fscanf(file_stu, "%s %s %s %d", stu_list[counter].stu_ID, stu_list[counter].stu_name, stu_list[counter].sex, &stu_list[counter].age); counter++)
        continue;
    *stu_total = counter + 1;
    for (counter = 0; EOF != fscanf(file_course, "%s %s %f", course_list[counter].course_ID, course_list[counter].course_name, &course_list[counter].course_grade); counter++)
        continue;
    *course_total = counter + 1;
    for (counter = 0; EOF != fscanf(file_select, "%s %s %f", select_list[counter].stu_ID, select_list[counter].course_ID, &select_list[counter].stu_grade); counter++)
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
        strcpy(grade_list[counter].stu_ID, stu_list[counter].stu_ID);
        strcpy(grade_list[counter].stu_name, stu_list[counter].stu_name);
        int tempstu = counter;
        grade_list[tempstu].total_grade = 0;
        for (counter = 0; counter < *select_total; counter++)
            if (strcmp(stu_list[tempstu].stu_ID, select_list[counter].stu_ID))
            {
                int course_counter;
                for (course_counter = 0; course_counter < *course_total; course_counter++)
                    if (strcmp(select_list[counter].course_ID, course_list[course_counter].course_ID))
                    {
                        grade_list[tempstu].stu_grade[course_counter] = select_list[counter].stu_grade;
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
    char *sort_array[*stu_total];
    int init;
    for (init = 0; init < *stu_total; init++)
    {
        sort_array[init] = stu_list[init].stu_ID;
    }
    qsort(sort_array, *stu_total, sizeof(stu_list[0].stu_ID), array_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *stu_total; init++)
    {
        int old;
        for (old = 0; old < *stu_total; old++)
        {
            if (strcmp(sort_array[init], stu_list[old].stu_ID))
                old = init;
        }
    }
}
void sort_clist(Course course_list[], int *course_total) //按照课程号升序排序。
{
    char *sort_array[*course_total];
    int init;
    for (init = 0; init < *course_total; init++)
    {
        sort_array[init] = course_list[init].course_ID;
    }
    qsort(sort_array, *course_total, sizeof(course_list[0].course_ID), array_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *course_total; init++)
    {
        int old;
        for (old = 0; old < *course_total; old++)
        {
            if (strcmp(sort_array[init], course_list[old].course_ID))
                old = init;
        }
    }
}
void sort_grade_list(Score grade_list[], int *stu_total) //按照平均成绩降序排序
{
    float sort_array[*stu_total];
    int init;
    for (init = 0; init < *stu_total; init++)
    {
        sort_array[init] = grade_list[init].average_grade;
    }
    qsort(sort_array, *stu_total, sizeof(grade_list[0].average_grade), float_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *stu_total; init++)
    {
        int old;
        for (old = 0; old < *stu_total; old++)
        {
            if (sort_array[init] == grade_list[old].average_grade)
                old = init;
        }
    }
}
int array_sort(const void *a, const void *b) //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
{
    return strcmp((*(Student *)a).stu_ID, (*(Student *)b).stu_ID); //注意指针的强制类型转换
}
int float_sort(const void *a, const void *b) //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
{
    return (*(float *)a > *(float *)b) ? 1 : -1; //注意指针的强制类型转换
}