#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
//��2.11 ѭ��������  p60
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

int count(LinkNode *L, ElemType x)
{
	int i = 0;
	LinkNode *p = L->next;					//pָ���׽�㣬i��Ϊ0
	while (p != L)									//ɨ��ѭ��������L
	{
		if (p->data == x)
			x++;											//�ҵ�ֵΪx�Ľ�����1
		p = p->next;								//pָ����һ�����
	}
	return i;											//����ֵΪx�Ľ�����
}

//��2.12 ѭ��˫���� p60

typedef struct DNode
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DLinkNode;

bool delelem(DLinkNode *&L, ElemType x)
{
	DLinkNode *p = L->next;							//pָ���׽��
	while (p != L && p->data != x)					//���ҵ�һ��dataֵΪx�Ľ��p
		p = p->next;											//��Ϊ��ѭ��˫����������Ҫ��p != L
	if (p != L)														//�ҵ��˵�һ��ֵΪx�Ľ��p
	{
		p->next->prior = p->prior;						//ɾ�����p
		p->prior->next = p->next;
		free(p);
		return true;												//������
	}
	else																//û���ҵ�ֵΪx�Ľ�㣬����false
		return false;
}

//��2.13 p60
bool Symm(DLinkNode *L)
{
	bool same = true;					//same��ʾL�Ƿ�Գƣ���ʼʱΪtrue
	DLinkNode *p = L->next;		//pָ���׽��
	DLinkNode *q = L->prior;		//qָ��β���
	while (same)
	{
		if (p->data != q->data) {		//��Ӧ���ֵ����ͬ��ѭ������
			same = false;
		}
		else {
			if (p == q || p == q->prior) break;
			q = q->prior;					//qǰ��һ�����
			p = p->next;					//p����һ�����
		}
	}
	return same;
}