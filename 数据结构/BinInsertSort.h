#include "RecType.h"

void BinInsertSort(RecType R[], int n)
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)
		{				//反序时
			tmp = R[i]; //将 R[i] 保存到 tmp 中
			low = 0;
			high = i - 1;
			while (low <= high)
			{							//在 R[low..high] 中查找插入的位置
				mid = (low + high) / 2; //取中间位置
				if (tmp.key < R[mid].key)
					high = mid - 1; //插入点在左半区
				else
					low = mid + 1;				//插入点在右半区
			}									//找位置 high
			for (j = i - 1; j >= high + 1; j--) //集中进行元素后移
				R[j + 1] = R[j];
			R[high + 1] = tmp; //插入 tmp
		}
	}
}