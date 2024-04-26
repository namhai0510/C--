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

ll n, m, gr[maxn + 2], ans = 0;
pair<ll, ll> a[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
    	ll x, y;
    	cin >> x >> y;
    	gr[x] = max(gr[x], y);
    }
    for (int j = 1; j <= m; ++j) {
    	cin >> a[j].fi >> a[j].se;
    }
    
    for (int pr = 1; pr <= 1000000; ++pr) {
    	gr[pr] = max(gr[pr], gr[pr - 1]);
    }
    for (int j = 1; j <= m; ++j) {
    	ans += max(gr[a[j].fi] - a[j].se, 0LL);
    }
    
    cout << ans << endl;
    
    return 0;
}
