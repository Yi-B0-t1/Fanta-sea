#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


typedef struct
{
	char xh[10]; //学号
	char xm[20]; //姓名，10个汉字以内
	char xb[3];  //性别，只能保存一个汉字
	int nl;       //年龄
}Student;

typedef struct
{
	char kh[10]; //课号，长度10字符以内
	char km[25]; //课姓名，12个汉字以内
	float  xf;    //课程学分，为一个浮点数
}Course;

typedef struct
{
	char xh[10]; //学号，长度10字符以下
	char kh[10]; //课程号
	float  cj;    //成绩，为一个浮点数
}Select;

typedef struct
{
	char xh[10]; //学号
	char xm[20]; //姓名
	float cj[30];//各门课程成绩
	float zpj;    //加权平均分
	float zxf;    //总修习学分
}Score;


Student slist[999];
int scount = 0;
Course clist[999];
int ccount = 0;
Select sclist[999];
int sccount = 0;
Score cjlist[999];
int cjnum = 0;


int searchstubyid(char xh[10]);
int searchcourbyid(char kh[10]);
void init(Student slist[], Course clist[], Select sclist[]);
void create_cjlist(Select sclist[], Course clist[], Score cjlist[]);
int input_stud(Student slist[], int scount);
int input_course(Course clist[], int ccount);
int input_select(Select sclist[], int sccount);
void add();
int delete_stud(Student slist[],int scount);
int delete_course(Course clist[], int ccount);
int delete_select(Select sclist[], int sccount); 
void delete_info();
void query_stud(Student slist[], int scount);
void query_course(Course clist[], int ccount);
void sort();
int searchscorebyid(char id[10]);
void query_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount);
void search();
void write_to_file1(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount); 
void write_to_file2(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount);
void sort_slist();
void sort_clist();
void disp_stud(Student slist[], int scount);
void disp_course(Course clist[], int ccount);
void disp_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount);
void print();
void menu();



int main()
{

	int n = 0;
	while (1)
	{
		menu();
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			init(slist, clist, sclist);
			create_cjlist(sclist, clist, cjlist);
			system("pause");
			system("cls");
			break;
		case 2:
			print();
			system("pause");
			system("cls");
			break;
		case 3:
			add();
			system("pause");
			system("cls");
			break;
		case 4:
			delete_info();
			system("pause");
			system("cls");
			break;
		case 5:
			search();
			system("pause");
			system("cls");
			break;
		case 6:
			write_to_file1(slist,scount,clist,ccount,sclist,sccount);
			write_to_file2(cjlist,cjnum,clist,ccount,slist,scount);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("\n感谢您的使用！\n");
			exit(0);
		default:
			break;
		}
	}
	return 0;
}



int searchstubyid(char xh[10])
{
	int i = 0;
	for (i = 0; i < scount; i++)
	{
		if (strcmp(xh, slist[i].xh) == 0)
		{
			return i;
		}
	}
	return -1;
}
int searchcourbyid(char kh[10])
{
	int i = 0;
	for (i = 0; i < ccount; i++)
	{
		if (strcmp(kh, clist[i].kh) == 0)
		{
			return i;
		}
	}
	return -1;
}
int searchselbyid(char xh[10])
{
	int i = 0;
	for (i = 0; i < sccount; i++)
	{
		if (strcmp(xh, sclist[i].xh) == 0)
		{
			return i;
		}
	}
	return -1;
}

void init(Student slist[], Course clist[], Select sclist[])
{
	FILE *f1;
	f1 = fopen("slist.txt", "r");
	if (f1 == NULL)
	{
		printf("学生信息文件为空，读取失败\n ");
	}
	else
	{
		while (!feof(f1))
		{
			fscanf(f1, "%s\t%s\t%s\t%d\n", slist[scount].xh, slist[scount].xm, slist[scount].xb, &slist[scount].nl);
			scount++;
		}
		fclose(f1);
		printf("学生信息读取成功\n");
	}

	FILE *f2;
	f2 = fopen("clist.txt", "r");
	if (f1 == NULL)
	{
		printf("课程信息文件为空，读取失败\n ");
	}
	else
	{
		while (!feof(f2))
		{
			fscanf(f2, "%s\t%s\t%f\n", clist[ccount].kh, clist[ccount].km, &clist[ccount].xf);
			ccount++;
		}
		fclose(f2);
		printf("课程信息读取成功\n");
	}

	FILE *f3;
	f3 = fopen("sclist.txt", "r");
	if (f1 == NULL)
	{
		printf("选课信息文件为空，读取失败\n ");
	}
	else
	{
		while (!feof(f3))
		{
			fscanf(f3, "%s\t%s\t%f\n", sclist[sccount].xh, sclist[sccount].kh, &sclist[sccount].cj);
			sccount++;
		}
		fclose(f3);
		printf("选课信息读取成功\n");
	}

}

