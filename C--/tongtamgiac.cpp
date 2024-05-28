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

ll m, n, k, a[maxa + 2][maxa + 2];
ll ans = -oo;

ll GET(ll x, ll y, ll k) {
	ll ret = 0;
	
	for (int i = 0; i < k; ++i) 
		for (int j = 0; j <= i; ++j) ret += a[x + i][y + j];
		
	return ret;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    
    for (int i = 1; i <= m - k + 1; ++i) {
    	for (int j = 1; j <= n - k + 1; ++j) {
    		ans = max(ans, GET(i, j, k));
    	}
    }
    
    cout << ans << endl;
    return 0;
}
