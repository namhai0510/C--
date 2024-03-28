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

ll n, q, t[maxn + 2];
ll dp[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> q;
    
    while (q--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> t[i];
    	}
    	sort(t + 1, t + 1 + n);
    	
    	for (int i = 1; i <= 205; ++i) {
    		for (int j = 0; j <= 405; ++j) {
    			dp[i][j] = +oo;
    		}
    	}
    	
    	dp[1][1] = 0;
    	for (int i = 1; i <= n + 1; ++i) {
    		for (int j = 1; j <= 2 * n - 1; ++j) {
    			if (dp[i][j] < +oo) {
	    			if (i < n + 1) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - j));
	    			
	    			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
    			}
    		}
    	}
    	
    	cout << dp[n + 1][2 * n] << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1437/C