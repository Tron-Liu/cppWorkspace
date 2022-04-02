#include <stdio.h>
#include <stdlib.h>
#include "circular_queue1.h"

void number(int n) {
	int i;
	ElemType e;
	SqQueue *q;						//���ζ���ָ��q
	InitQueue(q);						//��ʼ������q
	for (i = 1; i <= n; i++)			//������ʼ����
		enQueue(q, i);
	printf("��������˳��");
	while (!QueueEmpty(q)) {	//���в���ѭ��
		deQueue(q, e);					//����һ��Ԫ��e
		printf("%d ", e);					//���Ԫ�ر��
		if (!QueueEmpty(q)) {		//���в���
			deQueue(q, e);				//����һ��Ԫ��e
			enQueue(q, e);				//���ճ��ӵ�Ԫ�ؽ���
		}
	}
	printf("\n");
	DestroyQueue(q);				//���ٶ���
}

int main()
{
	int i, n = 8;
	printf("��ʼ����:");
	for (i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
	number(n);
	system("pause");
	return 1;
}