
void sort_slist(void) //按照学号升序排序。
{
    char *sort_array[*stu_real_total];
    int init;
    for (init = 0; init < *stu_real_total; init++)
    {
        strcpy(sort_array[init], stu_list[init].stu_ID);
    }
    qsort(sort_array, *stu_real_total, sizeof(stu_list[0].stu_ID), array_sort);
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
    char *sort_array[*course_total];
    int init;
    for (init = 0; init < *course_total; init++)
    {
        strcpy(sort_array[init], course_list[init].course_ID);
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
    return strcmp((*(Student *)a).stu_ID, (*(Student *)b).stu_ID); //注意指针的强制类型转换
}
int float_sort(const void *a, const void *b) //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
{
    return (*(float *)a > *(float *)b) ? 1 : -1; //注意指针的强制类型转换
}