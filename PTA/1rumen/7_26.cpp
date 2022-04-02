#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N;
	multiset<int> ms;
	cin >> N;
	
	int max = 1, temp = 1;
	int p;
	for(int i = 0; i < N; i++) {
		cin >> p;
		ms.insert(p);
	}
	multiset<int>::iterator mit;
	mit = ms.begin();
	int num = *mit;
	mit++;
	while(mit != ms.end()) {
		if(num == *mit) {
			temp++;
			max = temp;
		}
		else {
			if(temp) temp--;
			else {
				temp = max + 1;
				num = *mit;
			}
		}
		mit++;	
	}
	printf("%d %d", num, max);
	return 0;
}
