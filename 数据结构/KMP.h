#pragma once
#include "˳��.h"
//��ģʽ����next����
void GetNext(SqString t, int next[]) {			//��ģʽ��t���next����
	int j, k;
	j = 0, k = -1;							//jɨ��t��k��¼t[j]֮ǰ��t��ͷ��ͬ���ַ�����
	next[0] = -1;							//����next[0]��ֵ
	while (j < t.length - 1) {		//��t����λ�õ�nextֵ
		if (k == -1 || t.data[j] == t.data[k]) {		//kΪ-1��Ƚϵ��ַ����ʱ
			j++; k++;						//j��k�����Ƶ���һ���ַ�
			next[j] = k;					//����next[j]Ϊk
		}
		else k = next[k];				//k����
	}
}

int KMPIndex(SqString s, SqString t) {
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length &&j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else j = next[j];				//i���䣬j����
	}
	if (j >= t.length)				//ƥ��ɹ�
		return (i - t.length);		//�����Ӵ�λ��
	else									//ƥ�䲻�ɹ�
		return -1;						//����-1
}

//�Ľ������ģʽ����next����
void GetNextval(SqString t, int nextval[]) {
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length) {
		if (k == -1 || t.data[j] == t.data[k]) {
			j++; k++;
			if (t.data[j] != t.data[k])
				nextval[j] = k;
			else
				nextval[j] = nextval[k];
		}
		else
			k = nextval[k];
	}
}

int KMPIndex1(SqString s, SqString t) {
	int nextval[MaxSize], i = 0, j = 0;
	GetNextval(t, nextval);
	while (i < s.length && j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= t.length)
		return(i - t.length);
	else
		return -1;
}