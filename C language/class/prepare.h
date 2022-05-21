#include <stdio.h>
#define TOTAL 15
FILE *file_stu, *file_course, *file_select; //输入的三个文件的指针
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
// void query_stud(Student stu_list[], int stu_total);
////根据学号或姓名查询学生记录并显示。
// void query_course(Course course_list[], int course_total);
////根据课程号或课程名查询课程记录并显示。
// void query_gradelist(Score grade_list[], int grade_total, Course course_list[], int course_total, Student stu_list[], int stu_total);
////根据信号查询成绩单，显示对应同学的所有课程成绩、平均分、学分以及排名情况，并显示。

///*批量导出数据*/
// void write_to_file1(Student stu_list[], int stu_total, Course course_list[], int course_total, Select select_list[], int select_total);
///*以时间序列字符串为文件名，把学生信息表、课程信息表和选课信息表分别保存都对应的磁盘文件中。例如，学生文件名为
// student20190918120423.txt、课程文件名为 course20190918120430.txt、选课信息文件名为 select201909181258.txt。*/
// void write_to_file2(Score grade_list[], int grade_total, Course course_list[], int course_total, Student stu_list[], int stu_total);
///*以时间序列字符串为文件名，把成绩单保存的磁盘文件中，包括名次、学号、姓名、性别、各门课成绩、平均分以及总学分*/