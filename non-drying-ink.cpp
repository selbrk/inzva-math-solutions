//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    // by divisibility rule for 11, every palindrome with even length is divisible by 11
    string s; cin >> s;
    int n = s.size();
    
    for(int i = 0; i< n-1; i++) { // for every digit except the last one, the number is not prime
        cout << "Not Prime\n";
    }
    if(s[n-1] == '1') cout << "Prime"; // if the last digit is 1, the last number is prime
    else cout << "Not Prime";
	return 0;
}
