#pragma once
#include "DLinkNode.h"

//��2.9 ˫�����е�Ԫ������ p58
void reverse(DLinkNode *&L)			//˫�����������㷨
{
	DLinkNode *p = L->next, *q;		//pָ���׽��
	L->next = NULL;							//����ֻ��ͷ����˫����L
	while (p != NULL)						//ɨ��L���������ݽ��
	{
		q = p->next;							//ͷ�巨��ı�p��next����q��ʱ�������̽��
		p->next = L->next;					//����ͷ�巨��p���뵽˫������
		if (L->next != NULL)				//��L�д������ݽ��
			L->next->prior = p;				//�޸�ԭ���׽���ǰ��ָ��
		L->next = p;							//���½����Ϊ�׽��
		p->prior = L;
		p = q;										//��p����ָ�����̽��
	}
}

//��2.10 ˫�����е�Ԫ��������� p58
void sort(DLinkNode *&L) {
	DLinkNode *p, *pre, *q;
	p = L->next->next;					//pָ��L�ĵڶ������ݽ��
	L->next->next = NULL;			//����ֻ��һ�����ݽ��������
	while (p != NULL)
	{
		q = p->next;						//q����p���ĺ�̽��
		pre = L;								//�������ͷ���бȽϣ�preָ�������p��ǰ�����
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;				//����������Ҳ������ǰ�����
		p->next = pre->next;			//��pre���֮�������p
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		p = q;									//ɨ��ԭ˫�������µĽ��
	}
}