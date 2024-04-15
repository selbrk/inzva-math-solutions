#include <bits/stdc++.h>
#define ii pair<int, int>

using ll = long long;
using namespace std;

const int mod = 1e9 + 7;

int gcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k = 1e6;
    vector<int> phi(k + 5);
    for (int i = 1; i <= k; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= k; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= k; j += i) { // mark all multiples of i
                phi[j] -= phi[j] / i; // phi[j] * (1 - 1/i)
            }
        }
    }

    int n;
    cin >> n;
    int ctr = 0;
    int i;
    for (i = 2; i <= k; i++) { // i = 2, 3, 4, 5, ...
        if (phi[i] + ctr < n) { // if current number of coprimes is less than n continue to add
            ctr += phi[i];
        } else { // if current number of coprimes is greater than or equal to n break
            break;
        }
    }
    // write until ctr == n
    for (int j = 1; j< i; j++) {
        if(gcd(i,j) == 1) ctr++;
        if(ctr == n) {
            cout << j << " " << i << endl;
            return 0;
        }
    }

    return 0;
}