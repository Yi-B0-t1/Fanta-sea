#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct //学生信息
{
    char xh[10]; //学号
    char xm[9];  //姓名,最多4个汉字
    char xb[3];  //性别
    int nl;      //年龄
} Student;

typedef struct //课程信息
{
    char kh[8];  //课号
    char km[11]; //课名,最多5个汉字
    float xf;    //学分
} Course;

typedef struct //选课信息
{
    char xh[10]; //学号
    char kh[8];  //课号
    float cj;    //成绩
} Select;

typedef struct //成绩信息
{
    char xh[9];   //学号
    float cj[10]; //不超过10门课程成绩
    float pj;     //加权平均分
    float zxf;    //总学分
} Score;

int display_main_menu(); //显示主菜单

void init(Student *, int *, Course *, int *, Select *, int *); //读取学生信息表，课程信息表，选课信息表
int create_cjlist(Select *, int, Course *, int, Score *);      //建立成绩单

int input_stud(Student slist[], int scount);                                                             //修改或添加学生记录
int input_course(Course clist[], int ccount);                                                            //修改或添加课程记录
int input_select(Select sclist[], int sccount, Student slist[], int scount, Course clist[], int ccount); //修改或添加选课信息

void disp_stud(Student slist[], int scount);                                //显示学生信息
void disp_course(Course clist[], int ccount);                               //显示课程信息
void disp_select(Select sclist[], int sccount);                             //显示选课信息
void disp_cjlist(Score cjlist[], int cjcount, Student slist[], int scount); //显示成绩单

int delete_stud(Student slist[], int scount);    //按学号删除学生信息
int delete_course(Course clist[], int ccount);   //按课号删除课程信息
int delete_select(Select sclist[], int sccount); //按学号和课程号删除选课信息

void query_stud(Student slist[], int scount);                                //按学号或姓名查询学生信息
void query_course(Course clist[], int ccount);                               //按课号或课程名查询课程信息
void query_cjlist(Score cjlist[], int cjcount, Student slist[], int scount); //按学号查询成绩信息

void sort_stud(Student slist[], int scount);  //学生表按照学号升序排序
void sort_course(Course clist[], int ccount); //课程信息按照课程号升序排序
void sort_cjlist(Score *cjlist, int cjcount); //成绩单按照平均成绩降序排序

void write_to_file(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount);
//把学生信息表、课程信息表、选课信息表保存到文件中

