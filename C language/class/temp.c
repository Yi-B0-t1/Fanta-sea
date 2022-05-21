int input_select()
{
    int i, c = 0, sid, cid;
    char a[30] = {0};
    float g;
begin:
    puts("按q退出,其他键+<enter>继续\n");
    if (getchar() == 'q')
        return;
    puts("输入若干条选课信息记录：");
    puts("学号：");
    scanf("%s", a);
    for (i = 0; i < *select_total; i++)
    {
        if (!strcmp(a, select_list[i].stu_ID))
        {
            c = 1;
            sid = i;
            break;
        }
    }
    if (c != 1)
    {
        puts("没有此学号");
        system("pause");
        goto begin;
    }
    puts("课号：");
    scanf("%s", a);
    for (i = 0; i < *select_total; i++)
    {
        if (!strcmp(a, select_list[i].stu_ID))
        {
            c = 1;
            cid = i;
            break;
        }
    }
    if (c != 1)
    {
        puts("没有此课号");
        system("pause");
        goto begin;
    }
    puts("学生成绩：");
    scanf("%f", &select_list);
    return ++select_total;
}