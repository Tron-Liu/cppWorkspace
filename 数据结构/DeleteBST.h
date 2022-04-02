#pragma once
#include "SearchType.h"

/* 该算法是在根节点指针为 bt 的二叉排序树中删除一个结点，bt的值可能发生变化，
	所以一定要用引用类型，即将 bt 的值改变后的结果回传给实参，否则可能会出现错误
*/
bool DeleteBST(BSTNode *&bt, KeyType k) {		//在 bt 中删除关键字为 k 的结点
	if (bt == NULL)
		return false;													//空树删除失败，返回假
	else {
		if (k < bt->key)
			return DeleteBST(bt->lchild, k);				//递归，在左子树中删除为 k 的结点
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k);				//递归，在右子树中删除为 k 的结点
		else {															//找到了要删除的结点 bt
			Delete(bt);												//调用 Delete(bt) 函数删除结点 bt
			return true;												//删除成功，返回真
		}
	}
}

void Delete(BSTNode *&p) {			//从二叉排序树中删除结点 p
	BSTNode *q;
	if (p->rchild == NULL) {				//结点 p没有右子树（含为叶子结点）的情况
		q = p;
		p = p->lchild;							//用结点 p 的左孩子代替它
		free(q);
	}
	else if (p->lchild == NULL) {		//结点 p 没有左子树的情况
		q = p;
		p = p->rchild;							//用结点 p 的右孩子代替它
		free(q);
	}
	else Delete1(p, p->lchild);			//结点 p 即有左子树又有右子树的情况
}

void Delete1(BSTNode *p, BSTNode *&r) {		//被删结点 p 有左、右子树，r指向其左孩子
	BSTNode *q;
	if (r->rchild != NULL)			//递归找结点 r 的最右下结点
		Delete1(p, r->rchild);
	else {									//找到了最右下结点 r （它没有右子树）
		p->key = r->key;				//将结点 r 的值存放到结点 p 中（结点值替代）
		p->data = r->data;
		q = r;								//删除结点 r
		r = r->lchild;					//用结点 r 的左孩子代替它
		free(q);								//释放结点 q 的空间
	}
}