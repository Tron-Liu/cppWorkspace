#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    while (start < end)
    {
        while (start < end && arr[end] >= pivot) //从右向左找第一个小于pivot的数
            end--;
        if (start < end)
            arr[start++] = arr[end];

        while (start < end && arr[start] <= pivot) //从左向右找第一个大于pivot的数
            start++;
        if (start < end)
            arr[end--] = arr[start];
    }
    arr[start] = pivot;
    return start;
}

void quick(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quick(arr, start, pivot - 1);
        quick(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[] = {8, 1, 2, 9, -10, 20, 38, 1, 0, -100};
    int start = 0;
    int end = 10;

    quick(arr, start, end);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;

    return 0;
}