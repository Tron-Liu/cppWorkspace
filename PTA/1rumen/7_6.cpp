#include <iostream>
#include <cmath>
#define MaxSize 10002
using namespace std;

int main()
{
	int N;
	int arr[MaxSize] = {0};
	cin >> N;
	
	int i;
	double sum = 0;
	for(i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
		
	double Avg = sum / N;			//求平均值
	double temp, result = 0;
	for(i = 0; i < N; i++)  {
		temp = arr[i] - Avg;
		result += temp * temp;
	}
	
	printf("%.5f", sqrt(result / N));
	return 0;
}
