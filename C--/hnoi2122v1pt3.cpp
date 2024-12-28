#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, k, tmp = 0, res = 0;
pair<ll, ll> pts[maxn + 2];
vector<pair<ll, ll>> v;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> pts[i].fi >> pts[i].se;
    	
    	v.pb({pts[i].fi, +1});
    	v.pb({pts[i].se, -1});
    }
    sort(v.begin(), v.end());
    v.pb({n + 1, 0});
    
    for (int i = 0; i < v.size(); ++i) {
    	tmp += v[i].se;
    	if (tmp == k) res += (v[i + 1].fi - v[i].fi), cout << v[i].fi << " " << v[i + 1].fi << endl;
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
