#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *in, *out;
	char ch, infile[10], outfile[10];
	printf("��������ļ�������:");
	scanf("%s", infile);
	printf("��������ļ�������:");
	scanf("%s", outfile);
	if ((in=fopen(infile,"r")) == NULL)			//�������ļ�
	{
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}
	if ((out=fopen(outfile,"w")) == NULL)		//������ļ�
	{
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}

	/*
	feof�������Լ�鵽�ļ���дλ�ñ���Ƿ��Ƶ��ļ���ĩβ���������ļ��Ƿ������
	����ǽ���������ֵΪ1���棩������Ϊ0���٣�
	*/
	while (!feof(in))				//���δ���������ļ��Ľ�����־
	{
		ch = fgetc(in);				//�������ļ�����һ���ַ�����ʱ���ڱ���ch��
		fputc(ch, out);				//��chд������ļ���
		putchar(ch);					//��ch��ʾ����Ļ��
	}
	putchar(10);						//��ʾ��ȫ���ַ�����
	fclose(in);							//�ر������ļ�
	fclose(out);						//�ر�����ļ�
	system("pause");
	return 0;
}