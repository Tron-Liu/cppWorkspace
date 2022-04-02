#pragma once
#include "HashType.h"

/*
	在采用开放地址法处理冲突的哈希表上执行删除操作时不能简单地将被删除元素地空间置为空，
	否则将截断在它之后填入哈希表的同义词元素的查找路径，这是因为在各种开放地址法中，空地址单元
	都是查找失败条件。因此只能在被删除元素上做删除标记，而不能真正地删除元素。
*/
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k) {		//删除哈希表中的关键字 k；
	int adr;
	adr = k % p;																		//计算哈希值
	while (ha[adr].key != NULLKEY && ha[adr].key != k)
		adr = (adr + 1) % m;													//线性探测
	if (ha[adr].key == k) {														//查找成功
		ha[adr].key = DELKEY;													//删除关键字
		return true;
	}
	else																					//查找失败
		return false;																	//返回假
}