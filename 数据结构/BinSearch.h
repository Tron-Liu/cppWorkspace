#pragma once
#include "SearchType.h"

int BinSearch(RecType R[], int n, KeyType k)
{ //折半查找算法
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{ //当前区间存在元素时循环
		mid = (low + high) / 2;
		if (k == R[mid].key) //查找成功返回其逻辑序号 mid+1
			return mid + 1;
		if (k < R[mid].key) //继续在 R[low..mid-1] 中查找
			high = mid - 1;
		else			   // k>R[mid].key
			low = mid + 1; //继续在 R[mid+1..high] 中查找
	}
	return 0; //未找到时返回0（查找失败）
}