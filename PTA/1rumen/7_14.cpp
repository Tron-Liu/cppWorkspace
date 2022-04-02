#include <stdio.h>
#include <math.h>

int main()
{
	int arr[6] = {0};
	int L, N;
	scanf("%d %d", &L, &N);
	
	int i, t = 1;
	for(i = 0; i < L; i++)
		t *= 26; 
	
	int tool = t - N;
	
	arr[0] = tool / pow(26, L-1);
	for(i = 1; i < L - 1; i++) {
		tool -= arr[i-1] * pow(26, L-i);
		arr[i] = tool / pow(26, L-1-i);
	}
	arr[L-1] = tool % 26;
	
	for(i = 0; i < L; i++)
		printf("%c", arr[i] + 97);
	return 0;
}
