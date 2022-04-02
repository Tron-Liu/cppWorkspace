#pragma once
typedef struct {
	char data;					//���ֵ
	double weight;		//Ȩ��
	int parent;				//˫�׽��
	int lchild;					//���ӽ��
	int rchild;					//�Һ��ӽ��
}HTNode;

//�����������
void CreateHT(HTNode ht[], int n0) {
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n0 - 1; i++)				//���н���������ó�ֵ -1
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	for (i = n0; i <= 2 * n0 - 2; i++) {			//������������� n0-1 ����֧���
		min1 = min2 = 32767;						//lnode �� rnode Ϊ��СȨ�ص��������λ��
		lnode = rnode = -1;
		for(k=0;k<=i-1;k++)						//�� ht[0...i-1]����Ȩֵ��С���������
			if (ht[k].parent == -1) {				//ֻ����δ����������Ľ���в���
				if (ht[k].weight < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;					//ht[i]��Ϊ˫�׽��
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
}

#define N 10
//���ÿ�����Ĺ��������������
typedef struct {
	char cd[N];			//��ŵ�ǰ���Ĺ�������
	int start;				//��ʾ cd[start...n0]�����ǹ�������
}HCode;

void CreateHCode(HTNode ht[], HCode hcd[], int n0) {
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0; i++) {				//���ݹ������������������
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (f != -1) {							//ѭ��ֱ����˫�׽�㣬����������
			if (ht[f].lchild == c)				//��ǰ�����˫�׽�������
				hc.cd[hc.start--] = '0';
			else										//��ǰ�����˫�׽����Һ���
				hc.cd[hc.start--] = '1';
			c = f; f = ht[f].parent;			//�ٶ�˫�׽�����ͬ���Ĳ���
		}
		hc.start++;								//������ָ���ʼ���ַ�
		hcd[i] = hc;
	}
}