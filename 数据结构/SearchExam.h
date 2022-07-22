#pragma once
#include "SearchType.h"

//例9.4 找出左子树的最大结点和右子树的最小结点
void maxminnode(BSTNode *p)
{
	if (p != NULL)
	{
		if (p->lchild != NULL)
			printf("左子树的最大结点为：%d\n", maxnode(p->lchild));
		if (p->rchild != NULL)
			printf("右子树的最大结点为：%d\n", maxnode(p->lchild));
	}
}

KeyType maxnode(BSTNode *p)
{ //返回一棵二叉排序树中最大结点关键字
	while (p->rchild != NULL)
		p = p->rchild;
	return (p->data);
}

KeyType minnode(BSTNode *p)
{ //返回一棵二叉排序树中最小结点关键字
	while (p->lchild != NULL)
		p = p->lchild;
	return (p->data);
}