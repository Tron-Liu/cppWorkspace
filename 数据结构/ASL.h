#include "HashType.h"

void ASL(HashTable ha[], int n, int m, int p) {				//��ƽ�����ҳ���
	int i, j;
	int succ = 0, unsucc = 0, s;
	for (i = 0; i < m; i++)
		if (ha[i].key != NULLKEY)
			succ += ha[i].count;											//�ۼƳɹ�ʱ���ܹؼ��ֱȽϴ���
	printf("�ɹ������ ASL��%d��=%g\n", n, succ*1.0 / n);
	for (i = 0; i < p; i++) {
		s = 1; j = i;
		while (ha[i].key != NULLKEY) {
			s++;
			j = (j + 1) % m;
		}
		unsucc += s;														//�ۼƲ��ɹ�ʱ���ܹؼ��ֱȽϴ���
	}
	printf("���ɹ������ ASL��%d��= %g\n", n, unsucc*1.0 / p);
}