int main() //主程序入口
{
    Student slist[100]; //学生信息表，最多100人
    Course clist[10];   //课程信息表，最多10门课
    Select sclist[500]; //选课信息表，最多500条选课信息
    Score cjlist[100];  //成绩汇总单,最多记录100人成绩
    char c;
    int scount, ccount, sccount, cjcount;                   //学生人数、课程门数、选课记录数、成绩表记录数
    init(slist, &scount, clist, &ccount, sclist, &sccount); //读取学生信息表，课程信息表，选课信息表
    cjcount = create_cjlist(sclist, sccount, clist, ccount, cjlist);
    //建立成绩单，返回选课学生人数。选课表提供-学号、成绩；课程表提供-学分

    for (;;)
    {
        switch (display_main_menu())
        {
        case 1:
            system("cls");
            while (1)
            {
                printf("修改或添加 \n");
                printf("1.学生名单;  2.课程信息;  3.选课信息;  0.返回\n");
                printf("请给出你的选择(0--3): ");
                fflush(stdin);
                c = getchar();
                if (c == '1')
                {
                    scount = input_stud(slist, scount);
                    sort_stud(slist, scount);
                }
                else if (c == '2')
                {
                    ccount = input_course(clist, ccount);
                    sort_course(clist, ccount);
                }
                else if (c == '3')
                {
                    sccount = input_select(sclist, sccount, slist, scount, clist, ccount);
                    cjcount = create_cjlist(sclist, sccount, clist, ccount, cjlist); //建立成绩单
                    sort_cjlist(cjlist, cjcount);
                }
                else if (c == '0')
                    break;
            }
            break;
        case 2:
            system("cls");
            while (1)
            {
                printf("\n 1.显示学生信息;  2.显示课程信息;  3.显示选课信息;  4.显示成绩单;  0.返回\n");
                printf(" 请给出你的选择(0--4): ");
                fflush(stdin);
                c = getchar();
                if (c == '1')
                {
                    sort_stud(slist, scount);
                    disp_stud(slist, scount);
                }
                else if (c == '2')
                {
                    sort_course(clist, ccount);
                    disp_course(clist, ccount);
                }
                else if (c == '3')
                    disp_select(sclist, sccount);
                else if (c == '4')
                {
                    sort_cjlist(cjlist, cjcount);
                    disp_cjlist(cjlist, cjcount, slist, scount);
                }
                else if (c == '0')
                    break;
            }
            break;
        case 3:
            system("cls");
            while (1)
            {
                printf("1.删除学生信息;  2.删除课程信息;  3.删除选课信息;  0.返回\n");
                printf("请给出你的选择(0--3): ");
                fflush(stdin);
                c = getchar();
                if (c == '1')
                    scount = delete_stud(slist, scount);
                else if (c == '2')
                    ccount = delete_course(clist, ccount);
                else if (c == '3')
                {
                    sccount = delete_select(sclist, sccount);
                    cjcount = create_cjlist(sclist, sccount, clist, ccount, cjlist); //重新建立成绩单
                }
                else if (c == '0')
                    break;
            }
            break;
        case 4:
            system("cls");
            while (1)
            {
                printf("1.查询学生信息;  2.查询课程信息;  3.查询成绩信息;  0.返回\n");
                printf("请给出你的选择(0--3): ");
                fflush(stdin);
                c = getchar();
                if (c == '1')
                    query_stud(slist, scount);
                else if (c == '2')
                    query_course(clist, ccount);
                else if (c == '3')
                    query_cjlist(cjlist, cjcount, slist, scount);
                else if (c == '0')
                    break;
            }
            break;
        case 5:
            write_to_file(slist, scount, clist, ccount, sclist, sccount);
            break;
        case 0:
            printf("再见!\n");
            exit(0);
        }
        system("pause");
    }
    return 0;
}

int display_main_menu()
{
    char c;
    do
    {
        system("cls");
        printf("\n\n\t\t\t         学生成绩管理系统\n\n");
        printf("\t\t\t 1.修改或添加学生、课程和选课信息\n");
        printf("\t\t\t 2.显示学生、课程和选课信息\n");
        printf("\t\t\t 3.删除学生、课程和选课信息\n");
        printf("\t\t\t 4.查询学生、课程和选课信息\n");
        printf("\t\t\t 5.保存学生、课程和选课信息到文件\n");
        printf("\t\t\t 0.退出\n");
        printf("\n\t\t\t   请选择 (0~5):  ");
        fflush(stdin);
        c = getchar();
    } while (c < '0' || c > '5');
    return c - '0';
}

//读取学生信息表，课程信息表，选课信息表//ok
void init(Student slist[], int *Scount, Course clist[], int *Ccount, Select sclist[], int *SCcount)
{
    int i;
    FILE *fp;
    *Scount = 0;
    *Ccount = 0;
    *SCcount = 0;
    printf("读取学生信息表，课程信息表，选课信息表\n");
    fp = fopen("slist.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(1);
    }
    for (i = 0; !feof(fp); i++)
    {
        fscanf(fp, "%s", slist[i].xh);
        fscanf(fp, "%s", slist[i].xm);
        fscanf(fp, "%s", slist[i].xb);
        fscanf(fp, "%d", &slist[i].nl);
        (*Scount)++;
    }
    fclose(fp);
    fp = fopen("clist.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(2);
    }
    for (i = 0; !feof(fp); i++)
    {
        fscanf(fp, "%s", clist[i].kh);
        fscanf(fp, "%s", clist[i].km);
        fscanf(fp, "%f", &clist[i].xf);
        (*Ccount)++;
    }
    fclose(fp);
    fp = fopen("sclist.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(3);
    }
    for (i = 0; !feof(fp); i++)
    {
        fscanf(fp, "%s", sclist[i].xh);
        fscanf(fp, "%s", sclist[i].kh);
        fscanf(fp, "%f", &sclist[i].cj);
        (*SCcount)++;
    }
    fclose(fp);
    system("pause");
} //对了

