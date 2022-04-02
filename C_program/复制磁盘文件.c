#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *in, *out;
	char ch, infile[10], outfile[10];
	printf("输入读入文件的名字:");
	scanf("%s", infile);
	printf("输入输出文件的名字:");
	scanf("%s", outfile);
	if ((in=fopen(infile,"r")) == NULL)			//打开输入文件
	{
		printf("无法打开此文件\n");
		exit(0);
	}
	if ((out=fopen(outfile,"w")) == NULL)		//打开输出文件
	{
		printf("无法打开此文件\n");
		exit(0);
	}

	/*
	feof函数可以检查到文件读写位置标记是否移到文件的末尾，即磁盘文件是否结束。
	如果是结束，则函数值为1（真），否则为0（假）
	*/
	while (!feof(in))				//如果未遇到输入文件的结束标志
	{
		ch = fgetc(in);				//从输入文件读入一个字符，暂时放在变量ch中
		fputc(ch, out);				//将ch写到输出文件中
		putchar(ch);					//将ch显示再屏幕上
	}
	putchar(10);						//显示完全部字符后换行
	fclose(in);							//关闭输入文件
	fclose(out);						//关闭输出文件
	system("pause");
	return 0;
}