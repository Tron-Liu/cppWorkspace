#pragma once
#include "Sqlist.h"

//���彨��˳���
void CreateList(Sqlist * &L, ElemType a[], int n) {	 //��a�е�n��Ԫ�ؽ���˳���
	L = (Sqlist *)malloc(sizeof(Sqlist));		//���������Ա�Ŀռ�
	for (int i = 0; i < n; i++) {						//iɨ������a�е�Ԫ��
		L->data[i] = a[i];								//��Ԫ��a[i]��ŵ�L��
	}
	L->length = n;										//����L�ĳ���n
}