#include <stdio.h>
#include <stdlib.h>
#define TOTAL 30
void clearline(void)
{
    while (getchar() != '\n')
        continue;
}
int main()
{
    char filename[15] = {0};
    FILE *file_stu;
    int checker;
    typedef struct
    {
        char stu_ID[10];   //学号
        char stu_name[20]; //姓名，10 个汉字以内
        char sex[3];       //性别，只能保存一个汉字
        int age;           //年龄
    } Student;
    Student stu_list[TOTAL] = {0};

    puts("Enter the name of the \"STUDENT\" file to be processed:\n");
    scanf("%s", filename); //应该加一个退出功能的，算了吧
    if ((file_stu = fopen(filename, "r")) == NULL)
    { /* 只读模式　 */
        printf("can't open %s,be well prepared next time!\n", filename);
        puts("file name such as \"name.txt\"");
        system("pause");
        checker = 1;
    }
    else
        puts("\n\"STUDENT\" file loaded.");

    rewind(file_stu);
    int counter;
    for (counter = 0; EOF != fscanf(file_stu, "%s %s %s %d", stu_list[counter].stu_ID, stu_list[counter].stu_name, stu_list[counter].sex, &stu_list[counter].age); counter++)
        continue;

    printf("counter==%d\n", counter--);
    printf("%s%s%s%d", stu_list[counter].stu_ID, stu_list[counter].stu_name, stu_list[counter].sex, stu_list[counter].age);
    printf("\n%s\n", stu_list[0].stu_name);
    getchar();
    printf("02990227 肖阳   女 19");
    system("pause");
    return 0;
}