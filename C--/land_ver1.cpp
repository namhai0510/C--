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

ll m, n, k, t;
ll a[maxa + 2][maxa + 2], ps[maxa + 2][maxa + 2];
ll ans = 0;

void Calc_Prefix_sum() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i][j];
		}
	}
}

void Sub_k1() {
	for (int i = 1; i <= m - min(m, n) + 1; ++i) {
    	for (int j = 1; j <= n - min(m, n) + 1; ++j) {
    		ll l = 1, r = min(m, n), mid;
    		
    		while (l <= r) {
    			mid = (l + r) / 2;
    			
    			// cout << i << " " << i + mid << " " << j << " " << j + mid << endl;
    			if (ps[i + mid - 1][j + mid - 1] - ps[i - 1][j - 1] <= t) {
    				l = mid + 1;
    			}
    			else r = mid - 1;
    		}
    		
    		if (ps[i + r - 1][j + r - 1] - ps[i - 1][j - 1] <= t)
    			ans = max(ans, r * r);
    		// cout << ans << endl;
    	}
    }
    
    cout << ans << endl;
}

int main() {
    nothing
    if (fopen("land.inp", "r")) {
        freopen("land.inp", "r", stdin);
        freopen("land.out", "w", stdout);
    }
    cin >> m >> n >> k >> t;
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    Calc_Prefix_sum();
    
    if (k == 1) Sub_k1();
    
    return 0;
}
