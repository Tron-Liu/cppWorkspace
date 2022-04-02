#include "HashType.h"

//在哈希表中查找关键字 k
void SearchHT(HashTable ha[], int m, int p, KeyType k) {
	int i = 1, adr;
	adr = k % p;															//计算哈希函数值
	while (ha[adr].key != NULLKEY && ha[adr].key != k) {
		i++;																	//累计关键字的比较次数
		adr = (adr + 1) % m;										//线性探测
	}
	if (ha[adr].key == k)												//查找成功
		printf("成功：关键字%d,比较%d次\n", k, i);
	else																		//查找失败
		printf("失败：关键字%d,比较%d次\n", k, i);
}