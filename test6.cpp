#include <iostream>
using namespace std;

const long long N = 59084709587505;
// const long long N = 5;

bool check(int x, int y, int z) {
  long long sum = 1;
  while (x--) {
    sum *= 3;
    if (sum >= N) return false;
  }
  while (y--) {
    sum *= 5;
    if (sum >= N) return false;
  }
  while (z--) {
    sum *= 7;
    if (sum >= N) return false;
  }
  // printf("***%lld***\n", sum);
  return true;
}

int main() {
  int n = 0;
  for (int i = 0; i <= 31; ++i) {
    for (int j = 0; j <= 20; ++j) {
      for (int k = 0; k <= 17; ++k) {
        if (check(i, j, k)) {
          n++;
        } else
          break;
      }
    }
  }
  printf("%d\n", n);
  return 0;
}
