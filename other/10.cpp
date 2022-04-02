#include <iostream>
#include <string>
using namespace std;

void my_init(const string &s, int &flag, int &start)
{
	if (s[0] == '-') {
		flag = -1;
		start = 1;
	}
}

int init_array(const string &s, int *arr, int length, int start)
{
	int j = 0;
	for (int i = start; i < length; i++) {			//去除逗号 
		if (s[i] == ',')
			continue;
		else
			arr[j++] = (int)(s[i] - '0');
	}
	return j;
}

int main()
{
	string a;				//以字符形式输入第一位整数 
	cin >> a;
	int aflag = 1;			//标记是否负数，默认正数 
	int astart = 0;				//标记起始位置，起去除负号作用 
	my_init(a, aflag, astart);
	int ia[202] = { 0 };		//以整数数组形式存储第一位整数中的数字
	int aend = init_array(a, ia, a.length(), astart);

	string b;					//与上同
	cin >> b;
	int bflag = 1;
	int bstart = 0;
	my_init(b, bflag, bstart);
	int ib[202] = { 0 };
	int bend = init_array(b, ib, b.length(), bstart);

	int c[402] = { 0 };							//存储相乘结果 
	int m = 0;									//乘操作
	for (int x = aend - 1; x >= 0; x--) {
		int n = m;
		for (int y = bend - 1; y >= 0; y--) {
			c[n] = c[n] + ia[x] * ib[y];
			n++;
		}
		m++;
	}

	int i;
	for (i = 0; i < 402; i++) {				//将数组 c 的各位进行进位操作
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	for (i = 401; i >= 0; i--)					//找到结果整数的第一位
		if (c[i] != 0) break;

	if ((i + 1) == 0) {								//输出
		cout << 0;
		return 0;
	}
	else {
		if (aflag * bflag < 0) cout << '-';
		int g = (i + 1) % 3;
		if (g == 0) g = 3;
		while (g--)
			cout << c[i--];
		for (int j = i; j >= 0; j--) {
			if ((j + 1) % 3 == 0) cout << ',';
			cout << c[j];
		}
	}

	return 0;
}
