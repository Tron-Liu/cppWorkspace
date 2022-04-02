#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, k, n = 3;
	printf("Enter strings:\n");
	for (i = 0; i < n; i++)
		gets_s(str[i]);
	for (i = 0; i < n-1; i++)							//用选择排序法对字符串排序
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(str[k], str[j]) > 0) k = j;
		if (k != i)
		{
			strcpy(temp, str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k], temp);
		}
	}
	if ((fp=fopen("file1.dat","w")) == NULL)		//打开磁盘文件
	{
		printf("can't open file!\n");
		exit(0);
	}
	printf("\nThe new sequence:\n");
	for (i = 0; i < n; i++)
	{
		fputs(str[i], fp);					//向磁盘文件写一个字符串
		fputs("\n", fp);					//输出一个换行符
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}