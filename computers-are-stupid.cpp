#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 3;
vector<int> isPrime(N, true); // isPrime[i] = true if i is prime
vector<int> primes; // primes[i] = i-th prime
void fill_sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<N; i++)
        if(isPrime[i])
            for(int j = 2*i; j < N; j += i)
                isPrime[j] = false;
}

void fill_primes() { // fill primes vector
    for(int i = 0; i<N; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
}
void solve(){
    int a, b, cnt = 0; cin >> a >> b;
    for(int& p : primes){ // for every prime, check if a or b is divisible by it and divide them by it until they are not divisible
        if(a % p == 0 || b % p == 0)
            cnt++;
        while(a % p == 0)
            a /= p;
        while(b % p == 0)
            b /= p;
        
    }
    if(a!=1 && b!=1 && b==a) cnt++; // if a and b are equal and not 1 that means they are both divisible by the same prime greater than N
    else if(a!=1 && b!= 1) cnt+=2; // if a and b are not equal and not 1 that means they are both divisible by different primes greater than N
    else if(a == 1 && b != 1) cnt++; // if a is 1 and b is not 1 that means b is divisible by a prime greater than N
    else if(a != 1 && b == 1) cnt++; // if b is 1 and a is not 1 that means a is divisible by a prime greater than N
    cout << cnt << "\n";
}

int main() {
    fill_sieve();
    fill_primes();
    int t; cin >> t;
    while(t--) solve();
    
	return 0;
}
