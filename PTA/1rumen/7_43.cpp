#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Student {
	int gender;
	string s;
};

int main()
{
	deque<Student> male, female, stu;

	int N;
	cin >> N;
	Student temp;
	while(N--) {
		cin >> temp.gender >> temp.s;
		stu.push_back(temp);
		if(temp.gender) male.push_back(temp);		//男生进队 
		else female.push_back(temp);				//女生进队 
	}
	
	
	while(!male.empty()) {
		temp = stu.front();
		stu.pop_front();
		if(temp.gender) {
			cout << temp.s << " " << female.back().s << endl;
			male.pop_front();
			female.pop_back();
		}
		else {
			cout << temp.s << " " << male.back().s << endl;
			female.pop_front();
			male.pop_back();
		}
	}
	return 0;
 } 
