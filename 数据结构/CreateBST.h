#pragma once
#include "SearchType.h"
#include "InsertBST.h"

//����BST�����ڵ�ָ��
BSTNode *CreateBST(KeyType A[], int n) {		//��������������
	BSTNode *bt = NULL;			//��ʼʱ bt Ϊ����
	int i = 0;
	while (i < n) {
		InsertBST(bt, A[i]);			//���ؼ���A[i]������������� bt ��
		i++;
	}
	return bt;								//���ؽ����Ķ����������ĸ�ָ��
}