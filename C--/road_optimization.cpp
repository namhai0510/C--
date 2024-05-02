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

ll n, l, k, ans = +oo;
pair<ll, ll> a[maxn + 2];
ll dp[maxa + 2][maxa + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> l >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i].fi;
    for (int i = 1; i <= n; ++i) cin >> a[i].se;
    
    a[n + 1].fi = l;
    
    for (int i = 1; i <= n + 1; ++i) {
    	for (int j = 0; j <= k; ++j) dp[i][j] = +oo;
    }
    dp[1][0] = 0;
    
    for (int i = 2; i <= n + 1; ++i) {
    	for (int j = 0; j <= min(k, i - 1LL); ++j) {
    		dp[i][j] = dp[i - 1][j] + a[i - 1].se * (a[i].fi - a[i - 1].fi);
    		
    		for (int w = 0; w <= j && i - w >= 2; ++w) {
    			dp[i][j] = min(dp[i][j], dp[i - w - 1][j - w] + (a[i].fi - a[i - w - 1].fi) * a[i - w - 1].se);
    		}
    	}
    }
    
    for(int i = 0 ; i <= k ; i ++) {
        ans = min(ans, dp[n + 1][i]);
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1625/C