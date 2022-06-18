#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "prepare.h"  //函数原型声明与数据结构原型
#include "funtions.h" //函数定义
#include <stdio.h>
#include <time.h>
#define TOTAL 15
FILE *file_stu, *file_course, *file_select; //输入的三个文件的指针
FILE *f1, *f2, *f3, *f4;
int ssssss[4] = {0};
int *stu_total = ssssss, *course_total = &ssssss[1], *select_total = &ssssss[2], *stu_real_total = &ssssss[3]; //保护指针

typedef struct
{
  char stu_ID[10];   //学号
  char stu_name[20]; //姓名，10 个汉字以内
  char sex[3];       //性别，只能保存一个汉字
  int age;           //年龄
} Student;
typedef struct
{
  char course_ID[10];   //课号，长度 10 字符以内
  char course_name[50]; //课名，12 个汉字以内
  float course_grade;   //课分，为一个浮点数
} Course;
typedef struct
{
  char stu_ID[10];    //学号，长度 10 字符以下
  char course_ID[10]; //课号
  float stu_grade;    //成绩，为一个浮点数
} Select;
typedef struct
{
  char stu_ID[10];     //学号
  char stu_name[20];   //姓名
  float stu_grade[30]; //各门课程成绩
  float average_grade; //加权平均分
  float total_grade;   //总修习学分
} Score;
/*数据结构*/
/*用于数据存储的数组*/
Student stu_list[TOTAL] = {0};
Course course_list[TOTAL] = {0};
Select select_list[TOTAL] = {0};
Score grade_list[TOTAL] = {0};

int menu_select(void); //菜单函数原型

/*初始化数据*/
int openfiles(void);
//输入表单
void init(void);
//初始化数据

void create_grade_list(void);
//建立成绩单
int array_sort(const void *a, const void *b); //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
int float_sort(const void *a, const void *b); //默认升序即a在前，b在后，返回a-b，注意return的强制类型转换，条件运算符是通解
/*排序函数*/

/*以下函数所有原型之参数仅做提示用，实际上均不需要参数，统一用全局变量即可*/

void sort_slist(void);      //按照学号升序排序。
void sort_clist(void);      //按照课程号升序排序。
void sort_grade_list(void); //按照平均成绩降序排序

void disp_stud(void);
void disp_course(void);
void disp_grade(void);
void del_c(void);
/*D·删除学生信息*/ void del_stuu_list(void);
///*显示数据*/
// void disp_stud(Student stu_list[], int stu_total);
////显示所有学生信息，每显示10 条记录暂停一次，stu_total 为学生数组元素个数。
// void disp_course(Course course_list[], int course_total);
////显示所有课程信息，每显示10 条记录暂停一次，course_total 为课程数组元素个数。
// void disp_grade_list(Score grade_list[], int grade_total, Course course_list[], int course_total, Student stu_list[], int stu_total);
////显示所有学生成绩单信息，每显示 10 行暂停一次，grade_total为数组元素个数。显示的学生姓名来自于学生信息表 stu_list，课程名来自于课程信息表 course_list

///*数据输入*/
// int input_stud(Student stu_list[], int stu_total);
////从键盘输入若干条学生信息记录，依次存放到学生信息结构体数组 stu_list 中，stu_number 为数组原有学生记录数，函数返回最后的学生记录数。
// int input_course(Course course_list[], int course_total);
////从键盘输入若干条课程信息记录，依次存放到课程信息结构体数组 course_list 中，course_total 为数组原有课程记录数，函数返回最后的课程记录数。

//上述两个函数运行时，每输入一条记录都检测是否已经存在相同记录，如果已经存在则
//提示是否替换，否则直接增加记录，使得函数同时具有增加记录和修改已有记录的功能。每
//输入完一条记录都要提示是否继续输入下一条记录，根据输入决定是否继续操作。*/

