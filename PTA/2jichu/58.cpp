#include <iostream>
#include <stack>
using namespace std;

int visited[12];
int b[12];
int n;

void DFS(int step)
{
	int i;
	if(step == n+1) {
		for(i = 1; i <= n; i++) {
			cout << b[i];
		}
		printf("\n");
		return;
	}
	
	for(i = 1; i <= n; i++) {
		if(visited[i] == 0) {
			b[step] = i;
			visited[i] = 1;
			
			DFS(step+1);
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	cin >> n;
	
	DFS(1);
	return 0;
}
