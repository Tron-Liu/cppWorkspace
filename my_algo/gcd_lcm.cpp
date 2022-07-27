#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
  int a = 2;
  int b = 5;
  int c = gcd(a, b);
  cout << c;
  return 0;
}

int gcd(int a, int b) {
  int r = 0;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }