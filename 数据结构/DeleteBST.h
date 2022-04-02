#pragma once
#include "SearchType.h"

/* ���㷨���ڸ��ڵ�ָ��Ϊ bt �Ķ�����������ɾ��һ����㣬bt��ֵ���ܷ����仯��
	����һ��Ҫ���������ͣ����� bt ��ֵ�ı��Ľ���ش���ʵ�Σ�������ܻ���ִ���
*/
bool DeleteBST(BSTNode *&bt, KeyType k) {		//�� bt ��ɾ���ؼ���Ϊ k �Ľ��
	if (bt == NULL)
		return false;													//����ɾ��ʧ�ܣ����ؼ�
	else {
		if (k < bt->key)
			return DeleteBST(bt->lchild, k);				//�ݹ飬����������ɾ��Ϊ k �Ľ��
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k);				//�ݹ飬����������ɾ��Ϊ k �Ľ��
		else {															//�ҵ���Ҫɾ���Ľ�� bt
			Delete(bt);												//���� Delete(bt) ����ɾ����� bt
			return true;												//ɾ���ɹ���������
		}
	}
}

void Delete(BSTNode *&p) {			//�Ӷ�����������ɾ����� p
	BSTNode *q;
	if (p->rchild == NULL) {				//��� pû������������ΪҶ�ӽ�㣩�����
		q = p;
		p = p->lchild;							//�ý�� p �����Ӵ�����
		free(q);
	}
	else if (p->lchild == NULL) {		//��� p û�������������
		q = p;
		p = p->rchild;							//�ý�� p ���Һ��Ӵ�����
		free(q);
	}
	else Delete1(p, p->lchild);			//��� p �������������������������
}

void Delete1(BSTNode *p, BSTNode *&r) {		//��ɾ��� p ������������rָ��������
	BSTNode *q;
	if (r->rchild != NULL)			//�ݹ��ҽ�� r �������½��
		Delete1(p, r->rchild);
	else {									//�ҵ��������½�� r ����û����������
		p->key = r->key;				//����� r ��ֵ��ŵ���� p �У����ֵ�����
		p->data = r->data;
		q = r;								//ɾ����� r
		r = r->lchild;					//�ý�� r �����Ӵ�����
		free(q);								//�ͷŽ�� q �Ŀռ�
	}
}