#pragma once

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;				//���Ԫ��ֵ
	struct DNode *prior;		//ָ��ǰ�����
	struct DNode *next;			//ָ���̽��
}DLinkNode;							//˫����Ľ������