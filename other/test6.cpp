#include <iostream>
#include <set> 
using namespace std;

//struct Node{
//	long long x;
//	long long y;
//};

int gcd(int a, int b);
int lcm(int a, int b);
bool judge(int year);

int main()
{
//	Node node[4] = {
//		{-1, 0},		//左 
//		{0, 1},			//上 
//		{1, 0},			//右 
//		{0, -1}			//下 
//	};
//	
//	long long len = 1;		//每次移动长度 
//	long long a = 0, b = 0;		//起点 
//	long long dis = 0;	//距离 
//	long long X, Y;
//	cin >> X >> Y;
//	
//	cout << node[0].x;
	
//	cout << gcd(11, 121) << endl;
//	
//	cout << lcm(12, 58);
	
	if(judge(2004)) cout << "True";
	else cout << "False";
	 
	return 0;
} 

int gcd(int a, int b)
{
	int t;
	while(b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

bool judge(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
	else return false;
}
