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

//有序顺序表的ListInsert
void ListInsert(SqList *&L, ElemType e)
{
	int i = 0, j;
	while (i < L->length && L->data[i] < e)
		i++;															//查找值为e的元素
	for (j = ListLength(L); j > i; j--)						//将data[i]及后面的元素后移一个位置
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;												//有序表的长度增1
}

//有序单链表的ListInsert
void ListInsert(LinkNode *&L, ElemType e)
{
	LinkNode *pre = L, *p;
	while (pre->next != NULL && pre->next->data < e)
		pre = pre->next;															//查找插入结点的前驱结点pre
	p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = e;																	//创建存放e的数据结点p
	p->next = pre->next;														//在pre结点之后插入p结点
	pre->next = p;
}

//有序表的归并算法
//采用有序表
void UnionList(SqList *LA, SqList *LB, SqList *&LC)
{
	int i = 0, j = 0, k = 0;												//i、j分别为LA、LB的下标，k为LC中元素的个数
	LC = (SqList *)malloc(sizeof(SqList));						//建立有序顺序表
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
	while (i<LA->length)												//LA尚未扫描完，将其余元素插入LC中
	{
		LC->data[k] = LA->data[i];
		i++;
		k++;
	}
	while (j < LB->length)												//LB尚未扫描完，将其余元素插入LC中
	{
		LC->data[k] = LB->data[i];
		j++;
		k++;
	}
	LC->length = k;
}
//采用单链表
void UnionList1(LinkNode *LA, LinkNode*LB, LinkNode*&LC)
{
	LinkNode *pa = LA->next, *pb = LB->next, *r, *s;
	LC = (LinkNode *)malloc(sizeof(LinkNode));							//创建LC的头结点
	r = LC;																						//r始终指向LC的尾结点
	while (pa !=NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = (LinkNode *)malloc(sizeof(LinkNode));						//复制pa所指结点
			s->data = pa->data;
			r->next = s;																		//将s结点插入到LC中
			r = s;
			pa = pa->next;
		}
		else
		{
			s = (LinkNode *)malloc(sizeof(LinkNode));						//复制pb所指结点
			s->data = pb->data;
			r->next = s;																		//将s结点插入到LC中
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
	r->next = NULL;					//尾结点的next域置空
}

//有序表的应用
//例2.15 p69
void Commnode(LinkNode *&LA, LinkNode*LB, LinkNode*LC)
{
	LinkNode *pa = LA->next, *pb = LB->next, *pc = LC->next, *q, *r;
	LA->next = NULL;													//此时LA作为新建单链表的头结点
	r = LA;																		//r始终指向LA的尾结点
	while (pa != NULL)													//查找均包含的公共结点并建立新链表
	{
		while (pb != NULL && pa->data > pb->data)	//pa结点域LB中的pb结点进行比较
			pb = pb->next;
		while (pc != NULL && pa->data > pc->data)		//pa结点域LC中的pc结点进行比较
			pc = pc->next;
		if (pb != NULL && pc != NULL && pa->data == pb->data && pa->data == pc->data)
		{																			//若pa结点是公共结点
			r->next = pa;													//将pa结点插入到LA中
			r = pa;
			pa = pa->next;												//pa移到下一个结点
		}
		else																		//若pa不是公共结点，则删除之
		{
			q = pa;
			pa = pa->next;												//pa移到下一个结点
			free(q);																//释放非公共结点
		}
	}
	r->next = NULL;														//尾结点的next域置空
}

//例2.16 p69
void dels(LinkNode *&L)
{
	LinkNode *p = L->next, *q;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)	//找到重复值的结点
		{
			q = p->next;							//q指向这个重复值的结点		
			p->next = q->next;					//删除q结点
			free(q);
		}
		else
			p = p->next;							//不是重复结点，p指针后移
	}
}

//例2.17 p70
ElemType M_serch(SqList *A, SqList *B)		//A、B的长度相同
{
	int i = 0, j = 0, k = 0;
	while (i<A->length && j<B->length)		//两个序列均没有扫描完
	{
		k++;														//当前归并的元素个数增1
		if (A->data[i] < B->data[j])					//归并较小的元素A->data[i]
		{
			if (k == A->length)							//若当前归并的元素是第n个元素
				return A->data[i];						//返回A->data[i]
			i++;
		}
		else														//归并较小的元素B->data[j]
		{
			if (k == B->length)							//若当前归并的元素是第n个元素
				return B->data[j];							//返回B->data[j]
			j++;
		}
	}
}