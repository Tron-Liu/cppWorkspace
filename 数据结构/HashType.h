#pragma once
#include <iostream>

/*��ϣ��Ľ������*/
#define NULLKEY -1			//����չؼ���ֵ�������õ�Ԫ�Ĺؼ�������Ϊ����ֵ -1
#define DELKEY -2				//���屻ɾ�ؼ���ֵ

typedef int KeyType;			//�ؼ�������
typedef struct {
	KeyType key;					//�ؼ�����
	int count;							//̽�������
}HashTable;							//��ϣ��Ԫ����