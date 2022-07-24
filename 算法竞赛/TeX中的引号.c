#include <stdio.h>

int main() {
	int c, q = 1;
	while ((c=getchar()) != EOF) {
		if (c == '"') {
			printf_s("%s", q ? "``":"''");
			q = !q;
		}
		else {
			printf_s("%c", c);
		}
	}
	return 0;
}