#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n;
string s;
bool P = 1, same = 1;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    cin >> s;
    
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) {
    	if (s[i] != s[n - i + 1]) P = 0;
    	if (s[i] != s[1]) same = 0;
    }
    
    
    if (same) {
    	cout << 0;
    }
    else if (P == 0) {
    	cout << n << endl;
    }
    else {
    	cout << n - 1 << endl;
    }
    return 0;
}

// dua ra do dai xau con dai nhat khong phai xau palindrome