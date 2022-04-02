#pragma once
#include <iostream>

typedef int KeyType;				//定义关键字类型为 int
typedef char InfoType;			//InfoType 类型暂定义为 char
typedef struct {
	KeyType key;						//关键字项
	InfoType data;						//其他数据项，类型为 InfoType
}RecType;									//查找元素的类型

#define MAXI 20			//索引表的最大长度
typedef struct {
	KeyType key;			//KeyType为关键字的类型
	int link;						//指向对应块的起始下标
}IdxType;						//索引表元素的类型

typedef struct node{					//元素类型
	KeyType key;							//关键字项
	InfoType data;							//其他数据域
	struct node *lchild, *rchild;		//左、右孩子指针
}BSTNode;