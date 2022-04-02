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
		f = find(vi.begin(), vi.end(), n);			//���� n
		 
		// f == vi.end() ��ʾû���ҵ� n ���������  
		if(f == vi.end())  vi.push_back(n);			//�� n ������������� vector 
	}
	
	//�� vector �е�Ԫ�شӴ�С����
	sort(vi.begin(), vi.end(), greater<int>());		
	
	//��������һ��
	vector<int>::iterator it;
	cout << "int[] arr = new int[]{"; 
	it = vi.begin();
	for(it; it != vi.end(); it++) {
		if(it == vi.begin()) cout << *it;		//��һ����������� 
		else cout  <<"," << *it;
	}
	cout << "};" << endl;
	
	//�������ڶ��� 
	cout << "int[] index = new int[]{"; 
	for(int i = 0; i < s.length(); i++) {
		n = s[i] - '0';
		f = find(vi.begin(), vi.end(), n);			//���� n
		
		if(!i)	{									//��һ����������� 
			printf("%d", f - vi.begin());
		}
		else {
			printf(",%d", f - vi.begin());
		}
	}
	cout << "};";
	
	return 0;
} 
