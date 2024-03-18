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

ll n, k;

vector<ll> v[maxn + 2];
ll dp[150][20005], ans = 0;

void Factor(ll x) {
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			if (i * i == x) {
				v[x].pb(i);
			}
			else {
				v[x].pb(i);
				v[x].pb(x / i);
			}
		}
	}
	
}

int main() {
    nothing
    if (fopen("seqdiv.inp", "r")) {
        freopen("seqdiv.inp", "r", stdin);
        freopen("seqdiv.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 1; i <= k; ++i) {
    	Factor(i);
    	
    	dp[0][i] = 0;
    	dp[1][i] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= k; ++j) {
    		for (int t = 0; t < v[j].size(); ++t) {
    			if (j != v[j][t])
    				dp[i][j] += dp[i - 1][v[j][t]];
    			dp[i][j] %= modd;
    		}
    		// a[i] % a[i - 1] = 0;
    		for (int t = 2; t * j <= k; ++t) {
    			dp[i][j] += dp[i - 1][t * j];
    			dp[i][j] %= modd;
    		}
    		// a[i - 1] % a[i] = 0;
    		
    		// cout << i << " " << j << " " << dp[i][j] << endl;
    	}
    }
    
    for (int i = 1; i <= k; ++i) {
    	ans += dp[n][i];
    	ans %= modd;
    }
    cout << ans << endl;
    return 0;
}

// dem so day con do dai n, 1 <= a[i] <= k, a[i] % a[i + 1] == 0 || a[i + 1] % a[i] == 0