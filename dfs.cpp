#include <iostream>
using namespace std;

int map[5][5] = {{0, 1, 1, 1, 1},
				 {0, 0, 1, 0, 0},
			     {1, 0, 0, 0, 1},
			     {1, 1, 0, 1, 1},
			     {1, 1, 0, 0, 0}};

int visited[5][5];
void dfs(int i, int j);
				     
int main()
{
//	cout << visited[0][0];
	dfs(0, 0);
	visited[0][0] = 1;
	return 0;
 }
 
void dfs(int i, int j) {
	cout << i << " " << j << endl;
	// �����յ� 
	if (i == 4 && j == 4) {
		cout << "True" << endl;
		return ;	
	}
	 
	// Խ��
	if (i < 0 || i >= 5 || j < 0 || j >= 5) {
		return ;
	}
	
	// ��
	if (j-1 > 0 && !visited[i][j-1] && !map[i][j-1]) {
		visited[i][j-1] = 1; 
		dfs(i, j-1);
		visited[i][j-1] = 0;
	}
	
	// ��
	if (i+1 < 5 && !visited[i+1][j] && !map[i+1][j]) {
		visited[i+1][j] = 1;
		dfs(i+1, j);
		visited[i+1][j] = 0;
	}
	
	// ��
	if (j+1 < 5 && !visited[i][j+1] && !map[i][j+1]) {
		visited[i][j+1] = 1;
		dfs(i, j+1);
		visited[i][j+1] = 0;
	}
	
	// �� 
	if (i-1 > 0 && !visited[i-1][j] && !map[i-1][j]) {
		visited[i-1][j] = 1;
		dfs(i-1, j);
		visited[i-1][j] = 0;
	}
}
