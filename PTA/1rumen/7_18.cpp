#include <iostream>
using namespace std;

int main()
{
	double s;
	cin >> s;
	double a = s - 1600;
	if(s <= 1600) printf("%.2lf", 0);
	else if(s <= 2500) printf("%.2lf", a * 0.05);
	else if(s <= 3500) printf("%.2lf", a * 0.1);
	else if(s <= 4500) printf("%.2lf", a * 0.15);
	else printf("%.2lf", a * 0.2);
	
	return 0; 
}
