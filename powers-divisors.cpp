//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6+5;
const ll mod = 1e9+7;
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


int main() {
    fill_sieve();
    fill_primes();
    ll n, k; cin >> n >> k;
    for(int i = 0; i < primes.size() - 1; i++) { // check the adjacent prime pairs
        ll prime1 = primes[i], prime2 = primes[i+1];
        ll temp = prime1+prime2+1; 
        if(temp > n) break; // if the sum of the primes is greater than n, break
        if(isPrime[temp]) k--; // if the sum is prime, decrement k
    }
    if(k <= 0) { // if k is less than or equal to 0, print TRUE since we have found at least k prime pairs
        cout << "TRUE" << endl;
    } else { // if k is greater than 0, print FALSE since we have not found k prime pairs
        cout << "FALSE" << endl;
    }
}
