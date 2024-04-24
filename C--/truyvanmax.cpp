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
const int maxn = 5e5 + 5;
const int maxa = 2e3 + 5;

ll n, q, a[maxn + 2];
ll f[maxn + 2], ans = 0, fa[maxn + 2], ufa[maxn + 2], factors[maxn + 2];
vector<pair<ll, ll>> v;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	f[i] = 0;
    	fa[i] = -oo;
    	ufa[i] = -oo;
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = i; j <= n; j += i) f[i] += a[j];
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = i; j <= n; j += i) {
    		fa[j] = max(fa[j], f[i]);
    		factors[j]++;
    	}
    }
    
    for (int i = 1; i <= n; ++i) v.pb({f[i], i});
    sort(v.begin(), v.end());
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = v.size() - 1; j >= v.size() - 1 - factors[i]; --j) {
    		if (i % v[j].se != 0) {
    			ufa[i] = v[j].fi;
    			break;
    		}
    	}
    }
    	
    cin >> q;
    while (q--) {
    	ll i, s;
    	
    	cin >> i >> s;
    	
    	ans += max({fa[i] + s, ufa[i]});
    }
    
    cout << ans << endl;
    return 0;
}
