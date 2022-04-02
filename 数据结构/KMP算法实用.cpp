#include <stdio.h>
#include <stdlib.h>
#include "KMP.h"
int main()
{
	SqString s;
	char c[9] = "abaabadd";
	StrAssign(s, c);
	int next[8];
	GetNext(s, next);
	for (int i = 0; i < 8; i++)
		printf("%d  ", next[i]);
	system("pause");
	return 0;
}