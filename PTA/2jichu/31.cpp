#include <stdio.h>

int main()
{
    int ID[100000]={0};
	int N, K, M;
	int i, flag = 1,n = 1;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &K);
		if (K >= 2) {
			while (K--) {
				scanf("%d", &i);
				ID[i] = 1;
			}
		}
        else {
			scanf("%d", &i);
		}
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &i);
		if (ID[i] == 0) {
			if (n) {
				printf("%05d", i);
				n = 0;
			}
			else printf(" %05d", i);
			ID[i] = 1;
            flag = 0;
		}
	}
	if (flag) printf("No one is handsome\n");
	return 0;
}
