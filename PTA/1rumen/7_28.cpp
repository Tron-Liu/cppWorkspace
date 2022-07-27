#include <stdio.h>

int main()
{
	int N, i;
	int arr[12] = {0};
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	int j = 0, temp;
	for(i = 0; i < N; i++) {
		if(arr[j] > arr[i])		//记录最小值 
			j = i;
	}
	temp = arr[0];
	arr[0] = arr[j];
	arr[j] = temp;
	
	for(i = 0; i < N; i++) {
		if(arr[j] < arr[i])		//记录最大值 
			j = i;
	}
	temp = arr[N-1];
	arr[N-1] = arr[j];
	arr[j] = temp;

	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
		
	return 0;
}