void create_cjlist(Select sclist[], Course clist[], Score cjlist[])
{
	int i = 0;
	for (i = 0; i < sccount; i++)
	{
		float cjzp[30];
		int j = searchstubyid(sclist[i].xh);
		strcpy(cjlist[cjnum].xh, sclist[i].xh);
		strcpy(cjlist[cjnum].xm, slist[i].xm);
		int m = 0;
		for (; j < sccount; j++)
		{
			if (strcmp(sclist[j].xh, cjlist[cjnum].xh) == 0)
			{
				int k = searchcourbyid(sclist[j].kh);
				cjlist[cjnum].cj[m] = sclist[j].cj;
				cjzp[m] = clist[k].xf * sclist[j].cj;
				cjlist[cjnum].zxf += clist[k].xf;
				m++;
			}
		}
		int n = 0;
		float sum = 0;
		for (n = 0; n < m; n++)
		{
			sum += cjzp[n];
		}
		cjlist[cjnum].zpj = sum / cjlist[cjnum].zxf;
		cjnum++;
	}
}

int input_stud(Student slist[], int scount)
{
	printf("请输入学生的学号:");
	scanf("%s", slist[scount].xh);
	printf("请输入学生的姓名:");
	scanf("%s", slist[scount].xm);
	printf("请输入学生的性别:");
	scanf("%s", slist[scount].xb);
	printf("请输入学生的年龄:");
	scanf("%d", &slist[scount].nl);
	int j = searchstubyid(slist[scount].xh);
	if (j != -1)
	{
		int n = 0;
		printf("该学生学号已存在，是否替换？1.是  2.否\n");
		printf("请选择：");
		scanf("%d", &n);
		if (n == 1)
		{
			slist[j] = slist[scount];
			printf("替换成功\n");
		}
	}
	else
	{
		scount++;
		printf("添加成功\n");
	}

	return scount;
}

int input_course(Course clist[], int ccount)
{
	printf("请输入课程的课号:");
	scanf("%s", clist[ccount].kh);
	printf("请输入课程的名称:");
	scanf("%s", clist[ccount].km);
	printf("请输入课程的学分:");
	scanf("%f", &clist[ccount].xf);
	int j = searchcourbyid(clist[ccount].kh);
	if (j != -1)
	{
		int n = 0;
		printf("该课程课号已存在，是否替换？1.是  2.否\n");
		printf("请选择：");
		scanf("%d", &n);
		if (n == 1)
		{
			clist[j] = clist[ccount];
			printf("替换成功\n");
		}
	}
	else
	{
		ccount++;
		printf("添加成功\n");
	}
	return ccount;
}

int input_select(Select sclist[], int sccount)
{

	printf("请输入选课信息的学号:");
	scanf("%s", sclist[sccount].xh);
	int j = searchstubyid(sclist[sccount].xh);
	while (j == -1)
	{
		printf("没有该学号的学生，请重新输入\n");
		printf("请输入选课信息的学号:");
		scanf("%s", sclist[sccount].xh);
		j = searchstubyid(sclist[sccount].xh);
	}
	printf("请输入选课信息的课号:");
	scanf("%s", sclist[sccount].kh);
	int k = searchcourbyid(sclist[sccount].kh);
	while (k == -1)
	{
		printf("没有该课号的课程，请重新输入\n");
		printf("请输入选课信息的课号:");
		scanf("%s", sclist[sccount].kh);
		k = searchcourbyid(sclist[sccount].kh);
	}
	printf("请输入选课信息的成绩:");
	scanf("%f", &sclist[sccount].cj);
	sccount++;
	printf("添加成功\n");
	return sccount;
}

void add()
{
	system("cls");
	printf("1.输入学生信息\n");
	printf("2.输入课程信息\n");
	printf("3.输入选课信息\n");
	int n = 0;
	printf("请选择：");
	scanf("%d", &n);
	if (n == 1)
	{
		scount = input_stud(slist, scount);
	}
	else if (n == 2)
	{
		ccount=input_course(clist, ccount);
	}
	else if (n == 3)
	{
		sccount=input_select(sclist, sccount);
		create_cjlist(sclist, clist, cjlist);
	}
}

int delete_stud(Student slist[],int scount)
{
	char xh[10];
	printf("请输入删除的学生的学号：");
	scanf("%s", xh);
	int j = searchstubyid(xh);
	while (j == -1)
	{
		printf("没有此学号的学生，请重新输入\n");
		printf("请输入删除的学生的学号：");
		scanf("%s", xh);
		j = searchstubyid(xh);
	}
	if (j == scount - 1)
	{
		scount--;
	}
	else
	{
		int m = 0;
		for (m = j; m < scount - 1; m++)
		{
			slist[m] = slist[m + 1];
		}
		scount--;
	}
	printf("删除成功\n");
	return scount;
}

