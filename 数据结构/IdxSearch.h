#pragma once
#include "SearchType.h"

/*
	param1：索引表
	param2：线性表被分成的块数
	param3：待查找元素所在的线性表
	param4：线性表中的元素个数
	param5：待查找的元素
*/
int IdxSearch(IdxType I[], int b, RecType R[], int n, KeyType k) {		//分块查找
	int s = (n + b - 1) / b;							//s 为每块的元素个数，应为 n/b 的上取整
	int low = 0, high = b - 1, mid, i;
	while (low <= high) {							//在索引表中进行折半查找，找到的位置为 high+1
		mid = (low + high) / 2;
		if (I[mid].key >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	//应先在索引表的 high+1 块中查找，再在主数据表中进行顺序查找
	i = I[high + 1].link;
	while (i <= I[high + 1].link + s - 1 && R[i].key != k)
		i++;
	if (i <= I[high + 1].link + s - 1)				//查找成功返回该元素的逻辑序号
		return i + 1;
	else
		return 0;											//查找失败返回 0
}