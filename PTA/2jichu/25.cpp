#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	stack<string> st;
	while(cin >> s) {		//���뵥�� 
		st.push(s);			//���ʽ�ջ 
	}
	while(!st.empty()) {	//��ջ��Ϊ��ʱ 
		cout << st.top(); 	//��ȡջ��Ԫ�� 
		st.pop();			//ջ��Ԫ�س�ջ 
		if(st.size())		//���һ��Ԫ�ز�����ո� 
			cout << " ";
	}
	
	return 0;
}
