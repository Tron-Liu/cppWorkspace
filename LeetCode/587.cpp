#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector< vector<int> >& grid);

int main() {
	vector< vector<int> > grid;
	vector<int> temp, temp1, temp2;
	temp.push_back(1); temp.push_back(1); temp.push_back(0); temp.push_back(0);
	grid.push_back(temp);
//	temp1.push_back(1); temp1.push_back(0); temp1.push_back(1);
//	grid.push_back(temp1);
//	temp2.push_back(1); temp2.push_back(1); temp2.push_back(1);
//	grid.push_back(temp2);
	
	cout << solution(grid);
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;	
}

int solution(vector< vector<int> >& grid) {
	int edge[102][102][2] = {0};
	int length = grid.size();		// 正方形的边长

	int i, j;
	for (i = 1; i <= length; i++) {
		for (j = 1; j <= length; j++) {
			if ( grid[i-1][j-1] == 0 ) continue;
			
			edge[i][j][0] = edge[i][j-1][0] + 1;
			edge[i][j][1] = edge[i-1][j][1] + 1;
		}
	}
	
	int max = 0;
	int min_len = 0;
	for (i = 1; i <= length; i++) {
		for (j = 1; j <= length; j++) {
			min_len = min(edge[i][j][0], edge[i][j][1]);
			if (min_len <= max) continue;
			
			int k = min_len;
			for (; k > max; k--) {
				if ( edge[i-k+1][j][0] >= min_len && edge[i][j-k+1][1] >= min_len ) {
					max = k;
					break;
				}
			}
		}
	}
	return max * max;
}
