#include "RecType.h"

void InsertSort(RecType R[], int n) {		//��R[0..n-1]�������������ֱ�Ӳ�������
	int i, j;
	RecType tmp;
	for (i = 1; i < n; i++) {
		if (R[i].key < R[i - 1].key) {				//����ʱ
			tmp = R[i];
			j = i - 1;
			do {												//��R[i]�Ĳ���λ��
				R[j + 1] = R[j];							//���ؼ��ִ���R[i].key�ļ�¼����
				j--;
			} while (j >= 0 && R[j].key > tmp.key);
			R[j + 1] = tmp;								//�� j+1������R[i]
		}
	}
}