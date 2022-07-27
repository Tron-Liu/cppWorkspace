#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
  unordered_multiset<int> hash;
  hash.insert(3);
  hash.insert(3);
  hash.insert(3);
  hash.insert(3);

  cout << hash.size() << endl;
  auto it = hash.find(3);

  hash.erase(it);

  cout << hash.size() << endl;
  for (int num : hash) cout << num << " ";

  return 0;
}
