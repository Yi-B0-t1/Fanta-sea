#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
    puts("按q退出,其他键继续\n");
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

/*D·显示学生信息，10条1停*/ void disp_stud()
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

/*D·显示课程信息，10条1停*/ void disp_course()
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

/*D·显示成绩单，10条1停*/ void disp_grade()
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
        puts("按q退出,其他键继续\n");
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