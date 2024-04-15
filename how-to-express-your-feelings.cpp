#include <bits/stdc++.h>


#define int long long
using namespace std;


string base_k(int n, int k) { // write n in base k without using 0
    string ans = ""; // answer
    while (n) {
        if (n % k == 0) { // last digit is 0, but we can't use 0, so we use k instead
            ans += to_string(k); // ans += k;
            n = (n - k); // decrease n by k
            n /= k; // pop the last digit
        } else { // last digit is not 0, we can use it
            ans += to_string(n % k); 
            n /= k;
        }
    }
    reverse(ans.begin(), ans.end()); // reverse the string
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        vector<int> v(b); 
        for (int i = 0; i < b; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end()); // 0 th index corresponds to 1, 1 st index corresponds to 2, ...
        string ans = base_k(a, b); // it is the answer of the smallest a th number with 1,2,..,b digits
        for (char c : ans) {
            cout << v[c - '0' - 1]; // convert char to int and print the corresponding digit
        }
        cout << '\n';
    }

    return 0;
}
