#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Student_type
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];

void save()
{
	FILE *fp;
	int i;
	if ((fp = fopen("file2","wb")) == NULL)
	{
		printf("cannot open file!\n");
		return;
	}
	for (i = 0; i < SIZE; i++)
	{
		if (fwrite(&stud[i], sizeof(struct Student_type), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);
}

//�Ӵ����ļ�stu_list��ȡ���������ݣ��������stud������
void load()
{
	FILE *fp;
	int i;
	if ((fp=fopen("stu_list","rb"))==NULL)  //��Ҫ�½�stu_list�ļ�
	{
		printf("cannot open infile\n");
		return;
	}
	for (i = 0; i < SIZE; i++)
	{
		if (fread(&stud[i],sizeof(struct Student_type),1,fp) != 1)
		{
			if (feof(fp))
			{
				fclose(fp);
				return;
			}
			printf("file read error\n");
		}
	}
	fclose(fp);
}

int main()
{
	int i;
	printf("Please enter data of student:\n");
	for (i = 0; i < SIZE; i++)
		scanf("%s%d%d%s", &stud[i].name, &stud[i].num, &stud[i].age, &stud[i].addr);
	save();
	system("pause");
	return 0;
}