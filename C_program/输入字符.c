#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch, filename[10];
	printf("���������õ��ļ���:");
	scanf("%s", filename);
	if ((fp = fopen(filename,"w")) == NULL)			//������ļ���ʹfpָ����ļ�
	{
		printf("�޷��򿪴��ļ�\n");							//�����ʱ������������򲻿�������Ϣ
		exit(0);															//��ֹ����
	}
	ch = getchar();													//���������������Ļس���
	printf("������һ��׼���洢�����̵��ַ���(��#����):");
	ch = getchar();													//���մӼ�������ĵ�һ���ַ�
	while (ch != '#')												//������'#'ʱ����ѭ��
	{
		fputc(ch, fp);												//������ļ����һ���ַ�
		putchar(ch);													//��������ַ���ʾ����Ļ��
		ch = getchar();												//�ٽ��մӼ��������һ���ַ�
	}
	fclose(fp);															//�ر��ļ�
	putchar(10);														//����Ļ���һ�����з�
	putchar(65);
	system("pause");
	return 0;
}