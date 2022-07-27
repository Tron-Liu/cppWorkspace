#include <iostream>

class Solution {
public:
    string fractionAddition(string expression) {
        int first_a = 0;
        int first_b = 1;
        int second_a = 0;
        int second_b = 1;

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+') {
                int g = gcd(first_b, second_b);

                first_a = first_a + second_a;
                first_b = first_b + second_b;
                

            } else if (expression[i] == '-') {
                first_a = first_a - second_a;
                first_b = first_a - second_b;


            } else if (expression[i] == '/') {
                second_a = expression[i - 1] - '0';
                second_b = expression[i + 1] - '0';
            } else 
                continue;
        }
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

    int lcm(int a, int b) {
        return a * b / ()
    }
};

int main()
{

}