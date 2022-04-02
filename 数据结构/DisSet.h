#pragma once
typedef struct node {
	int data;			//结点对应人的编号
	int rank;			//结点对应秩
	int parent;		//结点对应双亲下标
}UFSTree;				//并查集树的结点类型

void MAKE_SET(UFSTree t[], int n) {		//初始化并查集树
	int i;
	for (i = 1; i <= n; i++) {
		t[i].data = i;				//数据为该人的编号		
		t[i].rank = 0;				//秩初始化为 0
		t[i].parent = i;			//双亲初始化为自己	
	}
}

int FIND_SET(UFSTree t[], int x) {				//在 x 所在的子树中查找集合编号
	if (x != t[x].parent)								//双亲不是自己
		return (FIND_SET(t, t[x].parent));		//递归在双亲中找 x
	else
		return x;											//双亲是自己，返回 x
}

void UNION(UFSTree t[], int x, int y) {		//将 x 和 y 所在的子树合并
	x = FIND_SET(t, x);								//查找 x 所在分离集合树的编号
	y = FIND_SET(t, y);								//查找 y 所在分离集合树的编号
	if (t[x].rank > t[y].rank)							//y 结点的秩小于 x 结点的秩
		t[y].parent = x;									//将 y 连到 x 结点上，x作为 y 的双亲结点
	else {													//y 结点的秩大于等于 x 结点的秩
		t[x].parent = y;									//将 x 连到 y 结点上，y 作为 x 的双亲结点
		if (t[x].rank == t[y].rank)					//x 和 y 结点的秩相同
			t[y].rank++;									//y 结点的秩增 1
	}
}