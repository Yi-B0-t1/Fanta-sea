#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define S 150
#define C 30
#define SL 30
int num_s, num_c, num_sc;
FILE *f1, *f2, *f3, *f4;
void ml();
void _2x();
void _3x();
void init();
void del_c();
void del_sc();
void find_c();
void find_cj();
void sort_clist();
typedef struct
{
    char xh[10]; //学号
    char xm[20]; //姓名
    char xb[3];  //性别
    int nl;      //年龄
} Student;       //学生
typedef struct
{
    char kh[10]; //课号
    char km[25]; //课名
    float xf;    //学分
} Course;        //课程
typedef struct
{
    char xh[10]; //学号
    char kh[10]; //课程号
    float cj;    //成绩
} Select;        //选课
typedef struct
{
    char xh[10];  //学号
    char xm[20];  //姓名
    float cj[30]; //各门课成绩
    float pj;     //平均分
    float zxf;    //总学分
} Score;          //成绩

Student st[S];
Course c[C];
Select sc[S * C];
Score CJ[S];

/*D·正确结束*/ void zqend()
{
    system("cls");
    printf("谢谢使用。\nHoping see you next time! \n");

    exit(0);
}
/*D·错误输入*/ void cw()
{
    int i;
    system("cls");
    printf("！！！\n输入值在预设范围之外。\n要结束程序吗？\n是，请按0.\n否（即将转至目录），请按1.\n");
    scanf("%d", &i);
    if (i == 0)
        zqend();
    if (i == 1)
        ml();
    if (i != 1 && i != 0)
        cw();
}
/*D·转置(1)*/ void zz()
{
    int i;
    system("cls");
    printf("还有其他要做的吗？\n是，请按1和<Enter>\n否(即关闭此程序)，请按0和<Enter>.\n");
    scanf("%d", &i);
    if (i == 0)
        zqend();
    if (i == 1)
        ml();
    if (i != 1 && i != 0)
        cw();
}
/*D·转置(2)*/ void zc()
{
    int i;
    printf("还需要看其他的信息吗？\n需要继续显示：1和<Enter>\n转到其他功能：2和<Enter>\n直接结束：0和<Enter>\n请输入：");
    scanf("%d", &i);
    if (i == 1)
        _2x();
    else if (i == 2)
        ml();
    else if (i == 0)
        zqend();
    else
        cw();
}
/*D·询问(3)*/ int ask()
{
    int i;
    printf("是否继续添改?\n是：1\n否：0\n");
    scanf("%d", &i);
    if (i == 1)
        return 1;
    else
        return 0;
}

