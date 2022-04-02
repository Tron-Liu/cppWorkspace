#include <iostream>

int map[5][5] = {{0, 1, 1, 1, 1},
				 {0, 0, 1, 1, 1},
			     {1, 0, 0, 1, 1},
			     {1, 1, 0, 1, 1},
			     {1, 1, 0, 0, 0}};

int visited[5][5]; 
				     
int main()
{
	dfs(0, 0);
	std::cout << visited[0][0];
	return 0;
 }
 
void dfs(int i, int j) {
	// �����յ� 
	if (i == 4 && j == 4) {
		cout << "True";
		return ;	
	}
	 
	// Խ��
	if (i < 0 || i >= 5 || j < 0 || j >= 5) {
		return ;
	} 
	
	// �ѷ���
	 
	// ��
	visited[i][j-1] = 1; 
	dfs(i, j-1);
	visited[i][j-1] = 0;
	// ��
	dfs(i+1, j);
	// ��
	dfs(i, j+1);
	// �� 
	dfs(i-1, j);
}
