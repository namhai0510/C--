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
const int maxa = 2e2 + 5;
const int base = 31;
ll R, G, B, ans;
ll r[maxn + 2], g[maxn + 2], b[maxn + 2];
ll dp[maxa + 2][maxa + 2][maxa + 2];

bool cmp (ll X, ll Y) {
	return X > Y;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> R >> G >> B;
    
    for (int i = 1; i <= R; ++i) {
    	cin >> r[i];
    }
    sort(r + 1, r + 1 + R, cmp);
    
    for (int i = 1; i <= G; ++i) {
    	cin >> g[i];
    }
    sort(g + 1, g + 1 + G, cmp);
    
    for (int i = 1; i <= B; ++i) {
    	cin >> b[i];
    }
    sort(b + 1, b + 1 + B, cmp);
    
    memset(dp, -1, sizeof(dp));
    dp[1][1][1] = 0;
    
    for (int i = 1; i <= R + 1; ++i) {
    	for (int j = 1; j <= G + 1; ++j) {
    		for (int k = 1; k <= B + 1; ++k) {
    			if (dp[i][j][k] == -1) continue;
    			
    			if (i + 1 <= R + 1 && j + 1 <= G + 1)
		        	dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
		        if (i + 1 <= R + 1 && k + 1 <= B + 1) 
		        	dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
		        if (j + 1 <= G + 1 && k + 1 <= B + 1)
		        	dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
    		}
    	}
    }
    
    ans = -1;
	for (int i = 1; i <= R + 1; ++i) {
		for (int j = 1; j <= G + 1; ++j) {
			for (int k = 1; k <= B + 1; ++k) {
				// if (dp[i][j][k] != -1)
					// cout << i << " " << j << " " << k << endl << dp[i][j][k] << endl;
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans;
    return 0;
}

// https://codeforces.com/problemset/problem/1398/D