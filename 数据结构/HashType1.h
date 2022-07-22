#include <iostream>

typedef int KeyType; //关键字类型
typedef struct node
{
	KeyType key;	   //关键字域
	struct node *next; //下一个结点指针
} NodeType;			   //单链表结点类型

typedef struct
{
	NodeType *firstp; //首结点指针
} HashTable;		  //哈希表单元类型