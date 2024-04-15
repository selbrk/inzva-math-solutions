#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ll ans = 0;
    ll n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        ans = gcd(ans,temp);
    }
    
    cout << ans << endl;
	return 0;
}
