#pragma once
#include "SearchType.h"
int SeqSearch(RecType R[], int n, KeyType k) {
	int i = 0;
	while (i < n&&R[i].key != k)		//�ӱ�ͷ������
		i++;
	if (i >= n)									//δ�ҵ�����0
		return 0;
	else											//�ҵ������߼���� i+1
		return i + 1;
}

//�� R ��ĩβ����һ���ؼ���Ϊ k�ļ�¼����֮Ϊ�ڱ�
//�������ҹ��̲�����Ҫ�ж� i �Ƿ񳬽磬�Ӷ���߲����ٶ�
int SeqSearch1(RecType R[], int n, KeyType k) {
	int i = 0;
	R[n].key = k;
	while (R[i].key != k)		//�ӱ�ͷ������
		i++;
	if (i == n)						//δ�ҵ�����0
		return 0;
	else								//�ҵ������߼���� i+1
		return i + 1;
}