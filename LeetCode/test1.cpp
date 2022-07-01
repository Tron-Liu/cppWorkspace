#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//int cmp(int** a, int** b) {
//    return (*a)[0] == (*b)[0] ? (*b)[1] - (*a)[1] : (*a)[0] - (*b)[0];
//}

int main()
{
	// int a[][4] = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
	// vector< vector<int> > en(a, a + 4); 
//	sort(a, a + 4, cmp);

	int a[4] = {1, 2, 3, 4};
	vector<int> map(a, a+4);

	reverse(map.begin(), map.end());
	for (int i : map) {
		cout << i << " ";
	}
    return 0;
}
