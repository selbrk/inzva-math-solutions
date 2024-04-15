#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9+7;
ll fast_exp(ll base, ll power) {
    if(power == 0) return 1;
    if(power % 2 == 1) return (base * fast_exp(base,power-1)) % mod;
    ll f = fast_exp(base, power / 2);
    return (f * f) % mod;
}

ll s(ll n, ll k) {
    ll ans = 0;
    for(int i = 1; i<=n; i++) {
        ans += fast_exp(i,k);
        ans %= mod;
    }
    return ans;
}

ll p(ll n){
    ll ans = 0;
    for(int i = 1; i<=n; i++) {
        ans+= fast_exp(i,i);
        ans %= mod;
    }
    return ans;
}

ll z(ll n, ll k) {
    return (s(n,k) + p(n)) % mod;
}

int main() {
// write your code here
    ll n, k; cin >> n >> k;
    cout << z(n,k) << endl;
	return 0;
}