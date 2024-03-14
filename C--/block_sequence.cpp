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
ll dp[maxn + 2];

void Reset() {
	for (int i = 1; i <= n + 2; ++i) {
		dp[i] = 0;
		a[i] = 0;
	}
	
	dp[n] = 1;
}

ll Calc(int pos) {
	if (pos > n + 1) return (n + 2);
	
	if (pos == n + 1) return 0;
	
	return dp[pos];
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	
    	Reset();
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	for (int i = n - 1; i >= 1; --i) {
    		dp[i] = min(dp[i + 1] + 1, Calc(i + a[i] + 1));
    	}
    	
    	cout << dp[1] << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1881/E
