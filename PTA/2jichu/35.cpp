#include <iostream>
using namespace std;

int main()
{
	int a[12][12] = { 0 };

	int n;
	cin >> n;

	int x = 0, y = 0;
	int t = 1;
	while (t < n * n) {
		while (y+1 < n && !a[x][y+1]) a[x][y++] = t++;	//向右 
		while (x+1 < n && !a[x+1][y]) a[x++][y] = t++;	//向下
		while (y-1 >= 0 && !a[x][y-1]) a[x][y--] = t++;		//向左 
		while (x-1 >= 0 && !a[x-1][y]) a[x--][y] = t++;		//向上 
	}
	a[x][y] = n * n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}
