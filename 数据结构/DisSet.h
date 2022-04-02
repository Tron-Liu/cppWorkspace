#pragma once
typedef struct node {
	int data;			//����Ӧ�˵ı��
	int rank;			//����Ӧ��
	int parent;		//����Ӧ˫���±�
}UFSTree;				//���鼯���Ľ������

void MAKE_SET(UFSTree t[], int n) {		//��ʼ�����鼯��
	int i;
	for (i = 1; i <= n; i++) {
		t[i].data = i;				//����Ϊ���˵ı��		
		t[i].rank = 0;				//�ȳ�ʼ��Ϊ 0
		t[i].parent = i;			//˫�׳�ʼ��Ϊ�Լ�	
	}
}

int FIND_SET(UFSTree t[], int x) {				//�� x ���ڵ������в��Ҽ��ϱ��
	if (x != t[x].parent)								//˫�ײ����Լ�
		return (FIND_SET(t, t[x].parent));		//�ݹ���˫������ x
	else
		return x;											//˫�����Լ������� x
}

void UNION(UFSTree t[], int x, int y) {		//�� x �� y ���ڵ������ϲ�
	x = FIND_SET(t, x);								//���� x ���ڷ��뼯�����ı��
	y = FIND_SET(t, y);								//���� y ���ڷ��뼯�����ı��
	if (t[x].rank > t[y].rank)							//y ������С�� x ������
		t[y].parent = x;									//�� y ���� x ����ϣ�x��Ϊ y ��˫�׽��
	else {													//y �����ȴ��ڵ��� x ������
		t[x].parent = y;									//�� x ���� y ����ϣ�y ��Ϊ x ��˫�׽��
		if (t[x].rank == t[y].rank)					//x �� y ��������ͬ
			t[y].rank++;									//y �������� 1
	}
}