// int input_select(Score select_list[], int select_total);
//从键盘输入若干条选课记录，依次存放到学生选课信息结构体数组 select_list 中，select_total 为数组原有选课记录数，
//函数返回最后的学生选课记录总数。如果课程暂时还没有成绩则用-1 表示。该函数除了要兼
//具增加和修改记录的功能外，还要保证输入数据的正确性，如果输入的学号不是学生信息表
//中存在的学号，或者输入的课程号不是课程信息表中存在的课程号，或者成绩超出范围（-1
//≦成绩≦120）则提示输入错误并要求重新输入*/
///*删除记录*/
// int delete_stu(Student stu_list[], int stu_total);         //根据姓名或学号删除满足条 件的若条学生记录，返回数组中的还剩下的记录数。
// int delete_course(Course course_list[], int course_total); //根据课程名或课程号删除 满足条件的若条课程记录，返回数组中还剩下的记录数。
// int delete_select(Select select_list[], int select_total); //根据学号删除满足条件 的若条选课记录，返回数组中还剩下的记录数。

///*查询信息*/
/*D·查询学生信息*/ void find_stu_list();
/*D·查询课程信息*/ void find_c();
/*D·查询成绩信息*/ void find_grade_list();
// void query_stud(Student stu_list[], int stu_total);
////根据学号或姓名查询学生记录并显示。
// void query_course(Course course_list[], int course_total);
////根据课程号或课程名查询课程记录并显示。
// void query_gradelist(Score grade_list[], int grade_total, Course course_list[], int course_total, Student stu_list[], int stu_total);
////根据信号查询成绩单，显示对应同学的所有课程成绩、平均分、学分以及排名情况，并显示。
/*D·导出至文件*/ void write_to_file1();
///*批量导出数据*/
// void write_to_file1(Student stu_list[], int stu_total, Course course_list[], int course_total, Select select_list[], int select_total);
///*以时间序列字符串为文件名，把学生信息表、课程信息表和选课信息表分别保存都对应的磁盘文件中。例如，学生文件名为
// student20190918120423.txt、课程文件名为 course20190918120430.txt、选课信息文件名为 select201909181258.txt。*/
// void write_to_file2(Score grade_list[], int grade_total, Course course_list[], int course_total, Student stu_list[], int stu_total);
///*以时间序列字符串为文件名，把成绩单保存的磁盘文件中，包括名次、学号、姓名、性别、各门课成绩、平均分以及总学分*/
/*D·导出至文件*/ void write_to_file2();
/*D·增加学生信息*/ void zj();
int main(void)
{
    while (1) //七个主功能，7*3个子功能
    {
        switch (menu_select()) //主菜单
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
            /*键入与修改数据*/
        case 4:
            menu4();
            break;
        case 5:
            menu5();
            /*根据输入查询信息*/
            break;
        case 6:
            menu6();
            //导出所有数据
            break;
        case 0: //退出程序
            puts("Goodbye!\n");
            return 0;
        }
        system("pause");
        fflush(stdin);
    }
}
//菜单函数
int menu_select(void)
{
    char c;
    system("cls"); /* 清屏 */
    puts(
        "enter number 0to6 to choose function:\n"
        "1. initialize from 3 files\n"
        "2. show all data\n"
        "3. renew\n"
        "4. delete\n"
        "5. find\n"
        "6. output all data\n"
        "0. exit\n"
        "enter your number:");
    while (EOF != (c = getchar()))
    {
        if ('0' <= c && c <= '6')
            break;
        else
        {
            fflush(stdin);
            puts("\nerror\nyou must enter NUMBER from 0, 1, 2, 3, 4, 5, 6\nplease enter again:");
        }
    }
    return (c - '0');
}

