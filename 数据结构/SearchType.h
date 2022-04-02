#pragma once
#include <iostream>

typedef int KeyType;				//����ؼ�������Ϊ int
typedef char InfoType;			//InfoType �����ݶ���Ϊ char
typedef struct {
	KeyType key;						//�ؼ�����
	InfoType data;						//�������������Ϊ InfoType
}RecType;									//����Ԫ�ص�����

#define MAXI 20			//���������󳤶�
typedef struct {
	KeyType key;			//KeyTypeΪ�ؼ��ֵ�����
	int link;						//ָ���Ӧ�����ʼ�±�
}IdxType;						//������Ԫ�ص�����

typedef struct node{					//Ԫ������
	KeyType key;							//�ؼ�����
	InfoType data;							//����������
	struct node *lchild, *rchild;		//���Һ���ָ��
}BSTNode;