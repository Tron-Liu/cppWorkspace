#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int *num = new int [n+2];
	memset(num, 0, n+2);
	
	for(int i = 0; i < n; i++)
		cin >> num[i];
	
	int max_size = 0;
	int sum = 0;
	int a = 0, b = 0;
	int c = 0, d = 0;	
	for(int i = 0; i < n; i++)	{
		if(num[i] < num[i+1]) {
			sum++;
			d = i+1;
			if(sum > max_size) {
				max_size = sum;
				a = c;
				b = d;
			}
		}
		else {
			c = i+1;
			sum = 0;
		}
	}
	
	cout << num[a];
	for(int i = a + 1; i <= b; i++)
		cout << " " << num[i];
		
	delete []num;
	return 0;
} 
