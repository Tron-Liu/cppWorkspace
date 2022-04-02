#pragma once
#include "顺序串.h"
//求模式串的next数组
void GetNext(SqString t, int next[]) {			//由模式串t求出next数组
	int j, k;
	j = 0, k = -1;							//j扫描t，k记录t[j]之前与t开头相同的字符个数
	next[0] = -1;							//设置next[0]的值
	while (j < t.length - 1) {		//求t所有位置的next值
		if (k == -1 || t.data[j] == t.data[k]) {		//k为-1或比较的字符相等时
			j++; k++;						//j，k依次移到下一个字符
			next[j] = k;					//设置next[j]为k
		}
		else k = next[k];				//k回退
	}
}

int KMPIndex(SqString s, SqString t) {
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length &&j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else j = next[j];				//i不变，j后退
	}
	if (j >= t.length)				//匹配成功
		return (i - t.length);		//返回子串位置
	else									//匹配不成功
		return -1;						//返回-1
}

//改进后的求模式串的next数组
void GetNextval(SqString t, int nextval[]) {
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length) {
		if (k == -1 || t.data[j] == t.data[k]) {
			j++; k++;
			if (t.data[j] != t.data[k])
				nextval[j] = k;
			else
				nextval[j] = nextval[k];
		}
		else
			k = nextval[k];
	}
}

int KMPIndex1(SqString s, SqString t) {
	int nextval[MaxSize], i = 0, j = 0;
	GetNextval(t, nextval);
	while (i < s.length && j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= t.length)
		return(i - t.length);
	else
		return -1;
}