#include <iostream>
using namespace std;

int pre[30002];
int stu[30002];
int num[30002];

int find(int x)
{
	int p = x;
	while(x != pre[x]) {		//寻找根结点 
		x = pre[x];
	}
	int tmp;
	while(p != x) {				//路径压缩 
		tmp = pre[p];
		pre[p] = x;
		p = tmp;
	} 
	return x;
}

void join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	
	if(a != b) pre[a] = b;	
}
 
int main()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)		//初始化为自己 
		pre[i] = i;
	
	int k;

	for(int i = 0; i < m; i++) {
		cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> stu[j];
		}
		for(int p=0, q=1; q < k; p++,q++) {
			join(stu[p], stu[q]);
		}
	}
	
	for(int i = 1; i <= n; i++)
		find(i);
	
	for(int i = 1; i <= n; i++) {
		num[pre[i]]++;
	}
	
	int max = 0;
	for(int i = 1; i <= n; i++) {
		if(max < num[i]) max = num[i];
	}
	cout << max;
	return 0;
}
