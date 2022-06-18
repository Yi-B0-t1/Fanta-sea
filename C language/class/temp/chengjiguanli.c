#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


typedef struct
{
	char xh[10]; //ѧ��
	char xm[20]; //������10����������
	char xb[3];  //�Ա�ֻ�ܱ���һ������
	int nl;       //����
}Student;

typedef struct
{
	char kh[10]; //�κţ�����10�ַ�����
	char km[25]; //��������12����������
	float  xf;    //�γ�ѧ�֣�Ϊһ��������
}Course;

typedef struct
{
	char xh[10]; //ѧ�ţ�����10�ַ�����
	char kh[10]; //�γ̺�
	float  cj;    //�ɼ���Ϊһ��������
}Select;

typedef struct
{
	char xh[10]; //ѧ��
	char xm[20]; //����
	float cj[30];//���ſγ̳ɼ�
	float zpj;    //��Ȩƽ����
	float zxf;    //����ϰѧ��
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
		printf("��ѡ��");
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
			printf("\n��л����ʹ�ã�\n");
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
		printf("ѧ����Ϣ�ļ�Ϊ�գ���ȡʧ��\n ");
	}
	else
	{
		while (!feof(f1))
		{
			fscanf(f1, "%s\t%s\t%s\t%d\n", slist[scount].xh, slist[scount].xm, slist[scount].xb, &slist[scount].nl);
			scount++;
		}
		fclose(f1);
		printf("ѧ����Ϣ��ȡ�ɹ�\n");
	}

	FILE *f2;
	f2 = fopen("clist.txt", "r");
	if (f1 == NULL)
	{
		printf("�γ���Ϣ�ļ�Ϊ�գ���ȡʧ��\n ");
	}
	else
	{
		while (!feof(f2))
		{
			fscanf(f2, "%s\t%s\t%f\n", clist[ccount].kh, clist[ccount].km, &clist[ccount].xf);
			ccount++;
		}
		fclose(f2);
		printf("�γ���Ϣ��ȡ�ɹ�\n");
	}

	FILE *f3;
	f3 = fopen("sclist.txt", "r");
	if (f1 == NULL)
	{
		printf("ѡ����Ϣ�ļ�Ϊ�գ���ȡʧ��\n ");
	}
	else
	{
		while (!feof(f3))
		{
			fscanf(f3, "%s\t%s\t%f\n", sclist[sccount].xh, sclist[sccount].kh, &sclist[sccount].cj);
			sccount++;
		}
		fclose(f3);
		printf("ѡ����Ϣ��ȡ�ɹ�\n");
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
	printf("������ѧ����ѧ��:");
	scanf("%s", slist[scount].xh);
	printf("������ѧ��������:");
	scanf("%s", slist[scount].xm);
	printf("������ѧ�����Ա�:");
	scanf("%s", slist[scount].xb);
	printf("������ѧ��������:");
	scanf("%d", &slist[scount].nl);
	int j = searchstubyid(slist[scount].xh);
	if (j != -1)
	{
		int n = 0;
		printf("��ѧ��ѧ���Ѵ��ڣ��Ƿ��滻��1.��  2.��\n");
		printf("��ѡ��");
		scanf("%d", &n);
		if (n == 1)
		{
			slist[j] = slist[scount];
			printf("�滻�ɹ�\n");
		}
	}
	else
	{
		scount++;
		printf("��ӳɹ�\n");
	}

	return scount;
}

int input_course(Course clist[], int ccount)
{
	printf("������γ̵Ŀκ�:");
	scanf("%s", clist[ccount].kh);
	printf("������γ̵�����:");
	scanf("%s", clist[ccount].km);
	printf("������γ̵�ѧ��:");
	scanf("%f", &clist[ccount].xf);
	int j = searchcourbyid(clist[ccount].kh);
	if (j != -1)
	{
		int n = 0;
		printf("�ÿγ̿κ��Ѵ��ڣ��Ƿ��滻��1.��  2.��\n");
		printf("��ѡ��");
		scanf("%d", &n);
		if (n == 1)
		{
			clist[j] = clist[ccount];
			printf("�滻�ɹ�\n");
		}
	}
	else
	{
		ccount++;
		printf("��ӳɹ�\n");
	}
	return ccount;
}

int input_select(Select sclist[], int sccount)
{

	printf("������ѡ����Ϣ��ѧ��:");
	scanf("%s", sclist[sccount].xh);
	int j = searchstubyid(sclist[sccount].xh);
	while (j == -1)
	{
		printf("û�и�ѧ�ŵ�ѧ��������������\n");
		printf("������ѡ����Ϣ��ѧ��:");
		scanf("%s", sclist[sccount].xh);
		j = searchstubyid(sclist[sccount].xh);
	}
	printf("������ѡ����Ϣ�Ŀκ�:");
	scanf("%s", sclist[sccount].kh);
	int k = searchcourbyid(sclist[sccount].kh);
	while (k == -1)
	{
		printf("û�иÿκŵĿγ̣�����������\n");
		printf("������ѡ����Ϣ�Ŀκ�:");
		scanf("%s", sclist[sccount].kh);
		k = searchcourbyid(sclist[sccount].kh);
	}
	printf("������ѡ����Ϣ�ĳɼ�:");
	scanf("%f", &sclist[sccount].cj);
	sccount++;
	printf("��ӳɹ�\n");
	return sccount;
}

