#include <ctype.h>

#include <iostream>

using namespace std;

class Solution {
 public:
  enum Operation { plus, sub };

  enum Fraction { denominator, numerator };

  string fractionAddition(string expression) {
    int first_a  = 0;
    int first_b  = 1;
    int second_a = 0;
    int second_b = 1;

    int op = plus;

    for (int i = 0; i < expression.length(); i++) {
      if (expression[i] == '+') {
        op = plus;
      }
      else if (expression[i] == '-') {
        op = sub;
      }
      else if (expression[i] == '/') {
        second_a = get_num(i, expression, numerator);
        second_b = get_num(i, expression, denominator);
        // cout << "second : " << second_a << " " << second_b << endl;

        int LCM = lcm(first_b, second_b);

        if (op == plus) {
          first_a = LCM / first_b * first_a + LCM / second_b * second_a;
          first_b = LCM;
        }
        else {
          first_a = LCM / first_b * first_a - LCM / second_b * second_a;
          first_b = LCM;
        }

        // 化简
        int GCD = gcd(first_a, first_b);
        first_a = first_a / GCD;
        first_b = first_b / GCD;

        if (first_b < 0) {
          first_a = -1 * first_a;
          first_b = -1 * first_b;
        }
        // cout << "first : " << first_a << " " << first_b << endl;
      }
    }

    string ans = to_string(first_a) + "/" + to_string(first_b);
    return ans;
  }

  int gcd(int a, int b) {
    int r = 0;

    while (b) {
      r = a % b;
      a = b;
      b = r;
    }

    return a;
  }

  int lcm(int a, int b) { return a * b / gcd(a, b); }

  int get_num(int i, string& s, int option) {
    int num  = 0;
    int base = 1;

    if (option == numerator) {
      while (i - 1 >= 0 && isdigit(s[i - 1])) {
        num  = num + (s[i - 1] - '0') * base;
        base = base * 10;
        i--;
      }
    }
    else {
      while (i + 1 <= s.length() && isdigit(s[i + 1])) {
        num = num * 10 + (s[i + 1] - '0');
        i++;
      }
    }

    return num;
  }
};

int main() {
  string expression  = "-5/2+10/3+7/9";
  string expression1 = "1/2-1/2";
  string expression2 = "1/3-1/2";

  Solution so;
  cout << so.fractionAddition(expression1);

  return 0;
}