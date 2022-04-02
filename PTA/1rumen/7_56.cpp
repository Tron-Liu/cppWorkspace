#include <iostream>
#include <vector>
using namespace std;

bool issame(vector<char> vc);		//判断倒过来的数组与原数组是否相同 
void print(char s, vector<char> vc, int N);		//输出目标结果 

int main()
{
	char s;
	cin.get(s);
	
	int N;
	cin >> N;
	
	vector<char> vc;
	int N2 = N * N + N;
	char c;
	for(int i = 0; i < N2; i++) {
		cin.get(c);
		if(c != '\n') vc.push_back(c);
	}
	
	if(issame(vc)) {
		printf("bu yong dao le\n");	
	}
	print(s, vc, N);
	
	return 0;
}

bool issame(vector<char> vc) {
	vector<char>::iterator b = vc.begin();
	vector<char>::iterator e = vc.end();
	
	e--; 
	while(b != e) {
		if(*b != *e) return false;
		b++;
		e--;
	}
	return true;
}

void print(char s, vector<char> vc, int N) {
	vector<char>::reverse_iterator b;
	
	int i = 1;
	for(b = vc.rbegin(); b != vc.rend(); b++) {
		if(*b != ' ') cout << s;
		else cout << " ";
		if(i % N == 0) cout << endl;
		i++;
	}
}
