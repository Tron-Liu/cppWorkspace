#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[low];

	while (low < high) {
		while (low < high && arr[high] > pivot)
			high--;
		if (low < high) arr[low++] = arr[high];
		while (low < high && arr[low] < pivot)
			low++;
		if (low < high) arr[high--] = arr[low];
	}
	
	arr[low] = pivot;
	return low;
}

void sort(vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		sort(arr, low, pivot - 1);
		sort(arr, pivot + 1, high);
	}
}

int main()
{
	int nums[] = { 1, 4, 2, 3 };
	int len = sizeof(nums) / sizeof(int);

	vector<int> arr(nums, nums + len);
	sort(arr, 0, len - 1);

	for (int a : arr)
		cout << a << " ";
	cout << endl;

	return 0;
}
