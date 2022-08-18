#include <iostream>

using namespace std;

int pre[1000 * 1000] = {0};
bool vis[1000 * 1000] = {0};

int find(int x) {
	int p = x;
	while(x != pre[x]) {
		x = pre[x];
	}
	int tmp;
	while(p != x) {
		tmp = pre[p];
		pre[p] = x;
		p = tmp;
	}
	return x;
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	
	if(a != b) {
		pre[a] = b;
	}
}
int main()
{
	int m;
	int n;
	cin >> m >> n;
	for(int i = 1; i <= m*n; i++)
		pre[i] = i;
		
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {
		int a;
		int b;
		cin >> a >> b;
		join(a, b);
	}
	
	for(int i = 1; i <= m*n; i++)
		vis[find(i)] = true;
	
	int cnt = 0;
	for(int i = 1; i <= m*n; i++) {
		if(vis[i] == true) {
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
