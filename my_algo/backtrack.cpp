#include <iostream>
#include <vector>
using namespace std;

/*
* res: ��ά���飬�洢���ս��
* temp: һά���飬�洢�м���
* nums: ����������
* n: ���ָ��� 
*/

int selected[4] = {0};

void func(vector< vector<int> >& res, vector<int>& temp, vector<int>& nums) {
	// ��������
	if (temp.size() == nums.size()) {
		res.push_back(temp);
		return;
	}
	
	for (int i = 0; i < nums.size(); i++) {
		// ����ѡ��
		if (selected[i] == 0) {
			temp.push_back(nums[i]);
			selected[i] = 1;
		}
		else
			continue;
		// �ݹ����
		func(res, temp, nums);
		// ����ѡ�� 
		temp.pop_back();
		selected[i] = 0;
	}
}

int main() {
	int a[] = {1, 2, 3, 4};
	int n = 4;
	int start = 0;
	vector<int> nums(a, a + 4);
	vector<int> temp;
	vector< vector<int> > res;
	
	func(res, temp, nums);
	
	vector< vector<int> >::iterator it1;
	vector<int>::iterator it2;
	for (it1 = res.begin(); it1 != res.end(); it1++) {
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
}
