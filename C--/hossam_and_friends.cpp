#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, m, cnt = 0, ft[maxn + 2];
pair<ll, ll> uf[maxn + 2];


int main() {
    nothing
    if (fopen("hossam_and_friends.inp", "r")) {
        freopen("hossam_and_friends.inp", "r", stdin);
        freopen("hossam_and_friends.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cin >> n >> m;
    	
    	for (int i = 1; i <= n; ++i) ft[i] = n;
    	cnt = n;
    	
    	for (int i = 1; i <= m; ++i) {
    		ll x, y; cin >> x >> y;
    		uf[i].fi = min(x, y);
    		uf[i].se = max(x, y);
    	}
    	
    	// sort(uf + 1, uf + 1 + m);
    	
    	for (int i = 1; i <= m; ++i) {
    		ft[uf[i].fi] = min(ft[uf[i].fi], uf[i].se - 1);
    	}
    	
    	for(int i = n - 1; i >= 1; --i) ft[i] = min(ft[i], ft[i + 1]);
    
        for(int i = 1; i <= n - 1 ; ++i) cnt += (ft[i] - i);
        
        cout << cnt << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1771/B