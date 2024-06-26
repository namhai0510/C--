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

ll t, n;
pair<ll, ll> a[maxn + 2], st[maxn + 2];
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n;
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i].fi;
    	for (int i = 1; i <= n; ++i) cin >> a[i].se;
    	
    	for (int i = 1; i <= n; ++i) {
    		st[i].fi = a[i].fi - a[i].se;
    		st[i].se = a[i].fi;
    	}
    	sort(st + 1, st + 1 + n);
    	
    	ll l = -1, r = -1, ans = 0;
    	
    	for (int i = 1; i <= n; ++i) {
    		if (st[i].fi >= r) {
    			ans += (r - l) * (r - l + 1) / 2;
    			l = st[i].fi;
    			r = st[i].se;
    		}
    		else {
    			r = max(r, st[i].se);
    		}
    	}
    	
    	ans += (r - l) * (r - l + 1) / 2;
    	
    	cout << ans << endl;
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1626/C