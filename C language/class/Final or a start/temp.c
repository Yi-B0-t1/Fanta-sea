
/*D·查询学生信息*/ void find_stu_list()
{
    char ch[20];
    int i, id = 0, p;

head:
    printf("以学号查找（1）\n或以姓名查找（2）\n");
    scanf("%d", &i);
    system("cls");
    if (i == 1)
        ;
    else if (i == 2)
        goto b;
    else
        cw();

a:
    printf("请输入学号：");
    scanf("%s", &ch);
    for (i = id = 0; i < *stu_total; i++)
        if (strcmp(ch, stu_list[i].stu_ID) == 0)
        {
            id = 1;
            printf("学号：%s\n姓名：%s\n性别：%s\n年龄：%d\n\n是否需要修改？\n是：1\n否：0\n", stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
            scanf("%d", &p);
            if (p == 1)
                th(i);
        }
    if (id != 1)
    {
        printf("此学号不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n");
        scanf("%d", &p);
        if (p == 1)
        {
            system("cls");
            goto a;
        }
        else
        {
            printf("是否需要增加学生信息？\n是：1\n否：0\n");
            scanf("%d", &p);
            if (p == 1)
            {
                strcpy(stu_list[*stu_total].stu_ID, ch);
                zj();
                *stu_total++;
            }
        }
    }
    goto end;

b:
    printf("请输入姓名：");
    scanf("%s", &ch);
    for (i = id = 0; i < *stu_total; i++)
        if (strcmp(ch, stu_list[i].stu_name) == 0)
        {
            id = 1;
            printf("学号：%s\n姓名：%s\n性别：%s\n年龄：%d\n\n是否需要修改？\n是：1\n否：0\n", stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入其学号：");
                scanf("%s", &stu_list[i].stu_ID);
                printf("请输入其性别：");
                scanf("%s", &stu_list[i].sex);
                printf("请输入其年龄：");
                scanf("%s", &stu_list[i].age);
                printf("操作成功！\n");
                system("pause");
                system("cls");
            }
        }
    if (id != 1)
    {
        printf("此姓名不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n");
        scanf("%d", &p);
        if (p == 1)
        {
            system("cls");
            goto b;
        }
        else
        {
            printf("是否需要增加学生信息？\n是：1\n否：0\n");
            scanf("%d", &p);
            if (p == 1)
            {
                strcpy(stu_list[*stu_total].stu_name, ch);
                printf("请输入其学号：");
                scanf("%s", &stu_list[*stu_total].stu_ID);
                printf("请输入其性别：");
                scanf("%s", &stu_list[*stu_total].sex);
                printf("请输入其年龄：");
                scanf("%s", &stu_list[*stu_total].age);
                printf("操作成功！\n");
                system("pause");
                system("cls");
                *stu_total++;
            }
        }
    }

end:
    printf("继续查询学生信息：1\n查询课程信息：2\n查询成绩信息：3\n不需要再查其他的了：0\n");
    scanf("%d", &p);
    system("cls");
    if (p == 1)
        goto head;
    else if (p == 2)
        find_c();
    else if (p == 3)
        find_grade_list();
}

/*D·查询课程信息*/ void find_c()
{
    char ch[25];
    int i, id = 0, p;

head:
    printf("以课号查找（1）\n或以课名查找（2）\n");
    scanf("%d", &i);
    if (i == 1)
        ;
    else if (i == 2)
        goto b;
    else
        cw();

a:
    printf("请输入课号：");
    scanf("%s", &ch);
    for (i = id = 0; i < *course_total; i++)
        if (strcmp(ch, course_list[i].course_ID) == 0)
        {
            id = 1;
            printf("课号：%s\n课名：%s\n学分：%.2f\n\n是否需要修改？\n是：1\n否：0\n", course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入课名:");
                scanf("%s", &course_list[i].course_name);
                printf("请输入其学分：");
                scanf("%f", course_list[i].course_grade);
                system("pause");
                system("cls");
            }
        }
    if (id != 1)
    {
        printf("此课号不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n");
        scanf("%d", &p);
        if (p == 1)
        {
            system("cls");
            goto a;
        }
        else
        {
            printf("是否需要增加课程信息？\n是：1\n否：0\n");
            scanf("%d", &p);
            if (p == 1)
            {
                strcpy(course_list[*course_total].course_ID, ch);
                printf("请输入课名:");
                scanf("%s", &course_list[*course_total].course_name);
                printf("请输入其学分：");
                scanf("%f", course_list[*stu_total].course_grade);
                system("pause");
                system("cls");
                *course_total++;
            }
        }
    }
    goto end;

b:
    printf("请输入课名：");
    scanf("%s", &ch);
    for (i = id = 0; i < *course_total; i++)
        if (strcmp(ch, course_list[i].course_name) == 0)
        {
            id = 1;
            printf("课号：%s\n课名：%s\n学分：%.2f\n\n是否需要修改？\n是：1\n否：0\n", course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入课号:");
                scanf("%s", &course_list[i].course_name);
                printf("请输入其学分：");
                scanf("%f", course_list[i].course_grade);
                system("pause");
                system("cls");
            }
        }
    if (id != 1)
    {
        printf("此课名不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n");
        scanf("%d", &p);
        if (p == 1)
        {
            system("cls");
            goto b;
        }
        else
        {
            printf("是否需要增加课程信息？\n是：1\n否：0\n");
            scanf("%d", &p);
            if (p == 1)
            {
                strcpy(course_list[*course_total].course_name, ch);
                printf("请输入课号:");
                scanf("%s", &course_list[*course_total].course_ID);
                printf("请输入其学分：");
                scanf("%f", course_list[*stu_total].course_grade);
                system("pause");
                system("cls");
                *course_total++;
            }
        }
    }

end:
    printf("继续查询课程信息：1\n查询学生信息：2\n查询成绩信息：3\n不需要再查其他的了：0\n");
    scanf("%d", &p);
    system("cls");
    if (p == 1)
        goto head;
    else if (p == 2)
        find_stu_list();
    else if (p == 3)
        find_grade_list();
}

/*D·查询成绩信息*/ void find_grade_list()
{
    int i, ex, j, m;
    char stu_ID[10];

head:
    printf("请输入目标学号：");
    scanf("%s", &stu_ID);
    for (i = ex = 0; i < *stu_total; i++)
    {
        if (strcmp(stu_ID, grade_list[i].stu_ID) == 0)
        {
            ex = 1;
            printf("学号:\t%s\n姓名:\t%s\n", grade_list[i].stu_ID, grade_list[i].stu_name);
            for (m = 0; m < *course_total; m++)
            {
                printf("%s:\t%.2f\n", course_list[m].course_name, grade_list[i].grade_list[m]);
            }
            printf("平均分:\t%.2f\n总学分:\t%.2f\n第%d名\n", grade_list[i].pj, grade_list[i].total_grade, i + 1);
        }
    }
    if (ex != 1)
    {
        printf("该学号不在成绩单中，请检查学号\n重新输入，请按1\n查看其他，请按2\n不看了，请按0\n");
        scanf("%d", &j);
        system("cls");
        if (j == 1)
            goto head;
        else if (j == 2)
            goto a;
        else
            goto end;
    }

a:
    printf("继续查询成绩信息：1\n查询学生信息，请按2\n查询课程信息，请按3\n");
    scanf("%d", &j);
    system("cls");
    if (j == 1)
        goto head;
    else if (j == 2)
        find_stu_list();
    else if (j == 3)
        find_c();

end:;
}

/*D·导出至文件*/ void write_to_file1()
{
    int i, j;
    char xs[40] = {"学生"}, kc[40] = {"课程"}, xk[40] = {"选课"}, sj[20] = {0}, ti[10];

    struct tm *n;
    time_t now;
    now = time(0);
    n = localtime(&now);

    printf("是否指定学生信息文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", &xs);
    }
    printf("是否指定课程信息文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", &kc);
    }
    printf("是否指定选课信息文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", &xk);
    }

    itoa(n->tm_year + 1900, ti, 10);
    strcat(sj, ti);
    itoa(n->tm_mon + 1, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_mday, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_hour, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_min, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_sec, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);

    strcat(xs, sj);
    strcat(kc, sj);
    strcat(xk, sj);
    strcat(xs, ".txt");
    strcat(kc, ".txt");
    strcat(xk, ".txt");

    sort_list();
    sort_c_list();

    f4 = fopen(xs, "w");
    fprintf(f4, "学号\t              姓名\t性别\t年龄\n-------------------------------------------------\n");
    for (i = 0; i < *stu_total; i++)
        fprintf(f4, "%s\t%s\t%s\t%d\n", stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
    fclose(f4);

    f4 = fopen(kc, "w");
    fprintf(f4, "课号\t  课名\t学分\n---------------------------\n");
    for (i = 0; i < *course_total; i++)
        fprintf(f4, "%s\t%s\t%.2f\n", course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
    fclose(f4);

    f4 = fopen(xk, "w");
    fprintf(f4, "学号\t              课号\t成绩\n---------------------------------------\n");
    for (i = 0; i < *stu_total; i++)
        fprintf(f4, "%s\t%s\t%.2f\n", select_list[i].stu_ID, select_list[i].course_ID, select_list[i].grade_list);
    fclose(f4);

    printf("操作成功！");
    system("pause");
}

/*D·导出至文件*/ void write_to_file2()
{
    int i, m, j;
    char grade_list[40] = {"成绩单"}, sj[20] = {0}, ti[10];
    struct tm *n;
    time_t now;
    now = time(0);
    n = localtime(&now);

    printf("是否指定成绩单文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", &grade_list);
    }

    itoa(n->tm_year + 1900, ti, 10);
    strcat(sj, ti);
    itoa(n->tm_mon + 1, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_mday, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_hour, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_min, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    itoa(n->tm_sec, ti, 10);
    if (strlen(ti) == 1)
        strcat(sj, "0");
    strcat(sj, ti);
    strcat(grade_list, sj);
    strcat(grade_list, ".txt");

    void sort_list(void);  //按照学号升序排序。
    void sort_clist(void); //按照课程号升序排序。
    void create_grade_list(void);
    void sort_grade_list(void); //按照平均成绩降序排序

    f4 = fopen(grade_list, "w");
    fprintf(f4, "排名\t学号\t\t姓名\t");
    for (m = 0; m < *course_total; m++)
    {
        fprintf(f4, "%s\t", course_list[m].course_name);
    }
    fprintf(f4, "平均分\t总学分\n-----------------------------------------------------------------");
    for (m = 0; m < *course_total * 8; m++)
    {
        fprintf(f4, "-");
    }
    fprintf(f4, "\n");
    for (i = 0; i < *stu_total; i++)
    {
        fprintf(f4, "第%d名\t%s\t%s\t", i + 1, grade_list[i].stu_ID, grade_list[i].stu_name);
        for (m = 0; m < *course_total; m++)
            fprintf(f4, "%.2f\t", grade_list[i].grade_list[m]);
        fprintf(f4, "%.2f\t%.2f\n", grade_list[i].pj, grade_list[i].total_grade);
    }

    printf("操作成功！");
    system("pause");
}