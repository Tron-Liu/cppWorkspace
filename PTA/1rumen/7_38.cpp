#include <stdio.h>

int main()
{
	int num, N, player;
	scanf("%d %d", &num, &N);
	
	int flag = 0;
	while(N) {
		scanf("%d", &player);
		if(player < 0) {
			printf("Game Over\n");
			return 0;	
		}
		if(player > num) {
			printf("Too big\n");
			flag++;
		}
		else if(player < num) {
			printf("Too small\n");
			flag++;
		}
		else {
			flag++;
			if(flag <= 1) printf("Bingo!\n");
			else if(flag <= 3) printf("Lucky You!\n");
			else printf("Good Guess!\n");
			return 0;
		}
		N--;	
	}
	printf("Game Over\n");
	return 0;
}
