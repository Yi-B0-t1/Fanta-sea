
//打开文件
int openfiles(void)
{
    char ch1[30], ch2[30], ch3[30];
    int i;
    system("cls");

    do
        puts("\n是否指定学生信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    while (1 != scanf("%d", &i));
    if (i == 1)
    {
        puts("请输入一个学生信息文件的文件名：");
        scanf("%30s", ch1);
    }
    if ((file_stu = fopen(ch1, "r+")) == NULL)
    {
        puts("文件名有误，即将打开默认文件");
        system("pause");
        file_stu = fopen("slist.txt", "r");
    }

    do
        puts("\n是否指定课程信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    while (1 != scanf("%d", &i));
    if (i == 1)
    {
        puts("请输入一个课程信息文件的文件名：");
        scanf("%30s", ch2);
    }
    if ((file_course = fopen(ch2, "r+")) == NULL)
    {
        puts("文件名有误，即将打开默认文件");
        system("pause");
        file_course = fopen("clist.txt", "r");
    }

    do
        puts("\n是否指定选课信息文件？\n是：1和<Enter>\n否：0和<Enter>.\n");
    while (1 != scanf("%d", &i));
    scanf("%d", &i);
    if (i == 1)
    {
        puts("请输入一个选课信息文件的文件名：");
        scanf("%30s", ch3);
    }
    if ((file_select = fopen(ch3, "r")) == NULL)
    {
        puts("文件名有误，即将打开默认文件");
        system("pause");
        file_select = fopen("sclist.txt", "r");
    }
}
