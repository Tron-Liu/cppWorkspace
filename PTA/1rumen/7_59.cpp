#include <stdio.h>

int judge(char map[][22], int x, int y);

int main()
{
	char map[22][22] = {0};
	
	int M, N;
	scanf("%d %d", &M, &N);
	
	getchar();
	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	
	int k;
	scanf("%d", &k);
	
	int count;
	int x, y;
	while(k--) {
		count = 0;
		scanf("%d %d", &x, &y);
		if(map[x][y] == '#') count++;
		
		if(x-1 >= 0) {
			if(judge(map, x-1, y)) count++;
		}
		if(x+1 < M) {
			if(judge(map, x+1, y)) count++;
		}
		if(y-1 >= 0) {
			if(judge(map, x, y-1)) count++;
		}
		if(y+1 < N) {
			if(judge(map, x, y+1)) count++;
		}
		printf("%d", count); 
	}
	return 0;
}

int judge(char map[][22], int x, int y) {
	if(map[x][y] == '#')  {
		map[x][y] = '!';
		return 0;
	}
	else if(map[x][y] == '!') {
		map[x][y] = '0';
		return 1;
	}
}
