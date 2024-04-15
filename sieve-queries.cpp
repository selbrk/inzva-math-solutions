//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
const int N = 5e6+5;
vector<bool> isPrime(N, true); // isPrime[i] = true if i is prime
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
// write your code here
    fill_sieve();
    fill_pref();
    
    int q, l, r; cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n"; // number of primes in [l,r] = number of primes in [1,r] - number of primes in [1,l-1]
    }
	return 0;
}
