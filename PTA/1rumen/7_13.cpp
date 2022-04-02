#include <iostream>
using namespace std;

int main()
{
	int result = 0;
	int i;
	int temp = 1;
	int N;
	cin >> N;
	for(i = 1; i <= N; i++) {
		temp = temp * i;
		result += temp;
	}
	printf("%d", result);
	
	return 0;
 } 
