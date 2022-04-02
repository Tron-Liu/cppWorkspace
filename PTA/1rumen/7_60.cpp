#include <stdio.h>

int main()
{
	char letter[10][5] = {
		{'0', ' '},
		{'1', ',', '.', '?', '!'},
		{'2', 'A', 'B', 'C'},
		{'3', 'D', 'E', 'F'},
		{'4', 'G', 'H', 'I'},
		{'5', 'J', 'K', 'L'},
		{'6', 'M', 'N', 'O'},
		{'7', 'P', 'Q', 'R', 'S'},
		{'8', 'T', 'U', 'V'},
		{'9', 'W', 'X', 'Y', 'Z'},
	};
	
	int num[10] = {2, 5, 4, 4, 4, 4, 4, 5, 4, 5};
	int count = 0;
	int i;
	
	char c, s = '#';
	c = getchar();
	while(c != '\n'){
		if(c == ' ') {
			if(s == '#') {
				c = getchar();
				continue;
			}
			else {
				i = (int)(s - '0');	
			}
			count = (count-1) % num[i];
			printf("%c", letter[i][count]);
			count = 0;
		}
		else if(c != '\n'){
			count++;
			s = c;
		}
		c = getchar();
	}
	
	i = (int)(s - '0');
	count = (count-1) % num[i];
	printf("%c\n", letter[i][count]);
	
	return 0;
}
