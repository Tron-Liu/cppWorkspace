#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int nthUglyNumber(int n);
int main() {
  int n = 1600;
  cout << nthUglyNumber(n) << endl;
  return 0;
}

int nthUglyNumber(int n) {
  vector<int> factors = {2, 3, 5};
  set<long> heap = {1};

  int count = 1;
  set<long>::iterator cursor = heap.begin();
  while (count < n) {
    // cout << *cursor << " ";
    for (int factor : factors) {
      int tmp = (*cursor) * factor;
      heap.insert(tmp);
    }
    cursor++;
    // heap.erase(heap.begin());
    // cout << "heap: ";
    // for (int a : heap) cout << a << " ";
    // cout << endl;
    count++;
  }
//   cout << endl;
    for (int a: heap) cout << a << " ";
  return *cursor;
}