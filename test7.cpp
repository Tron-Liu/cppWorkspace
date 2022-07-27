#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int a[100005], n, ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ans = a[1] - a[0];
    for (int i = 2; i < n; i++)
        ans = gcd(ans, a[i] - a[i - 1]);
    if (a[n - 1] - a[0] == 0)
        cout << n;
    else
        cout << (a[n - 1] - a[0]) / ans + 1;
    return 0;
}
