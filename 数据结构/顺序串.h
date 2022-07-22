#pragma once

/*
	ADT String
	{
		数据对象：
				D = { a[i] | 1<= i <= n, n>=0, a[i]为char类型 }
		数据关系：
				R = { <a[i], a[i+1]> | a[i], a[i+1]属于D, i = 1, ... , n-1}
		基本运算：
				StrAssign(&s, cstr):将字符串常量cstr赋给串s，即生成其值等于cstr的串s。
				DestroyStr(&s):销毁串，释放为串s分配的存储空间。
				StrCopy(&s, t):串复制，将串t赋给串s。
				StrEqual(s, t):判断串是否相等，若两个串s与t相等则返回真；否则返回假。
				StrLength(s):求串长，返回串s中字符的个数。
				Concat(s, t):串连接，返回由两个串s和t连接在一起形成的新串。
				SubStr(s, i, j):求子串，返回串s中从第i(1 <= i <= n)个字符开始的由连续j个字符组成的子串。
				InsStr(s1, i, s2):子串插入，将串s2插入到串s1的第i(1 <= i <= n+1)个位置，
										并返回产生的新串。
				DelStr(s, i, j):子串删除，从串s中删去从第i(1 <= i <= n)个字符开始的长度为j的子串
									并返回产生的新串。
				RepStr(s, i, j, t):子串替换，在串s中将第i(1 <= i <= n)个字符开始的j个字符构成的子串
										用串t代替，并返回产生的新串。
				DispStr(s):串输出，输出串s的所有字符值。
*/
#include <stdio.h>

#define MaxSize 20
typedef struct
{
	char data[MaxSize]; //存放串字符
	int length;			//存放串长
} SqString;				//顺序串类型

//生成串
void StrAssign(SqString &s, char cstr[])
{ // s为引用型参数
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i; //设置串s的长度
}

//销毁串
void DestroyStr(SqString &s)
{
	/*这里的顺序串是直接采用顺序串本身来表示，
		它的存储空间由操作系统分配，
		所以这里的销毁顺序串运算不包含任何操作。
	*/
}

//串的复制
void StrCopy(SqString &s, SqString t)
{ // s为引用型参数
	int i;
	for (i = 0; i < t.length; i++) //复制t的所有字符
		s.data[i] = t.data[i];
	s.length = t.length; //设置串s的长度
}

//判断串相等
bool StrEqual(SqString s, SqString t)
{
	bool same = true;
	int i;
	if (s.length != t.length) //长度不相等时返回0
		same = false;
	else
		for (i = 0; i < s.length; i++)
			if (s.data[i] != t.data[i])
			{ //有一个对应字符不相同时返回假
				same = false;
				break;
			}
	return same;
}

//求串长
int StrLength(SqString s)
{
	return s.length;
}

//串的连接
SqString Concat(SqString s, SqString t)
{
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++) //将s.data[0 ... s.length-1]复制到str
		str.data[i] = s.data[i];
	for (i = 0; i < t.length; i++) //将t.data[0 ... s.length-1]复制到str
		str.data[s.length + i] = t.data[i];
	return str;
}

//求子串
SqString SubStr(SqString s, int i, int j)
{
	int k;
	SqString str;	//定义结果串
	str.length = 0; //设置str为空串
	if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length)
		return str;						//参数不正确时返回空串
	for (k = i - 1; k < i + j - 1; k++) //将s.data[i ... i+j-1]复制到str
		str.data[k - i + 1] = s.data[k];
	s.length = j;
	return str;
}

//子串的插入
SqString InsStr(SqString s1, int i, SqString s2)
{
	int j;
	SqString str;					 //定义结果串
	str.length = 0;					 //设置str为空串
	if (i <= 0 || i > s1.length + 1) //(1<= i <= n+1)
		return str;					 //参数错误返回空串
	for (j = 0; j < i - 1; j++)		 //将s1.data[0 ... i-2]复制到str
		str.data[j] = s1.data[j];
	for (j = 0; j < s2.length; j++) //将s2.data[0 ... s2.length-1]复制到str
		str.data[i + j - 1] = s2.data[j];
	for (j = i - 1; j < s1.length; j++) //将s1.data[i-1 ... s.length-1]复制到str
		str.data[s2.length + j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

//子串的删除
SqString DelStr(SqString s, int i, int j)
{
	int k;
	SqString str;	//定义结果串
	str.length = 0; //设置str为空串
	if (i <= 0 || i > s.length || i + j > s.length + 1)
		return str;				//参数不正确是返回空串
	for (k = 0; k < i - 1; k++) //将s.data[0 ... i-2]复制到str
		str.data[k] = s.data[k];
	for (k = i + j - 1; k < s.length; k++) //将s.data[i+j-1 ... s.length-1]复制到str
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}

//子串的替换
SqString RepStr(SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;	//定义结果串
	str.length = 0; //设置str为空串
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
		return str;				//参数不正确时返回空串
	for (k = 0; k < i - 1; k++) //将s.data[0 ... i-2]复制到str
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++) //将t.data[0 ... t.length-1]复制到str
		str.data[i + k - 1] = t.data[k];
	for (k = i + j - 1; k < s.length; k++) //将s.data[i+j-1 ... s.length-1]复制到str
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}

//输出串
void DisStr(SqString s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}

//例题
int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.length < t.length) //求s和t的共同长度
		comlen = s.length;
	else
		comlen = t.length;
	for (i = 0; i < comlen - 1; i++)
	{ //在共同长度内逐个字符比较
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length) // s == t
		return 0;
	else if (s.length > t.length) // s > t
		return 1;
	else // s < t
		return -1;
}

//例题
void LongestString(SqString s, int &index, int &maxlen)
{
	int length, i = 1, start; // length保存局部平台的长度
	index = 0, maxlen = 1;	  // index保存最长平台在s中的开始位置，maxlen保存其长度
	while (i < s.length)
	{
		start = i - 1; //查找局部重复子串
		length = 1;
		while (i < s.length && s.data[i] == s.data[i - 1])
		{
			i++;
			length++;
		}
		if (maxlen < length)
		{ //当前平台长度大，则更新maxlen
			maxlen = length;
			index = start;
		}
		i++;
	}
}