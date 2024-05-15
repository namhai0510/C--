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

ll n, ans = 0, res = 0;
map<pair<ll, ll>, ll> diamond;

pair<ll, ll> a[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2}, {1, -1}, {1, 0}, {1, 1}, {2, 0}};
pair<ll, ll> b[] = {{-2, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2}, {1, -1}, {1, 0}, {1, 1}};
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	ll x, y, w;
    	cin >> x >> y >> w;
    	diamond[{x, y}] = w;
    }
    
    for (auto it : diamond) {
    	ll x = it.fi.fi, y = it.fi.se;
    	
    	for (int i = 0; i < 12; ++i) {
    		ll x2 = x + b[i].fi, y2 = y + b[i].se;
    		
    		res = 0;
    		for (int j = 0; j < 12; ++j) {
    			ll x3 = x2 + a[j].fi, y3 = y2 + a[j].se;
    			if (diamond.find({x3, y3}) != diamond.end()) res += diamond[{x3, y3}];
    		}
    		
    		ans = max(ans, res);
    	}
    }
    
    cout << ans << endl;
    
    return 0;
}

// https://oj.vnoi.info/problem/bedao_g16_a