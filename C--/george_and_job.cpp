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
const int maxa = 5e3 + 5;

ll n, m, k, p[maxn + 2];
ll dp[maxa + 2][maxa + 2], ps[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m >> k;
    
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> p[i];
    	
    	ps[i] = ps[i - 1] + p[i];
    }
    
    // dp(i, j) : max ans if choose i pair, the last element have index j
    // i * m > j -> dp(i, j) = 0
    // else dp(i, j) = max(dp(i, j - 1), dp(i - 1, j - m) + prefixsum[j] - prefixsum[j - m])
    
    for (int i = 1; i <= k; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (i * m > j) dp[i][j] = 0;
    		else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + ps[j] - ps[j - m]);
    	}
    }
    
    cout << dp[k][n] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/467/C