//由选课表、课程表创建成绩表
int create_cjlist(Select sclist[], int sccount, Course clist[], int ccount, Score cjlist[])
{                                            //     选课表       选课记录数     课程表      课程数       成绩表
    int i = -1, j, m, t = 0, k, cjcount = 0; // count-选修成绩人数
    float xfh = 0, colum = 0;
    float xf_a[20];
    FILE *fp;
    Select test[230];
    printf("由选课表、课程表创建成绩表\n");
    fp = fopen("cjlist.txt", "w");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(4);
    }
    for (i = 0; i < sccount; i++)
        strcpy(test[i].xh, "0");
    for (i = 0; i < sccount; i++) // cjcount
    {
        for (j = 0; j < sccount; j++)
            if (strcmp(sclist[i].xh, test[j].xh) == 0)
                break;
        if (j == sccount)
        {
            cjcount++;
            strcpy(test[i].xh, sclist[i].xh);
        }
        else
            continue;
    }
    for (i = 0; i < cjcount; i++) // cj初值
        for (j = 0; j < ccount; j++)
            cjlist[i].cj[j] = 0;
    for (i = 0; i < cjcount; i++) //初始化zong学分
        cjlist[i].zxf = 0;
    for (i = 0; i < sccount; i++) //初始化test
        strcpy(test[i].xh, "0");
    for (i = 0; i < sccount; i++)
    {
        for (m = 0; m < sccount; m++)
            if (strcmp(sclist[i].xh, test[m].xh) == 0)
                break;
        if (m == sccount) //证明是不重复项
        {
            strcpy(cjlist[t].xh, sclist[i].xh);
            t++;
            strcpy(test[i].xh, sclist[i].xh);
        }
        else
            continue; // 已经得到了cjlist学号
    }
    for (i = 0; i < cjcount; i++)
    {
        xfh = 0;
        cjlist[j].pj = 0;
        //每个学生都初始化
        for (j = 0; j < sccount; j++) //
        {
            if (strcmp(sclist[j].xh, cjlist[i].xh) == 0) // search for xh
            {
                for (t = 0; t < ccount; t++) //找选课表j+1项对应的课程项
                    if (strcmp(clist[t].kh, sclist[j].kh) == 0)
                    {
                        xf_a[t] = clist[t].xf;
                        cjlist[i].cj[t] = sclist[j].cj;
                    }
                for (k = 0; k < ccount; k++)                    //录入j+1项成绩
                    if (strcmp(clist[k].kh, sclist[j].kh) == 0) // j+1项学分
                        cjlist[i].zxf += clist[k].xf;           //累加学分
            }
        }
    }
    for (i = 0; i < cjcount; i++)
    {
        colum = 0;
        for (j = 0; j < ccount; j++)
            colum += xf_a[j] * cjlist[i].cj[j];
        colum /= cjlist[i].zxf;
        cjlist[i].pj = colum;
    }
    for (i = 0; i < cjcount; i++)
    {
        fprintf(fp, "%s", cjlist[i].xh);
        for (j = 0; j < ccount; j++)
            fprintf(fp, " %6.2f", cjlist[i].cj[j]);
        fprintf(fp, " %6.2f %6.2f\n", cjlist[i].pj, cjlist[i].zxf);
    }
    fclose(fp);
    system("pause");
    return cjcount;
}

