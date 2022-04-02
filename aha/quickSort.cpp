#include <stdio.h>

void quickSort(int left, int right, int *arr)
{
	int i = left, j = right;
	while (i != j)
	{
		
	}
	
}


int main() {
	int arr[10] = {2, 7, 1, 9, 0, -3, 5, 4, -9, 8};
	quickSort(0, 9, arr);
	
	int i;
	for(i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}
