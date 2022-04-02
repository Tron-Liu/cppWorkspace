#pragma once
#include "顺序串.h"
int BF(SqString s, SqString t) {
	int i = 0, j = 0;
	while (i < s.length&&j < t.length) {		//两个串都没有扫描完时循环
		if (s.data[i] == t.data[j]) {					//当前比较的两个字符相同
			i++;												//依次比较后续的两个字符
			j++;
		}
		else {							//当前比较的两个字符不相同
			i = i - j + 1;				//扫描目标串的i回退，并向前加1
			j = 0;						//子串从头开始匹配
		}
	}
	if (j >= t.length)				//j超界，表示t是s的子串
		return(i - t.length);		//返回t在s中的位置
	else									//模式匹配失败
		return -1;						//返回-1
}