int input_stud(Student slist[], int scount)
{
    Student temp;
    int i, n;
    char yes;
lable1:
    printf("添加或修改学生信息表\n");
    printf("0表示添加，1表示修改,请选择\n");
    scanf("%d", &n);
    if (n == 0) // add new student
    {
        getchar();
        printf("确定添加新学生吗(y/n)\n");
        scanf("%c", &yes);
        if (yes == 'y')
        {
            printf("输入学号\n");
            scanf("%s", temp.xh);
            printf("输入性别\n");
            scanf("%s", temp.xb);
            printf("输入姓名\n");
            scanf("%s", temp.xm);
            printf("输入年龄\n");
            scanf("%d", &temp.nl);
            slist[scount] = temp;
            scount++;
        }
        else if (yes == 'n')
            ;
        else
            goto lable1;
    }
    else if (n == 1)
    {
        getchar();
        printf("确定修改学生吗(y/n)\n");
        yes = getchar();
        if (yes == 'y')
        {
            printf("输入学号\n");
            getchar();
            gets(temp.xh);
            for (i = 0; strcmp(slist[i].xh, temp.xh) != 0; i++)
                ;
            printf("输入性别\n");
            scanf("%s", temp.xb);
            printf("输入姓名\n");
            scanf("%s", temp.xm);
            printf("输入年龄\n");
            scanf("%d", &temp.nl);
            slist[i] = temp;
        }
        else if (yes == 'n')
            ;
        else
            goto lable1;
    }
    else
        goto lable1;
    system("pause");
    return scount;
}

int input_course(Course clist[], int ccount)
{
    Course temp;
    int i, n;
    char yes;
lable2:
    printf("添加或修改课程信息表\n");
    printf("0表示添加，1表示修改\n");
    scanf("%d", &n);
    if (n == 0) // add new course
    {
        getchar();
        printf("确定添加新课程吗(y/n)\n");
        yes = getchar();
        if (yes == 'y')
        {
            printf("输入课号\n");
            scanf("%s", temp.kh);
            printf("输入课名\n");
            scanf("%s", temp.km);
            printf("输入学分\n");
            scanf("%f", &temp.xf);
            clist[ccount] = temp;
            ccount++;
        }
        else if (yes == 'n')
            ;
        else
            goto lable2;
    }
    else if (n == 1)
    {
        getchar();
        printf("确定修改课程吗(y/n)\n");
        yes = getchar();
        if (yes == 'y')
        {
            printf("输入课号\n");
            scanf("%s", temp.kh);
            for (i = 0; strcmp(clist[i].kh, temp.kh) != 0; i++)
                ;
            printf("输入课名\n");
            scanf("%s", temp.km);
            printf("输入学分\n");
            scanf("%f", &temp.xf);
            clist[i] = temp;
        }
        else if (yes == 'n')
            ;
        else
            goto lable2;
    }
    else
        goto lable2;
    system("pause");
    return ccount;
}

int input_select(Select sclist[], int sccount, Student slist[], int scount, Course clist[], int ccount)
{
    Select temp;
    int i, n, chu = 0;
    char yes;
lable3:
    printf("添加或修改选课信息表\n");
    printf("0表示添加，1表示修改\n");
    scanf("%d", &n);
    if (n == 0) // add new select course chart
    {
        getchar();
        printf("确定添加新选课吗(y/n)\n");
        yes = getchar();
        if (yes == 'y')
        {
            printf("输入学号\n");
            scanf("%s", temp.xh);
            printf("输入课号\n");
            scanf("%s", temp.kh);
            printf("输入成绩\n");
            scanf("%f", &temp.cj);
            sclist[sccount] = temp;
            sccount++;
        }
        else if (yes == 'n')
            ;
        else
            goto lable3;
    }
    else if (n == 1)
    {
        getchar();
        printf("确定修改选课信息吗(y/n)\n");
        yes = getchar();
        if (yes == 'y')
        {
            printf("输入学号\n");
            scanf("%s", temp.xh);
        lable4:
            for (i = chu; strcmp(sclist[i].xh, temp.kh) != 0; i++)
                ;
            printf("输入课号\n");
            scanf("%s", temp.kh);
            printf("输入成绩\n");
            scanf("%f", &temp.cj);
            sclist[i] = temp;
            if (i <= sccount)
            {
                chu = i;
                goto lable4;
            }
        }
        else if (yes == 'n')
            ;
        else
            goto lable3;
    }
    else
        goto lable3;
    system("pause");

    return sccount;
}

