#include <iostream>

typedef int KeyType;		//�ؼ�������
typedef struct node {
	KeyType key;				//�ؼ�����
	struct node *next;		//��һ�����ָ��
}NodeType;						//������������

typedef struct {
	NodeType *firstp;		//�׽��ָ��
}HashTable;						//��ϣ��Ԫ����