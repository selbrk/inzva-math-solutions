#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll N = 1e7+3;
int isPrime[N];
ll ans = 0, cnt = 0, j;
void fill_sieve(ll n){
    for(int i = 2; i< n+5; i++) {
        if(isPrime[i] == 0) { // i is prime
            for(j = 2*i; j < n+5; j+=i) {
                if(isPrime[j] > 1) continue; // it is marked as a prime power
                isPrime[j] = 1; // j is not prime
            }
            for(j = i; j < n+5; j*=i) {
                if(j > (n+1)) break; 
                ans += i; // for all prime powers less than n, add the prime to the answer
                cnt++; // count the prime powers
                isPrime[j] = i; // mark the prime power
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    fill_sieve(n);
    
    ans += n- cnt; // add the remaining 1s to the answer
    
    
    cout << ans << endl;
	return 0;
}
