#pragma once
#include "HashType.h"

/*
	param1:哈希表
	param2:哈希表已存入的元素
	param3:哈希表地址空间大小
	param4:除留余数法中的除数
	patam5:待插入关键字
*/
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {		//将关键字 k 插入到哈希表中
	int i, adr;
	adr = k % p;														//计算哈希函数值
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY) {
		ha[adr].key = k;											//k 可以直接放在哈希表中
		ha[adr].count = 1;
	}
	else {																//发生冲突时采用线性探测法解决冲突
		i = 1;															// i 记录 k 发生冲突的次数
		do {
			adr = (adr + 1) % m;								//线性探测
			i++;
		} while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = k;											//在 adr 处放置 k
		ha[adr].count = i;											//设置探测次数
	}
	n++;																	//哈希表中总元素个数加一
}

//由关键字序列 keys[0..n1-1]创建哈希表
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1) {
	int i;
	for (i = 0; i < m; i++) {						//哈希表置空的初值
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	n = 0;												//哈希表中总元素个数从 0 开始递增
	for (i = 0; i < n1; i++)
		InsertHT(ha, n, m, p, keys[i]);		//插入 n 个关键字
}