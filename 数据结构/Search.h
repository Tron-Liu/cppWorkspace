#pragma once
#include "GraphType.h"

int visited[MAXV] = { 0 };					//ȫ������
void DFS(AdjGraph *G, int v) {			//���ڽӱ�Ϊ�洢�ṹ��������ȱ����㷨
	ArcNode *p;
	visited[v] = 1;								//���ѷ��ʵı��
	printf("%d", v);								//��������ʶ���ı��
	p = G->adjlist[v].firstarc;				//p ָ�򶥵� v �ĵ�һ���ڽӵ�
	while (p != NULL) {
		if (visited[p->adjvex] == 0)		//�� p->adjvex����δ�����ʣ��ݹ������
			DFS(G, p->adjvex);
		p = p->nextarc;						//p ָ�򶥵� v ����һ���ڽӵ�
	}
}

#include "circular_queue1.h"
void BFS(AdjGraph *G, int v) {
	int w, i;
	ArcNode *p;
	SqQueue *qu;												//���廷�ζ���ָ��
	InitQueue(qu);												//��ʼ������
	int visited1[MAXV];										//���嶥����ʱ������
	for (i = 0; i < G->n; i++) visited1[i] = 0;		//���ʱ�������ʼ��
	printf("%2d", v);											//��������ʶ���ı��
	visited1[v] = 1;												//���ѷ��ʱ��
	enQueue(qu, v);
	while (!QueueEmpty(qu)) {							//�Ӳ���ѭ��
		deQueue(qu, w);										//����һ������ w
		p = G->adjlist[w].firstarc;						//ָ�� w �ĵ�һ���ڽӵ�
		while (p != NULL) {									//���� w �������ڽӵ�
			if (visited1[p->adjvex] == 0) {				//����ǰ�ڽӵ�δ������
				printf("%2d", p->adjvex);				//���ʸ��ڽӵ�
				visited1[p->adjvex] = 1;					//���ѷ��ʱ��
				enQueue(qu, p->adjvex);				//�ö������
			}
			p = p->nextarc;									//����һ���ڽӵ�
		}
	}
	printf("\n");
}

//����������ȱ�������ͨͼ���㷨
void DFS1(AdjGraph *G) {
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0) DFS(G, i);
}

//���ù�����ȱ�������ͨͼ���㷨
void BFS1(AdjGraph *G) {
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0)BFS(G, i);
}

//��8.3 ����ͼ G �����ڽӱ�洢�����һ���㷨���ж�����ͼ G �Ƿ���ͨ
bool Connect(AdjGraph * G) {			//�ж�����ͼ����ͨ��
	int i;
	bool flag = true;
	for (i = 0; i < G->n; i++)				//visited�����ó�ֵ
		visited[i] = 0;
	DFS(G, 0);										//���� DFS �㷨���Ӷ��� 0 ��ʼ������ȱ���
	for(i=0;i<G->n;i++)
		if (visited[i] == 0) {					//���ж���û�б����ʵ���˵���ǲ���ͨ��
			flag = false;
			break;
		}
	return flag;
}

//��8.4 ����ͼ G �����ڽӱ�洢�����һ���㷨�ж�ͼ G �дӶ��� u �� v �Ƿ���ڼ�·����
//��·����·���ϵĶ��㲻�ظ�

void ExistPath(AdjGraph *G, int u, int v, bool & has) {
	//has ��ʾ u �� v �Ƿ���·������ֵΪ false
	int w;
	ArcNode *p;
	visited[u] = 1;							//���ѷ��ʱ��
	if (u == v) {								//�ҵ�һ��·��
		has = true;							//�� has Ϊ true������
		return;
	}
	p = G->adjlist[u].firstarc;			//p ָ�򶥵� u �ĵ�һ���ڽӵ�
	while (p != NULL) {
		w = p->adjvex;					//w Ϊ���� u ���ڽӵ�
		if (visited[w] == 0)
			ExistPath(G, w, v, has);
		p = p->nextarc;					//p ָ�򶥵� u ����һ���ڽӵ�
	}
}
//���㷨����û�м�·�������������������ʱ has ��Ϊ false

//�� 8.5 ����ͼ G �����ڽӱ�洢�����һ���㷨���ͼ G�дӶ��� u �� v ��һ����·��
//�����·������
void FindaPath(AdjGraph *G, int u, int v, int path[], int d) {
	//d ��ʾ path �е�·�����ȣ���ʼΪ -1
	int w, i;
	ArcNode *p;
	visited[u] = 1;
	d++; path[d] = u;					//·������ d �� 1������ u ���뵽·����
	if (u == v) {								//�ҵ�һ��·�������������
		for (i = 0; i <= d; i++)
			printf("%d", path[i]);
		printf("\n");
		return;
	}
	p = G->adjlist[u].firstarc;			//p ָ�򶥵� u �ĵ�һ���ڽӵ�
	while (p != NULL) {
		w = p->adjvex;					//�ڽӵ�ı��Ϊ w
		if (visited[w] == 0)
			FindaPath(G, w, v, path, d);
		p = p->nextarc;					//p ָ�򶥵� u ����һ���ڽӵ�
	}
}

//�� 8.6 ����ͼ�����ڽӱ� G �洢�����һ���㷨���ͼ G �дӶ��� u �� v �����м�·��
//����ͼ G �дӶ��� u �� v ���ٴ���һ����·��
void FindAllPath(AdjGraph * G, int u, int v, int path[], int d) {
	// d ��ʾ path �е�·�����ȣ���ʼΪ -1
	int w, i;
	ArcNode *p;
	d++;											//·������ d �� 1
	path[d] = u;								//���� u ���뵽·����
	visited[u] = 1;
	if (u == v && d >= 0) {			//���ҵ�һ��·�������
		for (i = 0; i <= d; i++)
			printf("%2d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc;			//p ָ�򶥵� u �ĵ�һ���ڽӵ�
	while (p != NULL) {
		w = p->adjvex;					//w Ϊ���� u ���ڽӵ�
		if (visited[w] == 0)				//�� w ����δ�����ʣ��ݹ������
			FindAllPath(G, w, v, path, d);
		p = p->nextarc;					//p ָ�򶥵� u ����һ���ڽӵ�
	}
	visited[u] = 0;							//�ָ�������ʹ�ö��������ʹ��
}

//�� 8.7 ����ͼ G �����ڽӱ�洢�����һ���㷨�����ͼ G �дӶ���u �� v �ĳ���Ϊ l �����м�·��
void PathlenAll(AdjGraph *G, int u, int v, int l, int path[], int d) {
	// d ��ʾ path �е�·�����ȣ���ʼΪ -1
	int w, i;
	ArcNode *p;
	d++;											//·������ d �� 1
	path[d] = u;								//���� u ���뵽·����
	visited[u] = 1;
	if (u == v && d == l) {			//���ҵ�һ��·�������
		for (i = 0; i <= d; i++)
			printf(" %d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc;			//p ָ�򶥵� u �ĵ�һ���ڽӵ�
	while (p != NULL) {
		w = p->adjvex;					//w Ϊ���� u ���ڽӵ�
		if (visited[w] == 0)				//�� w ����δ�����ʣ��ݹ������
			PathlenAll(G, w, v, l, path, d);
		p = p->nextarc;					//p ָ�򶥵� u ����һ���ڽӵ�
	}
	visited[u] = 0;							//�ָ�������ʹ�ö��������ʹ��
}