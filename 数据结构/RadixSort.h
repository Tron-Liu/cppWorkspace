#pragma once
#include <iostream>
#define MAXD 10
#define MAXR 10			//MAXR Ϊ������

typedef struct node
{
	char data[MAXD];		//MAXD Ϊ���ؼ���λ��
	struct node *next;		//ָ����һ���
}NodeType;						//�����������ݵĽ������

/*
	param1���洢�Ĵ��������еĵ������ָ��
	param2������
	param3���ؼ���λ��
*/
void RadixSort(NodeType *&p, int r, int d) {		//LSD�����λ�������򣩻��������㷨
	NodeType *head[MAXR], *tail[MAXR], *t;		//��������ӵ���βָ��
	int i, j, k;
	for (i = 0; i <= d - 1; i++) {				//�ӵ�λ����λѭ��
		for (j = 0; j < r; j++)						//��ʼ�������ӵ��ס�β���
			head[j] = tail[j] = NULL;
		while (p != NULL) {						//���䣺����ԭ�����е�ÿ�����ѭ��
			k = p->data[i] - '0';					//�ҵ� k ������
			if (head[k] == NULL) {				//�� k �����ӿ�ʱ����ͷ����β��ָ����p
				head[k] = p;
				tail[k] = p;
			}
			else {										//�� k �����ӷǿ�ʱ���p����
				tail[k]->next = p;
				tail[k] = p;
			}
			p = p->next;							//ȡ��һ���������Ԫ��
		}
		p = NULL;									//������p���ռ����н��
		for(j = 0; j < r; j++)						//�ռ�������ÿһ������ѭ��
			if (head[j] != NULL) {				//���� j ������ǵ�һ���ǿ�����
				if (p == NULL) {
					p = head[j];
					t = tail[j];
				}
				else {									//�� p �ǿ�
					t->next = head[j];
					t = tail[j];
				}
			}
		t->next = NULL;							//���һ������ next ����NULL
	}
}