int delete_course(Course clist[], int ccount)
{

	char kh[10];
	printf("请输入删除的课程的课号：");
	scanf("%s", kh);
	int j = searchcourbyid(kh);
	while (j == -1)
	{
		printf("没有此课号的课程，请重新输入\n");
		printf("请输入删除的课程的课号：");
		scanf("%s", kh);
		j = searchcourbyid(kh);
	}
	if (j == ccount - 1)
	{
		ccount--;
	}
	else
	{
		int m = 0;
		for (m = j; m < ccount - 1; m++)
		{
			clist[m] = clist[m + 1];
		}
		ccount--;
	}
	printf("删除成功\n");
	return ccount;
}

int delete_select(Select sclist[], int sccount)
{
	char xh[10];
	printf("请输入删除的选课信息的学号：");
	scanf("%s", xh);
	int j = searchselbyid(xh);
	while (j == -1)
	{
		printf("没有此学号的选课信息，请重新输入\n");
		printf("请输入删除的选课信息的学号：");
		scanf("%s", xh);
		j = searchselbyid(xh);
	}
	if (j == sccount - 1)
	{
		sccount--;
	}
	else
	{
		int m = 0;
		for (m = j; m < sccount - 1; m++)
		{
			sclist[m] = sclist[m + 1];
		}
		sccount--;
	}
	printf("删除成功\n");
	return sccount;
}

void delete_info()
{
	system("cls");
	printf("1.删除学生信息\n");
	printf("2.删除课程信息\n");
	printf("3.删除选课信息\n");
	int n = 0;
	printf("请选择：");
	scanf("%d", &n);
	if (n == 1)
	{
		scount=delete_stud(slist, scount);
	}
	else if (n == 2)
	{
		ccount=delete_course(clist, ccount);
	}
	else if (n == 3)
	{
		sccount=delete_select(sclist, sccount);
	}
}

