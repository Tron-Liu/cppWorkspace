/*
所谓选择法就是先将10个数中最小的数与a[0]对换；
再将a[1]~a[10]中最小的数与a[1]对换......共九轮比较
*/

#include <stdio.h>
void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n-1; i++)
	{
		k = i;
		for (j = i+1; j <n; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
}
int main()
{
	int a[10], i;
	printf("enter array:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	sort(a, 10);
	printf("The sorted array:\n");
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
	return 0;
}