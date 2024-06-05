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
const int base = 31;

ll n, a[maxn + 2];
string s;

ll dp[7];

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
    	cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
    	if (s[i] == 'h') dp[1] += a[i];
		if (s[i] == 'a') dp[2] = min(dp[1], dp[2] + a[i]);
		if (s[i] == 'r') dp[3] = min(dp[2], dp[3] + a[i]);
		if (s[i] == 'd') dp[4] = min(dp[3], dp[4] + a[i]);
    }
    
    cout << dp[4] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1096/D
