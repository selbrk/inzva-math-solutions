#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 5e6 + 5;
const ll mod = 1e9+7;
ll spf[N]; // spf[i] = smallest prime factor of i

void fill_spf() {
    for(int i = 2; i<N; i++) {
        if(spf[i] == 0) { // i is prime
            for(int j = i; j<N; j+=i) { // mark all multiples of i
                if(spf[j] == 0) spf[j] = i; // if not marked already (i.e. not marked by a smaller prime) mark it
            }
        }
    }
}

ll fast_exp(ll base, ll power, ll mod = 1e9+7) {
    if(power == 0) return 1;
    if(power % 2 == 1) return (fast_exp(base,power-1) * base) % mod;
    ll findFirst = fast_exp(base,power/2);
    return (findFirst * findFirst) % mod;
}

int main() {
    fill_spf();
    ll n, x, cpf, count_cpf; cin >> n; // cpf = current prime factor, count_cpf = count of current prime factor
    unordered_map<ll,ll> factorization; // <prime, power> of lcm
    for(int i = 0; i<n; i++) {
        cin >> x;
        while(x != 1) { // factorize x
            cpf = spf[x]; // current prime factor
            count_cpf = 0;
            while(x % cpf == 0) { // count the power of current prime factor
                x /= cpf;
                count_cpf++;
            }
            factorization[cpf] = max(factorization[cpf], count_cpf); // update the power of current prime factor
        }
    }
    ll lcm = 1;
    for(auto& [x,y] : factorization) { // calculate lcm
        lcm *= fast_exp(x,y);
        lcm %= mod;
    }
    
    cout << lcm << endl;
	return 0;
}
