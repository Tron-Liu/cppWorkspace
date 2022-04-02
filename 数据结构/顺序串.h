#pragma once

/*
	ADT String
	{
		���ݶ���
				D = { a[i] | 1<= i <= n, n>=0, a[i]Ϊchar���� }
		���ݹ�ϵ��
				R = { <a[i], a[i+1]> | a[i], a[i+1]����D, i = 1, ... , n-1}
		�������㣺
				StrAssign(&s, cstr):���ַ�������cstr������s����������ֵ����cstr�Ĵ�s��
				DestroyStr(&s):���ٴ����ͷ�Ϊ��s����Ĵ洢�ռ䡣
				StrCopy(&s, t):�����ƣ�����t������s��
				StrEqual(s, t):�жϴ��Ƿ���ȣ���������s��t����򷵻��棻���򷵻ؼ١�
				StrLength(s):�󴮳������ش�s���ַ��ĸ�����
				Concat(s, t):�����ӣ�������������s��t������һ���γɵ��´���
				SubStr(s, i, j):���Ӵ������ش�s�дӵ�i(1 <= i <= n)���ַ���ʼ��������j���ַ���ɵ��Ӵ���
				InsStr(s1, i, s2):�Ӵ����룬����s2���뵽��s1�ĵ�i(1 <= i <= n+1)��λ�ã�
										�����ز������´���
				DelStr(s, i, j):�Ӵ�ɾ�����Ӵ�s��ɾȥ�ӵ�i(1 <= i <= n)���ַ���ʼ�ĳ���Ϊj���Ӵ�
									�����ز������´���
				RepStr(s, i, j, t):�Ӵ��滻���ڴ�s�н���i(1 <= i <= n)���ַ���ʼ��j���ַ����ɵ��Ӵ�
										�ô�t���棬�����ز������´���
				DispStr(s):������������s�������ַ�ֵ��
*/
#include <stdio.h>

#define MaxSize 20
typedef struct {
	char data[MaxSize];		//��Ŵ��ַ�
	int length;					//��Ŵ���
}SqString;							//˳������

//���ɴ�
void StrAssign(SqString &s, char cstr[]) {		//sΪ�����Ͳ���
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;													//���ô�s�ĳ���
}

//���ٴ�
void DestroyStr(SqString &s) {
/*�����˳����ֱ�Ӳ���˳�򴮱�������ʾ��
	���Ĵ洢�ռ��ɲ���ϵͳ���䣬
	�������������˳�����㲻�����κβ�����
*/
}

//���ĸ���
void StrCopy(SqString &s, SqString t) {		//sΪ�����Ͳ���
	int i;
	for (i = 0; i < t.length; i++)						//����t�������ַ�
		s.data[i] = t.data[i];
	s.length = t.length;									//���ô�s�ĳ���
}

//�жϴ����
bool StrEqual(SqString s, SqString t) {
	bool same = true;
	int i;
	if (s.length != t.length)					//���Ȳ����ʱ����0
		same = false;
	else
		for(i = 0; i < s.length; i++)
			if (s.data[i] != t.data[i]) {		//��һ����Ӧ�ַ�����ͬʱ���ؼ�
				same = false;
				break;
			}
	return same;
}

//�󴮳�
int StrLength(SqString s) {
	return s.length;
}

//��������
SqString Concat(SqString s, SqString t) {
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)					//��s.data[0 ... s.length-1]���Ƶ�str
		str.data[i] = s.data[i];
	for (i = 0; i < t.length; i++)					//��t.data[0 ... s.length-1]���Ƶ�str
		str.data[s.length + i] = t.data[i];
	return str;
}


//���Ӵ�
SqString SubStr(SqString s, int i, int j) {
	int k;
	SqString str;										//��������
	str.length = 0;									//����strΪ�մ�
	if (i <= 0 || i > s.length || j<0 || i + j - 1>s.length)
		return str;										//��������ȷʱ���ؿմ�
	for (k = i - 1; k < i + j - 1; k++)		//��s.data[i ... i+j-1]���Ƶ�str
		str.data[k - i + 1] = s.data[k];
	s.length = j;
	return str;
}

//�Ӵ��Ĳ���
SqString InsStr(SqString s1, int i, SqString s2) {
	int j;
	SqString str;												//��������
	str.length = 0;											//����strΪ�մ�
	if (i <= 0 || i > s1.length + 1)					//(1<= i <= n+1)
		return str;												//�������󷵻ؿմ�
	for (j = 0; j < i - 1; j++)							//��s1.data[0 ... i-2]���Ƶ�str
		str.data[j] = s1.data[j];
	for (j = 0; j < s2.length; j++)					//��s2.data[0 ... s2.length-1]���Ƶ�str
		str.data[i + j - 1] = s2.data[j];
	for (j = i - 1; j < s1.length; j++)				//��s1.data[i-1 ... s.length-1]���Ƶ�str
		str.data[s2.length + j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

//�Ӵ���ɾ��
SqString DelStr(SqString s, int i, int j) {
	int k;
	SqString str;											//��������
	str.length = 0;										//����strΪ�մ�
	if (i <= 0 || i > s.length || i + j > s.length + 1)
		return str;											//��������ȷ�Ƿ��ؿմ�
	for (k = 0; k < i - 1; k++)						//��s.data[0 ... i-2]���Ƶ�str
		str.data[k] = s.data[k];
	for (k = i + j - 1; k < s.length; k++ )	//��s.data[i+j-1 ... s.length-1]���Ƶ�str
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}

//�Ӵ����滻
SqString RepStr(SqString s, int i, int j, SqString t) {
	int k;
	SqString str;											//��������
	str.length = 0;										//����strΪ�մ�
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
		return str;											//��������ȷʱ���ؿմ�
	for (k = 0; k < i - 1; k++)						//��s.data[0 ... i-2]���Ƶ�str
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++)				//��t.data[0 ... t.length-1]���Ƶ�str
		str.data[i + k - 1] = t.data[k];
	for (k = i + j - 1; k < s.length; k++)		//��s.data[i+j-1 ... s.length-1]���Ƶ�str
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}

//�����
void DisStr(SqString s) {
	int i;
	if (s.length > 0) {
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}

//����
int Strcmp(SqString s, SqString t) {
	int i, comlen;
	if (s.length < t.length)					//��s��t�Ĺ�ͬ����
		comlen = s.length;
	else
		comlen = t.length;
	for (i = 0; i < comlen - 1; i++) {	//�ڹ�ͬ����������ַ��Ƚ�
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length)				//s == t
		return 0;
	else if (s.length > t.length)			//s > t
		return 1;
	else												//s < t
		return -1;
}

//����
void LongestString(SqString s, int &index, int &maxlen) {
	int length, i = 1, start;			//length����ֲ�ƽ̨�ĳ���
	index = 0, maxlen = 1;			//index�����ƽ̨��s�еĿ�ʼλ�ã�maxlen�����䳤��
	while (i < s.length) {
		start = i - 1;						//���Ҿֲ��ظ��Ӵ�
		length = 1;
		while (i < s.length && s.data[i] == s.data[i - 1]) {
			i++;
			length++;
		}
		if (maxlen < length) {		//��ǰƽ̨���ȴ������maxlen
			maxlen = length;
			index = start;
		}
		i++;
	}
}