/*D·打开文件*/ void name()
{
    char ch1[100], ch2[100], ch3[100];
    int i;
    system("cls");
    printf("是否指定学生信息txt文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    scanf("%d", &i);
    if (i == 1)
    {
        printf("请输入一个学生信息文件的文件名：");
        scanf("%s", ch1);
    }
    else
        strcpy(ch1, "Students.txt");
    if ((f1 = fopen(ch1, "r+")) == NULL)
    {
        printf("文件名有误，即将打开默认文件");
        system("pause");
        f1 = fopen("Students.txt", "r+");
    }
    printf("\n是否指定课程信息txt文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    scanf("%d", &i);
    if (i == 1)
    {
        printf("请输入一个课程信息文件的文件名：");
        scanf("%s", ch2);
    }
    else
        strcpy(ch2, "Course.txt");
    if ((f2 = fopen(ch2, "r+")) == NULL)
    {
        printf("文件名有误，即将打开默认文件");
        system("pause");
        f2 = fopen("Course.txt", "r+");
    }
    printf("\n是否指定选课信息txt文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    scanf("%d", &i);
    if (i == 1)
    {
        printf("请输入一个选课信息文件的文件名：");
        scanf("%s", ch3);
    }
    else
        strcpy(ch3, "Selection.txt");
    if ((f3 = fopen(ch3, "r+")) == NULL)
    {
        printf("文件名有误，即将打开默认文件");
        system("pause");
        f3 = fopen("Selection.txt", "r+");
    }
    init();
    ml();
}
/*D·初始化数据,加载至结构体*/ void init()
{
    int i = 0;
    while (feof(f1) == 0)
    {
        fscanf(f1, "%s%s%s%d", &st[i].xh, &st[i].xm, &st[i].xb, &st[i].nl);
        i++;
    }
    num_s = i;
    i = 0;
    while (feof(f2) == 0)
    {
        fscanf(f2, "%s%s%f", &c[i].kh, &c[i].km, &c[i].xf);
        i++;
    }
    num_c = i;
    i = 0;
    while (feof(f3) == 0)
    {
        fscanf(f3, "%s%s%f", &sc[i].xh, &sc[i].kh, &sc[i].cj);
        i++;
    }
    num_sc = i;
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
/*D·make成绩单*/ void creat_cjlist()
{
    int i = 0, j, k = 0, m, n = 0, p;
    while (i < num_s) //加载学号和姓名
    {
        strcpy(CJ[i].xh, st[i].xh);
        strcpy(CJ[i].xm, st[i].xm);
        i++;
    }

    for (i = 0; i < num_s; i++)
    {
        k = 0;
        for (j = 0; j < num_sc; j++)
            if (strcmp(CJ[i].xh, sc[j].xh) == 0)
                k = 1;
        if (k != 1)
        {
            for (m = 0; m < num_c; m++)
            {
                CJ[i].cj[m] = -1;
            }
            CJ[i].zxf = 0;
        }
    }

    for (i = 0; i < num_s; i++)
    {
        n = 0;
        CJ[i].pj = CJ[i].zxf = 0.0;
        for (k = 0; k < num_c; k++)
        {
            for (j = 0; j < num_sc; j++)
            {
                if (strcmp(CJ[i].xh, sc[j].xh) == 0 && strcmp(sc[j].kh, c[k].kh) == 0)
                {
                    if (sc[j].cj < 0)
                    {
                        CJ[i].cj[k] = sc[j].cj;
                        n++;
                    }
                    else
                    {
                        CJ[i].cj[k] = sc[j].cj;
                        CJ[i].zxf = CJ[i].zxf + c[k].xf;
                    }
                }
            }
        }
        for (m = 0; m < k; m++) //算平均分
        {
            if (CJ[i].cj[m] < 0)
                ;
            else
                CJ[i].pj = CJ[i].pj + CJ[i].cj[m] / (num_c - n);
        }
    }
}

/*D·显示学生信息，10条1停*/ void disp_stud()
{
    int i;
    printf("\t学号\t\t\t姓名\t\t性别\t\t年龄\n---------------------------------------------------------------------\n");
    for (i = 0; i < num_s;)
    {
        printf("%d\t%s\t\t%s\t\t%s\t\t%d\n", (i + 1), st[i].xh, st[i].xm, st[i].xb, st[i].nl);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}

/*D·显示课程信息，10条1停*/ void disp_course()
{
    int i;
    printf("编号   课程号\t\t课程名\t学分\n-------------------------------------------------\n");
    for (i = 0; i < num_c;)
    {
        printf("%d\t%s\t\t%s\t%.2f\n", (i + 1), c[i].kh, c[i].km, c[i].xf);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}

/*D·显示成绩单，10条1停*/ void disp_cjlist()
{
    int i, j, k, m = 0;
    printf("\t学号\t\t姓名");
    for (j = 0; j < num_c; j++)
        printf("\t%s", c[j].km);
    printf("\t平均分\t\t总学分\n");
    printf("-----------------------------------------------------------");
    for (j = 0; j < num_c; j++)
        m = m + strlen(c[j].km);
    m = m + num_c * 4;
    for (j = 0; j < m; j++)
        printf("-");
    printf("\n");
    for (i = 0; i < num_s;)
    {
        printf("第%d名\t%s\t%s", (i + 1), CJ[i].xh, CJ[i].xm);
        for (k = 0; k < num_c; k++)
            printf("\t%.2f", CJ[i].cj[k]);
        printf("\t%.2f\t\t%.2f\n", CJ[i].pj, CJ[i].zxf);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}

/*D·学生·学号升序*/ void sort_slist()
{

    int i, j, k = -1;
    char ch[10];

    char xh[10];
    char xm[20];
    char xb[3];
    int nl;
    for (i = 0; i < num_s;)
    {
        strcpy(ch, st[i].xh);
        for (j = k = i; j < num_s; j++)
        {
            if (strcmp(ch, st[j].xh) > 0)
            {
                strcpy(ch, st[j].xh);
                k = j;
            }
        }
        strcpy(xh, st[i].xh);
        strcpy(st[i].xh, st[k].xh);
        strcpy(st[k].xh, xh);

        strcpy(xm, st[i].xm);
        strcpy(st[i].xm, st[k].xm);
        strcpy(st[k].xm, xm);

        strcpy(xb, st[i].xb);
        strcpy(st[i].xb, st[k].xb);
        strcpy(st[k].xb, xb);

        nl = st[i].nl;
        st[i].nl = st[k].nl;
        st[k].nl = nl;
        i++;
    }
}

/*D·课程·课号升序*/ void sort_clist()
{
    int i, j, k;
    char ch[10];
    char kh[10];
    char km[25];
    float xf;
    for (i = 0; i < num_c; i++)
    {
        strcpy(ch, c[i].kh);
        for (j = k = i; j < num_c; j++)
            if (strcmp(ch, c[j].kh) > 0)
            {
                strcpy(ch, c[j].kh);
                k = j;
            }
        strcpy(kh, c[i].kh);
        strcpy(c[i].kh, c[k].kh);
        strcpy(c[k].kh, kh);

        strcpy(km, c[i].km);
        strcpy(c[i].km, c[k].km);
        strcpy(c[k].km, km);

        xf = c[i].xf;
        c[i].xf = c[k].xf;
        c[k].xf = xf;
    }
}

/*D·成绩·平均降序*/ void sort_cjlist()
{
    int i, j, k, m;
    float t;
    char xh[10];
    char xm[20];
    float cj;
    float pj;
    float zxf;
    for (i = 0; i < num_s; i++)
    {
        t = CJ[i].pj;
        for (j = k = i; j < num_s; j++)
            if (t < CJ[j].pj)
            {
                t = CJ[j].pj;
                k = j;
            }
        strcpy(xh, CJ[i].xh);
        strcpy(CJ[i].xh, CJ[k].xh);
        strcpy(CJ[k].xh, xh);
        strcpy(xm, CJ[i].xm);
        strcpy(CJ[i].xm, CJ[k].xm);
        strcpy(CJ[k].xm, xm);
        for (m = 0; m < num_c; m++)
        {
            cj = CJ[i].cj[m];
            CJ[i].cj[m] = CJ[k].cj[m];
            CJ[k].cj[m] = cj;
        }
        pj = CJ[i].pj;
        CJ[i].pj = CJ[k].pj;
        CJ[k].pj = pj;
        zxf = CJ[i].zxf;
        CJ[i].zxf = CJ[k].zxf;
        CJ[k].zxf = zxf;
    }
}

/*D·替换学生信息*/ void th(int i)
{
    system("cls");
    printf("请输入其姓名：");
    scanf("%s", &st[i].xm);
    printf("请输入其性别：");
    scanf("%s", &st[i].xb);
    printf("请输入其年龄：");
    scanf("%s", &st[i].nl);
    printf("操作成功！");
    system("pause");
}
/*D·增加学生信息*/ void zj()
{
    printf("请输入其姓名：");
    scanf("%s", &st[num_s].xm);
    printf("请输入其性别：");
    scanf("%s", &st[num_s].xb);
    printf("请输入其年龄：");
    scanf("%d", &st[num_s].nl);
    printf("操作成功！\n");
    system("pause");
    system("cls");
}
/*D·键入学生信息*/ void ip_st()
{
    int i, p, t;
    char xh[10];
ag:
    printf("请输入其学号：");
    scanf("%s", &xh);
    for (i = p = 0; i < num_s; i++)
    {
        if (strcmp(xh, st[i].xh) == 0)
        {
            p = 1;
        re:
            printf("%s   %s  %s  %d\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
            printf("是否修改原有数据？\n是，请按1和<Enter>\n否但增加信息，请按2和<Enter>\n不做任何操作，请按0和<Enter>\n请输入：");
            scanf("%d", &t);
            if (t == 1)
                th(i);
            else if (t == 2)
            {
                printf("将添加信息");
                system("pause");
                strcpy(st[num_s].xh, xh);
                zj();
                num_s++;
            }
            else if (t == 0)
                goto end;
            else
            {
                system("cls");
                goto re;
            }
        }
    }
    if (p != 1)
    {
        strcpy(st[num_s].xh, xh);
        zj();
        num_s++;
    }

end:
    printf("还有%d条学生信息\n", num_s);
    if (ask() == 1)
        goto ag;
}

/*D·更新课程信息*/ void gx(int i)
{
    system("cls");
    printf("请输入其课号:");
    scanf("%s", &c[i].km);
    printf("请输入其学分:");
    scanf("%f", &c[i].xf);
    printf("操作成功！");
    system("pause");
}
/*D·添加课程信息*/ void tj()
{
    printf("请输入其课名：");
    scanf("%s", &c[num_c].km);
    printf("请输入其学分：");
    scanf("%f", &c[num_c].xf);
    printf("操作成功！\n");
    system("pause");
}
/*D·键入课程信息*/ void ip_c()
{
    int i, p, t;
    char kh[10];
ag:
    printf("请输入该课号：");
    scanf("%s", &kh);
    for (i = p = 0; i < num_c; i++)
    {
        if (strcmp(kh, c[i].kh) == 0)
        {
            p = 1;
        re:
            printf("%s  %s  %.2f", c[i].kh, c[i].km, c[i].xf);
            printf("是否修改原有数据？\n是，请按1和<Enter>\n不修改但增加信息，请按2和<Enter>\n不做添改，请按0和<Enter>\n请输入：");
            scanf("%d", &t);
            if (t == 1)
                gx(i);
            else if (t == 2)
            {
                printf("将增加至信息");
                system("pause");
                strcpy(c[num_c].kh, kh);
                tj();
                num_c++;
            }
            else if (t == 0)
                goto end;
            else
            {
                system("cls");
                goto re;
            }
        }
    }
    if (p != 1)
    {
        strcpy(c[num_c].kh, kh);
        tj();
        num_c++;
    }

end:
    printf("还有%d条课程信息\n", num_c);
    if (ask() == 1)
        goto ag;
}

/*D·键入选课记录*/ void ip_sc()
{
    int i, j, p;
    char xh[10], kh[10];

head:
    printf("请输入其学号：");
    scanf("%s", &xh);
    printf("请输入其课号：");
    scanf("%s", &kh);
    for (i = p = 0; i < num_sc; i++)
    {
        if (strcmp(sc[i].xh, xh) == 0 && strcmp(sc[i].kh, kh) == 0)
        {
            p = 1;
            printf("是否为：\n%s   %s   %.2f\n修改成绩，请按1\n不做修改，请按2\n请输入：", sc[i].xh, sc[i].kh, sc[i].cj);
            scanf("%s", &j);
            if (j == 1)
                ;
            else if (j == 2)
                goto end;
            else
                cw();
        }
    }
    if (p != 1)
    {
        for (i = p = 0; i < num_s; i++)
        {
            if (strcmp(st[i].xh, xh) == 0)
                p = 1;
        }
        if (p != 1)
        {
            printf("该学号不在学生信息中！\n重新输入：请按1\n增加学生信息，请按2\n终止输入，请按0\n请输入：");
            scanf("%d", &j);
            if (j == 1)
                goto head;
            else if (j == 2)
            {
                system("cls");
                ip_st();
                goto head;
            }
            else
                goto end;
        }
        for (i = p = 0; i < num_c; i++)
        {
            if (strcmp(c[i].kh, kh) == 0)
                p = 1;
        }
        if (p != 1)
        {
            printf("该课号不在学生信息中！\n重新输入：请按1\n增加课程信息，请按2\n终止输入，请按0\n请输入：");
            scanf("%d", &j);
            if (j == 1)
                goto head;
            else if (j == 2)
            {
                system("cls");
                ip_c();
                goto head;
            }
            else
                goto end;
        }
        printf("所指定的学号与课号的组合在原有的选课信息中不存在\n是否补充？\n是：请按1\n否，请按0\n请输入：");
        scanf("%d", &j);
        if (j == 1)
        {
            strcpy(sc[num_sc].xh, xh);
            strcpy(sc[num_sc].kh, kh);
            printf("请输入其成绩：");
            scanf("%f", &sc[num_sc].cj);
            num_sc++;
            printf("操作成功！\n");
        }
        else
            goto end;
    }

end:
    printf("还有%d条选课信息\n", num_sc);
    printf("继续增加选课信息，请按1：\n返回上一级，请按2\n结束输入，请按0:\n请输入：");
    scanf("%d", &j);
    system("cls");
    if (j == 1)
        goto head;
    else if (j == 2)
    {
        system("cls");
        _3x();
    }
}

/*D·删除学生信息的操作*/ void d_st(int i)
{
    strcpy(st[i].xh, st[num_s - 1].xh);
    strcpy(st[i].xm, st[num_s - 1].xm);
    strcpy(st[i].xb, st[num_s - 1].xb);
    st[i].nl = st[num_s - 1].nl;
    strcpy(st[num_s - 1].xh, "\0");
    strcpy(st[num_s - 1].xm, "\0");
    strcpy(st[num_s - 1].xb, "\0");
    st[num_s - 1].nl = 0;
    num_s--;
}
/*D·删除学生信息*/ void del_st()
{
    int i, j, k;
    char ch[20];

head:
    printf("以学号查找（1）\n或以姓名查找（2）\n");
    scanf("%d", &i);
    if (i == 1)
        goto a;
    else if (i == 2)
        goto b;
    else
        cw();

a:
    printf("请输入学号：");
    scanf("%s", &ch);
    for (i = k = 0; i < num_s; i++)
    {
        if (strcmp(ch, st[i].xh) == 0)
        {
            k = 1;
            printf("%s  %s  %s  %d\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_st(i);
                printf("删除成功!!");
                system("pause");
            }
        }
    }
    if (k != 1)
    {
        printf("此学号不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n请输入：");
        scanf("%d", &j);
        if (j == 1)
        {
            system("cls");
            goto a;
        }
        else
            goto end;
    }
    else
        goto end;

b:
    printf("请输入姓名：");
    scanf("%s", &ch);
    for (i = k = 0; i < num_s; i++)
    {
        if (strcmp(ch, st[i].xm) == 0)
        {
            k = 1;
            printf("%s  %s  %s  %d\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_st(i);
                printf("删除成功!!");
                system("pause");
            }
        }
    }
    if (k != 1)
    {
        printf("此姓名不在学生信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n请输入：");
        scanf("%d", &j);
        if (j == 1)
        {
            system("cls");
            goto b;
        }
    }

end:
    system("cls");
    printf("还剩%d条学生信息\n", num_s);
    printf("是否还删除其他的学生信息？\n是：1\n否：0\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        goto head;
    }
    printf("是否还需删除另外两类的信息？\n课程信息：1\n选课信息：2\n不，没有其他需要删除的了：0\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        del_c();
    }
    else if (j == 2)
    {
        system("cls");
        del_sc();
    }
}

/*D·删除课程信息的操作*/ void d_c(int i)
{
    strcpy(c[i].kh, c[num_c - 1].kh);
    strcpy(c[i].km, c[num_c - 1].km);
    c[i].xf = c[num_c - 1].xf;
    strcpy(c[num_c - 1].kh, "\0");
    strcpy(c[num_c - 1].km, "\0");
    c[num_c - 1].xf = -1;
    num_c--;
}
/*D·删除课程信息*/ void del_c()
{
    int i, j, k;
    char ch[25];

head:
    printf("以课号查找（1）\n或以课名查找（2）\n");
    scanf("%d", &i);
    if (i == 1)
        goto a;
    else if (i == 2)
        goto b;
    else
        cw();

a:
    printf("请输入课号：");
    scanf("%s", &ch);
    for (i = k = 0; i < num_c; i++)
    {
        if (strcmp(ch, c[i].kh) == 0)
        {
            k = 1;
            printf("%s  %s  %.2f\n", c[i].kh, c[i].km, c[i].xf);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_c(i);
                printf("删除成功!!");
                system("pause");
            }
        }
    }
    if (k != 1)
    {
        printf("此课号不在课程信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n请输入：");
        scanf("%d", &j);
        system("cls");
        if (j == 1)
        {
            system("cls");
            goto a;
        }
        else
            goto end;
    }
    else
        goto end;

b:
    printf("请输入课名：");
    scanf("%s", &ch);
    for (i = k = 0; i < num_c; i++)
    {
        if (strcmp(ch, c[i].km) == 0)
        {
            k = 1;
            printf("%s  %s  %f\n", c[i].kh, c[i].km, c[i].xf);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_c(i);
                printf("删除成功!!");
                system("pause");
            }
        }
    }
    if (k != 1)
    {
        printf("此课名不在课程信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n请输入：");
        scanf("%d", &j);
        system("cls");
        if (j == 1)
            goto b;
    }

end:
    system("cls");
    printf("还剩%d条课程信息\n", num_c);
    printf("是否还删除其他的课程信息？\n是：1\n否：0\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        goto head;
    }
    printf("是否还需删除另外两类的信息？\n学生信息：1\n选课信息：2\n不，没有其他需要删除的了：0\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        del_st();
    }
    else if (j == 2)
    {
        system("cls");
        del_sc();
    }
}

/*D·删除选择信息的操作*/ void d_sc(int i)
{
    strcpy(sc[i].xh, sc[num_sc - 1].xh);
    strcpy(sc[i].kh, sc[num_sc - 1].kh);
    sc[i].cj = sc[num_sc - 1].cj;
    strcpy(sc[num_sc - 1].xh, "\0");
    strcpy(sc[num_sc - 1].kh, "\0");
    sc[num_sc - 1].cj = -1;
    num_sc--;
}
/*D·删除选择信息*/ void del_sc()
{
    int i, p, j;
    char xh[10];
a:
    printf("请输入其学号：");
    scanf("%s", &xh);
    for (i = p = 0; i < num_sc; i++)
    {
        if (strcmp(xh, sc[i].xh) == 0)
        {
            p = 1;
            printf("%s  %s  %.2f\n是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>", sc[i].xh, sc[i].kh, sc[i].cj);
            scanf("%d", &j);
            if (j == 1)
            {
                d_sc(i);
                printf("删除成功!!");
                system("pause");
            }
        }
    }
    if (p != 1)
    {
        printf("此学号不在选课信息中。\n是否重新输入？\n是，请按<1>和<Enter>\n否，请按<0>和<Enter>\n");
        scanf("%d", &j);
        system("cls");
        if (j == 1)
            goto a;
    }
    system("cls");
    printf("还剩%d条选课信息\n", num_sc);
    printf("是否还删除其他的选课信息？\n是：1\n否：0\n");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        goto a;
    }
    printf("是否还需删除另外两类的信息？\n学生信息：1\n课程信息：2\n不，没有其他需要删除的了：0\n");
    scanf("%d", &j);
    if (j == 1)
    {
        system("cls");
        del_st();
    }
    else if (j == 2)
    {
        system("cls");
        del_c();
    }
}

/*D·查询学生信息*/ void find_st()
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
    for (i = id = 0; i < num_s; i++)
        if (strcmp(ch, st[i].xh) == 0)
        {
            id = 1;
            printf("学号：%s\n姓名：%s\n性别：%s\n年龄：%d\n\n是否需要修改？\n是：1\n否：0\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
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
                strcpy(st[num_s].xh, ch);
                zj();
                num_s++;
            }
        }
    }
    goto end;

b:
    printf("请输入姓名：");
    scanf("%s", &ch);
    for (i = id = 0; i < num_s; i++)
        if (strcmp(ch, st[i].xm) == 0)
        {
            id = 1;
            printf("学号：%s\n姓名：%s\n性别：%s\n年龄：%d\n\n是否需要修改？\n是：1\n否：0\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入其学号：");
                scanf("%s", &st[i].xh);
                printf("请输入其性别：");
                scanf("%s", &st[i].xb);
                printf("请输入其年龄：");
                scanf("%s", &st[i].nl);
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
                strcpy(st[num_s].xm, ch);
                printf("请输入其学号：");
                scanf("%s", &st[num_s].xh);
                printf("请输入其性别：");
                scanf("%s", &st[num_s].xb);
                printf("请输入其年龄：");
                scanf("%s", &st[num_s].nl);
                printf("操作成功！\n");
                system("pause");
                system("cls");
                num_s++;
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
        find_cj();
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
    for (i = id = 0; i < num_c; i++)
        if (strcmp(ch, c[i].kh) == 0)
        {
            id = 1;
            printf("课号：%s\n课名：%s\n学分：%.2f\n\n是否需要修改？\n是：1\n否：0\n", c[i].kh, c[i].km, c[i].xf);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入课名:");
                scanf("%s", &c[i].km);
                printf("请输入其学分：");
                scanf("%f", c[i].xf);
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
                strcpy(c[num_c].kh, ch);
                printf("请输入课名:");
                scanf("%s", &c[num_c].km);
                printf("请输入其学分：");
                scanf("%f", c[num_s].xf);
                system("pause");
                system("cls");
                num_c++;
            }
        }
    }
    goto end;

b:
    printf("请输入课名：");
    scanf("%s", &ch);
    for (i = id = 0; i < num_c; i++)
        if (strcmp(ch, c[i].km) == 0)
        {
            id = 1;
            printf("课号：%s\n课名：%s\n学分：%.2f\n\n是否需要修改？\n是：1\n否：0\n", c[i].kh, c[i].km, c[i].xf);
            scanf("%d", &p);
            if (p == 1)
            {
                printf("请输入课号:");
                scanf("%s", &c[i].km);
                printf("请输入其学分：");
                scanf("%f", c[i].xf);
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
                strcpy(c[num_c].km, ch);
                printf("请输入课号:");
                scanf("%s", &c[num_c].kh);
                printf("请输入其学分：");
                scanf("%f", c[num_s].xf);
                system("pause");
                system("cls");
                num_c++;
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
        find_st();
    else if (p == 3)
        find_cj();
}

/*D·查询成绩信息*/ void find_cj()
{
    int i, ex, j, m;
    char xh[10];
    creat_cjlist();
    sort_cjlist();

head:
    printf("请输入目标学号：");
    scanf("%s", &xh);
    for (i = ex = 0; i < num_s; i++)
    {
        if (strcmp(xh, CJ[i].xh) == 0)
        {
            ex = 1;
            printf("学号:\t%s\n姓名:\t%s\n", CJ[i].xh, CJ[i].xm);
            for (m = 0; m < num_c; m++)
            {
                printf("%s:\t%.2f\n", c[m].km, CJ[i].cj[m]);
            }
            printf("平均分:\t%.2f\n总学分:\t%.2f\n第%d名\n", CJ[i].pj, CJ[i].zxf, i + 1);
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
        find_st();
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

    sort_slist();
    sort_clist();

    f4 = fopen(xs, "w");
    fprintf(f4, "学号\t              姓名\t性别\t年龄\n-------------------------------------------------\n");
    for (i = 0; i < num_s; i++)
        fprintf(f4, "%s\t%s\t%s\t%d\n", st[i].xh, st[i].xm, st[i].xb, st[i].nl);
    fclose(f4);

    f4 = fopen(kc, "w");
    fprintf(f4, "课号\t  课名\t学分\n---------------------------\n");
    for (i = 0; i < num_c; i++)
        fprintf(f4, "%s\t%s\t%.2f\n", c[i].kh, c[i].km, c[i].xf);
    fclose(f4);

    f4 = fopen(xk, "w");
    fprintf(f4, "学号\t              课号\t成绩\n---------------------------------------\n");
    for (i = 0; i < num_sc; i++)
        fprintf(f4, "%s\t%s\t%.2f\n", sc[i].xh, sc[i].kh, sc[i].cj);
    fclose(f4);

    printf("操作成功！");
    system("pause");
}

/*D·导出至文件*/ void write_to_file2()
{
    int i, m, j;
    char cjd[40] = {"成绩单"}, sj[20] = {0}, ti[10];
    struct tm *n;
    time_t now;
    now = time(0);
    n = localtime(&now);

    printf("是否指定成绩单文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", &cjd);
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
    strcat(cjd, sj);
    strcat(cjd, ".txt");

    sort_slist();
    sort_clist();
    creat_cjlist();
    sort_cjlist();

    f4 = fopen(cjd, "w");
    fprintf(f4, "排名\t学号\t\t姓名\t");
    for (m = 0; m < num_c; m++)
    {
        fprintf(f4, "%s\t", c[m].km);
    }
    fprintf(f4, "平均分\t总学分\n-----------------------------------------------------------------");
    for (m = 0; m < num_c * 8; m++)
    {
        fprintf(f4, "-");
    }
    fprintf(f4, "\n");
    for (i = 0; i < num_s; i++)
    {
        fprintf(f4, "第%d名\t%s\t%s\t", i + 1, CJ[i].xh, CJ[i].xm);
        for (m = 0; m < num_c; m++)
            fprintf(f4, "%.2f\t", CJ[i].cj[m]);
        fprintf(f4, "%.2f\t%.2f\n", CJ[i].pj, CJ[i].zxf);
    }

    printf("操作成功！");
    system("pause");
}

/*D·选项1---生成*/ void _1x()
{
    creat_cjlist();
    printf("成功创建成绩单！");
    system("pause");
}
/*D·选项2---显示*/ void _2x()
{
    int i;
    sort_slist();
    sort_clist();
    creat_cjlist();
    sort_cjlist();
    system("cls");
    printf("希望展示哪些？\n学生信息：1和<Enter>\n课程信息：2和<Enter>\n成绩单：3和<Enter>\n请输入您的选择：");
    scanf("%d", &i);
    system("cls");
    switch (i)
    {
    case 1:
        disp_stud();
        break;
    case 2:
        disp_course();
        break;
    case 3:
        disp_cjlist();
        break;
    default:
        cw();
    }
    zc();
}
/*D·选项3---输入*/ void _3x()
{
    int i;

a:
    system("cls");
    printf("若要增加（更正）学生信息：请按1和<Enter>\n若要增加（更正）课程信息：请按2和<Enter>\n若要增加（更正）选课信息：请按3和<Enter>\n");
    scanf("%d", &i);
    system("cls");
    switch (i)
    {
    case 1:
        ip_st();
        break;
    case 2:
        ip_c();
        break;
    case 3:
        ip_sc();
        break;
    default:
        cw();
        break;
    }
    system("cls");
    printf("还需要做添改吗？\n是：1\n否，转到目录：；2\n请输入：");
    scanf("%d", &i);
    if (i == 1)
        goto a;
    else if (i == 2)
        ;
    else
        cw();
}
/*D·选项4---删除*/ void _4x()
{
    int i;
    printf("删除什么信息？\n学生：1\n课程：2\n选课：3\n");
    scanf("%d", &i);
    system("cls");
    if (i == 1)
        del_st();
    else if (i == 2)
        del_c();
    else if (i == 3)
        del_sc();
    else
        cw();
}
/*D·选项5---查询*/ void _5x()
{
    int i;
    printf("请输入想查询的信息：\n学生信息：1\n课程信息：2\n个人成绩单（含有选课信息）：3\n");
    scanf("%d", &i);
    system("cls");
    if (i == 1)
        find_st();
    else if (i == 2)
        find_c();
    else if (i == 3)
        find_cj();
    else
        cw();
}
/*D·选项6---导出*/ void _6x()
{
    int i;
    printf("请选择：\n导出学生信息、课程信息和选课信息：1\n导出成绩信息：2\n");
    scanf("%d", &i);
    if (i == 1)
        write_to_file1();
    else if (i == 2)
        write_to_file2();
    else
        cw();
}
/*D·目录*/ void ml()
{
    int i;
again:
    system("cls");
    printf("┌——————————————————————┐\n\n");
    printf("|   1.生成成绩单\t\t              |\n|   2.显示信息（学生、课程、成绩）\t      |\n|   3.添改记录（学生、课程、选课）\t      |\n|   4.删除记录（学生、课程、选课）\t      |\n|   5.查找信息（学生、课程、成绩）\t      |\n|   6.批量导入数据\t\t\t      |\n|   0.退出程序。\t\t\t      |\n\n");
    printf("└——————————————————————┘\n请输入你的选择和<Enter>:");
    scanf("%d", &i);
    system("cls");
    switch (i)
    {
    case 1:
        _1x();
        break;
    case 2:
        _2x();
        break;
    case 3:
        _3x();
        break;
    case 4:
        _4x();
        break;
    case 5:
        _5x();
        break;
    case 6:
        _6x();
        break;
    case 0:
        zqend();
        break;
    default:
        printf("Sorry! I do not understand your order. Let us check my catalog again. \nPlease choose the one I can understand.");
        system("pause");
        goto again;
        break;
    }
    zz();
}
int main()
{
    int i;
    printf("\tWelcome!\n\t作者：071960123  蒋科\n\tHow can I help you? \n\tIf you want to do something, plesae input 1 and <Enter>\n\tIf you opened me by mistake.\n\tSorry about that, please input 0 and <Enter>\n");
    scanf("%d", &i);
    if (i == 0)
        zqend();
    if (i == 1)
        name();
    else
        cw();

    return 3;
}