//打开文件
int openfiles(void)
{
    char ch1[30], ch2[30], ch3[30];
    int i;
    system("cls");
    getchar();
    puts("按q退出,其他键+<enter>继续\n");
    if (getchar() == 'q')
        return 0;

    do
    {
        puts("\n是否指定学生信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
        fflush(stdin);
        scanf("%d", &i);
    } while (i != 1 && i != 0);
    if (i == 1)
    {
        puts("请输入一个学生信息文件的文件名：");
        scanf("%30s", ch1);
    }
    if ((file_stu = fopen(ch1, "r")) == NULL)
    {
        puts("即将打开默认文件");
        file_stu = fopen("slist.txt", "r");
    }

    do
    {
        puts("\n是否指定课程信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
        fflush(stdin);
        scanf("%d", &i);
    } while (i != 1 && i != 0);
    if (i == 1)
    {
        puts("请输入一个课程信息文件的文件名：");
        scanf("%30s", ch2);
    }
    if ((file_course = fopen(ch2, "r")) == NULL)
    {
        puts("即将打开默认文件");
        file_course = fopen("clist.txt", "r");
    }

    do
    {
        puts("\n是否指定选课信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
        fflush(stdin);
        scanf("%d", &i);
    } while (i != 1 && i != 0);
    if (i == 1)
    {
        puts("请输入一个选课信息文件的文件名：");
        scanf("%30s", ch3);
    }
    if ((file_select = fopen(ch3, "r")) == NULL)
    {
        puts("即将打开默认文件");
        file_select = fopen("sclist.txt", "r");
        puts("\n所有文件打开完毕");
        system("pause");
        return 1;
    }
}

//建表
void init(void)
{
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

    /*这些是测试用代码，验证文件确实正常读取
        printf("counter==%d\n", counter--);
        printf("%s %s %s %f", select_list[counter].stu_ID, course_list[3].course_ID, stu_list[2].sex, course_list[3].course_grade);
        printf("\n%s\n", stu_list[0].stu_name);
        getchar();
        printf("02990227 肖阳   女 19");
        system("pause");
    */
}

/*以上内容已验证过准确无误*/

//事实证明driver的做法是好的，大程序往往很难看出来问题，有必要把每个函数部分单独测试

//学号，姓名，各科（按读入顺序）成绩，总分，加权平均分
void create_grade_list(void)
{
    int counter, average_part, average;
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
    }
}

//以上代码已检验无误，相关driver已验证

//以下是排序模块
void sort_slist()
{

    int i, j, k = -1;
    char ch[10];

    char xh[10];
    char xm[20];
    char xb[3];
    int nl;
    for (i = 0; i < *stu_total;)
    {
        strcpy(ch, stu_list[i].stu_ID);
        for (j = k = i; j < *stu_total; j++)
        {
            if (strcmp(ch, stu_list[j].stu_ID) > 0)
            {
                strcpy(ch, stu_list[j].stu_ID);
                k = j;
            }
        }
        strcpy(xh, stu_list[i].stu_ID);
        strcpy(stu_list[i].stu_ID, stu_list[k].stu_ID);
        strcpy(stu_list[k].stu_ID, xh);

        strcpy(xm, stu_list[i].stu_name);
        strcpy(stu_list[i].stu_name, stu_list[k].stu_name);
        strcpy(stu_list[k].stu_name, xm);

        strcpy(xb, stu_list[i].sex);
        strcpy(stu_list[i].sex, stu_list[k].sex);
        strcpy(stu_list[k].sex, xb);

        nl = stu_list[i].age;
        stu_list[i].age = stu_list[k].age;
        stu_list[k].age = nl;
        i++;
    }
}

void sort_clist(void)
{
    int i, j, k;
    char ch[10];
    char kh[10];
    char km[50];
    float xf;
    for (i = 0; i < *course_total; i++)
    {
        strcpy(ch, course_list[i].course_ID);
        for (j = k = i; j < *course_total; j++)
            if (strcmp(ch, course_list[j].course_ID) > 0)
            {
                strcpy(ch, course_list[j].course_ID);
                k = j;
            }
        strcpy(kh, course_list[i].course_ID);
        strcpy(course_list[i].course_ID, course_list[k].course_ID);
        strcpy(course_list[k].course_ID, kh);

        strcpy(km, course_list[i].course_name);
        strcpy(course_list[i].course_name, course_list[k].course_name);
        strcpy(course_list[k].course_name, km);

        xf = course_list[i].course_grade;
        course_list[i].course_grade = course_list[k].course_grade;
        course_list[k].course_grade = xf;
    }
}
void sort_grade_list()
{
    int i, j, k, m;
    float t;
    char xh[10];
    char xm[20];
    float cj;
    float pj;
    float zxf;
    for (i = 0; i < *stu_total; i++)
    {
        t = grade_list[i].average_grade;
        for (j = k = i; j < *stu_total; j++)
            if (t < grade_list[j].average_grade)
            {
                t = grade_list[j].average_grade;
                k = j;
            }
        strcpy(xh, grade_list[i].stu_ID);
        strcpy(grade_list[i].stu_ID, grade_list[k].stu_ID);
        strcpy(grade_list[k].stu_ID, xh);
        strcpy(xm, grade_list[i].stu_name);
        strcpy(grade_list[i].stu_name, grade_list[k].stu_name);
        strcpy(grade_list[k].stu_name, xm);
        for (m = 0; m < *course_total; m++)
        {
            cj = grade_list[i].stu_grade[m];
            grade_list[i].stu_grade[m] = grade_list[k].stu_grade[m];
            grade_list[k].stu_grade[m] = cj;
        }
        pj = grade_list[i].average_grade;
        grade_list[i].average_grade = grade_list[k].average_grade;
        grade_list[k].average_grade = pj;
        zxf = grade_list[i].total_grade;
        grade_list[i].total_grade = grade_list[k].total_grade;
        grade_list[k].total_grade = zxf;
    } //完全可以设计一个swap函数的，后来人要注意优化呀
}

void disp_stud()
{
    system("cls"); /* 清屏 */
    int i;
    puts("\t学号\t\t\t姓名\t\t\t性别\t\t\t年龄\n-----------------------------------------------------------------------------------------\n");
    for (i = 0; i < *stu_total;)
    {
        printf("%d\t%s\t\t%s\t\t\t%s\t\t\t%d\n", (i + 1), stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}

void disp_course()
{
    system("cls"); /* 清屏 */
    int i;
    puts("编号\t课程号\t\t\t课程名        \t\t\t学分\n----------------------------------------------------------------------\n");
    for (i = 0; i < *course_total;)
    {
        printf("%d\t%s\t\t\t%s\t\t\t%.2f\n", (i + 1), course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}

void disp_grade()
{
    system("cls"); /* 清屏 */
    int i, j, k, m = 0;
    printf("排名      学号              姓名");
    for (j = 0; j < *course_total; j++)
        printf("   %13s", course_list[j].course_name);
    printf("     平均分     总学分\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < *stu_total;)
    {
        printf("第%d名     %s        %13s", (i + 1), grade_list[i].stu_ID, grade_list[i].stu_name);
        for (k = 0; k < *course_total; k++)
            printf("%13.2f", grade_list[i].stu_grade[k]);
        printf("%13.2f%13.2f\n", grade_list[i].average_grade, grade_list[i].total_grade);
        i++;
        if (i % 10 == 0)
            system("pause");
    }
}
void menu2()
{
    int checker;
    /*显示所有数据*/
    while (1)
    {
        fflush(stdin);
        system("cls"); /* 清屏 */
        puts("按q退出,其他键+<enter>继续\n");
        if (getchar() == 'q')
            return;
        do
        {
            fflush(stdin);
            puts("显示学生表输入1\n显示课程表输入2\n显示成绩表输入3\n其他输入无效");
            scanf("%d", &checker);
        } while (checker != 1 && checker != 2 && checker != 3);
        switch (checker)
        {
        case 1:
            disp_stud();
            system("pause");
            return;
        case 2:
            disp_course();
            system("pause");
            return;
        case 3:
            disp_grade();
            system("pause");
            return;
        }
    }
}
///*数据输入*/
// int input_stud(Student stu_list[], int stu_total);
////从键盘输入若干条学生信息记录，依次存放到学生信息结构体数组 stu_list 中，stu_number 为数组原有学生记录数，函数返回最后的学生记录数。
// int input_course(Course course_list[], int course_total);
////从键盘输入若干条课程信息记录，依次存放到课程信息结构体数组 course_list 中，course_total 为数组原有课程记录数，函数返回最后的课程记录数。

///*上述两个函数运行时，每输入一条记录都检测是否已经存在相同记录，如果已经存在则
//提示是否替换，否则直接增加记录，使得函数同时具有增加记录和修改已有记录的功能。每
//输入完一条记录都要提示是否继续输入下一条记录，根据输入决定是否继续操作。*/

int input_stud(void)
{
    int i;
begin:
    puts("按q退出,其他键+<enter>继续\n");
    if (getchar() == 'q')
        return *stu_total;
    puts("输入一条学生信息记录：");
    puts("学号：");
    scanf("%s", stu_list[*stu_total].stu_ID);
    for (i = 0; i < *stu_total; i++)
    {
        if (!strcmp(stu_list[*stu_total].stu_ID, stu_list[i].stu_ID))
        {
            puts("已有记录，是否继续输入？(y/n)");
            if (getchar() == 'y')
                break;
            else
            {
                strcpy(stu_list[*stu_total].stu_ID, "");
                goto begin;
            }
        }
    }
    puts("姓名：");
    scanf("%s", stu_list[*stu_total].stu_name);
    for (i = 0; i < *stu_total; i++)
    {
        if (!strcmp(stu_list[*stu_total].stu_name, stu_list[i].stu_name))
        {
            puts("已有记录，是否继续输入？(y/n)");
            if (getchar() == 'y')
                break;
            else
            {
                strcpy(stu_list[*stu_total].stu_name, "");
                strcpy(stu_list[*stu_total].stu_ID, "");
                goto begin;
            }
        }
    }
    puts("性别：");
    scanf("%s", stu_list[*stu_total].sex);
    puts("年龄：");
    scanf("%d", &stu_list[*stu_total].age);
    return ++*stu_total;
}

int input_course(void)
{
    int i;
begin:
    puts("按q退出,其他键+<enter>继续\n");
    if (getchar() == 'q')
        return *course_total;
    puts("输入一条课程信息记录：");
    puts("课号：");
    scanf("%s", course_list[*course_total].course_ID);
    for (i = 0; i < *course_total; i++)
    {
        if (!strcmp(course_list[*course_total].course_ID, course_list[i].course_ID))
        {
            puts("已有记录，是否继续输入？(y/n)");
            if (getchar() == 'y')
                break;
            else
            {
                strcpy(course_list[*course_total].course_ID, "");
                goto begin;
            }
        }
    }
    puts("课名：");
    scanf("%s", course_list[*course_total].course_name);
    for (i = 0; i < *course_total; i++)
    {
        if (!strcmp(course_list[*course_total].course_name, course_list[i].course_name))
        {
            puts("已有记录，是否继续输入？(y/n)");
            if (getchar() == 'y')
                break;
            else
            {
                strcpy(course_list[*course_total].course_name, "");
                strcpy(course_list[*course_total].course_ID, "");
                goto begin;
            }
        }
    }
    puts("学分：");
    scanf("%f", &course_list[*course_total].course_grade);
    return ++*course_total;
}

int input_select()
{
    int i, c = 0, sid, cid;
    char a[30] = {0};
    float g;
begin:
    puts("按q退出,其他键+<enter>继续\n");
    if (getchar() == 'q')
        return *select_total;
    puts("输入一条选课信息记录：");
    puts("学号：");
    scanf("%s", a);
    for (i = 0; i < *stu_total; i++)
    {
        if (!strcmp(a, stu_list[i].stu_ID))
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
    else
        strcpy(select_list[*select_total].stu_ID, a);
    puts("课号：");
    scanf("%s", a);
    for (i = 0; i < *course_total; i++)
    {
        if (!strcmp(a, course_list[i].course_ID))
        {
            c = 1;
            cid = i;
            break;
        }
    }
    if (c != 1)
    {
        puts("没有此课号");
        strcpy(select_list[*select_total].stu_ID, "");
        system("pause");
        goto begin;
    }
    else
        strcpy(select_list[*select_total].course_ID, a);
    puts("学生成绩：");
    puts("是否有成绩？(y/n)");
    if (getchar() == 'y')
    {
        scanf("%f", &g);
        if (g < -1 || g > 120)
        {
            puts("成绩超限");
            strcpy(select_list[*select_total].stu_ID, "");
            strcpy(select_list[*select_total].course_ID, "");
            system("pause");
            goto begin;
        }
        else
            select_list[*select_total].stu_grade = g;
    }
    else
        select_list[*select_total].stu_grade = -1;
    return ++*select_total;
}
void menu3()
{
    int i, k1, k2, k3;
    while (1)
    {
        fflush(stdin);
        system("cls"); /* 清屏 */
        puts("按q退出,其他键+<enter>继续\n");
        if (getchar() == 'q')
            return;
        puts("改学生表输入1  改学生表输入2  改选课表输入3");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            k1 = input_stud();
            printf("共有%d学生\n", k1);
            return;
        case 2:
            k2 = input_course();
            printf("共有%d课程\n", k2);
            return;
        case 3:
            k3 = input_select();
            printf("共有%d选课\n", k3);
            return;
        }
    }
}
void menu1()
{
    system("cls"); /* 清屏 */
    // input stream loaded
    puts("NOW you are in: Initialize from 3 files\n");
    if (openfiles()) //注意，不能把函数原型直接拷贝过来用，把类型名字去掉
    {                // create lists
        init();
        create_grade_list();
        //一鼓作气吧这写完吧，抄也罢，省也罢，完成是第一目标
        sort_slist();      //按照学号升序排序。
        sort_clist();      //按照课程号升序排序。
        sort_grade_list(); //按照平均成绩降序排序
    }
}

/*D·删除选择信息的操作*/ void d_sc(int i)
{
    strcpy(select_list[i].stu_ID, select_list[*select_total - 1].stu_ID);
    strcpy(select_list[i].course_ID, select_list[*select_total - 1].course_ID);
    select_list[i].stu_grade = select_list[*select_total - 1].stu_grade;
    strcpy(select_list[*select_total - 1].stu_ID, "\0");
    strcpy(select_list[*select_total - 1].course_ID, "\0");
    select_list[*select_total - 1].stu_grade = -1;
    *select_total--;
}
/*D·删除选择信息*/ void del_sc()
{
    int i, p, j;
    char stu_ID[10];
a:
    printf("请输入其学号：");
    scanf("%s", stu_ID);
    for (i = p = 0; i < *select_total; i++)
    {
        if (!strcmp(stu_ID, select_list[i].stu_ID))
        {
            p = 1;
            printf("%s  %s  %f\n是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>", select_list[i].stu_ID, select_list[i].course_ID, select_list[i].stu_grade);
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
    printf("还剩%d条选课信息\n", *select_total);
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
        del_stuu_list();
    }
    else if (j == 2)
    {
        system("cls");
        del_c();
    }
}

/*D·删除学生信息的操作*/ void d_stu_list(int i)
{
    strcpy(stu_list[i].stu_ID, stu_list[*stu_total - 1].stu_ID);
    strcpy(stu_list[i].stu_name, stu_list[*stu_total - 1].stu_name);
    strcpy(stu_list[i].sex, stu_list[*stu_total - 1].sex);
    stu_list[i].age = stu_list[*stu_total - 1].age;
    strcpy(stu_list[*stu_total - 1].stu_ID, "\0");
    strcpy(stu_list[*stu_total - 1].stu_name, "\0");
    strcpy(stu_list[*stu_total - 1].sex, "\0");
    stu_list[*stu_total - 1].age = 0;
    *stu_total--;
}
/*D·删除学生信息*/ void del_stuu_list()
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

a:
    printf("请输入学号：");
    scanf("%s", ch);
    for (i = k = 0; i < *stu_total; i++)
    {
        if (strcmp(ch, stu_list[i].stu_ID) == 0)
        {
            k = 1;
            printf("%s  %s  %s  %d\n", stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_stu_list(i);
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
    for (i = k = 0; i < *stu_total; i++)
    {
        if (strcmp(ch, stu_list[i].stu_name) == 0)
        {
            k = 1;
            printf("%s  %s  %s  %d\n", stu_list[i].stu_ID, stu_list[i].stu_name, stu_list[i].sex, stu_list[i].age);
            printf("是否删除此条记录？\n是，请按<1>和<Enter>\n否，请按<2>和<Enter>\n请输入：");
            scanf("%d", &j);
            if (j == 1)
            {
                d_stu_list(i);
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
    printf("还剩%d条学生信息\n", *stu_total);
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
    strcpy(course_list[i].course_ID, course_list[*course_total - 1].course_ID);
    strcpy(course_list[i].course_name, course_list[*course_total - 1].course_name);
    course_list[i].course_grade = course_list[*course_total - 1].course_grade;
    strcpy(course_list[*course_total - 1].course_ID, "\0");
    strcpy(course_list[*course_total - 1].course_name, "\0");
    course_list[*course_total - 1].course_grade = -1;
    *course_total--;
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

a:
    printf("请输入课号：");
    scanf("%s", &ch);
    for (i = k = 0; i < *course_total; i++)
    {
        if (strcmp(ch, course_list[i].course_ID) == 0)
        {
            k = 1;
            printf("%s  %s  %.2f\n", course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
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
    for (i = k = 0; i < *course_total; i++)
    {
        if (strcmp(ch, course_list[i].course_name) == 0)
        {
            k = 1;
            printf("%s  %s  %f\n", course_list[i].course_ID, course_list[i].course_name, course_list[i].course_grade);
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
    printf("还剩%d条课程信息\n", *course_total);
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
        del_stuu_list();
    }
    else if (j == 2)
    {
        system("cls");
        del_sc();
    }
}

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

a:
    printf("请输入学号：");
    scanf("%s", &ch);
    for (i = id = 0; i < *stu_total; i++)
        if (strcmp(ch, stu_list[i].stu_ID) == 0)
        {
            id = 1;
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
                printf("%s:\t%.2f\n", course_list[m].course_name, grade_list[i].stu_grade[m]);
            }
            printf("平均分:\t%.2f\n总学分:\t%.2f\n第%d名\n", grade_list[i].average_grade, grade_list[i].total_grade, i + 1);
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

    sort_slist(); //按照学号升序排序。
    sort_clist(); //按照课程号升序排序。

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
        fprintf(f4, "%s\t%s\t%.2f\n", select_list[i].stu_ID, select_list[i].course_ID, select_list[i].stu_grade);
    fclose(f4);

    printf("操作成功！");
    system("pause");
}

/*D·导出至文件*/ void write_to_file2()
{
    int i, m, j;
    char grade[40] = {"成绩单"}, sj[20] = {0}, ti[10];
    struct tm *n;
    time_t now;
    now = time(0);
    n = localtime(&now);

    printf("是否指定成绩单文件名？\n是：请按1和<Enter>\n否：请按0和<Enter>\n请输入：");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("请输入名字：");
        scanf("%s", grade);
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
    strcat(grade, sj);
    strcat(grade, ".txt");

    void sort_list(void);  //按照学号升序排序。
    void sort_clist(void); //按照课程号升序排序。
    void create_grade_list(void);
    void sort_grade_list(void); //按照平均成绩降序排序

    f4 = fopen(grade, "w");
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
            fprintf(f4, "%.2f\t", grade_list[i].stu_grade[m]);
        fprintf(f4, "%.2f\t%.2f\n", grade_list[i], grade_list[i].total_grade);
    }

    printf("操作成功！");
    system("pause");
}
void menu4()
{
    /*根据输入删除对应数据*/ int i;
    while (1)
    {
        fflush(stdin);
        system("cls"); /* 清屏 */
        puts("按q退出,其他键+<enter>继续\n");
        if (getchar() == 'q')
            return;
        puts("删除学生按1  删除课程按2  删除选课按3");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            del_stuu_list();
            return;
        case 2:
            del_c();
            return;
        case 3:
            del_sc();
            return;
        }
    }
}
void menu5()
{
    /*根据输入删除对应数据*/ int i;
    while (1)
    {
        fflush(stdin);
        system("cls"); /* 清屏 */
        puts("按q退出,其他键+<enter>继续\n");
        if (getchar() == 'q')
            return;
        puts("查找学生按1  查找课程按2  查找选课按3");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            find_stu_list();
            return;
        case 2:
            find_c();
            return;
        case 3:
            find_grade_list();
            return;
        }
    }
}
void menu6()
{
    /*根据输入删除对应数据*/ int i;
    while (1)
    {
        fflush(stdin);
        system("cls"); /* 清屏 */
        puts("按q退出,其他键+<enter>继续\n");
        if (getchar() == 'q')
            return;
        puts("导出学生按1  导出成绩按2");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            write_to_file1();
            return;
        case 2:
            write_to_file2();
            return;
        }
    }
}
