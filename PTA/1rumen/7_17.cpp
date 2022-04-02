#include <iostream>
using namespace std;

struct Student{
	char ID[6];
	char name[12];
	int grade;
};

int main()
{
	int N, i;
	double sum = 0, ave = 0;
	Student s[11];
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> s[i].ID >> s[i].name >> s[i].grade;
		sum += s[i].grade;
	}
	ave = sum / N;
	printf("%.2lf\n", ave);
	for(i = 0; i < N; i++) {
		if(s[i].grade < ave) printf("%s %s\n", s[i].name, s[i].ID);
	}
	return 0;
}
