#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int length;
}SqList;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

int ListLength(SqList *L)
{
	return L->length;
}

//����˳����ListInsert
void ListInsert(SqList *&L, ElemType e)
{
	int i = 0, j;
	while (i < L->length && L->data[i] < e)
		i++;															//����ֵΪe��Ԫ��
	for (j = ListLength(L); j > i; j--)						//��data[i]�������Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;												//�����ĳ�����1
}

//���������ListInsert
void ListInsert(LinkNode *&L, ElemType e)
{
	LinkNode *pre = L, *p;
	while (pre->next != NULL && pre->next->data < e)
		pre = pre->next;															//���Ҳ������ǰ�����pre
	p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = e;																	//�������e�����ݽ��p
	p->next = pre->next;														//��pre���֮�����p���
	pre->next = p;
}

//�����Ĺ鲢�㷨
//���������
void UnionList(SqList *LA, SqList *LB, SqList *&LC)
{
	int i = 0, j = 0, k = 0;												//i��j�ֱ�ΪLA��LB���±꣬kΪLC��Ԫ�صĸ���
	LC = (SqList *)malloc(sizeof(SqList));						//��������˳���
	while (i<LA->length && j<LB->length)
	{
		if (LA->data[i]<LB->data[j])
		{
			LC->data[k] = LA->data[i];
			i++;
			k++;
		}
		else																		//LA->data[i]>LB->data[j]
		{
			LC->data[k] = LB->data[j];
			j++;
			k++;
		}
	}
	while (i<LA->length)												//LA��δɨ���꣬������Ԫ�ز���LC��
	{
		LC->data[k] = LA->data[i];
		i++;
		k++;
	}
	while (j < LB->length)												//LB��δɨ���꣬������Ԫ�ز���LC��
	{
		LC->data[k] = LB->data[i];
		j++;
		k++;
	}
	LC->length = k;
}
//���õ�����
void UnionList1(LinkNode *LA, LinkNode*LB, LinkNode*&LC)
{
	LinkNode *pa = LA->next, *pb = LB->next, *r, *s;
	LC = (LinkNode *)malloc(sizeof(LinkNode));							//����LC��ͷ���
	r = LC;																						//rʼ��ָ��LC��β���
	while (pa !=NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = (LinkNode *)malloc(sizeof(LinkNode));						//����pa��ָ���
			s->data = pa->data;
			r->next = s;																		//��s�����뵽LC��
			r = s;
			pa = pa->next;
		}
		else
		{
			s = (LinkNode *)malloc(sizeof(LinkNode));						//����pb��ָ���
			s->data = pb->data;
			r->next = s;																		//��s�����뵽LC��
			r = s;
			pb = pb->next;
		}
	}
	while (pa != NULL)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = pa->data;
		r->next = s;
		r = s;
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = pb->data;
		r->next = s;
		r = s;
		pb = pb->next;
	}
	r->next = NULL;					//β����next���ÿ�
}

//������Ӧ��
//��2.15 p69
void Commnode(LinkNode *&LA, LinkNode*LB, LinkNode*LC)
{
	LinkNode *pa = LA->next, *pb = LB->next, *pc = LC->next, *q, *r;
	LA->next = NULL;													//��ʱLA��Ϊ�½��������ͷ���
	r = LA;																		//rʼ��ָ��LA��β���
	while (pa != NULL)													//���Ҿ������Ĺ�����㲢����������
	{
		while (pb != NULL && pa->data > pb->data)	//pa�����LB�е�pb�����бȽ�
			pb = pb->next;
		while (pc != NULL && pa->data > pc->data)		//pa�����LC�е�pc�����бȽ�
			pc = pc->next;
		if (pb != NULL && pc != NULL && pa->data == pb->data && pa->data == pc->data)
		{																			//��pa����ǹ������
			r->next = pa;													//��pa�����뵽LA��
			r = pa;
			pa = pa->next;												//pa�Ƶ���һ�����
		}
		else																		//��pa���ǹ�����㣬��ɾ��֮
		{
			q = pa;
			pa = pa->next;												//pa�Ƶ���һ�����
			free(q);																//�ͷŷǹ������
		}
	}
	r->next = NULL;														//β����next���ÿ�
}

//��2.16 p69
void dels(LinkNode *&L)
{
	LinkNode *p = L->next, *q;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)	//�ҵ��ظ�ֵ�Ľ��
		{
			q = p->next;							//qָ������ظ�ֵ�Ľ��		
			p->next = q->next;					//ɾ��q���
			free(q);
		}
		else
			p = p->next;							//�����ظ���㣬pָ�����
	}
}

//��2.17 p70
ElemType M_serch(SqList *A, SqList *B)		//A��B�ĳ�����ͬ
{
	int i = 0, j = 0, k = 0;
	while (i<A->length && j<B->length)		//�������о�û��ɨ����
	{
		k++;														//��ǰ�鲢��Ԫ�ظ�����1
		if (A->data[i] < B->data[j])					//�鲢��С��Ԫ��A->data[i]
		{
			if (k == A->length)							//����ǰ�鲢��Ԫ���ǵ�n��Ԫ��
				return A->data[i];						//����A->data[i]
			i++;
		}
		else														//�鲢��С��Ԫ��B->data[j]
		{
			if (k == B->length)							//����ǰ�鲢��Ԫ���ǵ�n��Ԫ��
				return B->data[j];							//����B->data[j]
			j++;
		}
	}
}