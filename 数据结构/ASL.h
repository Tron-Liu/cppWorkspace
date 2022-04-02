#include "HashType.h"

void ASL(HashTable ha[], int n, int m, int p) {				//求平均查找长度
	int i, j;
	int succ = 0, unsucc = 0, s;
	for (i = 0; i < m; i++)
		if (ha[i].key != NULLKEY)
			succ += ha[i].count;											//累计成功时的总关键字比较次数
	printf("成功情况下 ASL（%d）=%g\n", n, succ*1.0 / n);
	for (i = 0; i < p; i++) {
		s = 1; j = i;
		while (ha[i].key != NULLKEY) {
			s++;
			j = (j + 1) % m;
		}
		unsucc += s;														//累计不成功时的总关键字比较次数
	}
	printf("不成功情况下 ASL（%d）= %g\n", n, unsucc*1.0 / p);
}