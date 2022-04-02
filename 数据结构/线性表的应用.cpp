#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
#define MaxCol 10					//�������

typedef struct Node1				//�������ݽ������
{
	ElemType data[MaxCol];		//���һ�е�����
	struct Node1 *next;				//ָ�������ݽ��
}DList;										//�н������

typedef struct Node2
{
	int Row, Col;						//����������
	DList *next;							//ָ���һ�����ݽ��
}HList;										//ͷ�������

//���ý�����ʽ������������㷨
void CreateTable(HList *&h)
{
	int i, j;
	DList *r, *s;
	h = (HList *)malloc(sizeof(HList));			//����ͷ�ڵ�
	h->next = NULL;
	printf("���������������");
	scanf("%d%d", &h->Row, &h->Col);		//����������������
	for (i = 0; i < h->Row; i++)						//���������е�����
	{
		printf("��%d�У�", i+1);
		s = (DList *)malloc(sizeof(DList));			//�������ݽ��s
		for (j = 0; j < h->Col; j++)					//����һ�е�����
			scanf("%d", &s->data[j]);
		if (h->next == NULL)							//�����һ�����ݽ������
			h->next = s;
		else														//�����������ݽ������
			r->next = s;										//��s�����뵽r���֮��
		r = s;													//rʼ��ָ��β���
	}
	r->next = NULL;										//β����next���ÿ�
}

//���ٵ�������㷨
void DestroyTable(HList *&h)
{
	DList *pre = h->next, *p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(h);
}

//�����������㷨
void DispTable(HList *h)
{
	int j;
	DList *p = h->next;						//pָ��ʼ�н��
	while (p != NULL)						//ɨ��������
	{
		for (j = 0; j < h->Col; j++)		//���һ�е�����
			printf("%4d", p->data[j]);
		printf("\n");
		p = p->next;							//pָ����һ���н��
	}
}

//�����������㷨
void LinkTable(HList *h1, HList *h2, HList *&h)
{
	int i, j, k;
	DList *p = h1->next, *q, *s, *r;
	printf("�����ֶ��ǣ���1������ţ���2������ţ�");
	scanf("%d%d", &i, &j);
	h = (HList *)malloc(sizeof(HList));								//���������ͷ���
	h->Row = 0;																//������Ϊ0
	h->Col = h1->Col + h2->Col;										//������Ϊ��1�ͱ�2��������
	h->next = NULL;															//��next��ΪNULL��
	while (p != NULL)														//ɨ���1
	{
		q = h2->next;															//qָ���2���׽��
		while (q != NULL)													//ɨ���2
		{
			if (p->data[i - 1] == q->data[j - 1])						//��Ӧ�ֶ�ֵ���
			{
				s = (DList *)malloc(sizeof(DList));						//����һ�����ݽ��s
				for (k = 0; k < h1->Col; k++)							//���Ʊ�1�ĵ�ǰ��
					s->data[k] = p->data[k];
				for (k = 0; k < h2->Col; k++)							//���Ʊ�2�ĵ�ǰ��
					s->data[h1->Col + k] = q->data[k];
				if (h->next == NULL)										//��������ǵ�һ�����ݽ��
					h->next = s;													//��s�����뵽ͷ���֮��
				else																	//�������������ݽ��
					r->next = s;													//��s�����뵽���r֮��
				r = s;																//rʼ��ָ��β���
				h->Row++;														//��������1
			}
			q = q->next;														//��2����һ�����
		}
		p = p->next;															//��1����һ�����
	}
	r->next = NULL;															//��β����next���ÿ�
 }

int main()
{
	HList *h1, *h2, *h;
	printf("��1��\n");
	CreateTable(h1);
	printf("��2��\n");
	CreateTable(h2);
	LinkTable(h1, h2, h);
	printf("���ӽ����\n");
	DispTable(h);
	DestroyTable(h1);
	DestroyTable(h2);
	DestroyTable(h);
	system("pause");
	return 1;
}