void disp_stud(Student slist[], int scount) //显示学生信息//ok
{
    int i;
    printf("显示学生信息\n");
    for (i = 0; i < scount; i++)
    {
        printf("%s", slist[i].xh);
        printf("  ");
        printf("%s", slist[i].xm);
        printf("  ");
        printf("%s", slist[i].xb);
        printf("  ");
        printf("%d\n", slist[i].nl);
    }
    system("pause");
}

void disp_course(Course clist[], int ccount) //显示课程信息
{
    int i;
    printf("显示课程信息\n");
    for (i = 0; i < ccount; i++)
    {
        printf("%s", clist[i].kh);
        printf("  ");
        printf("%s", clist[i].km);
        printf("  ");
        printf("%6.2f\n", clist[i].xf);
    }
    system("pause");
}

void disp_select(Select sclist[], int sccount) //显示选课信息
{
    int i;
    printf("显示选课信息\n");
    for (i = 0; i < sccount; i++)
    {
        printf("%s", sclist[i].xh);
        printf("  ");
        printf("%s", sclist[i].kh);
        printf("  ");
        printf("%6.2f\n", sclist[i].cj);
    }
    system("pause");
}

void disp_cjlist(Score cjlist[], int cjcount, Student slist[], int scount) //显示成绩信息
{
    int i, j;
    printf("显示成绩信息\n");
    for (i = 0; i < cjcount; i++)
    {
        printf("%s", cjlist[i].xh);
        printf("  ");
        for (j = 0; j < cjcount; j++)
        {
            printf("%6.2f", cjlist[i].cj[j]);
        }
        printf("  ");
        printf("%6.2f", cjlist[i].pj);
        printf("  ");
        printf("%6.2f\n", cjlist[i].zxf);
    }
    system("pause");
}

int delete_stud(Student slist[], int scount) //删除学生信息
{
    char xh[10];
    int i, j, flag = 0;
    char yes;
    printf("显示学生信息\n");
    for (i = 0; i < scount; i++)
    {
        printf("%s", slist[i].xh);
        printf("  ");
        printf("%s", slist[i].xm);
        printf("  ");
        printf("%s", slist[i].xb);
        printf("  ");
        printf("%d\n", slist[i].nl);
    }
lable5:
    printf("输入想删除学生的学号\n");
    scanf("%s", xh);
    printf("你不会真的要删吧？(y/n)\n");
    getchar();
    yes = getchar();
    if (yes == 'y')
    {
        for (i = 0; i < scount; i++)
            if (strcmp(xh, slist[i].xh) == 0)
            {
                for (j = i + 1; j < scount; j++)
                {
                    slist[i] = slist[j];
                    i++;
                }
                break;
            }
        scount--;
    }
    else if (yes == 'n')
        ;
    else
        goto lable5;
    system("pause");
    return scount;
}
int delete_course(Course clist[], int ccount) //删除课程信息
{
    char kh[11];
    int i, j, flag = 0;
    char yes;

    printf("显示课程信息\n");
    for (i = 0; i < ccount; i++)
    {
        printf("%s", clist[i].kh);
        printf("  ");
        printf("%s", clist[i].km);
        printf("  ");
        printf("%6.2f\n", clist[i].xf);
    }
lable6:
    printf("输入想删除课程的课号\n");
    scanf("%s", kh);
    printf("你不会真的要删吧？(y/n)\n");
    getchar();
    yes = getchar();
    if (yes == 'y')
    {
        for (i = 0; i < ccount; i++)
            if (strcmp(kh, clist[i].kh) == 0)
            {
                for (j = i + 1; j < ccount; j++)
                {
                    clist[i] = clist[j];
                    i++;
                }
                break;
            }
        ccount--;
    }
    else if (yes == 'n')
        ;
    else
        goto lable6;
    system("pause");

    return ccount;
}

