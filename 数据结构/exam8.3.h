#pragma once
#include "GraphType.h"

//��8.9 ����ͼG�����ڽӱ�洢�����һ���㷨��
//�󲻴�Ȩ������ͨͼG�дӶ��� u �� v ��һ�����·��
typedef struct {
	int data;			//������
	int parent;		//ǰһ�������λ��
}QUERE;				//�ǻ��ζ�������

void ShortPath(AdjGraph *G, int u, int v) {
	//����Ӷ��� u ������ v �����·��
	ArcNode *p;
	int w, i;
	QUERE qu[MAXV];					//�ǻ��ζ���
	int front = -1, rear = -1;			//���е�ͷβָ��
	int visited[MAXV];
	for (i = 0; i < G->n; i++)			//���ʱ���ó�ֵ 0
		visited[i] = 0;
	rear++;									//���� u ����
	qu[rear].data = u;
	qu[rear].parent = -1;
	visited[u] = 1;
	while (front != rear) {				//�Բ���ѭ��
		front++;								//���Ӷ��� w
		w = qu[front].data;
		if (w == v) {										//�ҵ� v ʱ���·��֮�沢�˳�
			i = front;										//ͨ�����������·��
			while (qu[i].parent != -1) {
				printf("%2d", qu[i].data);
				i = qu[i].parent;
			}
			printf("%2d", qu[i].data);
			break;
		}
		p = G->adjlist[w].firstarc;			//�� w �ĵ�һ���ڽӵ�
		while (p != NULL) {
			if (visited[p->adjvex] = 0) {		//�� w δ���ʹ����ڽӵ����
				visited[p->adjvex] = 1;
				rear++;
				qu[rear].data = p->adjvex;
				qu[rear].parent = front;
			}
			p = p->nextarc;						//�� w ����һ���ڽӵ�
		}
	}
}

//��8.10 ����ͼG�����ڽӱ�洢�����һ���㷨���󲻴�Ȩ������ͨͼG�о��붥�� v ��Զ��һ������
int Maxdist(AdjGraph *G, int v) {
	ArcNode *p;
	int Qu[MAXV];							//���ζ�������
	int front = 0, rear = 0;				//���е�ͷβָ��
	int visited[MAXV];					//���ʱ������
	int i, j, k;
	for (i = 0; i < G->n; i++)			//��ʼ�����ʱ������
		visited[0];
	rear++;									//���� v ����
	Qu[rear] = v;
	visited[v] = 1;							//��� v �ѷ���
	while (rear != front) { 
		front = (front + 1) % MAXV;
		k = Qu[front];									//���� k ����
		p = G->adjlist[k].firstarc;					//�ҵ�һ���ڽӵ�
		while (p!=NULL) {							//����δ�����ʹ����ڽӵ����
			j = p->adjvex;								//�ڽӵ�Ϊ���� j
			if (visited[j] == 0) {						//�� j δ�����ʹ�
				visited[j] = 1;
				rear = (rear + 1) % MAXV;
				Qu[rear] = j;								//���� j ����
			}
			p = p->nextarc;							//����һ���ڽӵ�
		}
	}
	return k;
}