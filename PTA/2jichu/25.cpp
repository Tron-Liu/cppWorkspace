#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	stack<string> st;
	while(cin >> s) {		//输入单词 
		st.push(s);			//单词进栈 
	}
	while(!st.empty()) {	//当栈不为空时 
		cout << st.top(); 	//获取栈顶元素 
		st.pop();			//栈顶元素出栈 
		if(st.size())		//最后一个元素不输出空格 
			cout << " ";
	}
	
	return 0;
}
