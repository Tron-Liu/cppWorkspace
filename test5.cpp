#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int divisorSubstrings(int num, int k)
{
    int count = 0;
    int div = pow(10, k);

    int a = num % div;
    while (num >= a) {
        if ( a!= 0 && num % a == 0)
            count++;

        num /= 10;
        a = num % div;
    }

    return count;
}

int main()
{
	int num = 123456;
	int a = 100;

	cout << num / 10;
    return 0;
}
