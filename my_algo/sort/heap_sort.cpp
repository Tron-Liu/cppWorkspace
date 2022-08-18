#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& arr, int low, int high) {
	int parent = low;
	int child = 2 * parent + 1;

	while (child <= high) {
		if (child + 1 <= high && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] > arr[child])
			return ;

		swap(arr[parent], arr[child]);

		parent = child;
		child = parent * 2 + 1;
	}
}

void sort(vector<int>& arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, i, len - 1);
	
	for (int i = len - 1; i > 0; i--) {
		swap(arr[i], arr[0]);
		heapify(arr, 0, i - 1);
	}
}

int main()
{
  //	int nums[] = { 2, 8, 0, -1, -100, 200, 10, 3, 2, 0, 1, 9, -1 };
	int nums[] = { 1, 4, 2, 3 };
	int len = sizeof(nums) / sizeof(int);
	
	// cout << "len : " << len << endl;

	vector<int> arr(nums, nums + len);
	sort(arr, len);

	for (int a : arr)
		cout << a << " ";
	cout << endl;

	return 0;
}
