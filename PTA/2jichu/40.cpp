#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s; 
	
	vector<int> vi;
	int n;
	vector<int>::iterator f;
	for(int i = 0; i < s.length(); i++) {
		n = s[i] - '0';
		f = find(vi.begin(), vi.end(), n);			//查找 n
		 
		// f == vi.end() 表示没有找到 n 代表的数字  
		if(f == vi.end())  vi.push_back(n);			//将 n 代表的数字推入 vector 
	}
	
	//将 vector 中的元素从大到小排序
	sort(vi.begin(), vi.end(), greater<int>());		
	
	//输出结果第一行
	vector<int>::iterator it;
	cout << "int[] arr = new int[]{"; 
	it = vi.begin();
	for(it; it != vi.end(); it++) {
		if(it == vi.begin()) cout << *it;		//第一个不输出逗号 
		else cout  <<"," << *it;
	}
	cout << "};" << endl;
	
	//输出结果第二行 
	cout << "int[] index = new int[]{"; 
	for(int i = 0; i < s.length(); i++) {
		n = s[i] - '0';
		f = find(vi.begin(), vi.end(), n);			//查找 n
		
		if(!i)	{									//第一个不输出逗号 
			printf("%d", f - vi.begin());
		}
		else {
			printf(",%d", f - vi.begin());
		}
	}
	cout << "};";
	
	return 0;
} 
