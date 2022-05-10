void init(Student slist[], int *scount, Course clist[], int *ccount, Select sclist[], int *sccount)
{
    FILE *fp1, *fp2, *fp3;
    int i = *scount;
    char ch1, ch2, ch3;
    char filexs[] = "slist.txt", filekc[] = "clist.txt", filexk[] = "sclist.txt";
    if ((fp1 = fopen(filexs, "r")) == NULL)
    {
        printf("文件 %s 打开失败\n", filexs);
        exit(1);
    }
    if ((fp2 = fopen(filekc, "r")) == NULL)
    {
        printf("文件 %s 打开失败\n", filekc);
        exit(2);
    }
    if ((fp3 = fopen(filexk, "r")) == NULL)
    {
        printf("文件 %s 打开失败\n", filexk);
        exit(3);
    }
    i = 0;
    while (!feof(fp1))
    {
        fscanf(fp1, "%s%s%s%d", slist[i].xh, slist[i].xm, slist[i].xb, &slist[i].nl);
        printf("%s\n", slist[i].xh);
        i++;
        void init(Student slist[], int *scount, Course clist[], int *ccount, Select sclist[], int *sccount)
        {
            FILE *fp1, *fp2, *fp3;
            int i = *scount;
            char ch1, ch2, ch3;
            char filexs[] = "slist.txt", filekc[] = "clist.txt", filexk[] = "sclist.txt";
            if ((fp1 = fopen(filexs, "r")) == NULL)
            {
                printf("文件 %s 打开失败\n", filexs);
                exit(1);
            }
            if ((fp2 = fopen(filekc, "r")) == NULL)
            {
                printf("文件 %s 打开失败\n", filekc);
                exit(2);
            }
            if ((fp3 = fopen(filexk, "r")) == NULL)
            {
                printf("文件 %s 打开失败\n", filexk);
                exit(3);
            }
            i = 0;
            while (!feof(fp1))
            {
                fscanf(fp1, "%s%s%s%d", slist[i].xh, slist[i].xm, slist[i].xb, &slist[i].nl);
                printf("%s\n", slist[i].xh);
                i++;
            }