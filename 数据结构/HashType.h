#pragma once
#include <iostream>

/*哈希表的结点类型*/
#define NULLKEY -1			//定义空关键字值，即闲置单元的关键字设置为特殊值 -1
#define DELKEY -2				//定义被删关键字值

typedef int KeyType;			//关键字类型
typedef struct {
	KeyType key;					//关键字域
	int count;							//探测次数域
}HashTable;							//哈希表单元类型