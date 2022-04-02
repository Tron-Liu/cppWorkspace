#pragma once
#include "tree.h"
#include "BTree.h"

//��7.3 �Ժ�������Ϊ���Ĵ洢�ṹ�����һ������ t �߶ȵĵݹ��㷨
int TreeHeight1(TSonNode *t) {
	TSonNode *p;
	int i, h, maxh = 0;
	if (t == NULL) return 0;						//�������ظ߶� 0
	else {													//����ǿ���
		for (i = 0; i < MaxSons; i++) {
			p = t->sons[i];								//p ָ�� t �ĵ� i+1 �����ӽ��
			if (p != NULL) {								//�����ڵ� i+1 ������
				h = TreeHeight1(p);					//�����Ӧ�����ĸ߶�
				if (maxh < h) maxh = h;			//���������������߶�
			}
		}
		return (maxh + 1);							//���� maxh+1
	}
}

//��7.4 �Ժ����ֵ�����Ϊ���Ĵ洢�ṹ�����һ������ t �߶ȵĵݹ��㷨
int TreeHeight2(TSBNode *t) {
	TSBNode *p;
	int h, maxh = 0;
	if (t == NULL) return 0;				//�������� 0
	else {
		p = t->vp;								//pָ���һ�����ӽ��
		while (p != NULL) {					//ɨ�� t ����������
			h = TreeHeight2(p);				//��� p �����ĸ߶�
			if (maxh < h) maxh = h;		//���������������߶�
			p = p->hp;							//�������� t ����������
		}
		return  (maxh + 1);					//���� maxh+1
	}
}

//�� 7.11 ���������ö������洢�ṹ������һ�Ÿ��������������н��ĸ���
int Nodes(BTNode *b) {
	int num1, num2;
	if (b == NULL) return 0;
	else return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}

//�� 7.12 ������������ö������洢�ṹ�����һ�Ÿ���������������Ҷ�ӽ��
void DispLeaf(BTNode *b) {
	if (b != NULL) {
		if (b->lchild != NULL && b->rchild != NULL)
			printf("%c", b->data);				//����Ҷ�ӽ��
		DispLeaf(b->lchild);						//����������е�Ҷ�ӽ��
		DispLeaf(b->rchild);						//����������е�Ҷ�ӽ��
	}
}

//�� 7.14 ������������ö������洢�ṹ�����һ���㷨������� b �е� k ��Ľ�����
void Lnodenum(BTNode *b, int h, int k, int &n) {
	if (b == NULL)							//����ֱ�ӷ���
		return;
	else {										//����ǿ���
		if (h == k) n++;					//��ǰ���ʵĽ���ڵ� k ��ʱ n �� 1
		else if (h < k) {						//����ǰ�����С�� k���ݹ鴦����������
			Lnodenum(b->lchild, h + 1, k, n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}

//�� 7.15 ������������ö������洢�ṹ�����һ���㷨�ж����Ŷ������Ƿ�����
bool Like(BTNode *b1, BTNode *b2) {			//b1 �� b2 ���Ŷ���������ʱ���� true�����򷵻� false
	bool like1, like2;
	if (b1 == NULL && b2 == NULL)
		return true;
	else if (b1 == NULL || b2 == NULL)
		return false;
	else {
		like1 = Like(b1->lchild, b2->lchild);
		like2 = Like(b1->rchild, b2->rchild);
		return (like1&&like2);								//���� like1 �� like2 ��������
	}
}

//�� 7.16 ������������ö������洢�ṹ�����һ���㷨���ֵΪ x �Ľ�����������
bool ancestor(BTNode *b, ElemType x) {
	if (b == NULL)
		return false;
	else if (b->lchild != NULL && b->lchild->data == x || b->rchild != NULL && b->rchild->data == x) {
		printf("%c", b->data);
		return true;
	}
	else if (ancestor(b->lchild, x) || ancestor(b->rchild, x)) {
		printf("%c", b->data);
		return true;
	}
	else return false;
}

//�� 7.19 ����������˳��洢�ṹת���ɶ������洢�ṹ
BTNode *trans(SqBinTree a, int i) {
	BTNode *b;
	if (i > MaxSize) return NULL;
	if (a[i] == '#') return NULL;								//�ս�㷵�� NULL
	b = (BTNode *)malloc(sizeof(BTNode));			//��������� b
	b->data = a[i];
	b->lchild = trans(a, 2 * i);								//�ݹ鴴��������
	b->rchild = trans(a, 2 * i + 1);							//�ݹ鴴��������
	return b;
}