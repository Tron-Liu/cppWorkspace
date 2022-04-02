#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode *next;
}LinkNode;

//��ʼ���㷨
void initQueue(LinkNode *&rear) {
	rear = NULL;
}

//�����㷨
void enQueue(LinkNode *&rear, ElemType e) {
	LinkNode *p;
	p = (LinkNode *)malloc(sizeof(LinkNode));			//�����½��
	p->data = e;
	if (rear == NULL) {												//ԭ����Ϊ��
		p->next = p;													//��Ϊѭ������
		rear = p;															//rearָ���½��
	}
	else {																	//ԭ���в���
		p->next = rear->next;										//��p�����뵽rear���֮��
		rear->next = p;												//��Ϊѭ������
		rear = p;															//rearָ���½��p
	}
}

//�����㷨
bool deQueue(LinkNode *&rear, ElemType &e) {
	LinkNode *t;
	if (rear == NULL)													//�ӿ�
		return false;
	else if (rear->next == rear) {								//ԭ����ֻ��һ�����
		e = rear->data;
		free(rear);
		rear == NULL;													//��rearΪ������
	}
	else {																	//ԭ�������������������ϵĽ��
		t = rear->next;													//tָ���ͷ���
		e = t->data;
		rear->next = t->next;										//ɾ��t���
		free(t);																//�ͷŽ��ռ�
	}
	return true;
}

//�жӿ��㷨
bool queueEmpty(LinkNode *rear) {
	return (rear == NULL);
}

