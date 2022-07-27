#include <stdio.h>
#define MAXN 20
typedef struct {
	char data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct {
	 char cd[MAXN];
	 int start;
}HCode;

void CreateHTree(HTNode ht[], int n) {
	int i, j, lnode, rnode;
	double min1, min2;
	for(i = 0; i <= 2 * n - 2; i++)
		ht[i].parent = ht[i].rchild = ht[i].lchild = -1;
	for(i = n; i <= 2 * n - 2; i++) {
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for(j = 0; j <= i - 1; j++) {
			if(ht[j].parent == -1) {
				if(ht[j].weight < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = ht[j].weight;
					lnode = j;
				}
				else if(ht[j].weight < min2) {
					min2 = ht[j].weight;
					rnode = j;
				}
			}
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
}

void CreateHCode(HTNode ht[], HCode hcd[], int n) {
	int i, f, c;
	for(i = 0; i < n; i++) {
		hcd[i].start = n - 1;
		c = i;
		f = ht[i].parent;
		while(f != -1) {
			if(ht[f].lchild == c)
				hcd[i].cd[hcd[i].start--] = '0';
			else
				hcd[i].cd[hcd[i].start--] = '1';
			c = f;
			f = ht[f].parent;
		}
		hcd[i].start++;
	}
}

void dispHCode(HTNode ht[], HCode hcd[], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		printf("%c:", ht[i].data);
		for(j = hcd[i].start; j < n; j++)
			printf("%c", hcd[i].cd[j]);
		printf("\n");
	}
}

int main()
{
	int n = 5;
	HTNode ht[2 * MAXN - 1];
	HCode hcd[MAXN];
	ht[0].data = 'a'; ht[0].weight = 4;
	ht[1].data = 'a'; ht[1].weight = 2;
	ht[2].data = 'a'; ht[2].weight = 1;
	ht[3].data = 'a'; ht[3].weight = 7;
	ht[4].data = 'a'; ht[4].weight = 3;
	CreateHTree(ht, n);
	CreateHCode(ht, hcd, n);
	printf("产生的哈夫曼编码如下：\n");
	dispHCode(ht, hcd, n);
	return 0;
}
