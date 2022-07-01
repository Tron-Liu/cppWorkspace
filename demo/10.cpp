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
	for (int i = start; i < length; i++) {			//ȥ������ 
		if (s[i] == ',')
			continue;
		else
			arr[j++] = (int)(s[i] - '0');
	}
	return j;
}

int main()
{
	string a;				//���ַ���ʽ�����һλ���� 
	cin >> a;
	int aflag = 1;			//����Ƿ�����Ĭ������ 
	int astart = 0;				//�����ʼλ�ã���ȥ���������� 
	my_init(a, aflag, astart);
	int ia[202] = { 0 };		//������������ʽ�洢��һλ�����е�����
	int aend = init_array(a, ia, a.length(), astart);

	string b;					//����ͬ
	cin >> b;
	int bflag = 1;
	int bstart = 0;
	my_init(b, bflag, bstart);
	int ib[202] = { 0 };
	int bend = init_array(b, ib, b.length(), bstart);

	int c[402] = { 0 };							//�洢��˽�� 
	int m = 0;									//�˲���
	for (int x = aend - 1; x >= 0; x--) {
		int n = m;
		for (int y = bend - 1; y >= 0; y--) {
			c[n] = c[n] + ia[x] * ib[y];
			n++;
		}
		m++;
	}

	int i;
	for (i = 0; i < 402; i++) {				//������ c �ĸ�λ���н�λ����
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	for (i = 401; i >= 0; i--)					//�ҵ���������ĵ�һλ
		if (c[i] != 0) break;

	if ((i + 1) == 0) {								//���
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
