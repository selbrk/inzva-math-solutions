#include <bits/stdc++.h>

using namespace std;
const int N = 5e6+5;
vector<int> isPrime(N, true); // isPrime[i] = true if i is prime
vector<int> pref(N); // pref[i] = number of primes in [1,i]
void fill_sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<N; i++)
        if(isPrime[i])
            for(int j = 2*i; j < N; j += i)
                isPrime[j] = false;
}

void fill_pref() {
    for(int i = 2; i<N; i++)
        pref[i] = pref[i-1] + isPrime[i]; // number of primes in [1,i] = number of primes in [1,i-1] + 1 if i is prime
}


int main() {
    fill_sieve();
    fill_pref();
    /*
    for every prime in the range [1, r] we get the greatest prime power in the range.
    that is simply the prime count in the range since every prime has only one greatest prime power in that range.
    */
    int q, r; cin >> q;
    while(q--) {
        cin >> r;
        cout << pref[r] << "\n"; // number of primes in [1,r]
    }
	return 0;
}
