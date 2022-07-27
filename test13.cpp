#include <iostream>
using namespace std;
 
//typedef long long ll;
//const ll mod = 1e7;
// 
////a ^ b
//ll ksm(ll a, ll b, ll mod) {
//    ll ans = 1, base = a;
//    while(b != 0) {
//	if(b & 1 != 0) {
//	    ans = (ans * base) % mod;
//	}
//	base = (base * base) % mod;
//	b >>= 1;
//    }
//    return ans;
//}
// 
////a * b
//ll ksc(ll a, ll b, ll mod) {
//    ll ans = 0;
//    while(b != 0) {
//	if(b & 1 != 0) {
//	    ans = (ans + a) % mod;
//	}
//	a = (a + a) % mod;
//	b >>= 1;
//    }
//    return ans;
//}
 
int main() {
//    cout << "5 ^ 3 = " << ksm(5, 3, mod) << endl;
//    cout << "345352 * 11 = " << ksc(345352, 11, mod) << endl;
	int a = 3;
	int b = a << 1;
	cout << b;
    return 0;
}
