#pragma once
#include "SearchType.h"

BSTNode *SearchBST(BSTNode *bt, KeyType k) {		//��������������
	if (bt == NULL || bt->key == k)			//�ݹ����������������ʧ�ܻ��߲��ҳɹ�ʱ���ݹ����
		return bt;											//���� bt ��ֵ
	if (k < bt->key)									//���������еݹ����
		return SearchBST(bt->lchild, k);
	else
		return SearchBST(bt->rchild, k);		//���������еݹ����
}

/*
	�ڶ��������� bt �в��ҹؼ���Ϊ k �Ľ�㣬�����ҳɹ����ú������ظý���ָ�룬f������˫�׽��
	���򣬸ú������� NULL������÷������£�
			SearchBST1( bt, x, NULL, f );
	����ĵ��������� f1 ����Ϊ�м������������ f����ʼֵ��Ϊ NULL
*/
/*
	param3��f1����¼��ǰ����˫�׽���ָ�룬�ڲ��ҳɹ�ʱ����ֵ���� f
*/
BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f) {
	if (bt == NULL) {												//����ʧ��
		f = NULL;														// f ��ֵΪ��
		return(NULL);												//�������� NULL
	}
	else if (k == bt->key) {									//���ҳɹ�
		f = f1;															// f ֵ��Ϊ f1������ǰ����˫�׽���ָ�룬���⣬f Ϊ������ָ����������Բ���return
		return(bt);													//���ظý���ָ��
	}
	else if (k < bt->key)											//���������еݹ����
		return SearchBST1(bt->lchild, k, bt, f);
	else
		return SearchBST1(bt->rchild, k, bt, f);		//���������еݹ����
}