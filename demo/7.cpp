#include <iostream>

using namespace std;
typedef long long ll; // 懒得写那么多 long long

void Exgcd(ll a, ll b, ll &x, ll &y) { // 扩展欧几里得求逆元
    if(!b) x = 1, y = 0;
    else Exgcd(b, a % b, y, x), y -= a / b * x;
}

inline ll mul(ll x, ll y, ll p) { // 快速乘，防止爆 long long
    ll z = (long double)x / p * y;
    ll res = (unsigned long long)x * y - (unsigned long long)z * p;
    return (res + p) % p;
}

ll fpm(ll x, ll power, ll p) { // 快速幂
    x %= p;
    ll ans = 1;
    for(; power; power >>= 1, x = mul(x, x, p))
        if(power & 1)(ans = mul(ans, x, p)) %= p;
    return ans;
}

int main() 
{
    ll n = 1001733993063167141, d = 212353, p, q;
    for(ll i = 3; i * i < n; i += 2) {
        /*
        if(i % 1000000000 == 1) // 进度条，要不然不知道程序有没有再跑
            cout << i << endl;
        */
        if(n % i == 0) { //n % i== 0
            p = i;
            q = n / i;
            break;
        }
    }
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    /*
    p = 891234941;
    q = 1123984201;
    */
    
    ll e, m = (p - 1) * (q - 1), x, y;

    Exgcd(d, m, x, y);
    
    e = (x % m + m) % m;
    ll C = 20190324;
    // cout << mul(d, e, m); 验证 d*e mod m = 1
    cout << fpm(C, e, n) << endl;
    return 0;
}
