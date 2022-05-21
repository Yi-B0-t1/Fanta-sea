#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prepare.h"
int main(void)
{
    file_stu = fopen("slist.txt", "r");
    file_course = fopen("clist.txt", "r");
    file_select = fopen("sclist.txt", "r");
    rewind(file_stu);
    rewind(file_course);
    rewind(file_select);
    int counter;
    for (counter = 0; EOF != fscanf(file_stu, "%s %s %s %d", stu_list[counter].stu_ID, stu_list[counter].stu_name, stu_list[counter].sex, &stu_list[counter].age); counter++)
        continue;
    *stu_total = counter;
    for (counter = 0; EOF != fscanf(file_course, "%s %s %f", course_list[counter].course_ID, course_list[counter].course_name, &course_list[counter].course_grade); counter++)
        continue;
    *course_total = counter;
    for (counter = 0; EOF != fscanf(file_select, "%s %s %f", select_list[counter].stu_ID, select_list[counter].course_ID, &select_list[counter].stu_grade); counter++)
        continue;
    *select_total = counter;
    fclose(file_stu);
    fclose(file_course);
    fclose(file_select);
    // int counter,average_part, average;
    int average_part, average;
    for (counter = 0; counter < *stu_total; counter++)
    {
        if (stu_list[counter].sex[1] != '\0')
        {
            average_part = 0, average = 0;
            strcpy(grade_list[counter].stu_ID, stu_list[counter].stu_ID);
            strcpy(grade_list[counter].stu_name, stu_list[counter].stu_name); //学号姓名拷贝
            int tempstu = counter;                                            //当前学生
            grade_list[tempstu].total_grade = 0;
            for (counter = 0; counter < *select_total; counter++)                       //遍历选课单
                if (0 == strcmp(stu_list[tempstu].stu_ID, select_list[counter].stu_ID)) //当学号匹配
                {
                    int course_counter;                                                        //课程计数
                    for (course_counter = 0; course_counter < *course_total; course_counter++) //遍历课程单
                        if (0 == strcmp(select_list[counter].course_ID, course_list[course_counter].course_ID))
                        {
                            grade_list[tempstu].stu_grade[course_counter] = select_list[counter].stu_grade;
                            average_part = select_list[counter].stu_grade * course_list[course_counter].course_grade;
                            average += average_part;
                            grade_list[tempstu].total_grade += course_list[course_counter].course_grade;
                        }
                }
            grade_list[tempstu].average_grade = (grade_list[tempstu].total_grade == 0) ? 0 : (average / grade_list[tempstu].total_grade);
            counter = tempstu;
            (*stu_real_total)++;
        }
        else
            break;
        printf("yes%d", *stu_real_total);
    }
    printf("\nAAAA%d", *stu_real_total);
    sort_clist();
    sort_grade_list();
    sort_slist();
    printf("BBB");
    return 0;
}
void sort_slist(void) //按照学号升序排序。
{
    char sort_array[*stu_real_total][9]; //变长数组，变量做数组长度，不能赋初值
    int init;
    for (init = 0; init < *stu_real_total; init++)
    {
        strcpy(sort_array[init], stu_list[init].stu_ID);
    }
    qsort(sort_array, *stu_real_total, sizeof(sort_array[0][0]), array_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *stu_real_total; init++)
    {
        int old;
        for (old = 0; old < *stu_real_total; old++)
        {
            if (strcmp(sort_array[init], stu_list[old].stu_ID))
            {
                old = init;
                break;
            }
        }
    }
}
void sort_clist(void) //按照课程号升序排序。
{
    char sort_array[*course_total][9];
    int init;
    for (init = 0; init < *course_total; init++)
    {
        strcpy(sort_array[init], course_list[init].course_ID);
    }
    qsort(sort_array, *course_total, sizeof(sort_array[0][0]), array_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *course_total; init++)
    {
        int old;
        for (old = 0; old < *course_total; old++)
        {
            if (strcmp(sort_array[init], course_list[old].course_ID))
            {
                old = init;
                break;
            }
        }
    }
}
void sort_grade_list(void) //按照平均成绩降序排序
{
    float sort_array[*stu_real_total];
    int init;
    for (init = 0; init < *stu_real_total; init++)
    {
        sort_array[init] = grade_list[init].average_grade;
    }
    qsort(sort_array, *stu_real_total, sizeof(grade_list[0].average_grade), float_sort);
    //一重循环排列元素
    //二重循环交换下标
    for (init = 0; init < *stu_real_total; init++)
    {
        int old;
        for (old = 0; old < *stu_real_total; old++)
        {
            if (sort_array[init] == grade_list[old].average_grade)
            {
                old = init;
                break;
            }
        }
    }
}
int array_sort(const void *a, const void *b) //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
{
    return strcmp((char *)b, (char *)a); //注意指针的强制类型转换
}
int float_sort(const void *a, const void *b) //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
{
    return (*(float *)b > *(float *)a) ? 1 : -1; //注意指针的强制类型转换
}
//降序排序，反向输出，遇零截止
//现在是降序了