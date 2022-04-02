#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	
	int max = 0;
	int temp = 0;
	int a;
	for(int i = 0; i < k; i++) {
		cin >> a;
		temp += a;
		if(temp < 0) temp = 0;
		if(temp > max) max = temp;
	}
	
	if(max > 0) cout << max;
	else cout << "0";
	
	return 0;
} 
