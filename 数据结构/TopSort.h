#pragma once
#include <stdio.h>
//ͼ���ڽӾ���洢����
#define  MAXV 25			//��󶥵����
#define INF 32767				//����Ϊ ����
typedef int InfoType;
typedef struct {
	int no;								//����ı��
	InfoType info;					//�����������Ϣ
}VertexType;							//���������

//ͼ���ڽӱ�洢����
typedef struct ANode {
	int adjvex;								//�ñߵ��ڽӵ���
	struct ANode *nextarc;			//ָ����һ���ߵ�ָ��
	int weight;								//�ñߵ������Ϣ����Ȩֵ�����������ͱ�ʾ��
}ArcNode;									//�߽�������

typedef struct {
	VertexType data;						//������Ϣ
	int count;									//���������򣺴�Ŷ������
	ArcNode *firstarc;					//ָ���һ���ڽӵ�
}VNode;										//ͷ�������

typedef struct {
	VNode adjlist[MAXV];				//�ڽӱ��ͷ�������
	int n, e;										//ͼ�еĶ����� n �ͱ��� e
}AdjGraph;									//������ͼ�ڽӱ�����


/*
	�������򷽷����£�
	��1��������ͼ��ѡ��һ��û��ǰ���������Ϊ 0 ���Ķ��㲢�������
	��2����ͼ��ɾȥ�ö��㣬����ɾȥ�Ӹö��㷢����ȫ�������
	��3���ظ�����������ֱ��ʣ���ͼ�в��ٴ���û��ǰ���Ķ���Ϊֹ
*/

void TopSort(AdjGraph *G) {
	int i, j;
	int St[MAXV], top = -1;				//ջ St ��ָ��Ϊ top
	ArcNode *p;
	for (i = 0; i < G->n; i++)				//����ó�ֵ 0
		G->adjlist[i].count = 0;
	for (i = 0; i < G->n; i++) {			//�����ж�������
		p = G->adjlist[i].firstarc;
		while (p != NULL) {
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)				//�����Ϊ 0 �Ķ����ջ
		if (G->adjlist[i].count == 0) {
			top++;
			St[top] = i;
		}
	while (top > -1) {							//ջ����ѭ��
		i = St[top];								//��ջһ������
		top--;
		printf("%d", i);							//����ö���
		p = G->adjlist[i].firstarc;			//�ҵ�һ���ڽӵ�
		while (p != NULL) {					//������ i �ĳ����ڽӵ����ȼ� 1
			j = p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count == 0) {		//�����Ϊ 0 ���ڽӵ��ջ
				top++;
				St[top] = j;
			}
			p = p->nextarc;					//����һ���ڽӵ�
		}
	}
}