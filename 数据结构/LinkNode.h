#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;				//���Ԫ��ֵ
	struct LNode *next;			//ָ���̽��
}LinkNode;							//������������