void add()
{
	system("cls");
	printf("1.����ѧ����Ϣ\n");
	printf("2.����γ���Ϣ\n");
	printf("3.����ѡ����Ϣ\n");
	int n = 0;
	printf("��ѡ��");
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
	printf("������ɾ����ѧ����ѧ�ţ�");
	scanf("%s", xh);
	int j = searchstubyid(xh);
	while (j == -1)
	{
		printf("û�д�ѧ�ŵ�ѧ��������������\n");
		printf("������ɾ����ѧ����ѧ�ţ�");
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
	printf("ɾ���ɹ�\n");
	return scount;
}

int delete_course(Course clist[], int ccount)
{

	char kh[10];
	printf("������ɾ���Ŀγ̵Ŀκţ�");
	scanf("%s", kh);
	int j = searchcourbyid(kh);
	while (j == -1)
	{
		printf("û�д˿κŵĿγ̣�����������\n");
		printf("������ɾ���Ŀγ̵Ŀκţ�");
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
	printf("ɾ���ɹ�\n");
	return ccount;
}

int delete_select(Select sclist[], int sccount)
{
	char xh[10];
	printf("������ɾ����ѡ����Ϣ��ѧ�ţ�");
	scanf("%s", xh);
	int j = searchselbyid(xh);
	while (j == -1)
	{
		printf("û�д�ѧ�ŵ�ѡ����Ϣ������������\n");
		printf("������ɾ����ѡ����Ϣ��ѧ�ţ�");
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
	printf("ɾ���ɹ�\n");
	return sccount;
}

void delete_info()
{
	system("cls");
	printf("1.ɾ��ѧ����Ϣ\n");
	printf("2.ɾ���γ���Ϣ\n");
	printf("3.ɾ��ѡ����Ϣ\n");
	int n = 0;
	printf("��ѡ��");
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
	printf("�������ѯѧ����ѧ�ţ�");
	scanf("%s", xh);
	int i = searchstubyid(xh);
	while (i == -1)
	{
		printf("û�д�ѧ�ŵ�ѧ��������������\n");
		printf("�������ѯ��ѧ����ѧ�ţ�");
		scanf("%s", xh);
		i = searchstubyid(xh);
	}
	printf("ѧ��\t����\t�Ա�\t����\n");
	printf("%s\t%s\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
}

void query_course(Course clist[], int ccount)
{
	char kh[10];
	printf("�������ѯ�γ̵Ŀκţ�");
	scanf("%s", kh);
	int i = searchstubyid(kh);
	while (i == -1)
	{
		printf("û�д˿κŵĿγ̣�����������\n");
		printf("�������ѯ�γ̵Ŀκţ�");
		scanf("%s", kh);
		i = searchstubyid(kh);
	}
	printf("�κ�\t�γ���\tѧ��\n");
	printf("%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
}

void sort()						//�ɼ����� 
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
	printf("�������ѯ��ѧ�ţ�");
	scanf("%s", xh);
	int i = searchscorebyid(xh);
	if (i != -1)
	{
		printf("ѧ��:%s\n", xh);
		printf("����:%s\n", cjlist[i].xm);
		printf("���Ƴɼ�:\n");
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
		printf("��Ȩƽ���֣�%.1f\n", cjlist[i].zpj);
		printf("��ѧ�֣�%.1f\n", cjlist[i].zxf);
	}
	else
	{
		printf("�˳ɼ���û�д�ѧ��\n");
	}

}

void search()
{
	system("cls");
	printf("1.��ѯѧ����Ϣ\n");
	printf("2.��ѯ�γ���Ϣ\n");
	printf("3.��ѯ�ɼ���\n");
	int n = 0;
	printf("��ѡ��");
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
	printf("ѧ����Ϣ�������\n");
	FILE *f2;
	f2 = fopen("clist.txt", "w");
	for (i = 0; i < ccount; i++)
	{
		fprintf(f2,"%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
	fclose(f2);
	printf("�γ���Ϣ�������\n");
	FILE *f3;
	f3 = fopen("sclist.txt", "w");
	for (i = 0; i < sccount; i++)
	{
		fprintf(f3, "%s\t%s\t%.1f\n", sclist[i].xh, sclist[i].kh, sclist[i].cj);
	}
	fclose(f3);
	printf("ѡ����Ϣ�������\n");
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
	printf("�ɼ�������ɹ�\n");
}

void sort_slist()											//ѧ������
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

void sort_clist()											//�κ����� 
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
	printf("ѧ��\t����\t�Ա�\t����\n");
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
	printf("�κ�\t�γ���\tѧ��\n");
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
		printf("ѧ��:%s\n", cjlist[i].xh);
		printf("����:%s\n", cjlist[i].xm);
		printf("���Ƴɼ�:");
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
		printf("\n��Ȩƽ���֣�%.1f\n", cjlist[i].zpj);
		printf("��ѧ�֣�%.1f\n", cjlist[i].zxf);
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
	printf("\n----------���ã�----------\n");
	printf("1.�����ʼ����\n");
	printf("2.��ʾ��Ϣ\n");
	printf("3.�����¼\n");
	printf("4.ɾ����¼\n");
	printf("5.��ѯ��Ϣ\n");
	printf("6.������������\n");
	printf("0.�˳�\n");
}
