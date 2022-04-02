#pragma once
#include <iostream>
#include "RecType.h"

//将两个有序表归并为一个有序表
//称R[low..mid]为第一段，R[mid+1..high]为第二段，
void Merge(RecType R[], int low, int mid, int high) {
	RecType *R1;
	int i = low, j = mid + 1, k = 0;				// k 是R1的下标，i、j分别为第1、2段的下标
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));		//动态分配空间
	while(i<=mid&&j<=high)					//在第一段和第二段均未扫描完时循环
		if (R[i].key <= R[j].key)	 {					//将第一段中的元素放入R1中
			R1[k] = R[i];
			i++; k++;
		}
		else {												//将第二段中的元素放入R1中
			R1[k] = R[j];
			i++; k++;
		}
	while (i <= mid) {									//将第一段余下的部分复制到R1中
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high) {								//将第二段余下的部分复制到R1中
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i < high; k++, i++)		//将R1复制到R[low..high]中
		R[i] = R1[k];
	free(R1);
}

void MergePass(RecType R[], int length, int n) {				//对整个排序序列进行一趟归并
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)		//归并 length 长的两相邻子表
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n - 1)												//余下两个子表，后者的长度小于 length
		Merge(R, i, i + length - 1, n - 1);								//归并这两个子表
}

void MergeSort(RecType R[], int n) {								//二路归并排序
	int length;
	for (length = 1; length < n; length = 2 * length)			//进行 floor(n/2) 趟排序，floor : 上取整函数
		MergePass(R, length, n);
}

void MergeSortDC(RecType R[], int low, int high) {		//对R[low..high]进行二路归并排序
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSortDC(R, low, mid);
		MergeSortDC(R, mid + 1, high);
		Merge(R, low, mid, high);
	}
}

void MergeSort1(RecType R[], int n) {			//自顶向下的二路归并算法
	MergeSortDC(R, 0, n - 1);
}