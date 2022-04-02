#pragma once
#include <iostream>

//ͼ���ڽӾ���洢����
#define  MAXV 25				//��󶥵����
#define INF 32767				//����Ϊ ����

typedef int InfoType;

typedef struct {
	int no;				//����ı��
	InfoType info;			//�����������Ϣ
}VertexType;				//���������

typedef struct {
	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n, e;				//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
}MatGraph;				//������ͼ�ڽӾ�������

//ͼ���ڽӱ�洢����
typedef struct ANode {
	int adjvex;			//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;			//�ñߵ������Ϣ����Ȩֵ�����������ͱ�ʾ��
}ArcNode;				//�߽�������

typedef struct Vnode {
	InfoType info;			//�����������Ϣ
	ArcNode *firstarc;			//ָ���һ���߽��
}VNode;					//�ڽӱ��ͷ�������

typedef struct {
	VNode adjlist[MAXV];		//�ڽӱ��ͷ�������
	int n, e;				//ͼ�еĶ����� n �ͱ��� e
}AdjGraph;				//������ͼ�ڽӱ�����