//背包问题

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, V;
    vector<int> v;      // 体积
    vector<int> w;      // 价值

    cin >> N >> V;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }

    int* dp = new int[V]();
    for(int i = 0; i < N; i++) {
        for(int j = V; j >= 1; j--) {
            if(j >= v[i])
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V];
    return 0;
}