void query_stud(Student slist[], int scount)
{
	char xh[10];
	printf("请输入查询学生的学号：");
	scanf("%s", xh);
	int i = searchstubyid(xh);
	while (i == -1)
	{
		printf("没有此学号的学生，请重新输入\n");
		printf("请输入查询的学生的学号：");
		scanf("%s", xh);
		i = searchstubyid(xh);
	}
	printf("学号\t姓名\t性别\t年龄\n");
	printf("%s\t%s\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
}

void query_course(Course clist[], int ccount)
{
	char kh[10];
	printf("请输入查询课程的课号：");
	scanf("%s", kh);
	int i = searchstubyid(kh);
	while (i == -1)
	{
		printf("没有此课号的课程，请重新输入\n");
		printf("请输入查询课程的课号：");
		scanf("%s", kh);
		i = searchstubyid(kh);
	}
	printf("课号\t课程名\t学分\n");
	printf("%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
}

void sort()						//成绩降序 
{
	int i, j;
	for (i = 0; i < cjnum - 1; i++)
	{
		for (j = 0; j < cjnum - i - 1; j++)
		{
			if (cjlist[j].zpj < cjlist[j + 1].zpj)
			{
				Score temp = cjlist[j];
				cjlist[j] = cjlist[j + 1];
				cjlist[j + 1] = temp;
			}
		}
	}
}

int searchscorebyid(char id[10])
{
	int i = 0;
	for (i = 0; i < cjnum; i++)
	{
		if (strcmp(id, cjlist[i].xh) == 0)
		{
			return i;
		}
	}
	return -1;
}

void query_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount)
{
	sort();
	char xh[10];
	printf("请输入查询的学号：");
	scanf("%s", xh);
	int i = searchscorebyid(xh);
	if (i != -1)
	{
		printf("学号:%s\n", xh);
		printf("姓名:%s\n", cjlist[i].xm);
		printf("各科成绩:\n");
		int j = 0;
		for (j = 0; j < 30; j++)
		{
			if (cjlist[i].cj[j] > 0 && cjlist[i].cj[j]<=100)
			{
				printf("%.1f\n", cjlist[i].cj[j]);
			}
			else
			{
				break;
			}
		}
		printf("加权平均分：%.1f\n", cjlist[i].zpj);
		printf("总学分：%.1f\n", cjlist[i].zxf);
	}
	else
	{
		printf("此成绩单没有此学号\n");
	}

}

void search()
{
	system("cls");
	printf("1.查询学生信息\n");
	printf("2.查询课程信息\n");
	printf("3.查询成绩单\n");
	int n = 0;
	printf("请选择：");
	scanf("%d", &n);
	if (n == 1)
	{
		query_stud(slist, scount);
	}
	else if (n == 2)
	{
		query_course(clist, ccount);
	}
	else if (n == 3)
	{
		query_cjlist(cjlist, cjnum, clist, ccount, slist, scount);
	}
}

void write_to_file1(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount)
{
	FILE *f1;
	f1 = fopen("slist.txt", "w");
	int i = 0;
	for (i = 0; i < scount; i++)
	{
		fprintf(f1,"%s\t%s\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
	fclose(f1);
	printf("学生信息保存完成\n");
	FILE *f2;
	f2 = fopen("clist.txt", "w");
	for (i = 0; i < ccount; i++)
	{
		fprintf(f2,"%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
	fclose(f2);
	printf("课程信息保存完成\n");
	FILE *f3;
	f3 = fopen("sclist.txt", "w");
	for (i = 0; i < sccount; i++)
	{
		fprintf(f3, "%s\t%s\t%.1f\n", sclist[i].xh, sclist[i].kh, sclist[i].cj);
	}
	fclose(f3);
	printf("选课信息保存完成\n");
}

void write_to_file2(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount)
{
	FILE *f1;
	f1 = fopen("List.txt", "w");
	int i = 0;
	for (i = 0; i < cjcount; i++)
	{
		fprintf(f1, "%s\t%s\t", cjlist[i].xh, cjlist[i].xm);
		int j = 0;
		for (j = 0; j < 30; j++)
		{
			if (cjlist[i].cj[j] > 0 && cjlist[i].cj[j] <= 100)
			{
				fprintf(f1,"%.1f\t", cjlist[i].cj[j]);
			}
			else
			{
				break;
			}
		}
		fprintf(f1, "%.1f\t%.1f\n", cjlist[i].zpj, cjlist[i].zxf);
	}
	fclose(f1);
	printf("成绩单保存成功\n");
}

void sort_slist()											//学号升序
{
	int i, j;
	for (i = 0; i < scount - 1; i++)
	{
		for (j = 0; j < scount - i - 1; j++)
		{
			if (strcmp(slist[j].xh,slist[j+1].xh) > 0)		//str1 > str2 
			{
				Student temp = slist[j];
				slist[j] = slist[j + 1];
				slist[j + 1] = temp;
			}
		}
	}
}

void sort_clist()											//课号升序 
{
	int i, j;
	for (i = 0; i < ccount - 1; i++)
	{
		for (j = 0; j < ccount - i - 1; j++)
		{
			if (strcmp(clist[j].kh, clist[j + 1].kh) > 0)	//str1 > str2
			{
				Course temp = clist[j];
				clist[j] = clist[j + 1];
				clist[j + 1] = temp;
			}
		}
	}
}

void disp_stud(Student slist[], int scount)
{
	sort_slist();
	int i = 0;
	printf("学号\t姓名\t性别\t年龄\n");
	for (i = 0; i < scount; i++)
	{
		if (i != 0 && i % 10 == 0)
		{
			system("pause");
		}
		printf("%s\t%s\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
}

void disp_course(Course clist[], int ccount)
{
	sort_clist();
	int i = 0;
	printf("课号\t课程名\t学分\n");
	for (i = 0; i < ccount; i++)
	{
		if (i != 0 && i % 10 == 0)
		{
			system("pause");
		}

		printf("%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
}

void disp_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount)
{
	sort();
	int i = 0;
	for (i = 0; i < cjcount; i++)
	{
		printf("学号:%s\n", cjlist[i].xh);
		printf("姓名:%s\n", cjlist[i].xm);
		printf("各科成绩:");
		int j = 0;
		for (j = 0; j < 30; j++)
		{
			if (cjlist[i].cj[j] > 0 && cjlist[i].cj[j] <= 100)
			{
				printf("%.1f\t", cjlist[i].cj[j]);
			}
			else
			{
				break;
			}
		}
		printf("\n加权平均分：%.1f\n", cjlist[i].zpj);
		printf("总学分：%.1f\n", cjlist[i].zxf);
	}
}

void print()
{
	disp_stud(slist, scount);
	printf("\n");
	disp_course(clist, ccount);
	printf("\n");
	disp_cjlist(cjlist, cjnum, clist, ccount, slist, scount);
	printf("\n");
}

void menu()
{
	printf("\n----------您好！----------\n");
	printf("1.导入初始数据\n");
	printf("2.显示信息\n");
	printf("3.输入记录\n");
	printf("4.删除记录\n");
	printf("5.查询信息\n");
	printf("6.批量导出数据\n");
	printf("0.退出\n");
}
