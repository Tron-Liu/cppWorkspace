#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	queue<int> A, B;
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a % 2) A.push(a);
		else B.push(a);
	}
	
	int count = 0;
	int tag = 0;
	while(!A.empty() && !B.empty()) {
		cout << A.front();
		A.pop();
		count++;
		tag++;
		if(count < n) cout << " ";
		if(tag % 2 == 0) {
			cout << B.front();
			B.pop();
			count++; 
			if(count < n) cout << " ";
		}	
	}
	
	if(!A.empty()) {
		while(!A.empty()) {
			cout << A.front();
			A.pop();
			count++;
			if(count < n) cout << " ";
		}
	}
	if(!B.empty()) {
		while(!B.empty()) {
			cout << B.front();
			B.pop();
			count++;
			if(count < n) cout << " ";
		}
	}
	return 0;
}
