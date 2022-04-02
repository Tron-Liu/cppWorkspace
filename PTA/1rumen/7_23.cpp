#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m[11][11] = {0};
	int i, j, k, q = 0;
	
	int T, n;
	scanf("%d", &T);
	vector<int> v;
	int flag = 0;
	
	for(k = 0; k < T; k++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &m[i][j]);
				
		for(i = 1; i < n; i++) {
			for(j = 0; j < i; j++) {
				if(m[i][j] != 0) {
					v.push_back(0);
					q++;
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) {
			v.push_back(1);
			q++;	
		}
		flag = 0;
	}
	
	for(i = 0; i < q; i++) {
		if(v[i] == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
