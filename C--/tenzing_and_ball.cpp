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

ll t, n, a[maxn + 2];
ll dp[maxn + 2], m[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		m[i] = -oo;
    	}
    	
    	for (int i = 1; i <= n; ++i) {
    		dp[i] = max(dp[i - 1], m[a[i]] + i);
    		m[a[i]] = max(m[a[i]], dp[i - 1] - (i - 1));
    	}
    	
    	cout << dp[n] << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1842/C