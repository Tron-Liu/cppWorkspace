#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
//例2.11 循环单链表  p60
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LinkNode;

int count(LinkNode *L, ElemType x)
{
	int i = 0;
	LinkNode *p = L->next; // p指向首结点，i置为0
	while (p != L)		   //扫描循环单链表L
	{
		if (p->data == x)
			x++;	 //找到值为x的结点后增1
		p = p->next; // p指向下一个结点
	}
	return i; //返回值为x的结点个数
}

//例2.12 循环双链表 p60

typedef struct DNode
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
} DLinkNode;

bool delelem(DLinkNode *&L, ElemType x)
{
	DLinkNode *p = L->next;		   // p指向首结点
	while (p != L && p->data != x) //查找第一个data值为x的结点p
		p = p->next;			   //因为是循环双链表，所以需要让p != L
	if (p != L)					   //找到了第一个值为x的结点p
	{
		p->next->prior = p->prior; //删除结点p
		p->prior->next = p->next;
		free(p);
		return true; //返回真
	}
	else //没有找到值为x的结点，返回false
		return false;
}

//例2.13 p60
bool Symm(DLinkNode *L)
{
	bool same = true;		 // same表示L是否对称，初始时为true
	DLinkNode *p = L->next;	 // p指向首结点
	DLinkNode *q = L->prior; // q指向尾结点
	while (same)
	{
		if (p->data != q->data)
		{ //对应结点值不相同，循环结束
			same = false;
		}
		else
		{
			if (p == q || p == q->prior)
				break;
			q = q->prior; // q前移一个结点
			p = p->next;  // p后移一个结点
		}
	}
	return same;
}