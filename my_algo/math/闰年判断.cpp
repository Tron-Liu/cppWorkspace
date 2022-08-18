#include <iostream>
#include <set>
using namespace std;

bool judge(int year);

int main() {
  if (judge(2004))
    cout << "True";
  else
    cout << "False";

  return 0;
}

bool judge(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
  else
    return false;
}
