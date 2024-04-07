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

ll n, h, l, r;
ll a[maxn + 2];

ll dp[maxa + 2][maxa + 2], check[maxa + 2][maxa + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> h >> l >> r;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    check[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < h; ++j) {
    		if (check[i - 1][j]) {
    			ll x, y;
    			
    			x = (j + a[i]) % h;
    			y = (j + a[i] - 1) % h;
    			
    			check[i][x] = check[i][y] = 1;
    			
    			dp[i][x] = max(dp[i][x], dp[i - 1][j] + (l <= x && x <= r));
                dp[i][y] = max(dp[i][y], dp[i - 1][j] + (l <= y && y <= r));
    		}
    	}
    }
    
    for (int i = 0; i < h; ++i) ans = max(ans, dp[n][i]);
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1324/E