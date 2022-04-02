#pragma once
#include <iostream>
typedef char ElemType;

#define MaxSize 100
typedef struct {
	ElemType data;				//存放结点的值
	int parent;						//存放双亲的位置
}PTree[MaxSize];					//PTree为双亲存储结构类型

#define MaxSons 10
typedef struct node{
	ElemType data;							//结点的值
	struct node *sons[MaxSons];		//指向孩子结点
}TSonNode;										//孩子链存储结构中的结点类型

typedef struct tnode {
	ElemType data;				//结点的值
	struct tnode *hp;				//指向兄弟
	struct tnode *vp;				//指向孩子结点
}TSBNode;							//孩子兄弟链存储结构中的结点类型