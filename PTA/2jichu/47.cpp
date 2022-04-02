#include <iostream>
#include <cstring>
using namespace std;

int main()
{	
	int k;
	cin >> k;
	
	int *num = new int[k + 1];
	memset(num, 0, k+1);
	
	int i = 0, count = 0;
	int a;
	cin >> a;
	while(a >= 0) {
		num[i % k] = a;
		i++;
		count++;
		cin >> a;
	}
	if(count < k) cout << "NULL";
	else cout << num[(i+k) % k];
	
	return 0;
}