int delete_select(Select sclist[], int sccount) //删除选课信息
{
    char xh[10], kh[11];
    int i, j, flag = 0;
    char yes;

    printf("显示选课信息\n");
    for (i = 0; i < sccount; i++)
    {
        printf("%s", sclist[i].xh);
        printf("  ");
        printf("%s", sclist[i].kh);
        printf("  ");
        printf("%6.2f\n", sclist[i].cj);
    }
lable7:
    printf("输入想删除的学号，课号\n");
    scanf("%s", xh);
    scanf("%s", kh);
    printf("你不会真的要删吧？(y/n)\n");
    getchar();
    yes = getchar();
    if (yes == 'y')
    {
        for (i = 0; i < sccount; i++)
            if (strcmp(xh, sclist[i].xh) == 0)
                if (strcmp(kh, sclist[i].kh) == 0)
                {
                    flag = i;
                    for (j = i + 1; j < sccount; j++)
                    {
                        sclist[i] = sclist[j];
                        i++;
                    }
                }
        i = flag + 1;
        sccount--;
    }
    else if (yes == 'n')
        ;
    else
        goto lable7;
    system("pause");

    return sccount;
}

void query_stud(Student slist[], int scount) //查询学生记录
{
    char namexh[10];
    int i;
    printf("按姓名或学号查询学生信息\n");
    getchar();
    gets(namexh);
    for (i = 0; i < scount; i++)
    {
        if (strcmp(namexh, slist[i].xh) == 0)
        {
            printf("%s", slist[i].xh);
            printf("  ");
            printf("%s", slist[i].xm);
            printf("  ");
            printf("%s", slist[i].xb);
            printf("  %d\n", slist[i].nl);
        }
        if (strcmp(namexh, slist[i].xm) == 0)
        {
            printf("%s", slist[i].xh);
            printf("  ");
            printf("%s", slist[i].xm);
            printf("  ");
            printf("%s", slist[i].xb);
            printf("  %d\n", slist[i].nl);
        }
    }
    system("pause");
}

void query_course(Course clist[], int ccount) //查询课程记录
{
    char khkm[11];
    int i;
    printf("按课程号或课程名查询课程信息\n");
    getchar();
    gets(khkm);
    for (i = 0; i < ccount; i++)
    {
        if (strcmp(khkm, clist[i].kh) == 0)
        {
            printf("%s", clist[i].kh);
            printf("  ");
            printf("%s", clist[i].km);
            printf("  %6.2f\n", clist[i].xf);
        }
        if (strcmp(khkm, clist[i].km) == 0)
        {
            printf("%s", clist[i].kh);
            printf("  ");
            printf("%s", clist[i].km);
            printf("  %6.2f\n", clist[i].xf);
        }
    }
    system("pause");
}

void query_cjlist(Score cjlist[], int cjcount, Student slist[], int scount)
{
    char xh[10];
    int i = 0, j;
    printf("按学号查询成绩信息\n");
    getchar();
    gets(xh);
    for (i = 0; i < cjcount; i++)
    {
        if (strcmp(xh, cjlist[i].xh) == 0)
        {
            printf("%s", cjlist[i].xh);
            printf("  ");
            for (j = 0; 0 <= cjlist[i].cj[j] && cjlist[i].cj[j] <= 100; j++)
                printf("%6.2f  ", cjlist[i].cj[j]);
            printf("%6.2f  %6.2f\n", cjlist[i].pj, cjlist[i].zxf);
        }
    }
    system("pause");
}

void sort_stud(Student slist[], int scount) //按学号升序排序学生信息
{
    int i, j, sxh[230], zxxh;
    Student p;
    printf("按学号升序排序学生信息\n");
    for (i = 0; i < scount; i++) // sxh的初始化
        sxh[i] = 0;
    for (i = 0; i < scount; i++) //将学号转成int形式
    {
        for (j = 0; slist[i].xh[j] != '\0'; j++)
        {
            sxh[i] += sxh[i] * 10 + slist[i].xh[j] - '0';
        }
    }
    for (i = 0; i < scount - 1; i++) //选择法排序
    {
        zxxh = i;
        for (j = i + 1; j < scount; j++)
        {
            if (sxh[j] < sxh[zxxh])
                zxxh = j;
        }
        if (zxxh != i)
        {
            p = slist[i];
            slist[i] = slist[zxxh];
            slist[zxxh] = p;
        }
    }
    system("pause");
}

