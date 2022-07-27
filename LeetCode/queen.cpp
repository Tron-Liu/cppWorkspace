#include <iostream>
#include <vector>

using namespace std;

#define N 4

void solve(char chess[][N], int row);
bool valid(char chess[][N], int row, int col);
void print(char chess[][N]);
int get_length(char chess[][N]);

int main() {
	char chess[4][4];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			chess[i][j] = '.';
		}
	}
	
	solve(chess, 0);
	return 0;
}

void solve(char chess[][N], int row) {
	int col = get_length(chess);
	// cout << "info : the col of the chess is " << col << endl;
	cout << "row " << row << endl;
	if (row == col) {
		print(chess);
		return;
	}
	
	for (int j = 0; j < col; j++) {
		if (valid(chess, row, j)) {
			chess[row][j] = 'Q'; 
			solve(chess, row + 1);
			chess[row][j] = '.';
		}
	}
}

bool valid(char chess[][N], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (chess[i][col] == 'Q')
			return false; 
	}
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (chess[i][j] == 'Q')
			return false;
	}
	for (int i = row - 1, j = col + 1; i >= 0 && j < get_length(chess); i--, j++) {
		if (chess[i][j] == 'Q')
			return false;
	}
	
	return true;
}

void print(char chess[][N]) {
	int length = get_length(chess);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
}

int get_length(char chess[][N]) {
	return sizeof(chess[0]) / sizeof(chess[0][0]);
}
