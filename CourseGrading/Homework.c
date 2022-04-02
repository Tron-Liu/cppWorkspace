#include <stdio.h>
#include <string.h>
#define MaxSize 100002

// c 数量最少的字符
char getMin(int *min, int *numOfLetter)      //获取数组中非零最小值，以及对应的字母
{
	int i, j = 0;
	for (i = 0; i < 26; i++) {
		if (numOfLetter[i] != 0 && numOfLetter[i] < *min) {
			*min = numOfLetter[i];
			j = i;
		}
	}
	numOfLetter[j] = 0;
	return j + 'a';
}

int deleteLetter(char *s, char c, int n)       //从字符串 s 中将所有的 c 删去 
{
	int i;
	int num = 0;                    //已删除的字符数
	for (i = 0; i < n; i++)
	{
		if (s[i] == c) num++;
		else s[i - num] = s[i];
	}
	return n - num;                     //删除字符后，字符串的长度
}

int main()
{
	char s[MaxSize];
	int k;
	scanf("%s", s);
	scanf("%d", &k);

	int numOfLetter[26] = { 0 };

	//k 不小于 s 的长度
	if (strlen(s) <= k)
	{
		printf("0\n");
		return 0;
	}

	//k 小于 s 的长度
	int i;

	char minNumLetter;                  //数量最少的字母

	int deleteNum = 0;                  //已删除字母的个数

	for (i = 0; i < strlen(s); i++)      //统计每个种类的字母的个数
		numOfLetter[s[i] - 'a']++;

	int length = strlen(s);

	while (k > deleteNum)
	{

		//获取数量最少的字符 minNumletter
		//获取数量 minNum
		int min = MaxSize;
		int *minNum;                     //最少的数量
		minNum = &min;

		minNumLetter = getMin(minNum, numOfLetter);
		deleteNum += *minNum;

		//将该类型的字母从字符串中删除
		if (k >= deleteNum)
			length = deleteLetter(s, minNumLetter, length);
	}

	for (i = 0; i < length; i++) {
		numOfLetter[s[i] - 'a']++;
	}

	int m = 0;
	for (i = 0; i < 26; i++) {
		if (numOfLetter[i] > 0) m++;
	}
	printf("%d\n", m);

	for (i = 0; i < length; i++) {
		printf("%c", s[i]);
	}

	return 0;
}