void sort_course(Course clist[], int ccount)
//按课程号升序排序课程信息
{
    int i, j, ckh[100], zxkh, t;
    Course p;
    printf("按课程号升序排序课程信息\n");
    for (i = 0; i < ccount; i++) // ckh的初始化
        ckh[i] = 0;
    for (i = 0; i < ccount; i++) //将课号转成int形式
    {
        for (j = 1; clist[i].kh[j] != '\0'; j++)
        {
            ckh[i] = ckh[i] * 10 + clist[i].kh[j] - '0';
        }
    }
    for (i = 0; i < ccount - 1; i++) //选择法排序
    {
        zxkh = i;
        for (j = i + 1; j < ccount; j++)
        {
            if (ckh[j] < ckh[zxkh])
                zxkh = j;
        }
        if (zxkh != i)
        {
            p = clist[i];
            clist[i] = clist[zxkh];
            clist[zxkh] = p;
            t = ckh[i];
            ckh[i] = ckh[zxkh];
            ckh[zxkh] = t;
        }
    }
    system("pause");
}

void sort_cjlist(Score *cjlist, int cjcount) //按平均成绩降序排序成绩信息
{
    int i, j;
    int zxpj;
    Score p;
    printf("按平均成绩降序排序成绩信息\n");
    for (i = 0; i < cjcount - 1; i++) //选择法排序
    {
        zxpj = i;
        for (j = i + 1; j < cjcount; j++)
        {
            if (cjlist[j].pj > cjlist[zxpj].pj)
                zxpj = j;
        }
        if (zxpj != i)
        {
            p = cjlist[i];
            cjlist[i] = cjlist[zxpj];
            cjlist[zxpj] = p;
        }
    }
    system("pause");
}

//将学生信息、课程信息和成绩信息写入文件
void write_to_file(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount)
{
    int i, j, cjcount;
    Score cjlist[230];
    FILE *fp;
    int create_cjlist(Select *, int, Course *, int, Score *);
    printf("将学生信息、课程信息和成绩信息写入文件\n");
    fp = fopen("slist.txt", "w");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(5);
    }
    for (i = 0; i < scount - 1; i++)
    {
        fprintf(fp, "%s", slist[i].xh);
        fprintf(fp, "  ");
        fprintf(fp, "%s", slist[i].xm);
        fprintf(fp, "  ");
        fprintf(fp, "%s", slist[i].xb);
        fprintf(fp, "  %d\n", slist[i].nl);
    }
    fprintf(fp, "%s", slist[i].xh);
    fprintf(fp, "  ");
    fprintf(fp, "%s", slist[i].xm);
    fprintf(fp, "  ");
    fprintf(fp, "%s", slist[i].xb);
    fprintf(fp, "  %d", slist[i].nl);
    fclose(fp);
    fp = fopen("clist.txt", "w");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(6);
    }
    for (i = 0; i < ccount - 1; i++)
    {
        fprintf(fp, "%s", clist[i].kh);
        fprintf(fp, "  ");
        fprintf(fp, "%s", clist[i].km);
        fprintf(fp, "  %6.2f\n", clist[i].xf);
    }
    fprintf(fp, "%s", clist[i].kh);
    fprintf(fp, "  ");
    fprintf(fp, "%s", clist[i].km);
    fprintf(fp, "  %6.2f", clist[i].xf);
    fclose(fp);
    fp = fopen("sclist.txt", "w");
    if (fp == NULL)
    {
        printf("Can't open the file!\n");
        exit(7);
    }
    for (i = 0; i < sccount - 1; i++)
    {
        fprintf(fp, "%s", sclist[i].xh);
        fprintf(fp, "  ");
        fprintf(fp, "%s", sclist[i].kh);
        fprintf(fp, "  %6.2f\n", sclist[i].cj);
    }
    fprintf(fp, "%s", sclist[i].xh);
    fprintf(fp, "  ");
    fprintf(fp, "%s", sclist[i].kh);
    fprintf(fp, "  %6.2f", sclist[i].cj);
    fclose(fp);
    cjcount = create_cjlist(sclist, sccount, clist, ccount, cjlist);
    system("pause");
}