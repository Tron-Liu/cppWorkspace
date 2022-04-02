#include <iostream>
using namespace std;

int main()
{
	int number;
	int count = 1;
	while(1) {
		scanf("%d", &number);
		if(number == 250) {
			printf("%d", count);
			return 0;
		}
		count++;
	}
}
