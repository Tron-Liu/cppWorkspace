#include <iostream>
#include <cstdlib>
using namespace std;

struct School {
	int i;
	int seat[102];
	int num;
};

int main()
{
	int n;
	cin >> n;

	int total[102] = { 0 };
	School* school = (School *)malloc(sizeof(School) * n);
	
	for (int j = 0; j < n; j++) {
		cin >> school[j].num;
		school[j].num *= 10;
		total[j] = school[j].num;
		school[j].i = 0;
	}

	int exits = n;
	int k = 1;
	int j = 0;
	for (int m = 0; exits > 0; m++) {
		j = m % n;

		if (school[j].num > 0) {
			int p = school[j].i;
			school[j].i++;
			school[j].seat[p] = k;

			school[j].num--;

			if (exits > 1) k++;
			else k += 2;
		}
		if (school[j].num == 0) {
			exits--;
			school[j].num--;
		}
	}

	for (int x = 0; x < n; x++) {
		cout << "#" << x+1 << endl;
		for (int y = 0; y < total[x]; y++) {
			cout << school[x].seat[y];

			if ((y + 1) % 10 == 0) cout << endl;
			else cout << " ";
		}
	}

	free(school);
	return 0;
}
