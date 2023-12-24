#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll m, n, e, sum, num;
pair<ll, ll> p[maxn + 2], pos[maxn + 2], cnt[maxn + 2];
// trai truoc phai sau

ll dgnum(ll i, ll j) {
	if (m >= n) return m - i + j;
	else return n - j + i;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m; n = m;
    e = min(m, n); num = (m + n - 1);
    
    ll val = 0;
    
    for (int i = (num) / 2; i >= 1; --i) {
    	if (val < e) val++;
    	p[i].fi = val; cnt[i].fi = val;
    	p[i].se = val; cnt[i].se = val;
    }
    
    // for (int i = 1; i <= m; ++i) {
    	// for (int j = 1; j <= n; ++j) cout << dgnum(i, j) - m << " ";
    	// cout << endl;
    // }
    
    sum = m; pos[0].fi = m; cnt[0].fi = m;
    for (int i = 1; i <= (num / 2); ++i) {
    	pos[i].fi = sum;
    	sum += p[i].fi;
    	pos[i].se = sum;
    	sum += p[i].se;
    }
    
    // for (int i = 1; i <= num / 2; ++i) 
    	// cout << pos[i].fi << " " << pos[i].se << "\n";
    	
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		ll dg = dgnum(i, j) - m;
    		if (dg == 0) {
    			cout << pos[dg].fi + p[dg].fi << " ";
				p[dg].fi--;
    		}
    		else if (dg < 0) {
    			dg = abs(dg);
    			cout << pos[dg].fi + p[dg].fi << " ";
    			p[dg].fi--;
    		}
    		else {
    			cout << pos[dg].se + p[dg].se << " ";
    			p[dg].se--;
    		}
    	}
    	cout << "\n";
    }
    
    return 0;
}
