#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    /*
    we want to find the number of i's such that (n-i^2) / (i+a) is an integer
    a number is an integer if and only if k more than the number is also an integer where k is an integer
    we want to get rid of i^2 in the numerator
    (n-i^2) / (i+a) + i - a = (n+i*a) / (i+a) - a = (n-a^2) / (i+a)
    n and a are known, we know the factors of n-a^2
    if n - a^2 = 0 then it has infinitely many divisors
    otherwise just count the number of divisors of n-a^2
    */
    ll n, a; cin >> n >> a;
    ll temp = abs(n - a * a);
    if(temp == 0) {
        cout << -1 << endl;
        return 0;
    }
    ll cnt = 0;
    for(ll i = 1; i*i <= temp; i++) {
        if(temp % i == 0 && (temp / i) != i) { // i and temp/i are divisors and they are different
            cnt+=2;
        }
        else if(temp % i == 0) { // i and temp/i are divisors and they are the same so we count only one
            cnt++;
        }
    }
    
    cout << 2*cnt << endl; // we only counted positive divisors so we multiply by 2
 	return 0;
}
